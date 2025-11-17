#include "GameObject.h"

GameObject::GameObject()
	:transform{std::make_unique<Transform> (Vector3::zero, Vector3::zero,Vector3::zero)}
	,mesh{std::make_unique<Mesh>()}
	,shader{std::make_unique<Shader>()}
	,material{std::make_unique<MaterialResource>()}
	,parent{this}
{
}

GameObject::GameObject(Vector3 _pos, Vector3 _rotate, Vector3 _scale)
	:transform{ std::make_unique<Transform> (_pos, _rotate,_scale)}
	,mesh{std::make_unique<Mesh>()}
	,shader{ std::make_unique<Shader>() }
	,material{ std::make_unique<MaterialResource>() }
	,parent{ this }
{
}

void GameObject::Awake()
{
	shader->Load("Res/Shader/Shader.glsl", "Res/Shader/FragmentShader.glsl");
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

Transform* GameObject::GetTransform()const
{
	return transform.get();
}

Mesh* GameObject::GetMesh() const
{
	return mesh.get();
}

Shader* GameObject::GetShader()const
{
	return shader.get();
}

MaterialResource* GameObject::GetMaterial() const
{
	return material.get();
}
