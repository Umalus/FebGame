#include "Transform.h"

Transform::Transform()
    :position{Vector3::zero}
    ,rotation{Vector3::zero}
    ,scale{Vector3::zero}
{
}

Transform::Transform(Vector3 _pos, Vector3 _rota, Vector3 _scale)
    :position{_pos}
    ,rotation{_rota}
    ,scale{_scale}
{
}

Transform::~Transform()
{
}

void Transform::ToMatirx()
{
}

void Transform::LookAt(const Vector3& _pos)
{
}

inline void Transform::SetPosition(Vector3 _pos)
{
}

inline void Transform::SetRotation(Vector3 _rota)
{
}

inline void Transform::SetScale(Vector3 _pos)
{
}

inline Vector3 Transform::GetForward() const
{
    return Vector3();
}

inline Vector3 Transform::GetRight() const
{
    return Vector3();
}

inline Vector3 Transform::GetUp() const
{
    return Vector3();
}
