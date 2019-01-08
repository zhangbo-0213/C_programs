#include <stdio.h>
int main(){
	char chars[100]={0};
	printf("chars: %s\n",chars);
	printf("请输入字符串：\n");
	fgets(chars,sizeof(chars)-1,stdin);
	int len=0;
	//得到空字符长度
	while(chars[len++]==' ');
	len--;
	int i=len;
	while(chars[i]!=0){
		chars[i-len]=chars[i];
		i++;
	}
	chars[i-len]=0;
	printf("去掉字符串之前的空格后的字符串:%s \n",chars);
	return 0;
}
