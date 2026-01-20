#include "Transform.h"
#include <array>
Transform::Transform()
    :position{ Vector3(0,0,-5) }
    ,rotation{Vector3::zero}
    , scale{ Vector3(1,1,1)}
    ,modelMatrix{}
{
    UpdateModelMatrix();
}

Transform::Transform(Vector3 _pos, Vector3 _rota = Vector3::zero, Vector3 _scale = Vector3::one)
    :position{_pos}
    ,rotation{_rota}
    ,scale{_scale}
{
    UpdateModelMatrix();
}

Transform::~Transform(){
}

void Transform::UpdateModelMatrix()
{
    modelMatrix = ToMatrix();
}

Matrix_4x4 Transform::ToMatrix()const{
    //çsóÒÇê∂ê¨
    Matrix_4x4 S = Matrix_4x4::FromScale(scale);
    Matrix_4x4 R = Matrix_4x4::FromRotationEuler(rotation);
    Matrix_4x4 T = Matrix_4x4::FromTranslation(position);

    Matrix_4x4 transformMatrix = S.Multiply(R).Multiply(T);
    transformMatrix.DebuPrint();
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

void Transform::SetPosition(Vector3 _pos){
    position = _pos;
    UpdateModelMatrix();
}

void Transform::SetRotation(Vector3 _rota){
    rotation = _rota;
    UpdateModelMatrix();
}

void Transform::SetScale(Vector3 _scale){
    scale = _scale;
    UpdateModelMatrix();
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

Vector3 Transform::GetPosition() const
{
    return position;
}

Vector3 Transform::GetRotation() const
{
    return rotation;
}

Vector3 Transform::GetScale() const
{
    return scale;
}

Transform Transform::operator=(const Transform& _other) const
{
    return Transform(_other);
}

