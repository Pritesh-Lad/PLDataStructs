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
public:
    int value;
    std::string color;
    
    PLTreeNodeData(int dataValue, std::string hexColor);    
};
#endif /* PLTreeNodeData_hpp */
