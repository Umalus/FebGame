#include "Transform.h"
#include <array>
Transform::Transform()
    :position{Vector3::zero}
    ,rotation{Vector3::zero}
    ,scale{Vector3::zero}
    ,modelMatrix{}
{
}

Transform::Transform(Vector3 _pos, Vector3 _rota = Vector3::zero, Vector3 _scale = Vector3::zero,Matrix_4x4 _matrix = Matrix_4x4())
    :position{_pos}
    ,rotation{_rota}
    ,scale{_scale}
    ,modelMatrix{_matrix}
{
}

Transform::~Transform(){
}

Matrix_4x4 Transform::ToMatrix()const{
    //çsóÒÇê∂ê¨
     Matrix_4x4 transformMatrix = Matrix_4x4::FromTranslation(position).Multiply
    (Matrix_4x4::FromRotationEuler(rotation).Multiply
    (Matrix_4x4::FromScale(scale)));

    return transformMatrix;
}

void Transform::LookAt(const Vector3& _pos){
    //ï˚å¸ÇãÅÇﬂÇÈ
    Vector3 direction = (_pos - position).Normalize();
    //âÒì]Çê∂ê¨
    float yaw = atan2f(direction.x, direction.z);
    float pitch = atan2f(-direction.y,sqrtf(direction.x * direction.x + direction.z * direction.z));

    rotation = Vector3(pitch, yaw, 0.0f);
}

inline void Transform::SetPosition(Vector3 _pos){
    position = _pos;
}

inline void Transform::SetRotation(Vector3 _rota){
    rotation = _rota;
}

inline void Transform::SetScale(Vector3 _scale){
    scale = _scale;
}

inline Vector3 Transform::GetForward() const{
    return rotation.forward;
}

inline Vector3 Transform::GetRight() const{
    return rotation.right;
}

inline Vector3 Transform::GetUp() const{
    return rotation.up;
}
