#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char str[1024]={0};
    //以写的方式打开文件
    FILE *p=fopen("/home/majortom/projects/C_Programs/Notes/C_C++/a.txt","w");
    //向文件写入字符串 w 表示如果文件不存在就建立新的文件，如果存在则覆盖
    while(1){
        memset(str,0,sizeof(str));
        gets(str);
        if(strcmp("exit",str)==0)
            break;
        int len=strlen(str);
        str[len]='\n';
        fputs(str,p);
    }
    //关闭文件
    fclose(p);
    printf("end\n");

    printf("写入的文件内容为：\n");
    //以读的方式打开文件
    FILE *s=fopen("/home/majortom/projects/C_Programs/Notes/C_C++/a.txt","r");
    //feof(s) 判断是否到了文件结尾，如果到了结尾就返回　true 否则就返回 false
    while(!feof(s)){
    	memset(str,0,sizeof(str));
	//fgets函数　第一个参数是　用来接收的字符串的内存地址，
	//第二个参数为地址长度，第三个为打开的文件句柄
	fgets(str,sizeof(str),s);
	printf("%s",str);
    }
    //关闭文件
    fclose(s);
    return 0;
}
