#pragma once
#include "Vec3.h"

class Collider;
struct HitInfo {
	bool isHit;						//当たったかどうか
	Vector3 point;					//当たった地点
	Vector3 normal;					//
	float distance;					//距離
	Collider* collider = nullptr;   //コライダー


};
/*
 * @class	Ray
 * @brief	レイを飛ばして当たり判定や視界、弾の制御等を行う	
 */
class Ray {
public:		//メンバ変数
	Vector3 origin;			//原点
	Vector3 direction;		//方向の正規化ベクトル

public:		//コンストラクタとデストラクタ

	/*
	 * @breif		デフォルトコンストラクタ
	 */
	Ray();

	/*
	 * @brief		コンストラクタのオーバーロード
	 * @param[in]	Vector3 _origin		原点
	 * @param[in]	Vector3 _direction	方向
	 */
	Ray(Vector3 _origin, Vector3 _direction);

	/*
	 * @brief		デストラクタ
	 */
	~Ray();

public:		//メンバ関数

	/*
	 * @function	GetPoint
	 * @brief		t距離先の座標の取得
	 * @param[in]	float _t	距離
	 * @return		Vector3
	 */
	inline Vector3 GetPoint(float _t)const;


public:		//静的メンバ関数

	/*
	 * @function	CreateAABB
	 * @brief		レイの当たった
	 */


};
