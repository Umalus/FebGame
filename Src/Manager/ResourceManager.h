#pragma once
#include "Singleton.h"
#include <map>
#include <unordered_map>
#include <iostream>
#include "../Resource/Resource.h"
#include "../Manager/ModelResourceManager.h"
#include "../Manager/TextureManager.h"
#include "../GameConst.h"
/*
 * @class	ResourceManager
 * @brief	素材の一元管理クラス
 * @tips	中央集権化させる(ID,Pathの管理、各ResourceManagerとからロードを呼び出す)
 */
class ResourceManager : public Singleton<ResourceManager> {
private:	//メンバ変数
	int nextModelID;
	int nextTextureID;
	int nextSoundID;
	int nextEffectID;

public:		//メンバ変数
	std::unordered_map<int, std::string > idToPath;						//IDからパス検索
	std::unordered_map<std::string, int> pathToID;						//パスからID検索
	std::unordered_map<int,std::shared_ptr<Resource>> idToResource;		//IDから本体を検索
	//マネージャー系
	ModelResourceManager modelManager;
	TextureResourceManager textureManager;
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
	 * @function	LoadResource
	 * @brief		タイプを読み取って各マネージャーにロードを指令、配列に保存
	 * @param[in]	const std::string&	_filePath
	 * @param[in]	ResourceType _type
	 */
	void LoadResource(const std::string& _filePath,ResourceType _type);

	/*
	 * @function	GetResourceFromID 
	 * @brief		IDからリソースを取得
	 * @param[in]	int _ID
	 * @return		std::shared_ptr
	 */
	std::shared_ptr<Resource> GetResourceFromID(int _ID);

	template<typename T>
	std::shared_ptr<T> GetResourceAs(int _ID);
};


template<typename T>
inline std::shared_ptr<T> ResourceManager::GetResourceAs(int _ID)
{
	auto res = GetResourceFromID(_ID);
	return std::dynamic_pointer_cast<T>(res);
}