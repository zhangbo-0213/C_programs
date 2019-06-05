//
//  main.cpp
//  11_static
//
//  Created by marker on 2019/5/6.
//  Copyright © 2019年 majortom. All rights reserved.
//

#include <iostream>
#include "Person.hpp"
using namespace std;

//类的静态成员在使用前一定要进行声明
int Person::c;

int main(int argc, const char * argv[]) {
    
    Person::c=10;
    Person person1(1,2);
    person1.AddC();
    Person person2(3,4);
    person2.AddC();
    Person::AddCDouble();
    
    Person & person3=person1.AddResult(person2);
    cout<<"person1 add :"<<&person1<<endl;
    cout<<"person3 add :"<<&person3<<endl;
    return 0;
}
