//
//  ShaderH.cpp
//  05_ShaderClass
//
//  Created by marker on 2019/6/9.
//  Copyright © 2019年 majortom. All rights reserved.
//

#include "ShaderH.hpp"
using namespace std;

ShaderH::ShaderH(const GLchar * vertexShaderPath,const GLchar * fragmentShaderPath){
    string vertexShaderStr;
    string fragmentShaderStr;
    ifstream vShaderFile;
    ifstream fShaderFile;
    //保证 ifstream 对象可以抛出异常
    vShaderFile.exceptions(ifstream::failbit | ifstream::badbit);
    fShaderFile.exceptions(ifstream::failbit | ifstream::badbit);
    try{
        //按路径打开shader文件
        vShaderFile.open(vertexShaderPath);
        fShaderFile.open(fragmentShaderPath);
        
        //读取文件缓冲内容到数据流
        stringstream vShaderStream,fShaderStream;
        vShaderStream<<vShaderFile.rdbuf();
        fShaderStream<<fShaderFile.rdbuf();
        
        //关闭文件处理器
        vShaderFile.close();
        fShaderFile.close();
        
        //转换数据流到string
        vertexShaderStr=vShaderStream.str();
        fragmentShaderStr=fShaderStream.str();
    }
    
    catch(ifstream::failure e){
        cout<<"File Failed to Read!"<<endl;
    }
    
    const char* vertexShaderCode;
    const char* fragmentShaderCode;
    vertexShaderCode=vertexShaderStr.c_str();
    fragmentShaderCode=fragmentShaderStr.c_str();
    
    //着色器创建&编译
    unsigned int vertexShader,fragmentShader;
    
    vertexShader=glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader,1,&vertexShaderCode,NULL);
    glCompileShader(vertexShader);
    CheckCompileError(vertexShader, "SHADER");
    
    fragmentShader=glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader,1,&fragmentShaderCode,NULL);
    glCompileShader(fragmentShader);
    CheckCompileError(fragmentShader, "FRAGMENT");
    
    //着色器链接,生成着色器程序
    ID=glCreateProgram();
    glAttachShader(ID,vertexShader);
    glAttachShader(ID,fragmentShader);
    glLinkProgram(ID);
    CheckCompileError(ID, "PROGRAM");
    
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}


void ShaderH::use(){
    glUseProgram(ID);
}

void ShaderH::SetBool(const string &name, const bool value) const {
   glUniform1i(glGetUniformLocation(ID,name.c_str()),(int)value);
}

void ShaderH::SetInt(const string &name, const int value) const {
    glUniform1i(glGetUniformLocation(ID,name.c_str()),value);
}

void ShaderH::SetFloat(const string &name, const float value) const {
    glUniform1f(glGetUniformLocation(ID,name.c_str()),value);
}

void ShaderH::CheckCompileError(const unsigned int Shader, const string type){
    int success;
    char infoLog[512];
    if(type!="PROGRAM"){
        glGetShaderiv(Shader,GL_COMPILE_STATUS,&success);
        if(!success){
            glGetShaderInfoLog(Shader,512,NULL,infoLog);
            cout<<"Shader Failed to Compile of Type:"<<Shader<<"    Info:"<<infoLog<<endl;
        }
    }else{
        glGetProgramiv(Shader,GL_LINK_STATUS,&success);
        if(!success){
            glGetProgramInfoLog(Shader,512,NULL,infoLog);
            cout<<"Program Failed to Link of Type:"<<Shader<<"    Info:"<<infoLog<<endl;
        }
    }
}
