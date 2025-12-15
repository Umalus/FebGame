#pragma once
#include "Vec3.h"
#include "Matrix_4x4.h"
class Transform {
private:		//メンバ変数
	Vector3 position;
	Vector3 rotation;
	Vector3 scale;

	Matrix_4x4 modelMatrix;

public:		//コンストラクタとデストラクタ

	/*
	 * @brief	デフォルトコンストラクタ
	 */
	Transform();

	/*
	 * @brief		コンストラクタのオーバーロード
	 * @param[in]	Vector3 _pos		初期化位置
	 * @param[in]	Vector3 _rota = Vector3::zero	初期化回転
	 * @param[in]	Vector3 _scale = Vector3::zero	初期化拡縮
	 */
	Transform(Vector3 _pos, Vector3 _rota, Vector3 _scale);

	/*
	 * @brief		デストラクタ
	 */
	~Transform();
public:		//メンバ関数

	/*
	 * @function	UpdateModelMatrix
	 * @brief		モデル行列の更新
	 */
	void UpdateModelMatrix();


	/*
	 * @function	ToMatrix
	 * @brief		位置、回転、拡縮からモデル行列を生成
	 * @return		Matrix_4x4
	 */
	Matrix_4x4 ToMatrix()const;


	/*
	 * @function	LookAt
	 * @brief		対象の方向を向くようにする
	 * @param[in]	const Vector3& _pos	対象の方向
	 */
	void LookAt(const Vector3& _pos);

public:		//セッター

	/*
	 * @function	SetPosition
	 * @brief		位置の変更
	 * @param[in]	Vector3 _pos	変更する値
	 */
	inline void SetPosition(Vector3 _pos);

	/*
	 * @function	SetRotation
	 * @brief		回転の変更
	 * @param[in]	Vector3 _rota	変更する値
	 */
	inline void SetRotation(Vector3 _rota);

	/*
	 * @function	SetScale
	 * @brief		拡縮の変更
	 * @param[in]	Vector3 _pos	変更する値
	 */
	inline void SetScale(Vector3 _pos);

	/*
	 * @function	GetForward
	 * @brief		前方向の取得
	 * @return		Vector3
	 */
	inline Vector3 GetForward() const;

	/*
	 * @function	GetRight
	 * @brief		右方向の取得
	 * @return		Vector3
	 */
	inline Vector3 GetRight() const;

	/*
	 * @function	GetUp
	 * @brief		上方向の取得
	 * @return		Vector3
	 */
	inline Vector3 GetUp() const;

	/*
	 * @function	GetPosition
	 * @brief		位置の取得
	 * @return		Vector3
	 */
	Vector3 GetPosition() const;

	/*
	 * @function	GetRotation
	 * @brief		回転の取得
	 * @return		Vector3
	 */
	Vector3 GetRotation() const;

	/*
	 * @function	GetScale
	 * @brief		拡縮の取得
	 * @return		Vector3
	 */
	Vector3 GetScale() const;

public:		//オペレーターのオーバーライド

	Transform operator=(const Transform& _other)const;

};

