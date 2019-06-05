//
//  main.cpp
//  08_ConstructorAndDestructor
//
//  Created by marker on 2019/4/28.
//  Copyright © 2019年 majortom. All rights reserved.
//

#include <iostream>
#include "Test.hpp"
using namespace std;

void Function(Test t){
    cout<<t.GetP()<<endl;
}

/**
 返回匿名对象测试函数
 @return 返回一个匿名对象
 */
Test Function2(){
    Test test("Bob");
    return test;   //该操作返回匿名对象 test对象初始化匿名对象 调用copy构造函数，函数释放时，释放test 和匿名对象 两个对象，调用两次析构函数
}
int main(int argc, const char * argv[]) {
    
    Test test("MajorTom");
    Test test2=test;
    Test test3(test2);
    Function(test3);
    cout<<"test2 p:"<<test2.GetP()<<endl;
    Function2();
    //Test test4;
    //test4=Function2();
    //cout<<test4.GetP()<<endl;
    Test test5("Jerry");
    test5=Function2();
    cout<<"~~~~"<<endl;
    return 0;
}
