#include "Mesh.h"
#include <iostream>

Mesh::Mesh()
	:indexCount(-1)
	,vao{}
	,vbo{}
	,ibo{}
	,materialIndex{-1}
{
}

Mesh::~Mesh()
{
	if (vao)
		glDeleteVertexArrays(1,&vao);
	if (vbo)
		glDeleteBuffers(1,&vbo);
	if (ibo)
		glDeleteBuffers(1,&ibo);
}

void Mesh::SetData(MeshData _meshData)
{;
	//頂点データを保存
	this->vertices = _meshData.vertecies;
	this->indices = _meshData.indices;
	indexCount = indices.size();
	UpdateToGPU();
}

void Mesh::UpdateToGPU()
{
	//vaoを生成してバインド
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	//Vboを生成してバインド
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), vertices.data(), GL_STATIC_DRAW);
	//Iboを生成してバインド
	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(unsigned int) * indices.size(),indices.data(), GL_STATIC_DRAW);

	//頂点属性を設定
	//ポジション
	glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof(Vertex),(void*)offsetof(Vertex,position));
	glEnableVertexAttribArray(0);
	//法線
	glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,sizeof(Vertex),(void*)offsetof(Vertex,normal));
	glEnableVertexAttribArray(1);
	//uv
	glVertexAttribPointer(2,2,GL_FLOAT,GL_FALSE,sizeof(Vertex),(void*)offsetof(Vertex,uv));
	glEnableVertexAttribArray(2);
	//Vaoをアンバインド
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	indexCount = static_cast<int>(indices.size());
	std::cout << "indexCount = " << indexCount << std::endl;

}

void Mesh::Draw()const
{
	std::cout << "[Draw] vao=" << vao << " indexCount=" << indexCount << std::endl;

	glBindVertexArray(vao); // VAOをバインド
	glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, nullptr);
	glBindVertexArray(0);   // 後片付け（任意）
}

void Mesh::Unload()
{
	//GPUリソースの解放
	glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &ibo);
	glDeleteVertexArrays(1, &vao);
	
	//CPU側のデータのクリア
	indices.clear();
	indices.shrink_to_fit();

	vertices.clear();
	vertices.shrink_to_fit();
}

void Mesh::SetMaterialIndex(int _index)
{
	materialIndex = _index;
}
