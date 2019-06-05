//
//  main.cpp
//  06_FunctionReload
//
//  Created by marker on 2019/4/22.
//  Copyright © 2019年 majortom. All rights reserved.
//

#include <iostream>
using namespace std;


void MyFunc(int a){
    cout<<"Func_0:"<<a<<endl;
}

void MyFunc(int a,int b){
    cout<<"Func_1:"<<a<<"   "<<b<<endl;
}

int main(int argc, const char * argv[]) {
    //使用类型定义，去定义一个类型的函数指针    
    typedef void(*Func)(int);
    //定义一个函数指针
    //void (*Func)(int);
    Func func=MyFunc;
    func(10);
    
    void (*Func2)(int,int);
    Func2=MyFunc;
    Func2(10,20);
    return 0;
}
