#include "ModelResource.h"
#include <fstream>

ModelResource::ModelResource()
{
}

ModelResource::~ModelResource()
{
}

void ModelResource::Load(const std::string& _filePath)
{
    //ファイルのロード
    std::ifstream ifs(_filePath);

    //読み込めなかった場合
    if (!ifs) {
        std::cerr << "ファイルが読み込めませんでした！" << std::endl;
        return;
    }


    ifs.close();
}

void ModelResource::UnLoad()
{
}

void ModelResource::Clear()
{
}

bool ModelResource::isLoaded() const
{
    return false;
}
