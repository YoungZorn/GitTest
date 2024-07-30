//
// Created by CN_YoungZorn on 2024/6/3.
//

#ifndef DEMO_FUNC_PTR_H
#define DEMO_FUNC_PTR_H

#include <iostream>

typedef int (*fun)(void* context);

class func_ptr {
public:
    static int MyFunc(void* value);
};


#endif //DEMO_FUNC_PTR_H
