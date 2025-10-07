#include "GameObject.h"

GameObject::GameObject()
	:transform{ glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f,0.0f,0.0f),glm::vec3(1.0f) },
	modelMatrix{},
	parent{this}
{
}

void GameObject::Awake()
{

}


void GameObject::Start()
{

}

/*
 * @
 */
void GameObject::Update(float _deltaTime)
{
	//単位行列を設定
	modelMatrix = glm::mat4(1.0f);
	//平行移動を適用
	modelMatrix = glm::translate(modelMatrix, transform.position);
	
	//回転を適用(引数は対象の行列、回転角(ラジアン角)、回転軸)
	//Z->Y->Xの順で適用
	modelMatrix = glm::rotate(modelMatrix, transform.rotation.z, glm::vec3(0, 0, 1));
	modelMatrix = glm::rotate(modelMatrix, transform.rotation.y, glm::vec3(0, 1, 0));
	modelMatrix = glm::rotate(modelMatrix, transform.rotation.x, glm::vec3(1, 0, 0));
	//拡縮を適用
	modelMatrix = glm::scale(modelMatrix,transform.scale);
	

}

void GameObject::Render()
{
}
