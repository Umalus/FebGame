#pragma once

#include "../Math/Transform.h"
#include "../Math/AABB.h"
#include "../Math/Matrix_4x4.h"
#include "../Resource/Mesh/Mesh.h"
#include "../Resource/Shader/Shader.h"

#include <string>
#include <vector>
#include <iostream>
class GameObject {
protected :		//メンバ変数
	std::unique_ptr<Transform> transform;
	std::unique_ptr<Mesh> mesh;
	std::unique_ptr<Shader> shader;
	std::string name;		//オブジェクトの名前
	
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
	GameObject(Vector3 _pos, Vector3 _rotate, Vector3 _scale);



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

public:		//ゲッター

	/*
	 * @function	GetTransform
	 * @brief		トランスフォームを取得
	 * @return		Transform&
	 */
	Transform* GetTransform()const;
	
	/*
	 * @function	GetMesh
	 * @brief		メッシュを取得
	 * @return		Mesh&
	 */
	Mesh* GetMesh()const;
	
	/*
	 * @function	GetShader
	 * @brief		シェーダーを取得
	 * @return		Shader&
	 */
	Shader* GetShader()const;

};