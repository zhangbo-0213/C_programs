//
//  main.cpp
//  13_FriendFunction
//
//  Created by marker on 2019/5/11.
//  Copyright © 2019年 majortom. All rights reserved.
//

#include <iostream>
#include "FriendTest.hpp"

using namespace std;

//有元函数定义在类的内部，非类的成员函数，可以访问类的书有访问修饰符的数据成员
// 由于非类的成员函数，通过类对象参数来访问数据成员
void ModifyValue(FriendTest *F,int a,int b){
    F->a=a;
    F->b=b;
}

int main(int argc, const char * argv[]) {
    
    FriendTest f(10,20);
    f.PrintValue();
    ModifyValue(&f, 40, 50);
    f.PrintValue();
    
    FriendTest2 t2(2,3);
    t2.SetValue(70, 80);
    t2.Print();
    return 0;
}
