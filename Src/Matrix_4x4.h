#pragma once
#include <array>
class Matrix_4x4 {
public:			//メンバ変数
	float matrix[4][4];

public:			//コンストラクタとデストラクタ

	/*
	 * @brief	//デフォルトコンストラクタ
	 */
	Matrix_4x4();
	
	/*
	 * @brief	//コンストラクタのオーバーライド
	 */
	Matrix_4x4(std::array<float,4> _x,std::array<float,4> _y = {}, std::array<float,4> _z = {},std::array<float,4> _w = {});

	/*
	 * @brief	//デストラクタ
	 */
	~Matrix_4x4();

public:			//メンバ関数

	/*
	 * @function	Identity
	 * @brief		単位行列を返す
	 * @return		Matrix_4x4
	 */
	Matrix_4x4 Identity();

	/*
	 * @function	Transpose
	 * @brief		転置行列を返す
	 * @return		Matrix_4x4
	 */
	Matrix_4x4 Transpose();

	/*
	 * @function	Inverse
	 * @brief		逆行列を返す
	 * @return		Matrix_4x4
	 */
	Matrix_4x4 Inverse();

	/*
	 * @function	Multiply
	 * @brief		行列の掛け算
	 * @param[in]	const Matrix_4x4& _other	掛け算する行列
	 * @return		Matrix_4x4
	 */
	Matrix_4x4 Multiply(const Matrix_4x4& _other);


};
