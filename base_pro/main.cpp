//
//  main.cpp
//  base_pro
//
//  Created by coffee on 2023/9/17.
//

#include "glfw3.h"
#include <stdio.h>

int main() {
  // 初始化 GLFW
  glfwInit();

  // 创建窗口
  GLFWwindow *window = glfwCreateWindow(800, 600, "Hello, World!", NULL, NULL);
  if (window == NULL) {
    glfwTerminate();
    return -1;
  }

  // 获取窗口大小
  int width, height;
  glfwGetWindowSize(window, &width, &height);

  // 打印窗口大小
  printf("width = %d, height = %d\n", width, height);

  // 获取帧缓冲区大小
  int framebufferWidth, framebufferHeight;
  glfwGetFramebufferSize(window, &framebufferWidth, &framebufferHeight);

  // 打印帧缓冲区大小
  printf("framebufferWidth = %d, framebufferHeight = %d\n", framebufferWidth, framebufferHeight);

  // 循环渲染
  while (!glfwWindowShouldClose(window)) {
    // 渲染
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // 交换缓冲区
    glfwSwapBuffers(window);

    // 处理事件
    glfwPollEvents();
  }

  // 释放资源
  glfwDestroyWindow(window);
  glfwTerminate();

  return 0;
}
