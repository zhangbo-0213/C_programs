//
//  Window.hpp
//  06_Texture
//
//  Created by marker on 2019/6/16.
//  Copyright © 2019年 majortom. All rights reserved.
//

#ifndef Window_hpp
#define Window_hpp

#include <stdio.h>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string.h>

using namespace std;

class Window{
public:
    Window(int width,int height,string name);
    ~Window();
    void Update();
    bool Close();
    GLFWwindow * GetWindow();
    void Terminate();
    bool isSuccess=true;
private:
    GLFWwindow *m_window;
    void Init();    
};

#endif /* Window_hpp */
