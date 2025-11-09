#pragma once

#include <iostream>
/// <summary>
/// シングルトンクラス
/// 主にマネージャー系クラスが一つしか存在しないことを保証するクラス
/// </summary>
template <typename T>

class Singleton {
public:
	static T& getInstance() {
		static T instance;
		return instance;
	}
	
	//コピーコンストラクタと代入演算子を削除
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

protected:		//コンストラクタとデストラクタ

	/*
	 * @brief	デフォルトコンストラクタ
	 * @tips	特にすることなし
	 */
	Singleton() = default;

	/*
	 * @brief	デストラクタ
	 * @tips	特にすることなし
	 */
	~Singleton() = default;


	

};
