#include <stdio.h>
int* ArrayInverse(int *s);
void PrintfArray(int *s);
int main(){
	int s[9]={18,38,534,93,234,67,3,57,9};
	PrintfArray(s);
	printf("\n");
	int *s2=ArrayInverse(s);
	PrintfArray(s2);
	printf("\n");
	return 0;
}

int* ArrayInverse(int *s){
	int *start=&s[0];
	int *end=&s[8];
	while(start<end){
		int tmp=*start;
		*start=*end;
		*end=tmp;
		start++;
		end--;
	}
	return s;
}

void PrintfArray(int *s){
	while(*s){
		printf("%d-",*s);
		s++;
	}
}
