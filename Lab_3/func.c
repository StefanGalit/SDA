#include <stdio.h>
#include <stdlib.h>
#include "func.h"
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Eroare la alocarea memoriei pentru un nod nou.\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

enum Menu_Option
{
    READ_TREE = 1,
    TREE_PRINT = 2,
    TREE_DEPTH = 3,
    NODE_DEPTH = 4,
    NODE_HEIGHT = 5,
    PRINT_LEAVES = 6,
    SEARCH_NODE = 7,
    DELETE_NODE = 8,
    FREE_TREE = 9,
    EXIT_PROGRAM = 0


};

Node* insert_node(Node* root, int data) {
    if (root == NULL) {
        root = create_node(data);
    } else {
        if (data <= root->data) {
            root->left = insert_node(root->left, data);
        } else {
            root->right = insert_node(root->right, data);
        }
    }
    return root;
}

Node* read_tree_from_keyboard() {
    Node* root = NULL;
    int num_elements, element;
    printf("Introduceti numarul de elemente din arbore: ");
    scanf("%d", &num_elements);
    printf("Introduceti elementele arborelui:\n");
    for (int i = 0; i < num_elements; i++) {
        scanf("%d", &element);
        root = insert_node(root, element);
    }
    return root;
}

void print_in_order(Node* root) {
    if (root != NULL) {
        print_in_order(root->left);
        printf("%d ", root->data);
        print_in_order(root->right);
    }
}

int tree_depth(Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        int left_depth = tree_depth(root->left);
        int right_depth = tree_depth(root->right);
        if (left_depth > right_depth) {
            return left_depth + 1  ;
        } else {
            return right_depth + 1 ;
        }
    }
}

int node_depth(Node* root, int target_data, int depth) {
    if (root == NULL) {
        return -1;
    } else if (root->data == target_data) {
        return depth;
    } else {
        int left_search = node_depth(root->left, target_data, depth + 1);
        int right_search = node_depth(root->right, target_data, depth + 1);
        if (left_search != -1) {
            return left_search;
        } else {
            return right_search;
        }
    }
}

Node* search(Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

int node_height(Node* root) {
    if (root == NULL) {
        return -1;
    } else {
        int left_height = node_height(root->left);
        int right_height = node_height(root->right);
        if (left_height > right_height) {
            return left_height + 1;
        } else {
            return right_height + 1;
        }
    }
}

void print_leaf_nodes(Node* root) {
    if (root == NULL) {
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        printf("%d ", root->data);
    } else {
        print_leaf_nodes(root->left);
        print_leaf_nodes(root->right);
    }
}

Node* delete_node(Node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = delete_node(root->left, key);
    } else if (key > root->data) {
        root->right = delete_node(root->right, key);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
    }
    return root;
}

void clear_tree(Node* root) {
    if (root != NULL) {
        clear_tree(root->left);
        clear_tree(root->right);
        free(root);
    }
}


void menu(Node* root, int option)
{

    do {
        printf("\nMeniu:\n");
        printf("1. Citeste arborele de la tastatura\n");
        printf("2. Afiseaza arborele\n");
        printf("3. Calculeaza adancimea arborelui\n");
        printf("4. Calculeaza adancimea unui nod\n");
        printf("5. Calculeaza inaltimea unui nod\n");
        printf("6. Afiseaza nodurile frunza\n");
        printf("7. Cauta un nod\n");
        printf("8. Sterge un nod\n");
        printf("9. Curata arborele (elibereaza memoria)\n");
        printf("0. Iesire\n");
        printf("Alegeti o optiune: ");
        scanf("%d", &option);

        switch (option) {
            case READ_TREE:
                root = read_tree_from_keyboard();
                break;
            case TREE_PRINT:
                printf("Elementele arborelui (traversare in ordine): ");
                print_in_order(root);
                printf("\n");
                break;
            case TREE_DEPTH:
                printf("Adancimea arborelui: %d\n", tree_depth(root));
                break;
            case NODE_DEPTH:
            {
                int target;
                printf("Introduceti valoarea nodului pentru a calcula adancimea acestuia: ");
                scanf_s("%d", &target);
                int depth = node_depth(root, target, 0);
                if (depth == -1) {
                    printf("Nodul nu a fost gasit in arbore.\n");
                } else {
                    printf("Adancimea nodului %d: %d\n", target, depth);
                }
            }
                break;
            case NODE_HEIGHT:
            {
                int target;
                printf("Introduceti valoarea nodului pentru a calcula inaltimea acestuia: ");
                scanf_s("%d", &target);
                Node* target_node = search(root, target);
                if (target_node == NULL) {
                    printf("Nodul nu a fost gasit in arbore.\n");
                } else {
                    printf("Inaltimea nodului %d: %d\n", target, node_height(target_node));
                }
            }
                break;
            case PRINT_LEAVES:
                printf("Nodurile frunza: ");
                print_leaf_nodes(root);
                printf("\n");
                break;
            case SEARCH_NODE:
            {
                int key;
                printf("Introduceti valoarea pentru a cauta in arbore: ");
                scanf_s("%d", &key);
                Node* result = search(root, key);
                if (result != NULL) {
                    printf("Nodul cu valoarea %d a fost gasit in arbore.\n", key);
                } else {
                    printf("Nodul cu valoarea %d nu a fost gasit in arbore.\n", key);
                }
            }
                break;
            case DELETE_NODE:
            {
                int key;
                printf("Introduceti valoarea nodului pentru a-l sterge: ");
                scanf("%d", &key);
                root = delete_node(root, key);
                printf("Nodul cu valoarea %d a fost sters din arbore.\n", key);
            }
                break;
            case FREE_TREE:
                clear_tree(root);
                root = NULL;
                printf("Memoria arborelui a fost eliberata.\n");
                break;
            case EXIT_PROGRAM:
                printf("Iesire din program.\n");
                break;
            default:
                printf("Optiune invalida. Va rugam sa incercati din nou.\n");
                break;
        }
    } while (option != 0);

}