#include <stdio.h>
int main(){
	char chars[100];
	printf("请输入字符：\n");
	scanf("%s",&chars[0]);	
	int len=0;
	while(chars[len++]);
	len--;
	printf("字符占用字节数为：%d\n",len);
	
	len=0;
	int i=0;
	while(chars[i]){
		if(chars[i]<0)
			i+=2;
		i++;
		len++;	
	}
	printf("字符个数为:%d\n",len);
	return 0;
}
