#include "ModelResource.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Mesh/Mesh.h"

ModelResource::ModelResource()
{
}

ModelResource::~ModelResource()
{
}

void ModelResource::Load(const std::string& _filePath)
{
    MeshData data;
    //ファイルのロード
    std::ifstream ifs(_filePath);

    //読み込めなかった場合
    if (!ifs) {
        std::cerr << "ファイルが読み込めませんでした！" << std::endl;
        return;
    }
    std::string line;
    while (std::getline(ifs, line)) {
        std::istringstream iss(line);
        float x, y, z;
        if (!(iss >> x >> y >> z)) {
            std::cerr << "ファイルが読み込めませんでした！" << std::endl;
            continue;
        }
        data.vertexs.push_back(Vector3(x, y, z));
    }

    Mesh mesh;
    mesh.SetData(data);

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
