#include <stdio.h>
#include "0_custom.h"

int main(){
	printf("请输入汉字:\n");
	char str[100];
	fgets(str,sizeof(str),stdin);
	printf("输入的内容是：%s\n",str);
	int len=GetCharArrayLength(str)-1;

	char *start=str;
	char *end=str+len-1;

	while(start<end-2){
		int tmp=*start;
		int tmp1=*(start+1);
		int tmp2=*(start+2);

		*start=*(end-2);
		*(start+1)=*(end-1);
		*(start+2)=*end;
		
		*(end-2)=tmp;
		*(end-1)=tmp1;
		*end=tmp2;
		
		start+=3;
		end-=3;
	}

	printf("转置后的字符串:%s\n",str);

	return 0;
}
