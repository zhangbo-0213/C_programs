### **OpenGL之VBO EBO ABO**    

**VBO**

定义

VBO就是用来管理存储在GPU的显存上的顶点内存=VBO代表着我们定义的顶点。

这样做的好处就是可以一次性发送大量顶点数据到显卡上，而不用每次发送一个。从CPU发送数据到显卡可是很慢的；因此我们也需要尽可能多地把所有顶点数据给VBO

具体代码操作流程

创建对象：
```c++
gluint VBO； //定义一个无符号整形VBO对象，其值为其ID
glGenBuffers(num, &VBO)；//分配num个VBO对象
```
绑定顶点缓冲：
```c++
glBindBuffer(GL_ARRAY_BUFFER,VBO)；//将VBO对象绑定到顶点缓冲
```
从此起，任何作用于顶点缓冲的操作，都会配置当前绑定的缓冲（VBO）。相当于状态设置。

复制数据给顶点缓冲：
```c++
glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
```
glBufferData是一个专门用来把用户定义的数据复制到当前绑定缓冲的函数:

第一个参数是目标缓冲的类型;
第二个参数指定传输数据的大小(以字节为单位);
第三个参数是我们希望发送的实际数据;
第四个参数指定了我们希望显卡如何管理给定的数据。

**EBO**

定义

EBO被设计用来存储顶点地顺序也就是索引（Element/Index）
根本目的是解决数据冗余地问题
类似于VBO
具体代码操作流程

创建对象：
```c++
unsigned int EBO;
glGenBuffers(1, &EBO); 
```
绑定缓冲：
```c++
glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
```
绑定数据：
```c++
glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
```

渲染：
```c++
glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
```
如果代码中需要索引来渲染，采用了EBO时，则需要用glDrawElements函数来代替glDrawArrays函数，来指明我们从索引缓冲渲染

在使用glDrawElements时，我们会使用当前绑定的索引缓冲对象中的索引进行绘制：

第一个参数指定了我们绘制的模式;
第二个参数是我们打算绘制顶点的个数;
第三个参数是索引的类型;
第四个参数可以指定EBO中的偏移量（或者传递一个索引数组，但是这是当你不在使用索引缓冲对象的时候），但是我们会在这里填写0

绑定VAO时也会自动绑定EBO
**不要在解绑VAO之前解绑索引数组缓冲（GL_ELEMENT_ARRAY_BUFFER），否则它就没有这个EBO配置了**

**VAO**

定义

顶点数据存储在VBO里面了，但是每次切换顶点缓冲对象都要重新配置其属性，这样很不方便，VAO可以解决这个问题，它记录了VBO及其属性配置。这样我们绘制一个物体时，只需要绑定相应的VAO就行了。
VAO至少有16个顶点属性
具体代码操作流程

创建对象
```c++
gLuint VAO;
glGenVertexArrays(1, &VAO); // 生成一个VAO
```
绑定到当前VAO
```c++
glBindVertexArray(VAO);
```
绑定一个IBO到当前VAO上
```c++
glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
```

启用相应的顶点属性
```c++
glEnableVertexAttribArray(0); 
glEnableVertexAttribArray(1);
glEnableVertexAttribArray(2);
//顶点属性默认是禁用的
// 0,1,2…代表着色器的input的location，分别代表顶点位置，顶点颜色，顶点纹理坐标; 
// 0,1,2也是顶点属性的位置值

告知计算机如何利用开启的顶点属性来理解这些顶点数据
```c++
glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, vertexes); 
glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, colores); 
glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, texCoordes);
//为属性0,1,2...指定相应的数据
```
glVertexAttribPointer函数：

第一个参数指定我们要配置的顶点属性；
第二个参数指定顶点属性的大小；
第三个参数指定数据的类型；
第四个参数定义我们是否希望数据被标准化(Normalize)；
第五个参数叫做步长(Stride)，它告诉我们在连续的顶点属性组之间的间隔，我们也可以设置为0来让OpenGL决定具体步长是多少（只有当数值是紧密排列时才可用）。这个参数的意思简单说就是从这个属性第二次出现的地方到整个数组0位置之间有多少字节
第六个参数表示位置数据在缓冲中起始位置的偏移量(Offset)。
注意

每个顶点属性从一个VBO管理的内存中获得它的数据，而具体是从哪个VBO（程序中可以有多个VBO）获取则是通过在调用glVetexAttribPointer时绑定到GL_ARRAY_BUFFER的VBO决定的

因此不同的VBO应该这样使用：

```c++
glBindBuffer(GL_ARRAY_BUFFER, vertexVBO); // 绑定位置VBO到当前的VAO上
glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0)); 
glBindBuffer(GL_ARRAY_BUFFER, colorVBO); // 绑定颜色VBO到当前的VAO上
glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
glBindBuffer(GL_ARRAY_BUFFER, textureVBO); // 绑定纹理VBO到当前的VAO上
glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0)); 
```
glEnableVertexAttribArray应该在glVertexAttribPointer之前还是之后调用？答案是都可以，只要在绘图调用（glDraw*系列函数）前调用即可   

一个顶点数组对象会储存以下这些内容：
- glEnableVertexAttribArray和glDisableVertexAttribArray的调用      
- 通过glVertexAttribPointer设置的顶点属性配置     
- 通过glVertexAttribPointer调用与顶点属性关联的**顶点缓冲对象**        

