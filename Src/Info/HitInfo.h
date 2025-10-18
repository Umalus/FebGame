#pragma once
#include "../Math/Vec3.h"

class Collider;
struct HitInfo {
	bool isHit = false;						//当たったかどうか
	Vector3 point;					//当たった地点
	Vector3 normal;					//
	float distance;					//距離
	Collider* collider = nullptr;   //コライダー

	bool isValid()const { return collider != nullptr; };
};