#pragma once

#include "Resource.h"
class ModelResource : public Resource {
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
};
