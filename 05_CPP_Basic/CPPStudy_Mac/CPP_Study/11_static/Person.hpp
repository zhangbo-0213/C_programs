//
//  Person.hpp
//  11_static
//
//  Created by marker on 2019/5/6.
//  Copyright © 2019年 majortom. All rights reserved.
//

#ifndef Person_hpp
#define Person_hpp

#include <stdio.h>

class Person{
public:
    static int c;
    Person(int a,int b);
    Person  & AddResult(Person p);
    void AddC() const;
    static void AddCDouble();
private:
    int a,b;
};
#endif /* Person_hpp */
