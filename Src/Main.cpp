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

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_DEPTH_BITS, 24);

	GLFWwindow* window = glfwCreateWindow(1920, 1080, "FPS", NULL, NULL);
	glfwMakeContextCurrent(window);

	if (!window) {
		std::cout << "Failed to create window" << std::endl;
		glfwTerminate();
		return -1;
	}


	/*if (!glfwGetCurrentContext()) {
		std::cout << "Context is NOT current!" << std::endl;
	}
	std::cout << "Context = " << glfwGetCurrentContext() << std::endl;
	std::cout << "GL_VERSION = " << glGetString(GL_VERSION) << std::endl;*/



	//GLADの初期化
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cerr << "エラーやでー" << std::endl;
		return -1;
	}
	std::cout << "GL_VERSION = " << (const char*)glGetString(GL_VERSION) << std::endl;

	glEnable(GL_DEPTH_TEST);


	int width, height;

	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
	float aspectRatio = static_cast<float>(width) / static_cast<float>(height);
#pragma region テスト
	/*ResourceManager::getInstance().LoadResource("Res/Model/testModelVer2.fbx", Model);

	GameObject* pTest = new GameObject();

	pTest->SetModel(ResourceManager::getInstance().GetResourceAs<ModelResource>(0));
	pTest->GetTransform()->SetPosition(Vector3(0, 0, 0));

	Camera* pCamera = new Camera();
	pCamera->Start();

	pCamera->GetTransform()->SetPosition(Vector3(0, 0, -20));
	pCamera->GetTransform()->LookAt(Vector3(0, 0, 0));

	Renderer* pRender = new Renderer();
	pRender->Submit(pTest);*/
	float tri[] = {
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f
	};

	GLuint vao, vbo;
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);

	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(tri), tri, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

#pragma endregion


	//描画
	while (!glfwWindowShouldClose(window)) {

#pragma region テスト
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(triShader); // 上の超シンプル頂点＋単色フラグメント
		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, 3);


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