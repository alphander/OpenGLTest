#include "GLAD/glad.h"
#include "GLFW/glfw3.h"
#include "stdlib.h"

void init(GLFWwindow** window)
{
    if (!glfwInit()) exit(-1);

    *window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(-1);
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) 
        exit(-1);
}

void loop(GLFWwindow* window)
{
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.3f, 0.2f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void clean(GLFWwindow* window)
{
    glfwTerminate();
}

int main(void)
{
    GLFWwindow* window;

    init(&window);
    loop(window);
    clean(window);

    return 0;
}