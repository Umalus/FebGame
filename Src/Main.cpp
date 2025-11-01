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

	GLFWwindow* window = glfwCreateWindow(800, 600, "FPS", NULL, NULL);
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
	//以下初期化
	Mesh testMesh;
	Shader testShader;

	if (!testShader.Load("Res/Shader/Shader.glsl", "Res/Shader/FragmentShader.glsl"))
		return -1;

	


	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	//glfwの解放
	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;

}