#include <stdio.h>
int main(){
	int i=0;
	printf("请输入※的行数：");
	scanf("%d",&i);
	for(int j=i;j>0;j--){
		for(int k=i-j;k>0;k--){
			printf(" ");	
		}
		for(int p=0;p<2*j-1;p++){			
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
