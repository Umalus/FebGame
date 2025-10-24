#pragma once
#include "Singleton.h"
#include <map>
#include <unordered_map>
#include <iostream>
#include <../../Src/Resource/Resource.h>
#include <../../Src/Manager/ModelResourceManager.h>

/*
 * @class	ResourceManager
 * @brief	素材の一元管理クラス
 * @tips	中央集権化させる(ID,Pathの管理、各ResourceManagerとからロードを呼び出す)
 */
class ResourceManager : public Singleton<ResourceManager> {
public:		//メンバ変数
	std::unordered_map<int, std::string > idToPath;						//IDからパス検索
	std::unordered_map<std::string, int> pathToID;						//パスからID検索
	std::unordered_map<int,std::shared_ptr<Resource>> idToResource;		//IDから本体を検索
	//マネージャー系
	ModelResourceManager modelManager;

public:		//コンストラクタとデストラクタ

	/*
	 * @brief	コンストラクタ
	 */
	ResourceManager();

	/*
	 * @brief	デストラクタ
	 */
	~ResourceManager();

public:		//メンバ関数

	/*
	 * @function	ModelLoad
	 * @brief		ModelResourceManagerにロードを指令
	 * @param[in]	const std::string&	_filePath
	 */
	void ModelLoad(const std::string& _filePath);
	
};
