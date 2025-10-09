#include "Camera.h"
#include <Windows.h>
Camera::Camera()
	:GameObject{}
	,pitch{0.0f}
	,yaw{0.0f}
	,fov{70}
{
}

Camera::Camera(const Vector3& _pos, const Vector3& _upDir, float _pitch, float _yaw)
	:GameObject{}
	,pitch{_pitch}
	,yaw{_yaw}
	,fov{70}
{
}

Camera::~Camera()
{
}

void Camera::Start()
{
}

void Camera::Update(float _deltaTime)
{
	front.x = cos(Vector3::Radians(yaw)) * cos(Vector3::Radians(pitch));
	front.y = sin(Vector3::Radians(pitch));
	front.z = sin(Vector3::Radians(yaw)) * cos(Vector3::Radians(pitch));
	front = front.Normalize();
}

void Camera::Renderer()
{
}

void Camera::FreeLook(float _x, float _y)
{
	POINT cursorPoint;
	if (!GetCursorPos(&cursorPoint))return;

}

void Camera::ZoomCamera()
{
}
