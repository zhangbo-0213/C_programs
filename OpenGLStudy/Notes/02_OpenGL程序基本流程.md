### OpenGL主函数基本流程   

1. **初始化**   
    glfw的初始化过程，确定使用的OpenGL主版本以及使用的渲染模式(即时渲染模式-旧，核心渲染模式-新)      
```c++
 glfwInit();
 //将主版本号(Major)和次版本号(Minor)都设为3,告诉GLFW,使用的opengl版本为3以上
 glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
 glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
 //告诉glfw，使用OpenGL的核心渲染模式(现代渲染模式)
 glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
 // MAC OS X 下的兼容设置
 glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GLFW_TRUE);   
```   

2. **创建窗口对象**       
```c++  
 //创建窗口对象
 GLFWwindow *window=glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
```    
3. **设置上下文状态**     
利用创建的窗口对象设置当前线程上下文的状态       
```c++   
 //通知GLFW将窗口的上下文设置为当前线程的主上下文
 glfwMakeContextCurrent(window);
```    

4. **设置glad**    
glad是用来管理OpenGL的函数指针，在使用OpenGL的内置函数前，glad需要拿到指定函数指针的地址    
```c++   
 if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
 cout<<"Failed to load opengl function pointers"<<endl;
 return -1;
 }
```  
给glad传入加载系统相关的OpenGL函数指针地址的函数     

5. **指定渲染视口**      
指定OpenGL渲染窗口的尺寸大小，即视口(Viewport)，这样OpenGL才只能知道怎样根据窗口大小显示数据和坐标      

```c++
 glViewport(0, 0, 800, 600);  
```   
可以将视口的维度设置为比GLFW的维度小，这样子之后所有的OpenGL渲染将会在一个更小的窗口中显示，这样子的话也可以将一些其它元素显示在OpenGL视口之外       

6. **执行渲染**      
```c++
 //!glfwWindowShouldClose(window) 检测是否有关闭窗口的指令，如果没有则一直执行渲染指令
 while(!glfwWindowShouldClose(window)){
 //视口颜色清除
 glClear(GL_COLOR_BUFFER_BIT);
 //交互颜色缓冲，每次覆盖迭代缓冲中存储的每个视口像素的颜色值，输出到屏幕上
 glfwSwapBuffers(window);
 //检测有没有事件的触发，用户输入，窗口更新等，并调用相应的回调，可以通过注册的方式对回调的执行做控制  
 glfwPollEvents();
}
```   
7. **渲染完成，释放资源**      
```c++
 glfwTerminate();
```
   
   
   

