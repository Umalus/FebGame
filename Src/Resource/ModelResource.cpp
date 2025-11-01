#include "ModelResource.h"
#include <iostream>
#include <string>
#include "../Manager/ResourceManager.h"



ModelResource::ModelResource()
	:mesh(nullptr)
{
}

ModelResource::~ModelResource()
{
}

void ModelResource::Load(const std::string& _filePath)
{
	//FBXManagerの初期化
	FBXLoader loader;
	bool isFbxDataLoaded = loader.LoadFBX(_filePath);
	//ロード出来ていなければ早期リターン
	if (!isFbxDataLoaded)
		return;
	//MeshDataを取得
	MeshData data = SearchNode(loader);

	//メッシュに抽出したデータを入れる
	mesh->SetData(data);
	mesh->UpdataToGPU();
	
}

void ModelResource::UnLoad()
{
}

void ModelResource::Clear()
{
}

bool ModelResource::isLoaded() const
{
	return false;
}

MeshData ModelResource::SearchNode(const FBXLoader& _loader)
{
	//最終的に返すMeshDataを作成
	MeshData meshData;
	//シーンからノードを巡回
	FbxNode* node = _loader.GetScene()->GetRootNode();
	FbxMesh* fbxMesh = node->GetMesh();
	//メッシュが無ければ早期リターン
	if (!fbxMesh || fbxMesh->GetElementUV() == nullptr)return meshData;
	//各要素(頂点、法線、UV、描画順)をポリゴンループ内で抽出
	std::vector<Vertex> fbxVertecies;
	std::vector<unsigned int> fbxIndices;
	unsigned int currentIndex = 0;
	for (int i = 0, max = fbxMesh->GetPolygonCount(); i < max; i++) {
		int polygonSize = fbxMesh->GetPolygonSize(i);
		for (int j = 0; j < polygonSize; j++) {
			Vertex v;

			//頂点を抽出
			Vector3 vertex = FBXVec4ToVec3(fbxMesh->GetControlPointAt(fbxMesh->GetPolygonVertex(i, j)));
			v.position = vertex;
			
			//法線を抽出
			FbxVector4 normal;
			if (fbxMesh->GetPolygonVertexNormal(i, j, normal))
				v.normal = FBXVec4ToVec3(normal);

			//UV座標を抽出
			const char* uvSetName = fbxMesh->GetElementUV()->GetName();
			FbxVector2 uv;
			bool unmapped;
			bool hasUv = fbxMesh->GetPolygonVertexUV(i, j, uvSetName, uv, unmapped);
			if (hasUv && !unmapped)
				v.uv = Vector3(uv[0], uv[1], 0);
			
			//作られた頂点情報を配列に挿入
			fbxVertecies.push_back(v);
			
			//ポリゴン描画順を設定
			fbxIndices.push_back(currentIndex++);
		}
	}
	//抽出したコンテナをMeshDataに格納
	meshData.vertecies = fbxVertecies;
	meshData.indices = fbxIndices;

	return meshData;
}

inline Vector3 ModelResource::FBXVec4ToVec3(const FbxVector4& _vec4) const
{
	return Vector3(_vec4.mData[0], _vec4.mData[1], _vec4.mData[2]);
}
