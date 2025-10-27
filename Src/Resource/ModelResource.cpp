#include "ModelResource.h"
#include <iostream>
#include <string>
#include "Mesh/Mesh.h"
#include "../Manager/FBXLoader.h"

ModelResource::ModelResource()
{
}

ModelResource::~ModelResource()
{
}

void ModelResource::Load(const std::string& _filePath)
{
    MeshData data;
    

    Mesh mesh;
    mesh.SetData(data);

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
