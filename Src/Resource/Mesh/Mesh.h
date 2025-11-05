#pragma once
#include "MeshData.h"
#include <glad/glad.h>
#include "Vertex.h"

/* 
 * @class		Mesh
 * @brief		モデルデータのメッシュを扱うクラス
 */
class Mesh {
private:		//メンバ変数

	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;
	GLsizei indexCount;

	GLuint vao, vbo, ibo;

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
	 * @param[in]	MeshData _meshData
	 */
	void SetData(MeshData _meshData);

	/*
	 * @function	UploadGPU
	 * @brief		GPUにデータをアップロード
	 */
	void UpdataToGPU();

	/*
	 * @function		Draw
	 * @brief			描画処理
	 */
	void Draw()const;

	/*
	 * @function	Unload
	 * @brief		GPUにアップロードしたバッファを削除、解放
	 */
	void Unload();

};
