
#ifndef UNTITLED_STRUCT_H
#define UNTITLED_STRUCT_H

struct TreeNode {
    int key;
    char* name;
    int age;
    float height;
    char gender;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct Tree {
    struct TreeNode* root;
};


struct TreeNode* create_node(int key, const char* name, int age, float height, char gender);

void insert_node(struct Tree* tree, int key, const char* name, int age, float height, char gender);

void inorder_traversal(struct TreeNode* root);

void preorder_traversal(struct TreeNode* root);

void postorder_traversal(struct TreeNode* root);

void dfs_traversal(struct TreeNode* root);

void bfs_traversal(struct TreeNode* root);

void mirror_tree(struct TreeNode* root);

void reverse_inorder_traversal(struct TreeNode* root);

struct TreeNode* search(struct TreeNode* root, int key);

void clear_tree(struct TreeNode* root);

void free_tree(struct TreeNode* root);

int get_height(struct TreeNode* node);

void update_height(struct TreeNode* node);

int get_balance_factor(struct TreeNode* node);

struct TreeNode* left_rotate(struct TreeNode* x);

struct TreeNode* right_rotate(struct TreeNode* y);

struct TreeNode* balance_node(struct TreeNode* node);
void print_node(struct TreeNode * node);

void menu(int *choice, int *key, int *age, float *height, char *name, char *gender, struct Tree *tree, struct TreeNode **found_node);

#endif
