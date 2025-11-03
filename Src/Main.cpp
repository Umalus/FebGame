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
	//以下初期化
	Mesh testMesh;
	Shader testShader;

	if (!testShader.Load("Res/Shader/Shader.glsl", "Res/Shader/FragmentShader.glsl"))
		return -1;


	std::vector<Vertex> vertices = {
	{Vector3{-0.5f, -0.5f, 0.0f}, Vector3{}, Vector3{0.0f, 0.0f,0.0f}}, // 左下
	{Vector3{ 0.5f, -0.5f, 0.0f}, Vector3{}, Vector3{1.0f, 0.0f,0.0f}}, // 右下
	{Vector3{ 0.0f,  0.5f, 0.0f}, Vector3{}, Vector3{0.5f, 1.0f,0.0f}}, // 上
	};

	std::vector<unsigned int> indices = { 0, 1, 2 };
	MeshData data;
	data.vertecies = vertices;
	data.indices = indices;

	testMesh.SetData(data);
	testMesh.UpdataToGPU();

	Matrix_4x4 mvp = Matrix_4x4::Identity();
	testShader.SetUniformMat4("uMVP", mvp);

	glClearColor(0.1f, 0.1f, 0.1f, 1.0f); // 背景色

#pragma endregion
	while (!glfwWindowShouldClose(window)) {
#pragma region テスト
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		testShader.Bind();
		testMesh.Draw();

		glfwSwapBuffers(window);
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