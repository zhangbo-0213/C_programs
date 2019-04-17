//
//  main.cpp
//  02_const
//
//  Created by marker on 2019/4/17.
//  Copyright © 2019年 majortom. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {

    //C++ 中 const 分配内存的时机在 编译期间
    int a;
    const int b=10;
    int c;
    
    printf("a=%p  b=%p  c=%p\n",&a,&b,&c);
    
    return 0;
}
