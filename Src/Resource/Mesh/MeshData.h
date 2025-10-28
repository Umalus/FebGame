#pragma once

#include "../../Math/Vec3.h"
#include <vector>
/*
 * @struct		MeshData
 * @brief		メッシュの読み込みの中間成果物
 */

struct MeshData
{
	std::vector<Vector3> vertecies;		//頂点データ
 	std::vector<Vector3> normals;		//法線データ
	std::vector<Vector3> uvs;			//UV座標データ
	std::vector<unsigned int> indices;	//ポリゴン描画順のデータ
};
