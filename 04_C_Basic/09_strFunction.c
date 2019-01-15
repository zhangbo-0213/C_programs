#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int WhichChar(char c);
int factorial(int a,int num);
int main(){
	char chars[100];
	printf("输入数字字符串：\n");
	fgets(chars,sizeof(chars),stdin);
	int len=0;
	while(chars[len++]);
	len--;
	printf("len:%d\n",len);
	int sum=0;
	for(int i=0;i<len-1;i++){
		sum+=WhichChar(chars[i])*factorial(10,len-i-2);
	}
	printf("转化后的数：%d\n",sum);
	return 0;
}

int factorial(int a,int num){
	int s=1;
	int i=0;
	while(i<num){
		s*=a;
		i++;
	}
	return s;
}

int WhichChar(char c){
	int i=0;
	switch(c){
		case '0':
	         i=0;
		 break;
		case '1':
		 i=1;
		 break;
		case '2':
		 i=2;
		 break;
		case '3':
                 i=3;
                 break;
		case '4':
                 i=4;
                 break;
		case '5':
                 i=5;
                 break;
		case '6':
                 i=6;
                 break;
		case '7':
                 i=7;
                 break; 
		case '8':
                 i=8;
                 break;
	 	case '9':
                 i=9;
                 break;	 
	}
	return i;
}
