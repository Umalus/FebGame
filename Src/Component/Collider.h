#pragma once
#include "../Math/Transform.h"
#include "../Math/Ray.h"
#include "../Info/HitInfo.h"

class Collider {
protected:		//メンバ変数
	Transform* pTransform;
	bool isTrigger;
	enum ColliderType {
		Invalid = -1,
		Sphere,
		Box,
		Mesh,
		Capsure,
	};
	ColliderType colliderType;

public:		//コンストラクタとデストラクタ

	/*
	 * @brief	デフォルトコンストラクタ
	 */
	Collider() = default;
	
	/*
	 * @brief	デストラクタ
	 * @tips	純粋仮想関数
	 */
	virtual ~Collider() = 0;

public:		//メンバ関数(純粋仮想関数)

	/*
	 * @function	RayCast
	 * @brief		レイとの当たり判定
	 * @param[in]	const Ray _ray	レイ
	 * @return		bool
	 */
	virtual bool Raycast(const Ray& _ray) = 0;

	/*
	 * @function	Intersects
	 * @brief		他のコライダーとの当たり判定
	 * @param[in]	const Collider&	_other
	 * @return		bool
	 */
	virtual bool Intersect(const Collider& _other) = 0;

	/*
	 * @function	GetTransform
	 * @brief		自身の位置、回転、拡縮を取得
	 * @return		const Transform&
	 */
	virtual const Transform& GetTransform() = 0;


};

