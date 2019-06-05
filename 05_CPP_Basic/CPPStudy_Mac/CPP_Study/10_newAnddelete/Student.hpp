//
//  Student.hpp
//  10_newAnddelete
//
//  Created by marker on 2019/5/5.
//  Copyright © 2019年 majortom. All rights reserved.
//

#ifndef Student_hpp
#define Student_hpp

#include <stdio.h>
class Student{
public:
    Student(char *name,int age);
    ~Student();
private:
    char *_name;
    int _age;
};
#endif /* Student_hpp */
