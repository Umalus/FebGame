#pragma once

#include "../glm/glm.hpp"
#include "../glm/vec3.hpp"
#include "gtc/matrix_transform.hpp"
#include <string>
#include <vector>

struct Transform {
	glm::vec3 position;		//位置
	glm::vec3 rotation;		//回転
	glm::vec3 scale;		//拡縮

};

class GameObject {
private :		//メンバ変数
	Transform transform;
	std::string name;		//オブジェクトの名前

	glm::mat4 modelMatrix;

	GameObject* parent;
	std::vector<GameObject*> children;

public:			//コンストラクタとデストラクタ
	/*
	 * @brief	コンストラクタ
	 */
	GameObject();

	/*
	 * @brief	コンストラクタのオーバーライド
	 * @param[in]	const Vector3& _pos		初期化する座標
	 * @param[in]	const Vector3& _rotate	初期化する回転
	 * @param[in]	const Vector3& _scale	初期化する拡縮
	 */
	GameObject(const glm::vec3& _pos, const glm::vec3& _rotate,const glm::vec3& _scale);



	/*
	 * @brief	デストラクタ
	 * @tips	仮想関数で実装
	 */

	virtual ~GameObject() = default;

public:			//メンバ関数
	/*
	 * @function	Awake
	 * @brief		生成されたタイミングで呼ばれる関数
	 */
	virtual void Awake();
	
	/*
	 * @function	Start
	 * @brief		更新処理の1フレーム前に呼び出される
	 */
	virtual void Start();

	/*
	 * @function	Update
	 * @brief		毎フレーム呼び出される
	 */
	virtual void Update(float _deltaTime);

	/*
	 * @function	Render
	 * @brief		描画処理
	 */
	virtual void Renderer();


};