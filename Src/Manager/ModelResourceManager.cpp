#include "ModelResourceManager.h"

ModelResourceManager::ModelResourceManager()
{
}

ModelResourceManager::~ModelResourceManager()
{
}

std::shared_ptr<ModelResource> ModelResourceManager::LoadModel(std::string _filePath)
{
    //モデルを作成してポインタを返す
    std::shared_ptr<ModelResource> loadModel = std::make_shared<ModelResource>();
    loadModel->Load(_filePath);
    return loadModel;
}
