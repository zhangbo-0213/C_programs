#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	//得到系统时间值
	time_t st=time(NULL);
	//随机数发生器种子，与rand配合使用,在每次调用rand()函数时
	//如果srand()中的参数与上次不同，则会产生不同的随机数
	srand(st);
	for(int i=0;i<10;i++){
		printf("%d\n",rand()%10);
	}
	return 0;
}
