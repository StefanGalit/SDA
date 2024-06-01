#include "struct.h"
#include <stdio.h>


int main() {
    int choice, key, age;
    float height;
    char name[50], gender;
    struct TreeNode* foundNode;

    struct Tree tree;
    tree.root = NULL;


    insert_node(&tree, 50, "John", 30, 1.75, 'M');
    insert_node(&tree, 30, "Alice", 25, 1.65, 'F');
    insert_node(&tree, 70, "Bob", 35, 1.80, 'M');
    insert_node(&tree, 20, "Eve", 22, 1.60, 'F');
    insert_node(&tree, 40, "Mike", 28, 1.70, 'M');
    insert_node(&tree, 60, "Carol", 32, 1.72, 'F');
    insert_node(&tree, 80, "David", 40, 1.85, 'M');

    menu(&choice, &key, &age, &height, name, &gender, &tree, &foundNode);

    free_tree(tree.root);

    return 0;
}

