//
//  Student.cpp
//  10_newAnddelete
//
//  Created by marker on 2019/5/5.
//  Copyright © 2019年 majortom. All rights reserved.
//

#include "Student.hpp"
#include <iostream>

using namespace std;

Student::Student(char *name,int age){
    _name=name;
    _age=age;
    cout<<"My name:"<<_name<<" and My age:"<<age<<endl;
}

Student::~Student(){
    cout<<"This Object has been delete"<<endl;
}
