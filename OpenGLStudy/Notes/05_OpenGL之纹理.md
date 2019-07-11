### **OpenGL之纹理**    
- 为了能够把纹理映射(Map)到三角形上，需要指定三角形的每个顶点各自对应纹理的哪个部分。这样每个顶点就会关联着一个纹理坐标(Texture Coordinate)，用来标明该从纹理图像的哪个部分采样。之后在图形的其它片段上进行片段插值(Fragment Interpolation)。           
- 纹理坐标的范围从 (0,0)到(1,1) ,分别对应纹理的左下角和右上角      

**纹理环绕方式**     
当纹理的坐标范围超出 (0,0)到(1,1)的范围后，超出范围后的纹理坐标部分的表现由 纹理的环绕方式决定，不同的纹理环绕方式，其表现方式不同：   
环绕方式                                描述         
GL_REPEAT                          对纹理的默认行为。重复纹理图像       
GL_MIRRORED_REPEAT     和GL_REPEAT一样，但每次重复图片是镜像放置的          
GL_CLAMP_TO_EDGE         纹理坐标会被约束在0到1之间，超出的部分会重复纹理坐标的边缘，产生一种边缘被拉伸的效果             
GL_CLAMP_TO_BORDER    超出的坐标为用户指定的边缘颜色           

纹理环绕方式的设定：      
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);    
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);     
S和T 分别对应两个轴向，如果是三维纹理，还对应 R 轴向        

如果使用   GL_CLAMP_TO_BORDER   的环绕方式后，还需要指定超出部分边框的颜色      
float borderColor[] = { 1.0f, 1.0f, 0.0f, 1.0f };           
glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);            

**纹理过滤**       
纹理坐标不依赖于分辨率(Resolution)，它可以是任意浮点值，所以OpenGL需要知道怎样将纹理像素(Texture Pixel，也叫Texel，译注1)映射到纹理坐标。当有一个很大的物体但是纹理的分辨率很低的时候这就变得很重要,OpenGL中常用的两种纹理过滤方式：    
- GL_NEAREST（也叫邻近过滤，Nearest Neighbor Filtering）是OpenGL默认的纹理过滤方式。当设置为GL_NEAREST的时候，OpenGL会选择中心点最接近纹理坐标的那个像素。       
- GL_LINEAR（也叫线性过滤，(Bi)linear Filtering）它会基于纹理坐标附近的纹理像素，计算出一个插值，近似出这些纹理像素之间的颜色。          

GL_NEAREST产生颗粒状的图案，能够清晰看到组成纹理的像素，而GL_LINEAR能够产生更平滑的图案，很难看出单个的纹理像素。       

设置纹理过滤的方式:        
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);      
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);        

**多级渐远纹理**     
OpenGL提供多级渐远纹理技术来使同一张纹理在近处拥有高分辨率，远处分辨率渐低，在节约内存的同时，视觉效果也更加真实。其具体原理是：    
距观察者的距离超过一定的阈值，OpenGL会使用不同的多级渐远纹理，即最适合物体的距离的那个。由于距离远，解析度不高也不会被用户注意到。同时，多级渐远纹理另一加分之处是它的性能非常好。          
OpenGL通过glGenerateMipmaps函数，在创建完一个纹理后调用它，OpenGL自动创建多级渐远纹理。        
OpenGL在两个不同级别的多级渐远纹理层之间会产生不真实的生硬边界。就像普通的纹理过滤一样，切换多级渐远纹理级别时可以在两个不同多级渐远纹理级别之间使用NEAREST和LINEAR过滤         

glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);   
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);   

需要注意的是，多级渐远纹理只有在纹理被缩小的情况下设置才能生效      

**纹理加载与创建过程**           
```c++      
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
//设置纹理翻转（纹理坐标和opengl坐标在竖直方向上相反）
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
```

**纹理采样器与纹理单元**      
当需要使用的纹理超过一张时，通过设置纹理单元来使用多张纹理。        
纹理单元的主要目的是让我们在着色器中可以使用多于一个的纹理。通过把纹理单元赋值给采样器，我们可以一次绑定多个纹理，只要我们首先激活对应的纹理单元。就像glBindTexture一样，我们可以使用glActiveTexture激活纹理单元，传入我们需要使用的纹理单元：         

glActiveTexture(GL_TEXTURE0); // 在绑定纹理之前先激活纹理单元      
glBindTexture(GL_TEXTURE_2D, texture);       

通过设置片元着色器中的 uniform sampler2d 采样器来接收 :     

```c++
//激活纹理单元，并进行纹理绑定
glActiveTexture(GL_TEXTURE0);
glBindTexture(GL_TEXTURE_2D,texture1);
glActiveTexture(GL_TEXTURE1);
glBindTexture(GL_TEXTURE_2D,texture2);

//设置纹理采样器所属纹理单元,这样不同的纹理采样器在不同的纹理单元中找到对应的纹理
//在设置纹理采样器所属纹理单元前，先激活shader 程序
glUniform1i(glGetUniformLocation(outShader.ID,"texture1"),0);
outShader.SetInt("texture2", 1);
```   
当只有一张纹理时，纹理单元 GL_TEXURE0 总是默认被激活，唯一的sampler2D采样器也会自动与该纹理单元关联     

