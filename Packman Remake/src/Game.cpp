#include "Game.h"



int Game::WindowWidth = 800;
int Game::WindowHeight = 600;

Game::Game()
{
    InitGameWindow();
}

void Game::InitGameWindow()
{
    //Init GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    Window = glfwCreateWindow(WindowWidth, WindowHeight, "Pacman", NULL, NULL);

    glfwMakeContextCurrent(Window);
    if (Window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }

    glfwMakeContextCurrent(Window);

    //Init Glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }

    //Set Viewport
    glViewport(0, 0, WindowWidth, WindowHeight);

    glfwSetFramebufferSizeCallback(Window, FrameBufferSizeCallBack);

}

void Game::Run()
{
    while (IsRunning())
    {
        glClearColor(0.5f, 1, 0.6f, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(Window);
        glfwPollEvents();
    }

    Close();
}
void Game::Close() {
    
}

void Game::FrameBufferSizeCallBack(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

bool Game::IsRunning()
{
    return !glfwWindowShouldClose(Window);
}