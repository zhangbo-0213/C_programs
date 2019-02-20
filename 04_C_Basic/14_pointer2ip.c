#include <stdio.h>

void ip2str(int ip);
int str2ip(char *s);

int main(){
	int ip=0;
	unsigned char* p=&ip;
	*p=192;
	p++;
	*p=168;
	p++;
	*p=1;
	p++;
	*p=1;
	printf("ip=%d\n",ip);

	ip2str(ip);

	char *str="192.168.23.56";
	int ip2=str2ip(str);
	printf("ip2-int:%d\n",ip2);
	return 0;
}

void ip2str(int ip){
	unsigned char* p=&ip;
	printf("ip=%d.%d.%d.%d\n",*p,*(p+1),*(p+2),*(p+3));
}

int str2ip(char *s){
	int a=0;
	int b=0;
	int c=0;
	int d=0;
	sscanf(s,"%d.%d.%d.%d",&a,&b,&c,&d);
	printf("ip:%d-%d-%d-%d\n",a,b,c,d);
	int re=0;
	unsigned char *p=&re;
	*p=a;
	p++;
	*p=b;
	p++;
	*p=c;
	p++;
	*p=d;
	return re;
}
