//
//  MyArray.cpp
//  15_ArrayOperatorOverload
//
//  Created by marker on 2019/6/1.
//  Copyright © 2019年 majortom. All rights reserved.
//

#include "MyArray.hpp"
#include <iostream>

using namespace std;
MyArray::MyArray(int _length){
    if(_length<0)
        this->length=0;
    this->length=_length;
    this->space=new int[length];
}

MyArray::MyArray(const MyArray &_MyArray){
    cout<<"Copy Constructor Function"<<endl;
    this->length=_MyArray.length;
    //指针成员的拷贝构造函数深拷贝
    this->space=new int[length];
    for(int i=0;i<length;i++){
        this->space[i]=_MyArray.space[i];
    }
}

MyArray::~MyArray(){
    this->length=0;
    if(this->space!=NULL)
        delete [] this->space;
    this->space=NULL;
}

void MyArray::SetData(int _index, int _value){
    this->space[_index]=_value;
}

int MyArray::GetData(int _index){
    return this->space[_index];
}

int MyArray::Length(){
    return this->length;
}

MyArray & MyArray::operator=(const MyArray & a1){
    cout<<"operator overload function"<<endl;
    if(this->space!=NULL)
        delete [] this->space;
    this->length=a1.length;
    this->space=new int[this->length];
    for(int i=0;i<this->length;i++){
        this->space[i]=a1.space[i];
    }
    return *this;
}

//a[i]=i;  函数返回值当左值，需要传递引用类型数据
int& MyArray::operator[](int index){
    return this->space[index];
}

bool MyArray::operator==(const MyArray & a1){
    if(this->length!=a1.length)
        return false;
    for(int i=0;i<this->length;i++){
        if(this->space[i]!=a1.space[i]){
            return false;
        }
    }
    return true;
}

bool MyArray::operator!=(const MyArray & a1){
    return !(*this==a1);
}
