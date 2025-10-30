#pragma once

#include "../../Math/Vec3.h"
#include <vector>
#include "Vertex.h"
/*
 * @struct		MeshData
 * @brief		メッシュの読み込みの中間成果物
 */

struct MeshData
{
	std::vector<Vertex> vertecies;		//頂点データ
	std::vector<unsigned int> indices;	//ポリゴン描画順のデータ
};
