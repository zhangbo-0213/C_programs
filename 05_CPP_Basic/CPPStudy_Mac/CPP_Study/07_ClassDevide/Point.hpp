//
//  Point.hpp
//  07_ClassDevide
//
//  Created by marker on 2019/4/27.
//  Copyright © 2019年 majortom. All rights reserved.
//

#ifndef Point_hpp
#define Point_hpp

#include <stdio.h>
struct point{
    int x;
    int y;
};
class Point{
private:
    point _point;
    
public:
    void SetPoint(int _x,int _y);
    double DistanceTwoPoint(point point);
    point GetPoint();
};
#endif /* Point_hpp */
