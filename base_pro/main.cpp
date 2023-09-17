/*
 *
 *  main.cpp
 *  base_pro
 *
 *  Created by coffee on 2023/9/17.
 *
 */

#include "glfw3.h"
#include <stdio.h>
/* #include "glad.h" */

void framebuffer_size_callback( GLFWwindow* window, int width, int height )
{
    glViewport( 0, 0, width / 2, height / 2 );
}
 

int main()
{
    /* 初始化 GLFW */
    glfwInit();

    /* 创建窗口 */
    GLFWwindow *window = glfwCreateWindow( 800, 600, "Hello, World!", NULL, NULL );
    if ( window == NULL )
    {
        glfwTerminate();
        return(-1);
    }

    /* 获取窗口大小 */
    int width, height;
    glfwGetWindowSize( window, &width, &height );

    glfwSetWindowSizeCallback( window, framebuffer_size_callback );
    glfwMakeContextCurrent( window );

    /* 打印窗口大小 */
    printf( "width = %d, height = %d\n", width, height );

    /* 获取帧缓冲区大小 */
    int framebufferWidth, framebufferHeight;
    glfwGetFramebufferSize( window, &framebufferWidth, &framebufferHeight );

    /* 打印帧缓冲区大小 */
    printf( "framebufferWidth = %d, framebufferHeight = %d\n", framebufferWidth, framebufferHeight );

    /* 循环渲染 */
    while ( !glfwWindowShouldClose( window ) )
    {
        /* 渲染 */
        glClearColor( 1.0f, 0.0f, 0.0f, 1.0f );
        glClear( GL_COLOR_BUFFER_BIT );

        GLint viewport[4];
        glGetIntegerv( GL_VIEWPORT, viewport );
        /* 打印帧缓冲区大小 */
        printf( "framebufferWidth = %d, framebufferHeight = %d\n", viewport[2], viewport[3] );


        /* 画一个矩形 */
        glBegin( GL_QUADS );
        glColor3f( 0.0f, 0.0f, 1.0f );
        glVertex2f( -width, -height );
        glVertex2f( width, -height );
        glVertex2f( width, height );
        glVertex2f( -width, height );
        glEnd();

        /* 画一个三角形 */
        glBegin( GL_TRIANGLES );
        glColor3f( 0.0f, 1.0f, 0.0f );
        glVertex2f( -0.5f, -0.5f );
        glVertex2f( 0.5f, -0.5f );
        glVertex2f( 0.0f, 0.5f );
        glEnd();
        /* 交换缓冲区 */
        glfwSwapBuffers( window );

        /* 处理事件 */
        glfwPollEvents();
    }

    /* 释放资源 */
    glfwDestroyWindow( window );
    glfwTerminate();

    return(0);
}


