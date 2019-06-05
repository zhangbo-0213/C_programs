### new与delete操作符   对象的动态建立与释放      
- new 操作符开辟堆内存空间，返回指定类型开辟的空间的首地址：       
```c++
//1. new 基础类型
//使用new操作符对变量初始化的方式
int *p=new int;
*p=20;
int *p1=new int(20);   
delete p;
delete p1;

//2.new 数组
//c语言方式：
int *array=(int *)malloc(sizeof(int)*10);
array[0]=10;
free(array);
//c++ new:
int *array2=new int[10];
array2[0]=20; 
delete[] array2; //数组的释放，在使用delete操作符时，要带 [] 

//3.new 对象   
Student *stu=new Student((char *)"MajorTom",18);
delete stu;   
//new 操作符在动态创建对象时，会调用对象的构造函数,使用malloc开辟堆内存则不会调用构造函数       
//delete 操作符在回收对象时，会调用对象的析构函数,使用free释放内存空间则不会调用析构函数       
```
