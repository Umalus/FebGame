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

#pragma region テスト
	ResourceManager::getInstance().LoadResource("Res/Model/testModelVer2.fbx",Model);

	GameObject* pTest = new GameObject();

#pragma endregion


	while (!glfwWindowShouldClose(window)) {

#pragma region テスト

#pragma endregion



	}

	//glfwの解放
	glfwDestroyWindow(window);
	glfwTerminate();

	//コンソールで正常に終わったことを確認
	std::cerr << "このプロジェクトは正常に終了しました" << std::endl;

	return 0;

}