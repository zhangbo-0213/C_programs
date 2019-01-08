#include <stdio.h>

int main(){
	printf("3-1000的素数:\n");
	int count=0;
	for(int i=3;i<1000;i++){
		int isPrime=1;
		for(int j=2;j<i;j++){
			if(i%j==0){
				isPrime=0;
				break;
			}
		}
		if(isPrime){
			printf("%3d    ",i);
			count++;
			if(count==10){
				printf("\n");
				count=0;
			}
		}

	}
	printf("\n");
	return 0;
}
