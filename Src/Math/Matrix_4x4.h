#pragma once
#include <array>
#include "Matrix_3x3.h"
#include "Vec3.h"
class Matrix_4x4 {
public:			//メンバ変数
	float matrix[4][4];

public:			//コンストラクタとデストラクタ

	/*
	 * @brief	//デフォルトコンストラクタ
	 */
	Matrix_4x4();
	
	/*
	 * @brief	//コンストラクタのオーバーロード
	 */
	Matrix_4x4(std::array<float,4> _x,std::array<float,4> _y, std::array<float,4> _z,std::array<float,4> _w);
	
	/*
	 * @brief	//デストラクタ
	 */
	~Matrix_4x4();

public:			//メンバ関数

	

	/*
	 * @function	Transpose
	 * @brief		転置行列を返す
	 * @return		Matrix_4x4
	 */
	Matrix_4x4 Transpose() const;

	/*
	 * @function	Inverse
	 * @brief		逆行列を返す
	 * @return		Matrix_4x4
	 */
	Matrix_4x4 Inverse()const;

	/*
	 * @function	Multiply
	 * @brief		行列の掛け算
	 * @param[in]	const Matrix_4x4& _other	掛け算する行列
	 * @return		Matrix_4x4
	 */
	Matrix_4x4 Multiply(const Matrix_4x4& _other)const;

	/*
	 * @function	PickupMiniQueue
	 * @brief		小行列式を取り出す
	 * @param[in]	int _row		除外する行のインデックス
	 * @param[in]	int _column		除外する列のインデックス
	 * @return		Matrix_3x3		小行列
	 */
	Matrix_3x3 PickupMiniQueue(int _row,int _column)const;

	/*
	 * @function	MakeCofactor
	 * @brief		余因子行列を作成
	 * @param[in]	int _row		除外する行のインデックス
	 * @param[in]	int _column		除外する列のインデックス
	 * @return		float
	 */
	float MakeCofactor(int _row, int _column)const;

	/*
	 * @function	Determinant
	 * @brief		行列式を返す
	 * @param[in]	int _row	除外する行のインデックス
	 * @param[in]	int _column	除外する列のインデックス
	 * @return		float
	 */
	float Determinant()const;

	/*
	 * @function	GetDataArray
	 * @brief		内部の値を配列で返す
	 * @param[in]	int _index
	 * @return		float*
	 */
	std::array<float, 16> GetDataArray()const;

	
public:		//静的メンバ関数

	/*
	 * @function	Identity
	 * @brief		単位行列を返す
	 * @return		Matrix_4x4
	 */
	static Matrix_4x4 Identity();

	/*
	 * @function	FromTranslation
	 * @brief		平行移動から行列を構築
	 * @param[in]	const Vector3& _pos	行列にする対象
	 * @return		Matrix_4x4
	 */
	static Matrix_4x4 FromTranslation(const Vector3& _pos);
	
	/*
	 * @function	FromRotationEuler
	 * @brief		回転から行列を構築
	 * @param[in]	const Vector3& _rota	行列にする対象
	 * @return		Matrix_4x4
	 */
	static Matrix_4x4 FromRotationEuler(const Vector3& _rota);
	
	/*
	 * @function	FromScale
	 * @brief		平行移動から行列を構築
	 * @param[in]	const Vector3& _scale	行列にする対象
	 * @return		Matrix_4x4
	 */
	static Matrix_4x4 FromScale(const Vector3& _scale);

	/*
	 * @function	LookAt
	 * @brief		主にビュー行列を返す
	 * @param[in]	const Vector3& _eye	位置
	 * @param[in]	const Vector3& _target		見ている方向
	 * @param[in]	const Vector3& _up	上方向ベクトル
	 * @return		Matrix_4x4
	 */
	static Matrix_4x4 LookAt(const Vector3& _eye, const Vector3& _target, const Vector3& _up);


private:	//内部処理しやすいようなメンバ関数

	/*
	 * @function	FromRotationX
	 * @brief		X軸回転から回転行列を生成
	 * @param[in]	float _radX		回転軸
	 * @return		Matrix_4x4
	 */
	static Matrix_4x4 FromRotationX(float _radX);
	/*
	 * @function	FromRotationY
	 * @brief		X軸回転から回転行列を生成
	 * @param[in]	float _radY 	回転軸
	 * @return		Matrix_4x4
	 */
	static Matrix_4x4 FromRotationY(float _radY);
	/*
	 * @function	FromRotationZ
	 * @brief		X軸回転から回転行列を生成
	 * @param[in]	float _radZ		回転軸
	 * @return		Matrix_4x4
	 */
	static Matrix_4x4 FromRotationZ(float _radZ);

public:		//オペレーターのオーバーロード

	//ベクトルとの掛け算
	Vector3 operator*(const Vector3& _vec3);
};
