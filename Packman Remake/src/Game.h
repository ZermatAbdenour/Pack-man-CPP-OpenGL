#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Game {
public:
	static int WindowWidth;
	static int WindowHeight;
	GLFWwindow* Window;
public:
	Game();
	void InitGameWindow();
	void Run();
	void Close();
	bool IsRunning();
	static void FrameBufferSizeCallBack(GLFWwindow* window, int width, int height);
};