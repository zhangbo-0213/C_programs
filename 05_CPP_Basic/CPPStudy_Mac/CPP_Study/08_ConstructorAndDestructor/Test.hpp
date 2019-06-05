//
//  Test.hpp
//  08_ConstructorAndDestructor
//
//  Created by marker on 2019/4/28.
//  Copyright © 2019年 majortom. All rights reserved.
//

#ifndef Test_hpp
#define Test_hpp

#include <stdio.h>
#include <iostream>
class Test{
public:
    Test();
    Test(const char *p);
    Test(const Test &t);
    ~Test();
    
    void SetP(char *str);
    char* GetP();
    
private:
    char *p;
};
#endif /* Test_hpp */
