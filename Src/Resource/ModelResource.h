#pragma once

#include "Resource.h"
#include "../Manager/FBXLoader.h"
#include "Mesh/Mesh.h"
class ModelResource : public Resource {
private:
	std::shared_ptr<Mesh> mesh;

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
	 * @function	SearchNode
	 * @brief		ノードを巡回
	 * @param[in]	const FbxLoader& _loader
	 * @return		MeshData
	 */
	MeshData SearchNode(const FBXLoader& _loader);

	/*
	 * @function	FBXVec4ToVec3
	 * @brief		Vec4からVec3に変換
	 * @param[in]	const FbxVector4& _vec4
	 * @return		Vector3
	 */
	inline Vector3 FBXVec4ToVec3(const FbxVector4& _vec4)const;
};
