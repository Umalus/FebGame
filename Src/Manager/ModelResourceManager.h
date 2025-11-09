#pragma once
#include "../Resource/ModelResource.h"
/*
 * @class	ModelResourceManager
 * @brief	主にモデル素材のロードアンロードを行う
 */

class ModelResourceManager {
private:

public:		//コンストラクタとデストラクタ

	/*
	 * @brief	コンストラクタ
	 */
	ModelResourceManager();

	/*
	 * @brief	デストラクタ
	 */
	~ModelResourceManager();

public:		//メンバ変数

	/*
	 * @function	LoadModel
	 * @brief		モデルをロード、すでにキャッシュしていたら、生成済みのものを返す
	 * @param[in]	const std::string& _filePath
	 * @return		std::shared_ptr<ModelResource>
	 */
	std::shared_ptr<ModelResource> LoadModel(std::string _filePath);	
};

