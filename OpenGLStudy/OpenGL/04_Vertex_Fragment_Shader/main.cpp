//
//  main.cpp
//  04_Vertex_Fragment_Shader
//
//  Created by marker on 2019/6/7.
//  Copyright © 2019年 majortom. All rights reserved.
//

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cmath>

using namespace std;

const unsigned int WIDTH=800;
const unsigned int HEIGHT=600;

void SetFrameBufferSizeFallBack(GLFWwindow *window,int width,int height){
    glViewport(0,0,width,height);
}

const char* vertexShaderSource="#version 330 core\n"
"layout(location=0) in vec3 aPos;\n"
"layout(location=1) in vec3 aColor;\n"
"out vec3 vertexColor;\n"
"void main(){\n"
"gl_Position=vec4(aPos,1.0f);\n"
"vertexColor=aColor;\n"
"}\n\0";

const char* fragmentShaderSource="#version 330 core\n"
"in vec3 vertexColor;\n"
//"uniform vec4 outColor;\n"
"out vec4 FragColor;\n"
"void main(){\n"
"FragColor=vec4(vertexColor,1.0f);\n"
"}\n\0";

float vertexs[]={
    -0.5f,0.5f,0.0f,    1.0f,0.0f,0.0f,//左上角_Pos_Color
     0.5f,0.5f,0.0f,    0.0f,1.0f,0.0f,//右上角_Pos_Color
    -0.5f,-0.5f,0.0f,   0.0f,0.0f,1.0f,//左下角_Pos_Color
    0.5f,-0.5f,0.0f,    1.0f,1.0f,0.0f//右下角_Pos_Color
};

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
    GLFWwindow *window=glfwCreateWindow(WIDTH, HEIGHT, "Vertex_Fragment_Shader", NULL, NULL);
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
        glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,6*sizeof(float),(void *)0);
        //顶点颜色配置
        glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,6*sizeof(float),(void *)(3*sizeof(float)));
    
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        
        int vertexShader,fragmentShader;
        vertexShader=glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader,1,&vertexShaderSource,NULL);
        glCompileShader(vertexShader);
        
        int success;
        char infoLog[512];
        glGetShaderiv(vertexShader,GL_COMPILE_STATUS,&success);
        if(!success){
            glGetShaderInfoLog(vertexShader,512,NULL,infoLog);
            cout<<"Vertex Shader Compile Failed:"<<infoLog<<endl;
        }
        
        fragmentShader=glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader,1,&fragmentShaderSource,NULL);
        glCompileShader(fragmentShader);
        glGetShaderiv(fragmentShader,GL_COMPILE_STATUS,&success);
        if(!success){
            glGetShaderInfoLog(fragmentShader,512,NULL,infoLog);
            cout<<"Fragment Shader Compile Failed!"<<infoLog<<endl;
        }
        
        int shaderProgram;
        shaderProgram=glCreateProgram();
        glAttachShader(shaderProgram,vertexShader);
        glAttachShader(shaderProgram,fragmentShader);
        glLinkProgram(shaderProgram);
        
        glGetProgramiv(shaderProgram,GL_LINK_STATUS,&success);
        if(!success){
            glGetProgramInfoLog(shaderProgram,512,NULL,infoLog);
            cout<<"shaderProgram link Failed:"<<infoLog<<endl;
        }
        
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    
    
    glViewport(0,0,WIDTH,HEIGHT);
    //循环渲染
    while(!glfwWindowShouldClose(window)){
        //设置背景颜色
        glClearColor(0.5f,0.5f,0.5f,1.0f);
        //清除颜色缓存
        glClear(GL_COLOR_BUFFER_BIT);
        
        //uniform 类型变量为opengl的全局变量，意味着任何着色器中都能调用设置该变量,而不依赖着色器前后的输出关系
        //对于在渲染迭代中需要改变的变量，使用uniform非常合适
        //float timevalue=glfwGetTime();
        //float redColor=(sin(timevalue)/2.0f)+0.5f;
        //找到uniform变量的定位
        //int glUniformLocation=glGetUniformLocation(shaderProgram,"outColor");
        //设置uniform变量值前，必须使用 shaderProgram uniform变量的更新是在当前激活的着色器程序上
        
        
        glUseProgram(shaderProgram);
        //glUniform4f(glUniformLocation,redColor,0.0f,0.0f,1.0f);
        
        
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
