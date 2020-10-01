//
//  PLTreeNodeData.hpp
//  PLDataStructs
//
//  Created by Pritesh on 01/10/20.
//  Copyright © 2020 pritesh. All rights reserved.
//

#ifndef PLTreeNodeData_hpp
#define PLTreeNodeData_hpp

#include <stdio.h>
#include <string>

class PLTreeNodeData {
    int value;
    std::string color;
public:
    PLTreeNodeData(int dataValue, std::string hexColor);
    int getValue();
    std::string getColor();
};
#endif /* PLTreeNodeData_hpp */
