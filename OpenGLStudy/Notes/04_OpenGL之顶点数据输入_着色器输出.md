### **OpenGL之顶点数据输入-着色器输出**   
- **顶点数据输入**     
OpenGL接收顶点数据的输入，并通过着色器处理后输出到屏幕    
顶点数据的处理由一系列顶点缓存对象来完成，如：  

- VBO   顶点缓存对象      
VBO 对象 管理GPU显存中存储顶点数据的内存区域   
- EBO   索引缓存对象   
EBO 对象 管理GPU显存中存储顶点索引数据的内存区域    
- VAO  顶点数组对象     
顶点数组对象记录了以上缓存对象的状态及其配置的属性，当需要重复绘制某个物体的时候，就无需重复绑定和设置以上缓存对象及其管理的数据了，通过VAO对象去获取缓存对象保存的状态和配置的属性    

用一张图解释VAO_VBO之间的关系：    
![VAO_VBO](https://pic1.zhimg.com/v2-2f7beaffce2851a26a5bcba77e29120a_r.jpg)

（1）显示列表是一组预先编译好的OpenGL函数语句，是记录的一组过程；而VAO对应的是一组内存缓存区组成的对象，是在显存里划分的。    
（2）VAO是一个对象，一个VAO可以包含都多个VBO，是一种关联关系；而VBO又可以有保存不同的类型，包括顶点坐标、UV、法线、颜色、索引等，通过glBufferData给VBO可以指定相应的类型及数据来源，再通过glVertexAttribPointer给VBO指定相应的顶点数据属性，由VAO保存下来。      
（3）glBindVertexArray 可以设置当前绑定的VAO，然后glGenBuffers生成VBO后，通过glBindBuffer能够关联到当前的VAO。VAO里的VBOs都设置好了以后，在绘制的地方只需要设置当前绑定的VAO是哪个，就能按照初始化的VAO来绘制，即调用glDrawArrays。也就是说在初始化的时候，事先确定VAO的格式，在需要的调用的时候，只需要绑定这个特定的VAO就好。        
（4）glBindVertexArray(0)表示当前不用VAO了，并不是VAO释放了    

顶点数据的输入过程：      
```c++      
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

    //顶点位置配置
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,6*sizeof(float),(void *)0);
    //顶点颜色配置
    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,6*sizeof(float),(void *)(3*sizeof(float)));
    //配置的属性激活
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);   
```

- **着色器输出**      
顶点数据准备好之后，由顶点着色器和片元着色器进行处理后输出，着色器值之间处理结果的传递通过定义输入和输出变量，在使用着色器之前，先生成，编译和链接着色器：     
```c++   
    //生成，编译顶点着色器
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
    
    //生成，编译片段着色器
    fragmentShader=glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader,1,&fragmentShaderSource,NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader,GL_COMPILE_STATUS,&success);
    if(!success){
    glGetShaderInfoLog(fragmentShader,512,NULL,infoLog);
    cout<<"Fragment Shader Compile Failed!"<<infoLog<<endl;
    }
    
    //链接顶点，片元着色器生成着色器程序
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
    
    //着色器链接完成后删除顶点及着色器程序
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
```     
链接成功的着色器程序激活后即可处理顶点数据的渲染和输出：    
```c++    
    //激活着色器程序
    glUseProgram(shaderProgram);
```
在编译顶点着色器和片元着色器时，需要指定对应着色器的源代码（字符串形式保存），如：    
```c++    
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
        "out vec4 FragColor;\n"
    "void main(){\n"
        "FragColor=vec4(vertexColor,1.0f);\n"
    "}\n\0";
```
