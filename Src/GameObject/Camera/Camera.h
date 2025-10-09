#pragma once
#include "../GameObject.h"
#include "../../Vec3.h"

class Camera : public GameObject {
private:	//メンバ変数
	Vector3 position;
	Vector3 front;
	Vector3 up;

	float pitch;
	float yaw;
	float fov;
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
	/*
	 * @function	Start
	 */
	void Renderer()override;



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

};
