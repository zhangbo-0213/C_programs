#include <stdio.h>

int main(){
	int buf[3][5]={{2,4,3,5,3},{7,2,6,8,1},{7,3,9,0,2}};
	int (*p)[5]=buf;
	for(int i=0;i<3;i++){
		printf("第%d行: ",i);
		for(int j=0;j<5;j++){
			printf("%d ",*(*(p+i)+j));
		}
		printf("\n");
	}
	
	for(int i=0;i<3;i++){
		int sum=0;
                for(int j=0;j<5;j++){
                        sum+=*(*(p+i)+j);
                }
		printf("第%d行平均值: %f\n",i,sum/5.0);

        }

	for(int i=0;i<5;i++){
                int sum=0;
                for(int j=0;j<3;j++){
                        sum+=*(*(p+j)+i);
                }
                printf("第%d列平均值: %f\n",i,sum/3.0);

        }

	return 0;
}
