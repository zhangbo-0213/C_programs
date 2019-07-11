//
//  main.cpp
//  05_ShaderClass
//
//  Created by marker on 2019/6/9.
//  Copyright © 2019年 majortom. All rights reserved.
//

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include "ShaderH.hpp"

using namespace std;

const unsigned int WIDTH=800;
const unsigned int HEIGHT=600;

void SetFrameBufferSizeFallBack(GLFWwindow *window,int width,int height){
    glViewport(0,0,width,height);
}

float vertexs[]={
    //     ---- 位置 ----       ---- 颜色 ----     - 纹理坐标 -
    0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // 右上
    0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // 右下
    -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // 左下
    -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // 左上
};

//float vertexs[]={
//    -0.5f,0.5f,0.0f,    1.0f,0.0f,0.0f,//左上角_Pos_Color
//    0.5f,0.5f,0.0f,    0.0f,1.0f,0.0f,//右上角_Pos_Color
//    -0.5f,-0.5f,0.0f,   0.0f,0.0f,1.0f,//左下角_Pos_Color
//    0.5f,-0.5f,0.0f,    1.0f,1.0f,0.0f//右下角_Pos_Color
//};

unsigned int indexs[]={
    0,1,3,
    0,2,3
};

int main(int argc, const char * argv[]) {
    
    
    //窗口初始化
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //mac 兼容
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
    
    //窗口设置
    GLFWwindow *window=glfwCreateWindow(WIDTH, HEIGHT, "Shader_Class", NULL, NULL);
    if(window==NULL){
        cout<<"Window Create Failed!"<<endl;
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent(window);
    //设置窗口尺寸变化的回调
    glfwSetFramebufferSizeCallback(window, SetFrameBufferSizeFallBack);
    
    //加载函数指针地址
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        cout<<"Glad Load Failed"<<endl;
        return -1;
    }
    
    unsigned int VAO,VBO,EBO;
    //指定生成VAO的数量
    glGenVertexArrays(1,&VAO);
    //指定生成VBO的数量
    glGenBuffers(1,&VBO);
    //指定生成EBO的数量
    glGenBuffers(1,&EBO);
    //VAO数据绑定
    glBindVertexArray(VAO);
    //VBO数据绑定
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    //顶点数据复制到指定缓存中
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertexs),vertexs,GL_STATIC_DRAW);
    //EBO数据绑定
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
    //数据索引复制到指定缓存中
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indexs),indexs,GL_STATIC_DRAW);
    //顶点属性配置
    
    //顶点位置配置
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,8*sizeof(float),(void *)0);
    //顶点颜色配置
    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,8*sizeof(float),(void *)(3*sizeof(float)));
    
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    
    ShaderH outShader("vertexCode.vs","fragmentCode.fs");
    
    glViewport(0,0,WIDTH,HEIGHT);
    //循环渲染
    while(!glfwWindowShouldClose(window)){
        //设置背景颜色
        glClearColor(0.5f,0.5f,0.5f,1.0f);
        //清除颜色缓存
        glClear(GL_COLOR_BUFFER_BIT);

        outShader.use();
        outShader.SetFloat("xOffset", -0.2f);
        
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);
        //缓存交换，实现双缓冲渲染
        glfwSwapBuffers(window);
        //监测用户的输入，窗口点击事件，通过注册的方式可以进行事件回调
        glfwPollEvents();
    }
    
    glDeleteVertexArrays(1,&VAO);
    glDeleteBuffers(1,&VBO);
    glDeleteBuffers(1,&EBO);
    
    glfwTerminate();
    return 0;
}
