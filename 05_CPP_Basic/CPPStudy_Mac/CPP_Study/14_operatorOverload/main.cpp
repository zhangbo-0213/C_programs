//
//  main.cpp
//  14_operatorOverload
//
//  Created by marker on 2019/5/26.
//  Copyright © 2019年 majortom. All rights reserved.
//

#include <iostream>
#include "Complex.hpp"
using namespace std;
int main(int argc, const char * argv[]) {
    Complex c1(2,4);
    Complex c2(3,6);
    Complex c3=c1+c2;
    c3.PrintComplex();
    c3=c1-c2;
    c3.PrintComplex();
    ++c3;
    c3.PrintComplex();
    --c3;
    c3.PrintComplex();
    c3++;
    c3.PrintComplex();
    c3--;
    c3.PrintComplex();
    cout<<c3<<"123"<<endl;
    return 0;
}
