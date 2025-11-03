#include "Renderer.h"
#include "../Math/Matrix_4x4.h"
#include <Windows.h>
#include "../Resource/Shader/Shader.h"

Renderer::Renderer()
	:drawObjects{}
{
}

Renderer::~Renderer()
{
	//登録されたポインタを削除し配列を最適化
	for (auto deleteobj : drawObjects) {
		delete deleteobj;
	}
	drawObjects.clear();
	drawObjects.shrink_to_fit();
}

void Renderer::Submit(GameObject* _obj)
{
	drawObjects.push_back(_obj);
}

void Renderer::DrawAll(Camera* _camera,float _aspect)
{
	for (auto drawObj : drawObjects) {
		//メッシュを取得
		Mesh* mesh = drawObj->GetMesh();
		//シェーダーを取得
		Shader* shader = drawObj->GetShader();
		//モデル行列を取得
		Matrix_4x4 modelMat = drawObj->GetTransform()->ToMatrix();
		//ビュー行列を取得
		Matrix_4x4 viewMat = _camera->GetViewMatrix();
		//投影行列を取得
		Matrix_4x4 ProjectionMat = _camera->GetProjectionMatrix(_aspect);

		//描画
		Matrix_4x4 uMVP = modelMat.Multiply(viewMat.Multiply(ProjectionMat));
		shader->Bind();
		shader->SetUniformMat4("uMVP", uMVP);
		mesh->Draw();
	}
}
