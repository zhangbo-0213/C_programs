//
//  main.cpp
//  10_newAnddelete
//
//  Created by marker on 2019/5/5.
//  Copyright © 2019年 majortom. All rights reserved.
//

#include <iostream>
#include "Student.hpp"
using namespace std;
int main(int argc, const char * argv[]) {
    //1. new 基础类型
    //使用new操作符对变量初始化的方式
    int *p=new int;
    *p=20;
    int *p1=new int(20);
    delete p;
    delete p1;
    
    //2.new 数组变量
    //c语言方式：
    int *array=(int *)malloc(sizeof(int)*10);
    array[0]=10;
    free(array);
    //c++ new:
    int *array2=new int[10];
    array2[0]=20;
    printf("array2[0]=%d\n",array2[0]);
    delete[] array2;
    
    //3.new 对象   
    Student *stu=new Student((char *)"MajorTom",18);
    delete stu;
    return 0;
}
