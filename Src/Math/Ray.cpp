#include "Ray.h"
namespace Math {

	constexpr float EPSILON = 0.000001f;
}
Ray::Ray()
    :origin{Vector3::zero}
    ,direction{Vector3::forward}{
}

Ray::Ray(Vector3 _origin, Vector3 _direction)
    :origin{_origin}
    ,direction{_direction.Normalize()} {
}

Ray::~Ray(){
}

inline Vector3 Ray::GetPoint(float _t) const
{
    return origin + direction * _t;
}

bool Ray::RaycastHitAABB(const AABB& _hitBox)
{
	float tmin = -INFINITY;
	float tmax = INFINITY;

	float tmin_x, tmax_x;
	float tmin_y, tmax_y;
	float tmin_z, tmax_z;


	//Xé≤
	if (abs(direction.x) <= Math::EPSILON) {
		if (origin.x < _hitBox.min.x || origin.x > _hitBox.max.x)
			return false;
		else {
			tmin_x = -INFINITY;
			tmax_x = INFINITY;
		}

	}

	else {
		float t1 = (_hitBox.min.x - origin.x) / direction.x;
		float t2 = (_hitBox.max.x - origin.x) / direction.x;

		tmin_x = std::min(t1, t2);
		tmax_x = std::max(t1, t2);
	}




	//Yé≤
	if (abs(direction.y) <= Math::EPSILON) {
		if (origin.y < _hitBox.min.y || origin.y > _hitBox.max.y)
			return false;
		else {
			tmin_y = -INFINITY;
			tmax_y = INFINITY;
		}

	}

	else {
		float t1 = (_hitBox.min.y - origin.y) / direction.y;
		float t2 = (_hitBox.max.y - origin.y) / direction.y;

		tmin_y = std::min(t1, t2);
		tmax_y = std::max(t1, t2);
	}
	//Zé≤
	if (abs(direction.z) <= Math::EPSILON) {
		if (origin.z < _hitBox.min.z || origin.z > _hitBox.max.z)
			return false;
		else {
			tmin_z = -INFINITY;
			tmax_z = INFINITY;
		}

	}

	else {
		float t1 = (_hitBox.min.z - origin.z) / direction.z;
		float t2 = (_hitBox.max.z - origin.z) / direction.z;

		tmin_z = std::min(t1, t2);
		tmax_z = std::max(t1, t2);
	}

	tmin = std::max(tmin_x, std::max(tmin_y, tmin_z));
	tmax = std::min(tmax_x, std::min(tmax_y, tmax_z));

	//åç∑îªíË
	if (tmax >= tmin && tmin >= 0)
		return true;

	return false; // åç∑Ç∑ÇÈ

}
