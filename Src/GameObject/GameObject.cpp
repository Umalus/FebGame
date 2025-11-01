#include "GameObject.h"

GameObject::GameObject()
	:transform{std::make_unique<Transform> (Vector3::zero, Vector3::zero,Vector3::zero)},
	parent{this}
{
}

GameObject::GameObject(Vector3 _pos, Vector3 _rotate, Vector3 _scale)
	:transform{ std::make_unique<Transform> (_pos, _rotate,_scale)},
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
