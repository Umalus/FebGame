#pragma once
#include <iostream>

/*
 * @class	Resource
 * @brief	全てのRes内で扱う素材の基底(model,sound等)
 */
class Resource {
protected:		//メンバ変数
	std::string path;	//ファイルパス
	int id;				//判別用ID

public:

	/*
	 * @brief	コンストラクタ
	 */
	Resource();

	/*
	 * @brief	デストラクタ
	 * @tips	仮想関数
	 */
	virtual ~Resource();

public:	//仮想関数で実装するメンバ関数

	/*
	 * @function	Load
	 * @brief		ファイルをロード
	 * @param[in]	std::string	_filePath	ファイルパス
	 * @return		Resource
	 */
	virtual void Load(const std::string& _filePath) = 0;

	/*
	 * @function	UnLoad
	 * @brief		ファイルをアンロード
	 */
	virtual void UnLoad() = 0;

	/*
	 * @function	Clear
	 * @brief		キャッシュをクリア
	 */
	virtual void Clear() = 0;

	/*
	 * @function	isLoaded
	 * @brief		ロードしたかどうか
	 * @return		bool
	 */
	virtual bool isLoaded() const = 0;

	/*
	 * @function	GetPath
	 * @brief		パスを取得
	 * @return		std::string
	 */
	virtual const std::string GetPath()const;

	/*
	 * @function	GetID
	 * @brief		IDを取得
	 * @return		int
	 */
	virtual int GetID()const;
	
	/*
	 * @function	SetPath
	 * @brief		パスを変更
	 * @param[in]	const std::string _filePath
	 */
	virtual void SetPath(const std::string _filePath);
	
	/*
	 * @function	SetID
	 * @brief		IDを変更
	 * @param[in]	int
	 */
	virtual void SetID(int _ID);
};
