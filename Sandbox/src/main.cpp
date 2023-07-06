#include "glew.h"
#include "glfw3.h"
#include "Logger.h"
#include <iostream>

int OpenGL();

namespace Journal {
     void Print();
}

int main()
{
    return OpenGL();
}

int OpenGL()
{
    Journal::Print();

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
    {
        Logger::log("Failed to initialize GLFW", "red", "error");
        return -1;
    }

    Logger::log("GLFW initialized: " + std::string(glfwGetVersionString()), "green", "info");

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", nullptr, nullptr);
    if (!window)
    {
        Logger::log("Failed to create GLFW window" , "red", "error");
        glfwTerminate();
        return -1;
    }

    Logger::log("GLFW window created", "green", "info");

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        /* Problem: glewInit failed, something is seriously wrong. */
        Logger::log("Failed to initialize GLEW", "red", "error");
        glfwTerminate();
        return -1;
    }

    Logger::log("Using Glew: " + std::string((char*)glewGetString(GLEW_VERSION)), "green", "info");
    Logger::log("OpenGL: " + std::string((char*)glGetString(GL_VERSION)), "green", "info");

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLES);
        glVertex2f(0.0f, 0.5f);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.5f, -0.5f);
        glEnd();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}