#include <stdio.h>

int main(){
	char c='c';
	printf("%c\n",c);
	printf("字符类型数据在内存中所占空间为:%d 字节\n",(int)sizeof(c));
	return 0;
}
