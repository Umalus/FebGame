#include "ResourceManager.h"

ResourceManager::ResourceManager()
	:nextModelID{0}
	,nextTextureID{256}
	,nextSoundID{512}
	,nextEffectID{768}
{
}

ResourceManager::~ResourceManager()
{
}

void ResourceManager::LoadResource(const std::string& _filePath, ResourceType _type)
{
	//まず最初にキャッシュされているかを確認
	if (pathToID[_filePath])
		return;
	//未登録なのでタイプによって作るリソースを変える
	std::shared_ptr<Resource> res;
	switch (_type)
	{
	case Model:
		res = modelManager.LoadModel(_filePath);
		//IDを設定
		res->SetID(nextModelID++);
		break;
	case Texture:
		break;
	case Sound:
		break;
	case Effect:
		break;
	default:
		break;
	}
	//パスを設定
	res->SetPath(_filePath);
	//各配列に保存
	idToPath[res->GetID()] = res->GetPath();
	pathToID[res->GetPath()] = res->GetID();
	//リソースを保存
	idToResource[res->GetID()] = res;
}

std::shared_ptr<Resource> ResourceManager::GetResourceFromID(int _ID)
{
	return idToResource[_ID];
}
