//
//  main.cpp
//  03_FirstTriangle
//
//  Created by marker on 2019/6/2.
//  Copyright © 2019年 majortom. All rights reserved.
//

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

using namespace std;

const unsigned int WIDTH = 800;

const unsigned int HEIGHT = 600;

//顶点着色器
const char *vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
//片段着色器
const char *fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0";

const char *fragmentShaderSource2 = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.0f, 0.2f, 1.0f);\n"
"}\n\0";

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}
void pressInput(GLFWwindow* window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main(){
    //初始化窗口
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);     //兼容Mac OS X
    
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "MajorTom's Triange", NULL, NULL);
    
    //判断窗口创建是否成功
    if(window == NULL){
        cout<<"Fail to Create Window"<<endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    
    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    
    //创建顶点着色器
    int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    //检查顶点着色器编译是否成功
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        cout<<"ERROR: VertexShader Compile Fail"<<infoLog<<endl;
    }
    
    //创建片段着色器
    int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    
    //检查片段着色器是否编译成功
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        cout<<"ERROR: FragmentShader Compile Fail"<<infoLog<<endl;
    }
    
    int fragmentShader2=glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader2,1,&fragmentShaderSource2,NULL);
    glCompileShader(fragmentShader2);
    glGetShaderiv(fragmentShader2,GL_COMPILE_STATUS,&success);
    if(!success){
        glGetShaderInfoLog(fragmentShader2,512,NULL,infoLog);
        cout<<"Error:FragmentShader2 Compile Fail"<<infoLog<<endl;
    }
    
    //链接着色器
    int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    
    //检查着色器链接是否成功
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success){
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        cout<<"ERROR: Shader Link Fail"<<infoLog<<endl;
    }
    
    int shaderProgram2 = glCreateProgram();
    glAttachShader(shaderProgram2, vertexShader);
    glAttachShader(shaderProgram2, fragmentShader2);
    glLinkProgram(shaderProgram2);
    
    //检查着色器链接是否成功
    glGetProgramiv(shaderProgram2, GL_LINK_STATUS, &success);
    if(!success){
        glGetProgramInfoLog(shaderProgram2, 512, NULL, infoLog);
        cout<<"ERROR: Shader Link Fail"<<infoLog<<endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    glDeleteShader(fragmentShader2);
    
    //设置顶点坐标
    float vertices[] = {
        0.5f, 0.5f, 0.0f,   // 右上角
        0.5f, -0.5f, 0.0f,  // 右下角
        -0.5f, -0.5f, 0.0f, // 左下角
        -0.5f, 0.5f, 0.0f   // 左上角
    };
    
    float vertices2[]={
        -0.50f,0.0f,0.0f,
        -0.25f,0.5f,0.0f,
         0.0f, 0.0f,0.0f
    };
    
    float vertices3[]={
        0.0f, 0.0f,0.0f,
        0.25f,0.5f,0.0f,
        0.5f,0.0f,0.0f
    };
    
    //设置三角形顶点索引
    unsigned int indices[] = { // 注意索引从0开始!
        0, 1, 3, // 第一个三角形
        1, 2, 3  // 第二个三角形
    };
    
    //顶点数组对象(Vertex Array Object, VAO)可以像顶点缓冲对象那样被绑定，任何随后的顶点属性调用都会储存在这个VAO中。这样的好处就是，当配置顶点属性指针时，你只需要将那些调用执行一次，之后再绘制物体的时候只需要绑定相应的VAO就行了。这使在不同顶点数据和属性配置之间切换变得非常简单，只需要绑定不同的VAO就行了
    //VAO 可以存储设置过的顶点属性（位置，颜色，纹理等），再次使用时，不必重复设置相应的顶点属性，直接通过绑定不同的VAO就可以了
    //VBO 中保存的只是顶点的数据，数据怎么解析，让opengl明白怎么用，需要通过顶点属性设置之后，由顶点着色器按照顶点属性来处理，而记录这些属性的工作由VAO来完成
    //EBO 索引缓存对象，用来保存绘制三角形时，顶点数据的索引
    unsigned int VAOs[2],VBOs[2],EBO;
    //glGenVertexArrays 设置顶点数组对象，生成顶点数组对象
    glGenVertexArrays(2,VAOs);
    //glGenBuffers 设置缓冲对象id，生成缓冲对象
    glGenBuffers(2,VBOs);
    //glGenBuffers 设置缓冲对象id，生成缓冲对象
    glGenBuffers(1,&EBO);
    //绑定数组顶点对象
    glBindVertexArray(VAOs[0]);
    //绑定顶点缓冲对象到指定的缓冲类型 绑定后，使用的任何（在GL_ARRAY_BUFFER目标上的）缓冲调用都会用来配置当前绑定的缓冲(VBO)
    glBindBuffer(GL_ARRAY_BUFFER,VBOs[0]);
    //通过 GL_ARRAY_BUFFER 类型的缓冲调用，将顶点数据复制到 VBO 顶点缓存对象中
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices2),vertices2,GL_STATIC_DRAW);
    //绑定索引缓冲对象到指定的缓冲类型 绑定后，使用的任何（在GL_ELEMENT_ARRAY_BUFFER目标上的）缓冲调用都会用来配置当前绑定的缓冲(EBO)
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
    //通过 GL_ELEMENT_ARRAY_BUFFER 类型的缓冲调用，将顶点索引数据复制到 EBO 顶点索引缓存对象中
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indices),indices,GL_STATIC_DRAW);
    //glBufferData是一个专门用来把用户定义的数据复制到当前绑定缓冲的函数
    //    第四个参数指定了我们希望显卡如何管理给定的数据。它有三种形式：
    //    GL_STATIC_DRAW ：数据不会或几乎不会改变。
    //    GL_DYNAMIC_DRAW：数据会被改变很多。
    //    GL_STREAM_DRAW ：数据每次绘制时都会改变。
    //    三角形的位置数据不会改变，每次渲染调用时都保持原样，所以它的使用类型最好是GL_STATIC_DRAW。如果，比如说一个缓冲中的数据将频繁被改变，那么使用的类型就是GL_DYNAMIC_DRAW或GL_STREAM_DRAW，这样就能确保显卡把数据放在能够高速写入的内存部分。
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(float),(void *)0);
    //链接顶点数据  解析顶点数据
    //使用glVertexAttribPointer函数告诉OpenGL该如何解析顶点数据
    //    glVertexAttribPointer函数的参数：
    //   第一个参数指定要配置的顶点属性。在顶点着色器中使用layout(location = 0)定义了position顶点属性的位置值(Location)，它可以把顶点属性的位置值设置为0。因为我们希望把数据传递到这一个顶点属性中，所以这里我们传入0。
    //   第二个参数指定顶点属性的大小。顶点属性是一个vec3，它由3个值组成，所以大小是3。
    //   第三个参数指定数据的类型，这里是GL_FLOAT(GLSL中vec*都是由浮点数值组成的)。
    //   下个参数定义我们是否希望数据被标准化(Normalize)。如果我们设置为GL_TRUE，所有数据都会被映射到0（对于有符号型signed数据是-1）到1之间。我们把它设置为GL_FALSE。
    //   第五个参数叫做步长(Stride)，它告诉我们在连续的顶点属性组之间的间隔。由于下个组位置数据在3个float之后，我们把步长设置为3 * sizeof(float)。要注意的是由于我们知道这个数组是紧密排列的（在两个顶点属性之间没有空隙）我们也可以设置为0来让OpenGL决定具体步长是多少（只有当数值是紧密排列时才可用）。一旦我们有更多的顶点属性，我们就必须更小心地定义每个顶点属性之间的间隔，我们在后面会看到更多的例子（译注: 这个参数的意思简单说就是从这个属性第二次出现的地方到整个数组0位置之间有多少字节）。
    //    最后一个参数的类型是void*，所以需要我们进行这个奇怪的强制类型转换。它表示位置数据在缓冲中起始位置的偏移量(Offset)。由于位置数据在数组的开头，所以这里是0。
    
    //   每个顶点属性从一个VBO管理的内存中获得它的数据，而具体是从哪个VBO（程序中可以有多个VBO）获取则是通过在调用glVetexAttribPointer时绑定到GL_ARRAY_BUFFER的VBO决定的。由于在调用glVetexAttribPointer之前绑定的是先前定义的VBO对象，顶点属性0现在会链接到它的顶点数据。
    glEnableVertexAttribArray(0);
    
    glBindVertexArray(VAOs[1]);
    glBindBuffer(GL_ARRAY_BUFFER,VBOs[1]);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices3),vertices3,GL_STATIC_DRAW);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(float),(void *)0);
    glEnableVertexAttribArray(0);
    
    //使用glEnableVertexAttribArray，以顶点属性位置值作为参数，启用顶点属性；顶点属性默认是禁用的
    glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindVertexArray(0);
    
    //循环渲染
    while(!glfwWindowShouldClose(window)){
        
        pressInput(window);
        
        glClearColor(0.8f, 0.8f, 0.8f, 0.8f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glUseProgram(shaderProgram);
        //使用时再具体绑定需要渲染的物体的顶点属性 VAO
        glBindVertexArray(VAOs[0]);
        glDrawArrays(GL_TRIANGLES,0,3);
        //使用索引缓存对象EBO 在绘制时，调用 glDrawElements() 函数
        //glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);
        
        glUseProgram(shaderProgram2);
        glBindVertexArray(VAOs[1]);
        glDrawArrays(GL_TRIANGLES,0,3);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glDeleteVertexArrays(2,VAOs);
    glDeleteBuffers(2,VBOs);
    glDeleteBuffers(1,&EBO);
    
    //释放分配的资源
    glfwTerminate();
    return 0;
}




