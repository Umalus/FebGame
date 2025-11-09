#pragma once

#include "../Resource/TextureResource.h"

/*
 * @class	textureManager
 */

class TextureResourceManager {
public:		//コンストラクタとデストラクタ

	/*
	 * @brief	コンストラクタ
	 */
	TextureResourceManager();

	/*
	 * @brief	デストラクタ
	 */
	~TextureResourceManager();

public:		//メンバ変数

	/*
	 * @function	LoadTexture
	 * @brief		テクスチャをロード、すでにキャッシュしていたら生成済みのものを返す
	 * @param[in]	const std::string& _filePath
	 * @return		std::shared_ptr<TextureResource>
	 */
	std::shared_ptr<TextureResource> LoadTexture(const std::string& _filePath);

};
