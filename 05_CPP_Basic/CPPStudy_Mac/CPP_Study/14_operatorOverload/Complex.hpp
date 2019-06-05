//
//  Complex.hpp
//  14_operatorOverload
//
//  Created by marker on 2019/5/26.
//  Copyright © 2019年 majortom. All rights reserved.
//

#ifndef Complex_hpp
#define Complex_hpp

#include <stdio.h>
#include <iostream>

using namespace std;
class Complex{
public:
    Complex(int,int);
    void PrintComplex();
    Complex operator +(const Complex&);
    Complex operator ++(); //++ 操作符前置重载
    Complex operator ++(int); //++ 操作符后置重载  (使用占位操作符)
    Complex  operator=(Complex);
    friend Complex operator -(const Complex &,const Complex &);
    friend Complex operator --(Complex &); //-- 操作符前置重载
    friend Complex operator --(Complex &,int); //-- 操作符后置重载  (使用占位操作符)
    friend ostream & operator <<(ostream &,Complex);
private:
    int a,b;
};


#endif /* Complex_hpp */
