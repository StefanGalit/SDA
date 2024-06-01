#ifndef BINARY_TREE
#define BINARY_TREE

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

/**
 * This function create the node and makes memory allocation
 * @param data
 * @return 'Node' memory allocation
 */
Node* create_node(int data);

/**
 * This function insert_node the node
 * @param root
 * @param data
 * @return 'Node', insert_node the node
 */
Node* insert_node(Node* root, int data);


/**
 *
 * This function read the nodes of tree from keyboard
 * @return 'Node' reading nodes
 */

Node* read_tree_from_keyboard();

/**
 * This function print the tree elements in order
 * @param root
 *  @return Void
 */



void print_in_order(Node* root);


/**
 * This function calculate the tree depth
 * @param root
 * @return 'int' tree depth
 */

int tree_depth(Node* root);
/**
 * This function calculate the node depth
 * @param root
 * @param target_data
 * @param depth
 * @return 'int' node depth
 */



int node_depth(Node* root, int target_data, int depth);


/**
 * This function search the element from tree
 * @param root
 * @param key
 * @return 'Node' element position
 */
Node* search(Node* root, int key);

/**
 * This function calculate the height node
 * @param root
 * @return 'int' node height
 */
int node_height(Node* root);


void print_leaf_nodes(Node* root);


Node* delete_node(Node* root, int key);


void clear_tree(Node* root);

void menu(Node* root, int option);



//
// Created by Ștefan on 10.04.2024.
//
#endif