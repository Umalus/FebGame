#pragma once

class Vector3 {
public:		//メンバ変数
	float x;
	float y;
	float z;
public:
	static Vector3 zero;
	static Vector3 one;
	static Vector3 right;
	static Vector3 left;
	static Vector3 up;
	static Vector3 down;
	static Vector3 forward;
	static Vector3 back;




public:
	static const float pi;
public:		//コンストラクタとデストラクタ
	/*
	 * @brief	デフォルトコンストラクタ
	 */
	Vector3();

	/*
	 * @brief	引数に3つの実数値型を持つコンストラクタ
	 */
	Vector3(float _x,float _y,float _z);

	/*
	 * @brief	デストラクタ
	 */

	~Vector3();

public:		//メンバ関数

	/*
	 * @function	Normalize
	 * @brief		ベクトルを正規化
	 * @return		Vector3
	 */
	Vector3 Normalize();

	/*
	 * @function	Normalize
	 * @brief		ベクトルの長さを計算
	 * @return		float
	 */
	float Magnitude()const;

	/*
	 * @function	Dot
	 * @brief		自分ともう一方のベクトルの内積を計算
	 * @param[in]	const Vector3& _other	他のベクトル
	 * @return		float
	 */
	float Dot(const Vector3& _other);

	/*
	 * @function	Dot
	 * @brief		自分ともう一方のベクトルの外積を計算
	 * @param[in]	const Vector3& _other	他のベクトル
	 * @return		Vector3
	 */
	Vector3 Cross(const Vector3& _other);



public:		//静的メンバ関数
	/*
	 * @function	Dot
	 * @brief		2つのベクトルの内積を計算
	 * @param
	 * @return		float
	 */
	static float DotProduct(const Vector3& _vec1,const Vector3& _vec2);

	/*
	 * @function	Cross
	 * @brief		2つベクトルの外積を計算
	 * @return		Vector3
	 */
	static Vector3 CrossProduct(const Vector3& _vec1, const Vector3& _vec2);

	/*
	 * @function	Radians
	 * @brief		デグリー角をラジアン角に変える
	 * @return		float
	 */
	static float Radians(float _degree);

	/*
	 * @function	Degrees
	 * @brief		ラジアン角をデグリー角に変える
	 * @return		float
	 */
	static float Degrees(float _radian);

public:		//オペレーターのオーバーライド
	//加算
	Vector3 operator+(const Vector3& _other)const;
	//減算
	Vector3 operator-(const Vector3& _other)const;
	//乗算(スカラー倍(掛ける値がVectorのバージョン))
	Vector3 operator*(const Vector3& _other)const;
	//乗算(スカラー倍(掛ける値がfloatのバージョン))
	Vector3 operator*(const float _value)const;
	//除算(割る値がVectorのバージョン)
	Vector3 operator/(const Vector3& _other)const;
	//除算(割る値がfloatのバージョン)
	Vector3 operator/(const float _value)const;
	
	//加算(複合代入演算子ver)
	Vector3 operator+=(const Vector3& _other);
	//減算(複合代入演算子ver)
	Vector3 operator-=(const Vector3& _other);


	//比較
	bool operator==(const Vector3& _other)const;

	bool operator!=(const Vector3& _other)const;
};
