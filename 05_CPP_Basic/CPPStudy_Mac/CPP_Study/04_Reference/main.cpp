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

int GetStackA(){
    int a=10;
    return a;
}

int & GetStackRefA(){
    int a=10;
    return a;
}

int & GetStaticA(){
    static int a=10;
    return a;
}
int main(int argc, const char * argv[]) {
    
    //引用语法 Type & name=var;
    int a=10;
    //普通引用必须要做初始化4
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
    
    cout<<"--------------------"<<endl;
    int stackA=GetStackA();
    int refA=GetStackRefA();
    int &refA1=GetStackRefA();
    int &refStaticA=GetStaticA();
    
    printf("stackA=%d,refA=%d,&refA1=%d,&refStaticA=%d\n",stackA,refA,refA1,refStaticA);
    printf("refStaticA()=%d\n",GetStaticA()=100);
    
    //常引用
    //常引用的初始化分两种情况：
    //1.使用变量初始化
    int val=20;
    //使用变量初始化常引用，使得引用所指内容为只读，即不能通过 常引用去改变 变量的值
    const int &r_val=val;
    //使用常引用去改变变量的值，编译不通过
    //r_val=30;
    //但是可以通过变量自身去改变 其值，引用的本质只是记录了该变量的内存地址
    val=30;
    
    //2.使用常值（字面量）初始化
    //直接使用字面量去初始化 对应类型的引用 是无法通过的，由于字面量，系统并为为其分配内存，因此初始化引用，无法拿到地址
    //在类型前加上 const 常量在取地址时，会为其分配内存空间
    const int &r_val1=43;
    cout<<"val:"<<r_val1<<endl;
    
    return 0;
}
