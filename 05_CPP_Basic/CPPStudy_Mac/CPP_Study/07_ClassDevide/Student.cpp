//
//  Student.cpp
//  07_ClassDevide
//
//  Created by marker on 2019/4/24.
//  Copyright © 2019年 majortom. All rights reserved.
//

#include "Student.hpp"
void Student::SetAge(int age){
    _age=age;
}

int Student::GetAge(){
    return _age;
}

void Student::SetName(char *name){
    _name=name;
}

char* Student::GetName(){
    return _name;
}
