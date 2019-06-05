//
//  Circle.hpp
//  07_ClassDevide
//
//  Created by marker on 2019/4/27.
//  Copyright © 2019年 majortom. All rights reserved.
//

#ifndef Circle_hpp
#define Circle_hpp

#include <stdio.h>
#include "Point.hpp"
class Circle{
private:
    Point point;
    int radius;
public:
    void Setpoint(int x,int y);
    void SetRadius(int r);
    Point GetPoint();
    int GetRadius();
    int TwoCirclelocation(Circle circle);
};
#endif /* Circle_hpp */
