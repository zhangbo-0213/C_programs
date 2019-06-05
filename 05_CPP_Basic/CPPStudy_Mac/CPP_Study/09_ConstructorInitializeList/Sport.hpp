//
//  Sport.hpp
//  09_ConstructorInitializeList
//
//  Created by marker on 2019/5/3.
//  Copyright © 2019年 majortom. All rights reserved.
//

#ifndef Sport_hpp
#define Sport_hpp

#include <stdio.h>
#include "Badminton.hpp"
#include "Swiming.hpp"
class Sport{
public:
    Sport(char * _name,int year,int year1,int year2);
private:
    char* name;
    const int year;
    Badminton badminton;
    Swiming swiming;
};
#endif /* Sport_hpp */
