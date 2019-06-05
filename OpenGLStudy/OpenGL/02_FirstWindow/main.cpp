//
//  main.cpp
//  02_FirstWindow
//
//  Created by marker on 2019/6/1.
//  Copyright © 2019年 majortom. All rights reserved.
//

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

using namespace std;

//定义了一个回调函数，根据窗口的尺寸来改变视口的像素尺寸
void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    //设置视口坐标（可以理解为 opengl 渲染输出的窗口）
    glViewport(0, 0, width, height);
}

int main(int argc, const char * argv[]) {
    //GLFW是一个专门针对OpenGL的C语言库，它提供了一些渲染物体所需的最低限度的接口。
    //它允许用户创建OpenGL上下文，定义窗口参数以及处理用户输入
    //glfw 初始化
    glfwInit();
    //将主版本号(Major)和次版本号(Minor)都设为3,告诉GLFW,使用的opengl版本为3以上
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    //告诉glfw，使用OpenGL的核心渲染模式(现代渲染模式)
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // MAC OS X 下的兼容设置
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GLFW_TRUE);
    
    //创建窗口对象
    GLFWwindow *window=glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    //创建失败的异常处理
    if(window==NULL){
        cout<<"Creat GLFW Window Failed!"<<endl;
        glfwTerminate();
        return -1;
    }
    
    //将窗口对象设置为线程当前的主上下文
    glfwMakeContextCurrent(window);
    //对窗口注册一个 视口随窗口尺寸变化的函数，当窗口尺寸改变时，该framebuffer_size_callback函数会被调用
    glfwSetFramebufferSizeCallback(window,framebuffer_size_callback);
    
    
    //初始化glad glad是用来管理OpenGL的函数指针的，当我们想要调用OpenGL的函数时，先使用glad加载OpenGL函数指针
    //给GLAD传入了用来加载系统相关的OpenGL函数指针地址的函数。
    //GLFW给我们的是glfwGetProcAddress，它根据我们编译的系统定义了正确的函数
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        cout<<"Failed to load opengl function pointers"<<endl;
        return -1;
    }
    
    //设置视口坐标（可以理解为 opengl 渲染输出的窗口）
    glViewport(0,0,800,600);
    //glViewport函数前两个参数控制窗口左下角的位置,第三个和第四个参数控制渲染窗口的宽度和高度（像素）
    //视口的维度设置可以比GLFW的维度小，之后所有的OpenGL渲染将会在一个更小的窗口中显示，
    //这样可以将一些其它元素显示在OpenGL视口之外
    
    //循环渲染
    //!glfwWindowShouldClose(window) 检测是否有关闭窗口的指令，如果没有则一直执行渲染指令
    while(!glfwWindowShouldClose(window)){
        //视口颜色清除
        glClear(GL_COLOR_BUFFER_BIT);
        //交互颜色缓冲，每次覆盖迭代缓冲中存储的每个视口像素的颜色值，输出到屏幕上
        glfwSwapBuffers(window);
        //检测有没有事件的触发，用户输入，窗口更新等，并调用相应的回调，可以通过注册的方式对回调的执行做控制  
        glfwPollEvents();
    }
    
//   双缓冲(Double Buffer)
//   应用程序使用单缓冲绘图时可能会存在图像闪烁的问题。 这是因为生成的图像不是一下子被绘制出来的，而是按照从左到右，由上而下逐像素地绘制而成的。最终图像不是在瞬间显示给用户，而是通过一步一步生成的，这会导致渲染的结果很不真实。为了规避这些问题，我们应用双缓冲渲染窗口应用程序。前缓冲保存着最终输出的图像，它会在屏幕上显示；而所有的的渲染指令都会在后缓冲上绘制。当所有的渲染指令执行完毕后，我们交换(Swap)前缓冲和后缓冲，这样图像就立即呈显出来，之前提到的不真实感就消除了。
    
    
    //程序结束前，释放所有的资源
    glfwTerminate();
    return 0;
}
