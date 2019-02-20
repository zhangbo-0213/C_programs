#include <stdlib.h>

int GetCharArrayLength(char *str){
	int len=0;
	while(*(str+len)){
		len++;
	}
	return len;
} 

int GetIntArrayLength(int *array){
	int len=0;
	while(*(array+len)){
		len++;
	}
	return len;
}
