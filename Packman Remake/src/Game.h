#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Renderer/Renderer.h"
#include "Levels/Level.h"


class Game {
public:
	static int WindowWidth;
	static int WindowHeight;
	GLFWwindow* Window;
	Renderer* GameRenderer;
	Level* CurrentLevel;
public:
	Game();
	void InitGameWindow();
	void LoadLevel(Level* level);
	void Run();
	void Close();
	bool IsRunning();
	static void FrameBufferSizeCallBack(GLFWwindow* window, int width, int height);
};