#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

enum Menu_Option
{
    ADD_NODE = 1,
    PRINT_TREE_VSD ,
    PRINT_TREE_SVD ,
    PRINT_TREE_SDV ,
    PRINT_TREE_DFS ,
    PRINT_TREE_BFS ,
    SEARCH_NODE ,
    MIRROR_TREE ,
    BALANCE_TREE ,
    EXIT_PROGRAM


};

struct TreeNode* create_node(int key, const char* name, int age, float height, char gender) {
    struct TreeNode* new_node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (new_node == NULL) {
        printf("Eroare la alocarea memoriei pentru un nou nod.\n");
        exit(EXIT_FAILURE);
    }
    new_node->key = key;
    new_node->name = strdup(name);
    if (new_node->name == NULL) {
        printf("Eroare la alocarea memoriei pentru numele nodului.\n");
        free(new_node);
        exit(EXIT_FAILURE);
    }
    new_node->age = age;
    new_node->height = height;
    new_node->gender = gender;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
void print_node(struct TreeNode * node)
{
    if( node == NULL)
    {
        return;
    }
    printf("Key: %d, Name: %s, Age: %d, Height: %.2f, Gender: %c\n", node->key, node->name, node->age, node->height, node->gender);
}
void insert_node(struct Tree* tree, int key, const char* name, int age, float height, char gender) {
    if (tree->root == NULL) {
        tree->root = create_node(key, name, age, height, gender);
        return;
    }

    struct TreeNode* current_node = tree->root;
    while (1) {
        if (key < current_node->key) {
            if (current_node->left == NULL) {
                current_node->left = create_node(key, name, age, height, gender);
                return;
            }
            current_node = current_node->left;
        } else if (key > current_node->key) {
            if (current_node->right == NULL) {
                current_node->right = create_node(key, name, age, height, gender);
                return;
            }
            current_node = current_node->right;
        } else {
            return;
        }
    }
}

void inorder_traversal(struct TreeNode* root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        print_node(root);
        inorder_traversal(root->right);
    }
}

void preorder_traversal(struct TreeNode* root) {
    if (root != NULL) {
        print_node(root);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

void postorder_traversal(struct TreeNode* root) {
    if (root != NULL) {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        print_node(root);
    }
}

void dfs_traversal(struct TreeNode* root) {
    if (root != NULL) {
        print_node(root);
        dfs_traversal(root->left);
        dfs_traversal(root->right);
    }
}

void bfs_traversal(struct TreeNode* root) {
    if (root == NULL)
        return;

    struct TreeNode* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct TreeNode* current = queue[front++];
        print_node(current);

        if (current->left != NULL)
            queue[rear++] = current->left;
        if (current->right != NULL)
            queue[rear++] = current->right;
    }
}

void mirror_tree(struct TreeNode* root) {
    if (root == NULL)
        return;

    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror_tree(root->left);
    mirror_tree(root->right);
}

void reverse_inorder_traversal(struct TreeNode* root) {
    if (root != NULL) {
        reverse_inorder_traversal(root->right);
        print_node(root);
        reverse_inorder_traversal(root->left);
    }
}

struct TreeNode* search(struct TreeNode* root, int key) {
    if (root == NULL || root->key == key)
        return root;

    if (key < root->key)
        return search(root->left, key);

    return search(root->right, key);
}

void clear_tree(struct TreeNode* root) {
    if (root != NULL) {
        clear_tree(root->left);
        clear_tree(root->right);
        free(root->name);
        free(root);
    }
}

void free_tree(struct TreeNode* root) {
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root->name);
        free(root);
    }
}

int get_height(struct TreeNode* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

void update_height(struct TreeNode* node) {
    int left_height = get_height(node->left);
    int right_height = get_height(node->right);
    node->height = (left_height > right_height ? left_height : right_height) ;
}

int get_balance_factor(struct TreeNode* node) {
    if (node == NULL)
        return 0;
    return get_height(node->left) - get_height(node->right);
}

struct TreeNode* left_rotate(struct TreeNode* x) {
    struct TreeNode* y = x->right;
    struct TreeNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    update_height(x);
    update_height(y);

    return y;
}

struct TreeNode* right_rotate(struct TreeNode* y) {
    struct TreeNode* x = y->left;
    struct TreeNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    update_height(y);
    update_height(x);

    return x;
}

struct TreeNode* balance_node(struct TreeNode* node) {
    update_height(node);

    int balance = get_balance_factor(node);

    if (balance > 1) {
        if (get_balance_factor(node->left) >= 0)
            return right_rotate(node);
        else {
            node->left = left_rotate(node->left);
            return right_rotate(node);
        }
    }
    if (balance < -1) {
        if (get_balance_factor(node->right) <= 0)
            return left_rotate(node);
        else {
            node->right = right_rotate(node->right);
            return left_rotate(node);
        }
    }
    return node;
}




void menu(int *choice, int *key, int *age, float *height, char *name, char *gender, struct Tree *tree, struct TreeNode **found_node)
{
    do
    {
        printf("\nMeniu:\n");
        printf("1. Adaugare nod\n");
        printf("2. Afisare arbore in ordine crescatoare\n");
        printf("3. Afisare arbore in preordine\n");
        printf("4. Afisare arbore in postordine\n");
        printf("5. Afisare arbore in DFS\n");
        printf("6. Afisare arbore in BFS\n");
        printf("7. Cautare nod\n");
        printf("8. Oglindirea arborelui\n");
        printf("9. Balansarea\n");
        printf("10. Iesire\n");
        printf("Alegeti o optiune: ");
        scanf("%d", choice);

        switch (*choice)
        {
            case ADD_NODE:
                printf("Introduceti cheia noului nod: ");
                scanf("%d", key);
                printf("Introduceti numele noului nod: ");
                scanf("%s", name);
                printf("Introduceti vârsta noului nod: ");
                scanf("%d", age);
                printf("Introduceti înălțimea noului nod (m): ");
                scanf("%f", height);
                printf("Introduceti genul noului nod (M/F): ");
                scanf(" %c", gender);
                insert_node(tree, *key, name, *age, *height, *gender);
                break;
            case PRINT_TREE_VSD:
                printf("Arborele in ordine crescatoare:\n");
                inorder_traversal(tree->root);
                printf("\n");
                break;
            case PRINT_TREE_SVD:
                printf("Arborele in preordine:\n");
                preorder_traversal(tree->root);
                printf("\n");
                break;
            case PRINT_TREE_SDV:
                printf("Arborele in postordine:\n");
                postorder_traversal(tree->root);
                printf("\n");
                break;
            case PRINT_TREE_DFS:
                printf("Arborele in DFS:\n");
                dfs_traversal(tree->root);
                printf("\n");
                break;
            case PRINT_TREE_BFS:
                printf("Arborele in BFS:\n");
                bfs_traversal(tree->root);
                printf("\n");
                break;
            case SEARCH_NODE:
                printf("Introduceti cheia nodului de cautat: ");
                scanf("%d", key);
                *found_node = search(tree->root, *key);
                if (*found_node != NULL)
                    printf("Nodul cu cheia %d a fost gasit.\n", (*found_node)->key);
                else
                    printf("Nodul cu cheia %d nu a fost gasit.\n", *key);
                break;
            case MIRROR_TREE:
                printf("Oglindirea arborelui...\n");
                mirror_tree(tree->root);
                printf("Arborele a fost oglindit.\n");
                printf("Afisare arbore in ordine inversa:\n");
                reverse_inorder_traversal(tree->root);
                printf("\n");
                break;
            case BALANCE_TREE:
                printf("Balansare arbore...\n");
                balance_node(&tree);
                printf("Arborele a fost balansat.\n");
                break;
            case EXIT_PROGRAM:
                printf("Programul se incheie.\n");
                break;
            default:
                printf("Optiune invalida! Incercati din nou.\n");
        }
    } while (*choice != 10);
}