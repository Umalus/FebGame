#include "Ray.h"

Ray::Ray()
    :origin{Vector3::zero}
    ,direction{Vector3::forward}{
}

Ray::Ray(Vector3 _origin, Vector3 _direction)
    :origin{_origin}
    ,direction{_direction}{
}

Ray::~Ray(){
}

inline Vector3 Ray::GetPoint(float _t) const
{
    return origin + direction * _t;
}
