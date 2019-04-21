//
//  main.cpp
//  05_SecondPointer
//
//  Created by marker on 2019/4/21.
//  Copyright © 2019年 majortom. All rights reserved.
//

#include <iostream>
using namespace std;

struct Student{
    char name[20];
    int age;
};

//一级指针传递后，若实参没有被分配内存空间，形参拷贝实参地址，改变的只是形参所指向的内存空间的内容
//函数调用完毕后，形参被栈空间释放，实参实际还是未被分配空间
int  SetStudentA(Student *p){
    Student *tmp=NULL;
    tmp=(Student *)malloc(sizeof(Student));
    if(tmp==NULL)
        return -1;
    tmp->age=30;
    p=tmp;
    return 0;
}

int SetStudentB(Student **p){
    Student *tmp=NULL;
    tmp=(Student *)malloc(sizeof(Student));
    if(tmp==NULL)
        return -1;
    tmp->age=40;
    *p=tmp;
    return  0;
}

//指针的引用做参数值，相当于传递二级指针
int SetStudentC(Student* &p){
    p=(Student *)malloc(sizeof(Student));
    if(p==NULL)
        return -1;
    p->age=50;
    return 0;
}

int main(int argc, const char * argv[]) {
    Student *stu1=NULL;
    //Student stu2={"Tom",10};
    //stu1=&stu2;
    cout<<"Call SetStudentA"<<endl;
    SetStudentA(stu1);
    //cout<<"Age: "<<stu1->age<<endl;
    cout<<"Call SetStdentB"<<endl;
    SetStudentB(&stu1);
    cout<<"Age: "<<stu1->age<<endl;
    cout<<"Call SetStudentC"<<endl;
    SetStudentC(stu1);
    cout<<"Age: "<<stu1->age<<endl;
    
    return 0;
}
