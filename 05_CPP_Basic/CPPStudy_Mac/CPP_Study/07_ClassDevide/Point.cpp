//
//  Point.cpp
//  07_ClassDevide
//
//  Created by marker on 2019/4/27.
//  Copyright © 2019年 majortom. All rights reserved.
//

#include "Point.hpp"
#include <math.h>
void Point::SetPoint(int _x, int _y){
    _point.x=_x;
    _point.y=_y;
}

point Point::GetPoint(){
    return _point;
}

double Point::DistanceTwoPoint(point point){
    double res=sqrt((point.x-_point.x)*(point.x-_point.x)+(point.y-_point.y)*(point.y-_point.y));
    return res;
}
