#include <iostream>
// GLEW
#define GLEW_STATIC
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>

void key_callback(GLFWwindow* window, int key, int scancode, int action, int  mode){
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, GL_TRUE);
}


int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGl", nullptr, nullptr);
    if (window == nullptr) {
      std::cout << "Failed to create GLFW window" << std::endl;
      return -1;
    }
    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK){
      std::cout << "Failed to initialize GLEW" << std::endl;
      return -1;
    }

    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0,0,width,height);

    glfwSetKeyCallback(window, key_callback);

    while(!glfwWindowShouldClose(window)){
      glfwPollEvents();

      glClearColor(0.2f,0.3f,0.3f,1.0f);
      glClear(GL_COLOR_BUFFER_BIT);
      
      glfwSwapBuffers(window);
    }


    glfwTerminate();
    return 0;
}
