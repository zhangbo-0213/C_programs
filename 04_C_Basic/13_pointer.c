#include <stdio.h>

int main(){
	int a=0,b=1;
	int c[10];
	printf("%p %p %p\n",&a,&b,&c);
	int *p=&a;
	printf("a=%d\n",a);
	*p=10;
	printf("*p=10,a=%d\n",a);

	printf("---------------\n");
	printf("int数组ｃ的地址：%p\n",c);
	printf("c[0]地址:%p\n",&c[0]);
	printf("c[1]地址:%p\n",&c[1]);

	printf("---------------\n");
	printf("&(c+1):%p\n",(c+1));
	printf("&(c[0]+1):%p\n",&c[0]+1);
	int d[10];
	return 0;
}
