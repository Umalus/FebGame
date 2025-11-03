#pragma once
#include "../GameObject.h"
#include "../../Math/Vec3.h"
#include <Windows.h>
class Camera : public GameObject {
private:	//メンバ変数
	Vector3 position;
	Vector3 front;
	Vector3 up;

	float pitch;
	float yaw;
	float fov;

	POINT prevCursorPoint;
public:		//コンストラクタとデストラクタ
	/*
	 * @brief	デフォルトコンストラクタ
	 */
	Camera();

	/*
	 * @brief	コンストラクタのオーバーライド
	 */
	Camera(const Vector3& _pos,const Vector3& _upDir,float _yaw,float _pitch);

	/*
	 * @brief	デストラクタ
	 */
	~Camera();
public:		//オーバーライドしたメンバ関数
	/*
	 * @function	Start
	 */
	void Start()override;
	/*
	 * @function	Start
	 */
	void Update(float _deltaTime)override;
	
public:		//メンバ関数

	/*
	 * @function	FreeLook
	 * @brief		マウスの移動に合わせて視点を移動
	 * @param[in]	float _x	マウスのX座標
	 * @param[in]	float _y	マウスのY座標
	 */
	void FreeLook(float _x, float _y);

	/*
	 * @function	ZoomCamera
	 * @brief		ズーム(今回のゲームではスナイパーでのみの想定)
	 */
	void ZoomCamera();

	/*
	 * @function	GetViewMatrix
	 * @brief		ビュー行列を取得
	 * @return		Matrix_4x4
	 */
	Matrix_4x4 GetViewMatrix();

	/*
	 * @function	GetProjectionMatrix
	 * @brief		投影行列を取得
	 * @param[in]	float _aspect
	 * @return		Matrix_4x4
 	 */
	Matrix_4x4 GetProjectionMatrix(float _aspect);

	/*
	 * @function	Perspective
	 * @brief		遠近感のある描画
	 * @param[in]	float _fov		視野角
	 * @param[in]	float _aspect	アスペクト比
	 * @param[in]	float _near		カメラからの最短距離
	 * @param[in]	float _far		カメラからの最長距離
	 */
	Matrix_4x4 Perscpective(float _fov, float _aspect, float _near, float _far);
};
