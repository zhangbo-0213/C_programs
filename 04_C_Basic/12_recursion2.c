#include <stdio.h>
#include <string.h>

int mystrlen(char str[],int n);
int main(){
	printf("输入一段字符串:\n");
	char str[100]; 
	//fgets吃回车
	fgets(str,sizeof(str),stdin);
	
	int len=mystrlen(str,0);
	printf("字符串的长度是:%d\n",len-1);
	return 0;
}
//递归求字符串长
int mystrlen(char str[],int n){
	if(str[n])
		return mystrlen(str,n+1);
	else{
		return n;
	}
}
