//
//  main.cpp
//  06_Texture
//
//  Created by marker on 2019/6/11.
//  Copyright © 2019年 majortom. All rights reserved.
//

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include "ShaderH.hpp"
#include "stb_image.h"
#include "Window.hpp"

using namespace std;

const int WIDTH=800;
const int HEIGHT=600;

float mixValue=0.2f;

void SetFrameBufferSizeCallBack(GLFWwindow *window,int width,int height){
    glViewport(0,0,width,height);
}

void processInput(GLFWwindow *window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE)==GLFW_PRESS){
        glfwSetWindowShouldClose(window,true);
    }
    if(glfwGetKey(window, GLFW_KEY_UP)==GLFW_PRESS){
        mixValue+=0.001f;
        if(mixValue>1.0f)
            mixValue=1.0f;
    }
    if(glfwGetKey(window, GLFW_KEY_DOWN)==GLFW_PRESS){
        mixValue-=0.001f;
        if(mixValue<0.0f)
            mixValue=0.0f;
    }
}

float vertices[] = {
    //     ---- 位置 ----       ---- 颜色 ----     - 纹理坐标 -
    0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // 右上
    0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // 右下
    -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // 左下
    -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // 左上
};

int indexs[]={
    0,1,3,
    1,2,3
};

int main(int argc, const char * argv[]) {
    
    //窗口初始化
//    glfwInit();
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//    //mac 兼容
//    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
//
//    //窗口设置
//    GLFWwindow *window=glfwCreateWindow(WIDTH, HEIGHT, "06_Texture", NULL, NULL);
//    if(window==NULL){
//        cout<<"Window Create Failed!"<<endl;
//        glfwTerminate();
//        return -1;
//    }
//
//    glfwMakeContextCurrent(window);
//    //设置窗口尺寸变化的回调
//    glfwSetFramebufferSizeCallback(window, SetFrameBufferSizeCallBack);
//
//    //加载函数指针地址
//    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
//        cout<<"Glad Load Failed"<<endl;
//        return -1;
//    }

    Window Window_=Window(WIDTH, HEIGHT, "Texture");
    
    if(!Window_.isSuccess){
        cout<<"Window Create Failed!!!"<<endl;
    }
    
    GLFWwindow *window=Window_.GetWindow();
    
    glfwSetFramebufferSizeCallback(window, SetFrameBufferSizeCallBack);
    
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
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
    //EBO数据绑定
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
    //数据索引复制到指定缓存中
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indexs),indexs,GL_STATIC_DRAW);
    //顶点属性配置


    //生成纹理对象
    unsigned int texture1,texture2;
    glGenTextures(1,&texture1);
    glBindTexture(GL_TEXTURE_2D,texture1);
    //设置纹理的环绕和过滤方式
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    //加载生成纹理
    int width,height,nrChanel;
    unsigned char *data=stbi_load("bricks2.jpg",&width,&height,&nrChanel,0);
    //设置纹理翻转（纹理坐标和openglc坐标在竖直方向上相反）
    stbi_set_flip_vertically_on_load(true);
    if(data){
        //使用图片数据生成纹理
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,data);
        //第一个参数指定了纹理目标(Target)。设置为GL_TEXTURE_2D意味着会生成与当前绑定的纹理对象在同一个目标上的纹理（任何绑定到GL_TEXTURE_1D和GL_TEXTURE_3D的纹理不会受到影响）。
        //第二个参数为纹理指定多级渐远纹理的级别，如果你希望单独手动设置每个多级渐远纹理的级别的话。这里我们填0，也就是基本级别。
        //第三个参数告诉OpenGL我们希望把纹理储存为何种格式。我们的图像只有RGB值，因此我们也把纹理储存为RGB值。
        //第四个和第五个参数设置最终的纹理的宽度和高度。我们之前加载图像的时候储存了它们，所以我们使用对应的变量。
        //下个参数应该总是被设为0（历史遗留的问题）。
        //第七第八个参数定义了源图的格式和数据类型。我们使用RGB值加载这个图像，并把它们储存为char(byte)数组，我们将会传入对应值。
        //最后一个参数是真正的图像数据。

        //自动设置多级渐远纹理
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else{
        cout<<"Failed to load image"<<endl;
    }
    stbi_image_free(data);
    
    //加载纹理2
    glGenTextures(1,&texture2);
    glBindTexture(GL_TEXTURE_2D,texture2);
    //设置纹理环绕方式和过滤纹理
    //glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE);
    //glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_BORDER);
    //设置 GL_CLAMP_TO_BORDER 模式需要指定边界颜色   
    float borderColor[]={0.0f,1.0f,0.0f,0.2f};
    glTexParameterfv(GL_TEXTURE_2D,GL_TEXTURE_BORDER_COLOR,borderColor);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    //设置纹理翻转（纹理坐标和openglc坐标在竖直方向上相反）
    stbi_set_flip_vertically_on_load(true);
    //加载纹理
    data=stbi_load("awesomeface.png", &width, &height, &nrChanel, 0);
    if(data){
        //使用加载的图片数据生成纹理
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,width,height,0,GL_RGBA,GL_UNSIGNED_BYTE,data);
        //自动设置多级渐远纹理
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else{
        cout<<"Failed to load image"<<endl;
    }
    stbi_image_free(data);
    
    ShaderH outShader("vertexCode.vs","fragmentCode.fs");
    outShader.use();
    
    //激活纹理单元，并进行纹理绑定
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D,texture1);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D,texture2);
    
    //设置纹理采样器所属纹理单元,这样不同的纹理采样器在不同的纹理单元中找到对应的纹理
    //在设置纹理采样器所属纹理单元前，先激活shader 程序
    glUniform1i(glGetUniformLocation(outShader.ID,"texture1"),0);
    outShader.SetInt("texture2", 1);
    

    //顶点属性配置
    //顶点位置配置
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,8*sizeof(float),(void *)0);
    //顶点颜色配置
    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,8*sizeof(float),(void *)(3*sizeof(float)));
    //纹理坐标配置
    glVertexAttribPointer(2,2,GL_FLOAT,GL_FALSE,8*sizeof(float),(void *)(6*sizeof(float)));

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);


    glViewport(0,0,WIDTH,HEIGHT);
    
    //循环渲染
    while(!Window_.Close()){
        //设置背景颜色
        glClearColor(0.2f,0.2f,0.2f,1.0f);
        //清除颜色缓存
        glClear(GL_COLOR_BUFFER_BIT);
        
        processInput(window);
        
        outShader.use();
        outShader.SetFloat("mixValue", mixValue);
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);
//        //缓存交换，实现双缓冲渲染
//        glfwSwapBuffers(window);
//        //监测用户的输入，窗口点击事件，通过注册的方式可以进行事件回调
//        glfwPollEvents();
        Window_.Update();
    }

    glDeleteVertexArrays(1,&VAO);
    glDeleteBuffers(1,&VBO);
    glDeleteBuffers(1,&EBO);

    glfwTerminate();
    return 0;
}
