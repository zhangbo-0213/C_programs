//
//  Complex.cpp
//  14_operatorOverload
//
//  Created by marker on 2019/5/26.
//  Copyright © 2019年 majortom. All rights reserved.
//

#include "Complex.hpp"
#include <iostream>

using namespace std;
Complex::Complex(int _a, int _b){
    this->a=_a;
    this->b=_b;
}

void Complex::PrintComplex(){
    cout<<this->a<<" + "<<this->b<<"i"<<endl;
}

Complex Complex::operator +(const Complex & c1){
    Complex temp(this->a+c1.a,this->b+c1.b);
    return temp;
}

Complex Complex::operator++(){
    ++this->a;
    ++this->b;
    return *this;
}

Complex Complex::operator++(int){
    Complex temp=*this;
    this->a++;
    this->b++;
    return temp;
}

Complex Complex::operator=(Complex c1){
    cout<<"operator = overload function"<<endl;
    //无指针成员，使用浅拷贝
    //如果使用深拷贝，先释放掉自身指针的内存，再根据传入对象的指针成员内存空间长度，开辟新的内存空间
    this->a=c1.a;
    this->b=c1.b;
    return *this;
}

//--------------------------------------------------

Complex operator - (const Complex & c1,const Complex & c2){
    Complex temp(c1.a-c2.a,c1.b-c2.b);
    return temp;
}

Complex  operator --(Complex & c1){
    --c1.a;
    --c1.b;
    return c1;
}

Complex  operator --(Complex & c1,int){
    Complex temp=c1;
    c1.a--;
    c1.b--;
    return temp;
}

ostream & operator <<(ostream & out,Complex c1){
    out<<"Custom friend Operator << Function:"<<c1.a<<"+"<<c1.b<<"i"<<endl;
    return out;
}
