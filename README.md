# PLDataStructs

`PLDataStructs` is a static library written in C++. This library provides user friendly APIs for the most common data structures used in programming.

The current version of the library provides implementation for the self balancing ordrerd binary trees. These are also called as AVL trees.

## Installation

Simply download the static PLDataStructs.framework & import the framework in your Xcode project.

Add `-lc++` in the target's build settings, under the `Other Linker Flags`, to let the xcode know that you want to link the c++ library code.  

## Usage

### Import the library header
```
#import <PLDataStructs/PLDataStructs.h>
```

### Creating a self balancing ordered binary tree - `PLBalancedBTree`

Creating with a single root node having a value & color
```
PLBalancedBTree *tree = new PLBalancedBTree(5, "#FF0000");
```

Creating with a list(`std::vector`) of nodes(first node being a root node) -
```
vector<PLTreeNodeData*> vector; 
# create data for each node
PLTreeNodeData *node1 = new PLTreeNodeData( 5, "#FF0000");
PLTreeNodeData *node2 = new PLTreeNodeData( 1, "#00FF00");
PLTreeNodeData *node3 = new PLTreeNodeData( 15, "#0000FF");

vector.push_back(node1); 
vector.push_back(node2); 
vector.push_back(node3); 

PLBalancedBTree *tree = new PLBalancedBTree(vector);
```

### Adding a new node to a tree -
```
tree->insertNode(10, "#23244");
```

### Remove a node from a tree -
```
tree->removeNode(5);
```

### Remove all node of a particular color from the tree -
```
tree->removeNodes("#00FF00"); // removes all green nodes
```

### Printing the description of a tree -
`PLDataStructs` provides following ways to print the description of a tree -

Inorder description -
```
tree->printInOrder();
```

Preorder description -
```
tree->printPreOrder();
```

Postorder description -
```
tree->printPostOrder();
```

Accessing tree properties/fields -
```
// root's value
int value = tree->getValue();

// root's color
std::string color = tree->getColor();

// height of the tree
int height = tree->getHeight();

// left subtree
PLBalancedBTree *left = tree->getLeftSubtree();

// right subtree
PLBalancedBTree *right = tree->getRightSubtree();
```
