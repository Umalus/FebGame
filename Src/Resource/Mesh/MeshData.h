#pragma once

#include "../../Math/Vec3.h"
#include <vector>
/*
 * @struct		MeshData
 * @brief		ƒƒbƒVƒ…‚Ì“Ç‚İ‚İ‚Ì’†ŠÔ¬‰Ê•¨
 */

struct MeshData
{
	std::vector<Vector3> vertexs;
 	std::vector<Vector3> normals;
	std::vector<Vector3> uvs;
	std::vector<unsigned int> index;
};
