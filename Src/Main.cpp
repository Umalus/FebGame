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
	//以下初期化
	Mesh testMesh;
	Shader testShader;

	if (!testShader.Load("Res/Shader/Shader.glsl", "Res/Shader/FragmentShader.glsl"))
		return -1;


	//std::vector<Vertex> vertices = {
	//{Vector3{-0.5f, -0.5f, 0.0f}, Vector3{}, Vector2{0.0f, 0.0f}}, // 左下
	//{Vector3{ 0.5f, -0.5f, 0.0f}, Vector3{}, Vector2{1.0f, 0.0f}}, // 右下
	//{Vector3{ 0.0f,  0.5f, 0.0f}, Vector3{}, Vector2{0.5f, 1.0f}}, // 上
	//};

	//std::vector<unsigned int> indices = { 0, 1, 2 };
	//MeshData data;
	//data.vertecies = vertices;
	//data.indices = indices;

	//testMesh.SetData(data);
	//testMesh.UpdateToGPU();

	auto model = std::make_shared<ModelResource>();
	model->Load("Res/Model/testModelVer2.fbx");

	auto mesh = model->GetMesh(0);

	Camera* pCamera = new Camera();


	

	glClearColor(0.1f, 0.1f, 0.1f, 1.0f); // 背景色


#pragma endregion
	while (!glfwWindowShouldClose(window)) {
#pragma region テスト
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		pCamera->Update(60.0f);

		Matrix_4x4 proj = pCamera->GetProjectionMatrix(aspectRatio);
		Matrix_4x4 view = pCamera->GetViewMatrix();
		Matrix_4x4 modelMat =
			Matrix_4x4::FromScale({ 0.01f, 0.01f, 0.01f })
			.Multiply(Matrix_4x4::FromRotationEuler({ 0.0f, 0, 0 }))
			.Multiply(Matrix_4x4::FromTranslation({ 0, 0.0f, 0.0f }));


		Matrix_4x4 mvp = proj.Multiply(view.Multiply(modelMat));
		testShader.SetUniformMat4("uMVP", mvp);

		testShader.Bind();
		mesh->Draw();

		glfwSwapBuffers(window);
		glfwPollEvents();

#pragma endregion
	}

	//glfwの解放
	glfwDestroyWindow(window);
	glfwTerminate();


	delete(pCamera);
	//コンソールで正常に終わったことを確認
	std::cerr << "このプロジェクトは正常に終了しました" << std::endl;

	return 0;

}