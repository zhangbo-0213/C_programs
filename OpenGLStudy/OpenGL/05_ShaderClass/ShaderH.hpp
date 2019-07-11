//
//  ShaderH.hpp
//  05_ShaderClass
//
//  Created by marker on 2019/6/9.
//  Copyright © 2019年 majortom. All rights reserved.
//

#ifndef ShaderH_hpp
#define ShaderH_hpp

#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;
class ShaderH{
public:
    //着色器id
    unsigned int ID;
    //构造函数 指定 顶点着色器 和 片元着色器 加载路径
    ShaderH(const GLchar * vertexShaderPath,const GLchar * fragmentShaderPath);
    //激活函数
    void use();
    //uniform 设置 函数
    void SetBool(const string &name,const bool value) const;
    void SetInt(const string &name,const int value) const;
    void SetFloat(const string &name,const float value) const;
    
private:
    void CheckCompileError(const unsigned int Shader,const string type);
};

#endif /* ShaderH_hpp */
