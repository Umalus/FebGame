#pragma once
#include "../GameObject/GameObject.h"
#include "../GameObject/Camera/Camera.h"
#include <vector>

/*
 * @class		Render
 * @brief		描画管理
 */

class Renderer {
private:	//メンバ変数
	std::vector<GameObject*> drawObjects;

public:		//コンストラクタとデストラクタ

	/*
	 * @brief		コンストラクタ
	 */
	Renderer();

	/*
	 * @brief		デストラクタ
	 */
	~Renderer();

public:		//メンバ関数

	/*
	 * @function	Submit
	 * @brief		描画するオブジェクトを登録
	 * @param[in]	GameObject*		_obj
	 */
	void Submit(GameObject* _obj);

	/*
	 * @function	DrawAll
	 * @brief		登録された全オブジェクトを描画
	 * @param[in]	Camera* _camera
	 * @param[in]	float _aspect
	 */
	void DrawAll(Camera* _camera,float _aspect);


};