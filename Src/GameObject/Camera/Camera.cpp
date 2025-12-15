#include "Camera.h"
#include <algorithm>
Camera::Camera()
	:GameObject{}
	,pitch{0.0f}
	,yaw{0.0f}
	,fov{70}
	, prevCursorPoint{}
{
	Start();
}

Camera::Camera(const Vector3& _pos, const Vector3& _upDir, float _pitch, float _yaw)
	:GameObject{}
	,pitch{_pitch}
	,yaw{_yaw}
	,fov{70}
	, prevCursorPoint{}
{
}

Camera::~Camera()
{
}

void Camera::Start()
{
	front = Vector3(0, 0, -1);
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
}

void Camera::Update(float _deltaTime)
{
	FreeLook(0.5f,0.5f);

	front.x = cos(Vector3::Radians(yaw)) * cos(Vector3::Radians(pitch));
	front.y = sin(Vector3::Radians(pitch));
	front.z = sin(Vector3::Radians(yaw)) * cos(Vector3::Radians(pitch));
	front = front.Normalize();
}

void Camera::FreeLook(float _senseX, float _senseY)
{
	static bool first = false;

	//現在のマウスの位置を取得
	POINT currentCursorPoint;
	if (!GetCursorPos(&currentCursorPoint))return;
	//初回時は前回位置として保存
	if (!first) {	
		prevCursorPoint = currentCursorPoint;
		first = true;
	}
	//前フレームとの差分を計算(Y軸は画面軸上では反転しているので逆にする)
	float deltaX = currentCursorPoint.x - prevCursorPoint.x;
	float deltaY = prevCursorPoint.y - currentCursorPoint.y;
	
	//yawとpitchを算出(pitchは裏返らないように±89に収める)
	yaw += deltaX * _senseX;
	pitch += deltaY * _senseY;
	pitch = std::clamp(pitch, -89.0f, 89.0f);
	//最後に前フレームのカーソルの場所を更新する
	prevCursorPoint = currentCursorPoint;
}

void Camera::ZoomCamera()
{
}

Matrix_4x4 Camera::GetViewMatrix()
{
	//位置取得
	Vector3 cameraPos = transform->GetPosition();
	//見ている方向を取得
	Vector3 lookDir = cameraPos + front;
	//上方向取得
	Vector3 up = Vector3::up;

	Matrix_4x4 viewMat = Matrix_4x4::LookAt(cameraPos, lookDir, up);

	return viewMat;
}

Matrix_4x4 Camera::GetProjectionMatrix(float _aspect)
{
	return Perscpective(fov,_aspect,0.1f,100.0f);
}

Matrix_4x4 Camera::Perscpective(float _fov, float _aspect, float _near, float _far)
{
	//視野角をラジアンに変換
	float fovRad = Vector3::Radians(_fov);
	//スケーリング係数を計算
	float yScale = 1 / tanf(fovRad / 2);
	float xScale = yScale / _aspect;

	//Z軸の奥行係数を計算する
	float zRange = _far - _near;
	float zScale = -(_far + _near) / zRange;
	float zTrans = -(2 * _far * _near) / zRange;

	//透視東映行列を構築
	std::array<float, 4> x = { xScale, 0.0f, 0.0f, 0.0f };
	std::array<float, 4> y = { 0.0f, yScale, 0.0f, 0.0f };
	std::array<float, 4> z = { 0.0f, 0.0f, zScale, zTrans };
	std::array<float, 4> w = { 0.0f, 0.0f, -1.0f, 0.0f };

	return Matrix_4x4(x,y,z,w);
}
