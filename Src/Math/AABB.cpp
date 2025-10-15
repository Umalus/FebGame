#include "AABB.h"

namespace Math {

	constexpr float EPSILON = 0.000001f;
}
AABB::AABB()
	:min{ Vector3::zero }
	, max{ Vector3::one } {
}

AABB::AABB(Vector3 _min, Vector3 _max)
	:min{ _min }
	, max{ _max } {
}

AABB::~AABB()
{
}

void AABB::Expand(Vector3 _amount)
{
	min -= _amount;
	max += _amount;
}

void AABB::Encapsulate(Vector3 _point)
{
	min.x = std::min(min.x, _point.x);
	min.y = std::min(min.y, _point.y);
	min.z = std::min(min.z, _point.z);

	max.x = std::max(max.x, _point.x);
	max.y = std::max(max.y, _point.y);
	max.z = std::max(max.z, _point.z);
}

void AABB::Encapsulate(AABB _other)
{
	Encapsulate(_other.min);
	Encapsulate(_other.max);
}

AABB AABB::FromCenterSize(Vector3 _center, Vector3 _scale)
{
	//中心座標と拡縮から最小座標と最大座標を生成
	Vector3 min = _center - _scale * 0.5f;
	Vector3 max = _center + _scale * 0.5f;

	//引数に入れてAABBを生成
	return AABB(min, max);
}

bool AABB::Intersect(const AABB& _other)const {
	return (max.x >= _other.min.x && min.x <= _other.max.x)
		&& (max.y >= _other.min.y && min.y <= _other.max.y)
		&& (max.z >= _other.min.z && min.z <= _other.max.z);
}

bool AABB::Contains(const Vector3& _point)const
{
	return (max.x >= _point.x && min.x <= _point.x)
		&& (max.y >= _point.y && min.y <= _point.y)
		&& (max.z >= _point.z && min.z <= _point.z);
}

bool AABB::RaycastHitAABB(const Vector3& _origin, const Vector3& _direction) const
{
	float tmin = -INFINITY;
	float tmax = INFINITY;

	float tmin_x, tmax_x;
	float tmin_y, tmax_y;
	float tmin_z, tmax_z;


	//X軸
	if (abs(_direction.x) <= Math::EPSILON) {
		if (_origin.x < min.x || _origin.x > max.x)
			return false;
		else {
			tmin_x = -INFINITY;
			tmax_x = INFINITY;
		}

	}

	else {
	float t1 = (min.x - _origin.x) / _direction.x;
	float t2 = (max.x - _origin.x) / _direction.x;

		tmin_x = std::min(t1, t2);
		tmax_x = std::max(t1, t2);
	}
	

	

	//Y軸
	if (abs(_direction.y) <= Math::EPSILON) {
		if (_origin.y < min.y || _origin.y > max.y)
			return false;
		else {
			tmin_y = -INFINITY;
			tmax_y = INFINITY;
		}

	}

	else {
		float t1 = (min.y - _origin.y) / _direction.y;
		float t2 = (max.y - _origin.y) / _direction.y;

		tmin_y = std::min(t1, t2);
		tmax_y = std::max(t1, t2);
	}
	//Z軸
	if (abs(_direction.z) <= Math::EPSILON) {
		if (_origin.z < min.z || _origin.z > max.z)
			return false;
		else {
			tmin_z = -INFINITY;
			tmax_z = INFINITY;
		}

	}

	else {
		float t1 = (min.z - _origin.z) / _direction.z;
		float t2 = (max.z - _origin.z) / _direction.z;

		tmin_z = std::min(t1, t2);
		tmax_z = std::max(t1, t2);
	}

	tmin = std::max(tmin_x, tmin_y, tmin_z);
	tmax = std::min(tmax_x, tmax_y, tmax_z);

	//交差判定
	if (tmax >= tmin && tmin >= 0)
		return true;

	return false; // 交差する

}

inline Vector3 AABB::GetCenter() const
{
	Vector3 center = (min + max) * 0.5f;
	return center;
}

inline Vector3 AABB::GetScale() const
{
	Vector3 scale = max - min;
	return scale;
}

std::array<Vector3, 8> AABB::GetTops() const
{
	//返す用の配列を生成
	std::array<Vector3, 8> tops;
	//最小座標から最大座標に向かって頂点を入れていく
	tops[0] = min;
	tops[1] = Vector3(max.x, min.y, min.z);
	tops[2] = Vector3(min.x, min.y, max.z);
	tops[3] = Vector3(max.x, min.y, max.z);
	tops[4] = Vector3(min.x, max.y, min.z);
	tops[5] = Vector3(max.x, max.y, min.z);
	tops[6] = Vector3(min.x, max.y, max.z);
	tops[7] = max;

	return tops;
}

