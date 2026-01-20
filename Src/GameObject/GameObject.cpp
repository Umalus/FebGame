#include "GameObject.h"

GameObject::GameObject()
	:transform{std::make_unique<Transform> (Vector3::zero, Vector3::zero,Vector3::zero)}
	,mesh{std::make_shared<Mesh>()}
	,shader{std::make_shared<Shader>()}
	,model{std::make_shared<ModelResource>()}
	,material{std::make_shared<MaterialResource>()}
	,parent{this}
{
	Awake();
}

GameObject::GameObject(Vector3 _pos, Vector3 _rotate, Vector3 _scale)
	:transform{ std::make_unique<Transform> (_pos, _rotate,_scale)}
	,mesh{std::make_shared<Mesh>()}
	,shader{ std::make_shared<Shader>() }
	,model{ std::make_shared<ModelResource>() }
	,material{ std::make_shared<MaterialResource>() }
	,parent{ this }
{
}

void GameObject::Awake()
{
	shader->Load("Res/Shader/Shader.glsl", "Res/Shader/FragmentShader.glsl");
}


void GameObject::Start()
{
	transform->SetPosition(Vector3(0, 0, -5));
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

void GameObject::SetMseh(std::shared_ptr<Mesh> _mesh)
{
	mesh = _mesh;
}

void GameObject::SetShader(std::shared_ptr<Shader> newShader)
{
	shader = newShader;
}

void GameObject::SetMaterial(std::shared_ptr<MaterialResource> newMaterial)
{
	material = newMaterial;
}

void GameObject::SetModel(std::shared_ptr<ModelResource> _newModel)
{
	model = std::move(_newModel);

	this->mesh = model->GetMesh(0);
	this->material = model->GetMaterial(0);
}

