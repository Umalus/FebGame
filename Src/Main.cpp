/*
 * @project		FPS_3D_SHOOTHING_GAME
 * @Goal		1月末までに作品提出できるくらいのレベルにする
 */

//必須インクルード
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm.hpp>

#include "Resource/Mesh/Mesh.h"
#include "Resource/Shader/Shader.h"
#include "Manager/ResourceManager.h"
#include "GameObject/GameObject.h"
#include "Renderer/Renderer.h"

int main() {
	//glfwの初期化
	if (!glfwInit()) return -1;

	GLFWwindow* window = glfwCreateWindow(1920, 1080, "FPS", NULL, NULL);
	//ウィンドウが作成されなければ処理終了
	if (!window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	//GLADの初期化
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cerr << "エラーやでー" << std::endl;
		return -1;
	}

	int width, height;
	
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
	float aspectRatio = static_cast<float>(width) / static_cast<float>(height);
#pragma region テスト
	ResourceManager::getInstance().LoadResource("Res/Model/testModelVer2.fbx",Model);

	GameObject* pTest = new GameObject();

	pTest->SetModel(ResourceManager::getInstance().GetResourceAs<ModelResource>(0));

	Camera* pCamera = new Camera();
	pCamera->Start();

	Renderer* pRender = new Renderer();
	pRender->Submit(pTest);
	
#pragma endregion


	//描画
	while (!glfwWindowShouldClose(window)) {

#pragma region テスト
		// カラーバッファをクリア
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// カメラ更新
		pCamera->Update(60.0f);

		// レンダリング
		pRender->DrawAll(pCamera, aspectRatio);

		// バッファをスワップ
		glfwSwapBuffers(window);

		// イベント処理
		glfwPollEvents();

#pragma endregion



	}

	//glfwの解放
	glfwDestroyWindow(window);
	glfwTerminate();

	//コンソールで正常に終わったことを確認
	std::cerr << "このプロジェクトは正常に終了しました" << std::endl;

	return 0;

}