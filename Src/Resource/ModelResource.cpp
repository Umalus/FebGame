#include "ModelResource.h"
#include <iostream>
#include <string>
#include "../Manager/ResourceManager.h"



ModelResource::ModelResource()
	:meshes{}
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
	std::vector<MeshData> allMeshData = SearchAllNode(loader);

	for (auto& data : allMeshData) {
		std::shared_ptr<Mesh> createdMesh;
		createdMesh->SetData(data);
		createdMesh->UpdataToGPU();
		meshes.push_back(createdMesh);
	}
	
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

std::vector<MeshData> ModelResource::SearchAllNode(const FBXLoader& _loader)
{
	//全てのノードが入る配列
	std::vector<MeshData> allMeshes;
	//ルートノードを取得
	FbxNode* root = _loader.GetScene()->GetRootNode();
	//その中のノードのデータを挿入
	SearceNodeRecursion(root, allMeshes);

	return allMeshes;
}

void ModelResource::SearceNodeRecursion(FbxNode* _node, std::vector<MeshData>& _meshes)
{
	//_nodeが無ければ処理しない
	if (!_node)return;

	//ノードからメッシュを取得
	FbxMesh* fbxMesh = _node->GetMesh();
	//メッシュからデータを抽出
	if (fbxMesh && fbxMesh->GetElementUV()) {
		MeshData meshData = SearchNode(fbxMesh);
		_meshes.push_back(meshData);
	}
	//全てのルートノード探索が完了するまで再帰
	for (int i = 0; i < _node->GetChildCount(); ++i) {
		SearceNodeRecursion(_node->GetChild(i), _meshes);
	}

}

MeshData ModelResource::SearchNode(FbxMesh* _mesh)
{
	//最終的に返すMeshDataを作成
	MeshData meshData;
	//メッシュが無ければ早期リターン
	if (!_mesh || _mesh->GetElementUV() == nullptr)return meshData;
	//各要素(頂点、法線、UV、描画順)をポリゴンループ内で抽出
	std::vector<Vertex> fbxVertecies;
	std::vector<unsigned int> fbxIndices;
	unsigned int currentIndex = 0;
	for (int i = 0, max = _mesh->GetPolygonCount(); i < max; i++) {
		int polygonSize = _mesh->GetPolygonSize(i);
		for (int j = 0; j < polygonSize; j++) {
			Vertex v;

			//頂点を抽出
			Vector3 vertex = FBXVec4ToVec3(_mesh->GetControlPointAt(_mesh->GetPolygonVertex(i, j)));
			v.position = vertex;
			
			//法線を抽出
			FbxVector4 normal;
			if (_mesh->GetPolygonVertexNormal(i, j, normal))
				v.normal = FBXVec4ToVec3(normal);

			//UV座標を抽出
			const char* uvSetName = _mesh->GetElementUV()->GetName();
			FbxVector2 uv;
			bool unmapped;
			bool hasUv = _mesh->GetPolygonVertexUV(i, j, uvSetName, uv, unmapped);
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
