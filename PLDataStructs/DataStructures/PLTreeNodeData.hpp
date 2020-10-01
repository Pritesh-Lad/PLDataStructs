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
/**
 * Data model to hold data for a tree node creation
 */
class PLTreeNodeData {    
public:
    /// Holds integre value for the node
    int value;
    
    /// Holds hex color string for the node in the format #RRGGBB
    std::string color;
    
    /**
     * Initializes node data with value & hex color
     * @param dataValue integer value to be used as node value
     * @param hexColor color in hex format(#RRGGBB)
     */
    PLTreeNodeData(int dataValue, std::string hexColor);    
};
#endif /* PLTreeNodeData_hpp */
