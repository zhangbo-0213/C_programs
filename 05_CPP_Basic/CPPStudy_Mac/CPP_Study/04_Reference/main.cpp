//
//  main.cpp
//  04_Reference
//
//  Created by marker on 2019/4/17.
//  Copyright © 2019年 majortom. All rights reserved.
//

#include <iostream>
using namespace std;

void swap01(int *a,int *b){
    int c=*a;
    *a=*b;
    *b=c;
}

//引用做函数参数时，不必初始化
void swap02(int &a,int &b){
    int c=a;
    a=b;
    b=c;
}
int main(int argc, const char * argv[]) {
    
    //引用语法 Type & name=var;
    int a=10;
    //普通引用必须要做初始化
    int &b=a;
    
    printf("b=%d\n",b);
    printf("a-add:%p  b-add:%p\n",&a,&b);
    
    b=100;
    
    printf("after b=100,a=%d\n",a);
    
    int c=20,d=30;
    printf("before swap: c=%d,d=%d\n",c,d);
    swap01(&c,&d);
    printf("after swap01: c=%d,d=%d\n",c,d);
    swap02(c,d);
    printf("after swap02: c=%d,d=%d\n",c,d);
    return 0;
}
