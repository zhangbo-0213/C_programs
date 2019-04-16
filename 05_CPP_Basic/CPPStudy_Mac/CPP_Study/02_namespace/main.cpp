//
//  main.cpp
//  02_Namespace
//
//  Created by marker on 2019/4/16.
//  Copyright © 2019年 majortom. All rights reserved.
//

#include <iostream>
using namespace std;

namespace namespaceA {
    int a=10;
}
namespace namespaceB {
    int b=20;
    namespace namespaceC{
        struct student{
            char name[10];
            int age;
        };
    }
}

int main(int argc, const char * argv[]) {
    using namespace namespaceA;
    using namespace namespaceB;
    using namespaceB::namespaceC::student;
    
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;
    
    student s1={"majortom",18};
    
    cout<<"student name:"<<s1.name<<"   age:"<<s1.age<<endl;
    return 0;
}
