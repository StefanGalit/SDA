

#ifndef SEMINAR_1_STRUCT_H
#define SEMINAR_1_STRUCT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100
#define MAX_PRODUCTS 1000

typedef struct {
    char *date;
    int product_id;
    char *product_name;
    char *product_category;
    char *product_subcategory;
    float unit_price;
    int quantity_sold;
    char *country;
    char *city;
} Sale_unit;

typedef struct Node {
    Sale_unit unit;
    struct Node *next;
} Node;

typedef struct CategoryNode {
    char category_name[MAX_LEN];
    int total_quantity;
    struct CategoryNode *next;
} CategoryNode;

void read_units(FILE *file, Node **head);

void display_file_contents(FILE *file);

float total_monthly_income(Node *head, const char *month, const char *year);

void display_monthly_income(Node *head, const char *year);

void top_5_best_selling_products(Node *head, const char *year);

void sales_distribution_by_category(Node *head);

void highest_sales_cities_per_country(Node *head, const char *country);

void display_menu(Node *head);

void free_list(Node *head);


#endif
