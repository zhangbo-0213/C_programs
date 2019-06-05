//
//  Sport.cpp
//  09_ConstructorInitializeList
//
//  Created by marker on 2019/5/3.
//  Copyright © 2019年 majortom. All rights reserved.
//

#include "Sport.hpp"
#include <iostream>
using namespace std;
Sport::Sport(char *name,int year,int year1,int year2):year(year),swiming(year2),badminton(year1){
    cout<<"PlayerName:"<<name<<endl;
}
