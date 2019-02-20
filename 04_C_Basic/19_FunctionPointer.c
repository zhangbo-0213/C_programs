#include <stdio.h>

int add(int a,int b){
	return a+b;
}

int max(int a,int b){
	return a>b?a:b;
}
int main(){
	//定义一个指向函数的指针
	int (*fp)(int,int);
	int status=0;
	scanf("%d",&status);
	if(status==0)
		//函数指针在赋值时，直接将函数名赋值给指针变量
		fp=add;
	else
		fp=max;
	int res=fp(5,7);
	printf("res=%d\n",res);
	return 0;
}
