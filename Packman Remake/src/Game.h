#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Renderer/Renderer.h"

class Game {
public:
	static int WindowWidth;
	static int WindowHeight;
	GLFWwindow* Window;
	Renderer* GameRenderer;
public:
	Game();
	void InitGameWindow();
	void Run();
	void Close();
	bool IsRunning();
	static void FrameBufferSizeCallBack(GLFWwindow* window, int width, int height);
};