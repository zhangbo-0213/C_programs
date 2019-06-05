//
//  Student.hpp
//  07_ClassDevide
//
//  Created by marker on 2019/4/24.
//  Copyright © 2019年 majortom. All rights reserved.
//

#ifndef Student_hpp
#define Student_hpp  //避免重复包含引用  相同作用的预编译指令  #pragma once

class Student{
private:
    int _age;
    char *_name;
    
public:
    void SetAge(int age);
    int GetAge();
    void SetName(char *name);
    char* GetName();
};

#endif /* Student_hpp */
