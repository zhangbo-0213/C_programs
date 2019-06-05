//
//  Test.cpp
//  08_ConstructorAndDestructor
//
//  Created by marker on 2019/4/28.
//  Copyright © 2019年 majortom. All rights reserved.
//

#include "Test.hpp"
using namespace std;
//构造函数
Test::Test(){}
//构造函数 成员初始化 重载
Test::Test(const char* str){
    p=(char *)malloc(20);
    strcpy(p, str);
    cout<<"p:"<<p<<endl;
    cout<<"Constructor Function is called!"<<endl;
}
//copy构造函数，使用一个对象给另一个对象做初始化时调用
Test::Test(const Test &t){
    p=t.p;
    cout<<"Copy Constructor Function is called!"<<endl;
}

//析构函数 释放资源
Test::~Test(){
    //free(p);
    //由于copy构造函数使用浅拷贝，对于指针成员进行简单的值复制，导致通过另一个对象来初始化的对象的指针成员
    //指向同一个内存空间，当这两个对象被释放时，同一内存空间会被释放多次，抛出异常
    cout<<"Destructor Function is callled!"<<endl;
}

void Test::SetP(char *str){
    p=str;
}

char* Test::GetP(){
    return p;
}
