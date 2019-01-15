#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char s1[100]="___hello___";
	printf("s1:%s\n",s1);
	char *s2="world";
	printf("s2:%s\n",s2);
	printf("strncat(s1,s2):\n");
	printf("s1:%s\n\n",strncat(s1,s2,sizeof(s2)));

	printf("strncpy(s1,s2,3):\n");
	printf("s1:%s\n\n",strncpy(s1,s2,3));
	
	char s[100];
	printf("sprintf(s,\"i=d\",100)\n");
	sprintf(s,"i=%d",100);
	printf("s:%s\n\n",s);
	
	char *s3="89+90=";
	int a,b;
	printf("s3:%s\n",s3);
	printf("sscanf(s3,\"d+d\",&a,&b)\n");
	sscanf(s3,"%d+%d",&a,&b);
	printf("a=%d,b=%d\n\n",a,b);

	printf("strchr(s1,\'o\')\n");
	printf("%s\n\n",strchr(s1,'o'));

	printf("strstr(s1,\"el\")\n");
        printf("%s\n\n",strstr(s1,"el"));

	char *s4="hello_world_a_bc_defg";
	printf("s4:%s\n",s4);
	printf("strtok(s4,\"_\")\n");
	char* buf=strtok(s4,"_");
	printf("%s\n",buf);
	printf("strtok(NULL,\"_\")\n");
	while(buf){
		buf=strtok(NULL,"_");
		printf("%s\n",buf);
	}
	return 0;
}
