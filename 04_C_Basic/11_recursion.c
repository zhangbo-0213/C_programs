#include <stdio.h>
int sum(int n);
int main(){
	printf("请输入一个正整数:\n");
	int n=0;
	scanf("%d",&n);
	printf("该正整数到零的连续和为:%d\n",sum(n));
	return 0;
}

//递归函数
int sum(int n){
	if(n==1)
		return 1;
	return sum(n-1)+n;
}
