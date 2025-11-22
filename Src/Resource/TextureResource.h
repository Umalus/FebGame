#pragma once
#include "Resource.h"
#include <glad/glad.h>
#include <fbxsdk.h>
/*
 * @class	TextureResource
 * @brief	テクスチャのリソース
 */
class TextureResource : public Resource {
private:		//メンバ変数
	GLuint textureID;			//テクスチャのID(リソースクラスのIDとは別物)
	std::string texturePath;	//テクスチャのパス(リソースクラスのパスとは別物)
public:		//コンストラクタとデストラクタ

	/*
	 * @brief		コンストラクタ
	 */
	TextureResource();

	/*
	 * @brief		デストラクタ
	 */
	~TextureResource();


public:		//継承したメンバ関数

	/*
	 * @function	Load
	 * @brief		テクスチャをロード
	 * @param[in]	const std::string	_filePath
	 */
	void Load(const std::string& _filePath)override;

	/*
	 * @function	UnLoad
	 * @brief		テクスチャをアンロード
	 */
	void UnLoad()override;

	/*
	 * @function	Clear
	 * @brief		テクスチャをクリア
	 */
	void Clear()override;

	/*
	 * @function	isLoaded
	 * @brief		ロードしたかどうか
	 * @return		bool
	 */
	bool isLoaded()const override;

	/*
	 * @function	Bind
	 * @brief		描画時のバインド
	 * @param[in]	GLuint	_index
	 */
	void Bind(GLuint _index);

public:		//ゲッターのみ

	/*
	 * @function	GetTextureID
	 * @brief		テクスチャIDを取得
	 * @return		int
	 */
	int GetTextureID()const;
	
	/*
	 * @function	GetTexturePath
	 * @brief		テクスチャPathを取得
	 * @return		std::string
	 */
	std::string GetTexturePath()const;

};
