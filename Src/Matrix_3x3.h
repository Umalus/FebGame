#pragma once

#include <array>
class Matrix_3x3 {
public:			//メンバ変数
	float matrix[3][3];

public:			//コンストラクタとデストラクタ

	/*
	 * @brief	デフォルトコンストラクタ
	 */
	Matrix_3x3();

	/*
	 * @brief		コンストラクタのオーバーライド
	 * @param[in]	std::array<float,3> _x		1行列目
	 * @param[in]	std::array<float,3> _y		2行列目
	 * @param[in]	std::array<float,3> _z		3行列目
	 */
	Matrix_3x3(std::array<float, 3> _x, std::array<float, 3> _y, std::array<float, 3> _z);

	/*
	 * @brief		デストラクタ
	 */
	~Matrix_3x3();

public:		//メンバ関数

	/*
	 * @function	Determinant
	 * @brief		3x3の行列を返す
	 * return		Matrix_3x3
	 */
	float Determinant() const;

	/*
	 * @function	Transpose
	 * @brief		転置行列を返す
	 * @return		Matrix_3x3
	 */
	Matrix_3x3 Transpose() const;

};
