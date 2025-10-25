#pragma once
#include "MeshData.h"
#include <glad/glad.h>

/* 
 * @class		Mesh
 * @brief		モデルデータのメッシュを扱うクラス
 */
class Mesh {
private:		//メンバ変数

	std::vector<Vector3> vertices;
	std::vector<Vector3> normals;
	std::vector<Vector3> uvs;
	std::vector<unsigned int> indices;

	GLuint vao, vbo, ebo;

public:			//コンストラクタとデストラクタ

	/*
	 * @brief	コンストラクタ
	 */
	Mesh();

	/*
	 * @brief	デストラクタ
	 */
	~Mesh();

public:			//メンバ関数

	/*
	 * @function	SetData 
	 * @brief		メッシュデータをセット
	 * @param[in]	const MeshData& _meshData
	 */
	void SetData(const MeshData& _meshData);

	/*
	 * @function	UploadGPU
	 * @brief		GPUにデータをアップロード
	 */
	void UploadGPU();

	/*
	 * @function		Draw
	 * @brief			描画処理
	 */
	void Draw();

};
