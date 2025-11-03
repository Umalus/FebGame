#pragma once
#include "Vec3.h"
#include <array>

/*
 * @class		AABB
 * @brief		軸整合なbox状の当たり判定
 */
class AABB {
public:		//メンバ変数
	Vector3 min;	//最小座標
	Vector3 max;	//最大座標

public:		//コンストラクタとデストラクタ

	/*
	 * @brief		デフォルトコンストラクタ
	 */
	AABB();

	/*
	 * @brief		コンストラクタのオーバーロード
	 * @param[in]	Vector3 _min	//最小座標
	 * @param[in]	Vector3 _max	//最大座標
	 */
	AABB(Vector3 _min, Vector3 _max);

	/*
	 * @brief		デストラクタ
	 */
	~AABB();
public:		//メンバ関数

	/*
	 * @function	Expand
	 * @brief		各方向に拡張
	 * @param[in]	Vector3	_amount		伸ばす方向
	 */
	void Expand(Vector3 _amount);

	/*
	 * @function		Encapsulate
	 * @brief			点を含むように拡張
	 * @param[in]		Vector3	_point	含む点
	 */
	void Encapsulate(Vector3 _point);

	/*
	 * @brief	上のEncapsulateのオーバーロード　他のAABBを含むように拡張
	 * @param	[in]	AABB _other		他のAABB
	 */
	void Encapsulate(AABB _other);

	/*
	 * @function	Intersect
	 * @brief		2つのAABBが重なっているかどうか
	 * @param[in]	const AABB& _other
	 * @return		bool
	 */
	bool Intersect(const AABB& _other)const;

	/*
	 * @function	Contains
	 * @brief		AABBに点が含まれているかどうか
	 * @param[in]	const Vector3& _point
	 * @return		bool
	 */
	bool Contains(const Vector3& _point)const;
public:		//静的メンバ関数

	/*
	 * @function	FromCenterSize
	 * @brief		中心座標とサイズからAABBを生成
	 * @param[in]	Vector3 _center		中心座標
	 * @param[in]	Vector3	_size		サイズ
	 * @return		AABB
	 */
	AABB FromCenterSize(Vector3 _center, Vector3 _scale);

public:		//ユーティリティ

	/*
	 * @function	GetCenter
	 * @brief		中心座標を取得
	 * @return		Vector3
	 */
	inline Vector3 GetCenter()const;

	/*
	 * @function	GetSize
	 * @brief		AABBのサイズを取得
	 * @return		Vector3
	 */
	inline Vector3 GetAABBScale()const;

	/*
	 * @function	GetTops
	 * @brief		各頂点座標を取得(主にデバッグ用)
	 * @return		std::array<Vector3,8>
	 */
	std::array<Vector3, 8> GetTops()const;

};


