#pragma once
#include <string>
#include <glad/glad.h>
#include "../../Math/Matrix_4x4.h"

class Shader {
private:
	GLuint programID = 0;

public:		//コンストラクタとデストラクタ

	/*
	 * @brief	コンストラクタ
	 */
	Shader();

	/*
	 * @brief	デストラクタ
	 */
	~Shader();

public:		//メンバ関数

	/*
	 * @function	Load
	 * @brief		シェーダーをロード
	 * @param[in]	const std::string& _vertPath
	 * @param[in]	const std::string& _fragPath
	 * @return		bool
	 */
	bool Load(const std::string& _vertPath, const std::string& _fragPath);

	/*
	 * @function	Bind
	 * @brief		ユニフォーム変数をバインド
	 */
	void Bind()const;

	/*
	 * @function	UnBind
	 * @brief		ユニフォーム変数を解除
	 */
	void UnBind()const;

	/*
	 * @function	SetUniformMat4
	 * @brief		行列をUniform変数に返す
	 * @param[in]	const std::string& _uMVP
	 * @param[in]	const Matrix_4x4& _matrix
	 */
	void SetUniformMat4(const std::string& _uMVP,const Matrix_4x4& _matrix);

private:		//メンバ関数

	/*
	 * @function	LoadFile
	 * @brief		GLSLファイルを読み込んで文字列としてコードを返す
	 * @param[in]	const std::string& _filePath
	 * @return		std::string
	 */
	std::string LoadFile(const std::string& _filePath);

	/*
	 * @function	Compile
	 * @brief		頂点orフラグメントシェーダーをOpenGLに渡してコンパイル
	 * @param[in]	GLenum _type	ロードのタイプ
	 * @param[in]	const std::string& _source
	 * @return		GLuint
	 */
	GLuint Compile(GLenum _type, const std::string& _source);

	/*
	 * @function	GetUniformLocation
	 * @brief		シェーダー内のuniform変数を取得
	 * @param[in]	const std::string& _name
	 * @return		GLint
	 */
	GLint GetUniformLocation(const std::string& _name);

};
