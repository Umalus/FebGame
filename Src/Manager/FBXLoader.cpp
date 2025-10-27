#include "FBXLoader.h"
#include <fstream>
#include <sstream>

FBXLoader::FBXLoader()
{
	//FBXManagerの初期化
	fbxManager = FbxManager::Create();
	if (fbxManager) {
		FbxIOSettings* ioSettings = FbxIOSettings::Create(fbxManager, IOSROOT);
		fbxManager->SetIOSettings(ioSettings);
	}
}

FBXLoader::~FBXLoader()
{
	if (fbxManager)fbxManager->Destroy();
}

inline bool FBXLoader::LoadFBX(const std::string& _filePath)
{
	//ファイルのロード
	std::ifstream ifs(_filePath);

	//読み込めなかった場合
	if (!ifs) {
		std::cerr << "ファイルが読み込めませんでした！" << std::endl;
		return false;
	}

	//FBXImporterとシーンを生成
	FbxImporter* importer = FbxImporter::Create(fbxManager, "Impoter");
	scene = FbxScene::Create(fbxManager, "Scene");
	//読み込み出来たかどうか確認
	bool isFbxLoaded = importer->Initialize(_filePath.c_str(), -1, fbxManager->GetIOSettings());
	if (!isFbxLoaded) {
		std::cerr << importer->GetStatus().GetErrorString() << std::endl;
		return false;
	}
	//シーンに展開
	bool isImportScene = importer->Import(scene);
	if (!isImportScene)
		return false;

	//読み込み成功なのでImpoterを破棄しtrueを返す
	if (importer)
		importer->Destroy();

	return true;
}

inline FbxScene* FBXLoader::GetScene() const
{
	return scene;
}
