#include "GameObject.h"

GameObject::GameObject()
	:transform{std::make_unique<Transform> (Vector3(0.0f, 0.0f, 0.0f), Vector3(0.0f,0.0f,0.0f),Vector3(1.0f,1.0f,1.0f))},
	parent{this}
{
}

GameObject::GameObject(Vector3 _pos, Vector3 _rotate, Vector3 _scale)
	:transform{ std::make_unique<Transform> (_pos, _rotate,_scale,Matrix_4x4())},
	parent{ this }
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
	//s—ñ
	transform->ToMatrix();
}

void GameObject::Renderer()
{
}
