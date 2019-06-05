//
//  Person.cpp
//  11_static
//
//  Created by marker on 2019/5/6.
//  Copyright © 2019年 majortom. All rights reserved.
//

#include "Person.hpp"

Person::Person(int _a,int _b){
    //对象成员函数隐式传入指向当前对象的 指针 *this
    this->a=_a;
    this->b=_b;
}

void Person::AddC() const{
    //this->a++;  const成员函数内，不允许修改 非static 数据成员
    printf("a:%d\n",this->a);
    this->c++;  // c为静态数据成员
    printf("c:%d\n",c);
}

void Person::AddCDouble(){
    c=c+2;
    printf("c:%d\n",c);
}

Person & Person::AddResult(Person p){
    this->a+=p.a;
    this->b+=p.b;
    return *this;
}
