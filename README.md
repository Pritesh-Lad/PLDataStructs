# PLDataStructs

***PLDataStructs*** is a static library written in C++. This library provides user friendly APIs for the most common data structures used in programming.

The current version of the library provides implementation for the folowing data structures -
- **PLBalancedBTree** - Self balancing ordered binary trees. These are also called as AVL trees.

## Installation

### Pre-built .framework package
1. Simply download the static framework [PLDataStructs.framework](https://github.com/Pritesh-Lad/PLDataStructs/releases/download/v1.0.0/PLDataStructs_framework.zip) 
2. Import the framework in your Xcode project.
3. Add `-lc++` in the target's build settings, under the `Other Linker Flags`, to let the Xcode know that you want to link the C++ library code.  

### Building the framework from source code
1. Clone the PLDataStructs git repo or download the source code.
2. cd into the PLDataStructs project directory & open PLDataStructs.xcodeproj in Xcode
3. Build the Framework-Universal target. It will build the static framework & open the directory where it's created(the same project directory).
4. Import this framework into your Xcode project
5. Add `-lc++` in the target's build settings, under the `Other Linker Flags`, to let the Xcode know that you want to link the C++ library code.

## Usage

All the binary tree implementations of this library are inherited from `PLBTree`, a base class that defines the basic binary tree behaviours. Thus, they follow similar properties & APIs.

However, the following guide demonstrates usage using `PLBalancedBTree`. If your implementation doesn't require a balanced tree, you may use `PLOrderedBTree` for a simple BST implementation.

(Explore the [API reference](https://pritesh-lad.github.io/PLDataStructs/) for more details)

### Import the library header
To use the data structures from this library, import the library header in your objective-C++ file.
```
#import <PLDataStructs/PLDataStructs.h>
```

### Creating a self balancing ordered binary tree -

1. Creating with a single root node(having a value & color)
```
PLBalancedBTree *tree = new PLBalancedBTree(5, "#FF0000");
```

2. Creating with a list(`std::vector`) of nodes(first node being a root node) -
```
std::vector<PLTreeNodeData*> vector; 
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
tree->insertNode(10, "#00FF00");
```

### Remove a node from a tree -
```
tree->removeNode(5);
```

### Remove all nodes of a particular color from a tree -
```
tree->removeNodes("#00FF00"); // removes all green nodes
```

### Printing the description of a tree -

- **Inorder description** -
```
tree->printInOrder();
```

- **Preorder description** -
```
tree->printPreOrder();
```

- **Postorder description** -
```
tree->printPostOrder();
```

### Accessing tree properties -
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

## API documentation
A detailed API documentation is available [here](https://pritesh-lad.github.io/PLDataStructs/)

## Example
You may also refer the [sample Xcode project](https://github.com/Pritesh-Lad/PLDataStructs/tree/master/Example) demonstrating the use of the library.
