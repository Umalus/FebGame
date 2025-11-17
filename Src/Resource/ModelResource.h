#pragma once

#include <fbxsdk.h>
#include "Resource.h"
#include "MaterialResource.h"
#include "../Manager/FBXLoader.h"
#include "Mesh/Mesh.h"
class ModelResource : public Resource {
private:
	std::vector<std::shared_ptr<MaterialResource>> materials;
	std::vector<std::shared_ptr<Mesh>> meshes;

public:		//コンストラクタとデストラクタ
	
	/*
	 * @brief	コンストラクタ
	 */
	ModelResource();

	/*
	 * @breif	デストラクタ
	 */
	~ModelResource();

public:		//継承するメンバ関数

	/*
	 * @function	Load
	 * @brief		モデルをロード
	 * @param[in]	const std::string	_filePath
	 */
	void Load(const std::string& _filePath)override;

	/*
	 * @function	UnLoad
	 * @brief		モデルをアンロード
	 */
	void UnLoad()override;

	/*
	 * @function	Clear
	 * @brief		モデルをクリア
	 */
	void Clear()override;

	/*
	 * @function	isLoaded
	 * @brief		ロードしたかどうか
	 * @return		bool
	 */
	bool isLoaded()const override;

private:		//描画処理に必要な変換や便利関数

	/*
	 * @function	SearchAllNode
	 * @brief		全てのノードを巡回
	 * @param[in]	const FBXLoader& _loader
	 * @return      std::vector<MeshData>
	 */
	std::vector<MeshData> SearchAllNode(const FBXLoader& _loader);

	/*
	 * @function	SearceNodeRecursion
	 * @brief		ノード探索の再帰関数
	 * @param[in]	FBXNode* _node
	 * @param[in]	std::vector<MeshData>& _meshes
	 */
	void SearceNodeRecursion(FbxNode* _node, std::vector<MeshData>& _meshes);

	/*
	 * @function	SearchNode
	 * @brief		ノードを巡回
	 * @param[in]	const FbxLoader& _loader
	 * @return		MeshData
	 */
	MeshData SearchNode(FbxMesh* _mesh);

	/*
	 * @function	FBXVec4ToVec3
	 * @brief		Vec4からVec3に変換
	 * @param[in]	const FbxVector4& _vec4
	 * @return		Vector3
	 */
	inline Vector3 FBXVec4ToVec3(const FbxVector4& _vec4)const;
};
