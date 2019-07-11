//
//  Window.cpp
//  06_Texture
//
//  Created by marker on 2019/6/16.
//  Copyright © 2019年 majortom. All rights reserved.
//

#include "Window.hpp"

using namespace std;

Window::Window(int width,int height,string name){
    Init();
    m_window=glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);
    if(!m_window){
        cout<<"Creat Window Failed!"<<endl;
        isSuccess=false;
    }
    glfwMakeContextCurrent(m_window);
    if(!gladLoadGLLoader(GLADloadproc(glfwGetProcAddress))){
        cout<<"Load glad Failed!"<<endl;
    }
}

Window::~Window(){
    
}

bool Window::Close(){
    return glfwWindowShouldClose(m_window);
}

GLFWwindow* Window::GetWindow(){
    return m_window;
}

void Window::Update(){
    glfwSwapBuffers(m_window);
    glfwPollEvents();
}

void Window::Terminate(){
    glfwTerminate();
}

void Window::Init(){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
}
