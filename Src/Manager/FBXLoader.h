#pragma once
#include <fbxsdk.h>
#include <iostream>
#include <string>

/*
 * @class	FBXLoader
 * @brief	FBXManagerの初期化やFBX
 */
class FBXLoader {
public:		//メンバ変数
	FbxManager* fbxManager = nullptr;
	FbxScene* scene = nullptr;

public:		//コンストラクタとデストラクタ

	/*
	 * @breif	コンストラクタ
	 * @tips	fbxManagerを生成して、ロードしなおすのを防ぐ
	 */
	FBXLoader();

	/*
	 * @brief	デストラクタ
	 * @tips	ポインタを解放
	 */
	~FBXLoader();
public:

	/*
	 * @function	Load
	 * @brief		FBXデータを読み込む
	 * @param[in]	const std::string& _filePath
	 * @return		bool
	 */
	bool LoadFBX(const std::string& _filePath);

	/*
	 * @function	GetScene
	 * @brief		シーンを取得
	 * @return		FbxScene*
	 */
	FbxScene* GetScene()const;

};
