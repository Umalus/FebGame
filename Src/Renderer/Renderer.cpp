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

void Renderer::DrawAll(Camera* _camera, float _aspect)
{
	if (_camera == nullptr)return;
	//ビュー行列を取得
	Matrix_4x4 viewMat = _camera->GetViewMatrix();
	//投影行列を取得
	Matrix_4x4 ProjectionMat = _camera->GetProjectionMatrix(_aspect);
	for (auto drawObj : drawObjects) {
		//メッシュを取得
		Mesh* mesh = drawObj->GetMesh();
		//シェーダーを取得
		Shader* shader = drawObj->GetShader();
		//マテリアルを取得
		MaterialResource* material = drawObj->GetMaterial();
		//モデル行列を取得
		Matrix_4x4 modelMat = drawObj->GetTransform()->ToMatrix();
		//シェーダーかメッシュがなければ処理をしない
		if (!mesh || !shader)continue;
		//描画
		Matrix_4x4 uMVP = ProjectionMat.Multiply(viewMat.Multiply(modelMat));

		shader->Bind();
		shader->SetUniformMat4("uMVP", uMVP);
		std::cout << "MVP:\n";
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				std::cout << uMVP.matrix[i][j] << " ";
			}
			std::cout << std::endl;
		}


		//マテリアルをバインド
		if (material) {
			shader->SetUniformVec3("uDiffuseColor", material->diffuseColor);
			shader->SetUniformVec3("uSpecularColor", material->specularColor);
			shader->SetUniformVec3("uEmissiveColor", material->emissiveColor);

			if (material->diffuseMap) {
				material->diffuseMap->Bind(0);
				shader->SetUniformInt("uDiffuseMap", 0);
			}
			if (material->normalMap) {
				material->normalMap->Bind(1);
				shader->SetUniformInt("uNormalMap", 1);
			}
			if (material->specularMap) {
				material->specularMap->Bind(2);
				shader->SetUniformInt("uSpecularMap", 2);
			}
			if (material->emissiveMap) {
				material->emissiveMap->Bind(3);
				shader->SetUniformInt("uEmissiveMap", 3);
			}
			if (material->opacityMap) {
				material->opacityMap->Bind(4);
				shader->SetUniformInt("uOpacityMap", 4);
			}



			mesh->Draw();
		}
	}
}