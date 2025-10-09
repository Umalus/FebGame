#include "Vec3.h"
#include <math.h>

const float Vector3::pi = 3.141592f;
Vector3::Vector3()
    :x{}
    ,y{}
    ,z{}
{
}

Vector3::Vector3(float _x, float _y, float _z)
    :x{_x}
    ,y{_y}
    ,z{_z}
{
}

Vector3::~Vector3()
{
}

Vector3 Vector3::Normalize(){
    float mag = Magnitude();
    //もしmag == 0ならば処理しない
    if (mag == 0)return Vector3(0, 0, 0);
    return Vector3(x / mag, y / mag, z / mag);
}

float Vector3::Magnitude()const{
    return sqrtf(x * x + y * y + z * z);
}

float Vector3::Dot(const Vector3& _vec1, const Vector3& _vec2)
{
    return _vec1.x * _vec2.x + _vec1.y * _vec2.y + _vec1.z * _vec2.z;
}

Vector3 Vector3::Cross(const Vector3& _vec1, const Vector3& _vec2)
{
    return Vector3( _vec1.y * _vec2.z - _vec1.z * _vec2.y,
                    _vec1.z * _vec2.x - _vec1.x * _vec2.z,
                    _vec1.x * _vec2.y - _vec1.y * _vec2.x);
}

float Vector3::Radians(float _degree)
{
    return _degree * pi / 180.0f ;
}


float Vector3::Degrees(float _radian)
{
    return _radian * 180.0f / pi;
}

Vector3 Vector3::operator+(const Vector3& _other) const
{
    return Vector3( x + _other.x,
                    y + _other.y,
                    z + _other.z);
}

Vector3 Vector3::operator-(const Vector3& _other) const
{
    return Vector3(x - _other.x,
                   y - _other.y,
                   z - _other.z);
}

Vector3 Vector3::operator*(const Vector3& _other) const
{
    return Vector3(x * _other.x,
                   y * _other.y,
                   z * _other.z);
}

Vector3 Vector3::operator*(const float _value) const
{
    return Vector3(x * _value,
                   y * _value,
                   z * _value);
}                  

Vector3 Vector3::operator/(const Vector3& _other) const
{
    //三項演算子で0チェック
    return Vector3(
        _other.x != 0 ? x / _other.x : 0,
        _other.y != 0 ? y / _other.y : 0,
        _other.z != 0 ? z / _other.z : 0);
}

Vector3 Vector3::operator/(const float _value) const
{
    if (_value == 0)return Vector3(0, 0, 0);

    return Vector3(x / _value,
                   y / _value,
                   z / _value);
}

bool Vector3::operator==(const Vector3& _other) const
{
    //ごくわずかな誤差を許容する
    constexpr float EPSILON =  0.0001f;
    return fabs(x - _other.x) < EPSILON &&
           fabs(y - _other.y) < EPSILON &&
           fabs(z - _other.z) < EPSILON;
}
