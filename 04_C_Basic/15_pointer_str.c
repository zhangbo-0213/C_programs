//指针实现求字符串的长度
//指针实现字符串长度的叠加

#include <stdio.h>
#include <string.h>
int GetSrtLen(char *s);
char* StrJoint(char *s1,char*s2);

int main(){
	char s1[100]="hello-";
	char s2[100]="world";
	printf("s1:%s\n",s1);
	int len1=GetStrLen(s1);
	printf("s2:%s\n",s2);
	int len2=GetStrLen(s2);

	printf("after joint:\n");
	printf("%s\n",StrJoint(s1,s2));

	return 0;
}

int GetStrLen(char *s){
	int len=0;
	while(*s){
		s++;
		len++;
	}
	printf("the length of str:%d\n",len);
	return len;
}

char * StrJoint(char *s1,char* s2){
	int len1=GetStrLen(s1);
	int len2=GetStrLen(s2);
	for(int i=0;i<len2;i++){
		*(s1+len1+i)=*(s2+i);
	}
	return s1;
}
