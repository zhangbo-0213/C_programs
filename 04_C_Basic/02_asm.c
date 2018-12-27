#include <stdio.h>
int main(){
	int i;
	asm
	{
		mov i, 10
		mov eax, i
		add eax, 30
		mov i, eax
	}
	printf("i 的值为:%d\n",i);
	return 0;
}
