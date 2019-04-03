### typedef  

typedef 用于将已有的类型进行自定义

- typedef  char BYTE; //定义一个新的数据类型，名字为BYTE,类型为 char 

- typedef struct {

​	char a;

​	int b;

​	} A

​	//定义一个新的数据类型，名字为Ａ，类型为struct ，成	员	为　char  a ,int b 

- typedef unsigned int UINT;  

- typedef  char * (*STRCAT) (char *,char *); //自定义一个指向函数的指针

   char *test(START p,char *s1,char *s2) {

  ​	return p(s1,s2);

  }



### #define    

#define 一般用于宏定义常量，属于编译指令，在编译时会进行对应的文本替换