#include "Mesh.h"

Mesh::Mesh()
	:vao{}
	,vbo{}
	,ebo{}
{
}

Mesh::~Mesh()
{
}

void Mesh::SetData(const MeshData& _meshData)
{
	vertices.clear();
	indices.clear();
	//頂点データを保存
	for (auto vertexDatas : _meshData.vertexs) {
		vertices.push_back(vertexDatas);
	}
	
	for (auto indexDatas : _meshData.index) {
		indices.push_back(indexDatas);
	}
}

void Mesh::UploadGPU()
{
}

void Mesh::Draw()
{
}
