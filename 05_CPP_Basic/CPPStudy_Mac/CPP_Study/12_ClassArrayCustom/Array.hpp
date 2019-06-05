//
//  Array.hpp
//  12_ClassArrayCustom
//
//  Created by marker on 2019/5/11.
//  Copyright © 2019年 majortom. All rights reserved.
//

#ifndef Array_hpp
#define Array_hpp

#include <stdio.h>
class Array{
public :
    Array(int);
    Array(const Array & arr);
    ~Array();
    void SetData(int ,int );
    int GetData(int);
    int GetLength();
private:
    int *array;
    int length;
};
#endif /* Array_hpp */
