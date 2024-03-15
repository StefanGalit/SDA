#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

typedef struct {
    char data[MAX_LEN];
    int product_id;
    char product_name[MAX_LEN];
    char product_category[MAX_LEN];
    char product_subcategory[MAX_LEN];
    float unit_price;
    int quantity_sold;
    char country[MAX_LEN];
    char city[MAX_LEN];
} Transaction;

typedef struct Node {
    Transaction transaction;
    struct Node *next;
} Node;

void add_transaction(Node **head, Transaction transaction) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory allocation error.\n");
        exit(1);
    }
    new_node->transaction = transaction;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        Node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void read_transactions(FILE *file, Node **head) {
    Transaction transaction;
    while (fscanf(file, "%s %d %s %s %s %f %d %s %s", 
        transaction.data, &transaction.product_id, transaction.product_name,
        transaction.product_category, transaction.product_subcategory,
        &transaction.unit_price, &transaction.quantity_sold,
        transaction.country, transaction.city) == 9) {
        
        add_transaction(head, transaction);
    }
}

float total_monthly_revenue(Node *head, const char *month_name) {
    float total_revenue = 0;
    while (head != NULL) {
        if (strstr(head->transaction.data, month_name) != NULL) {
            total_revenue += head->transaction.unit_price * head->transaction.quantity_sold;
        }
        head = head->next;
    }
    return total_revenue;
}

void display_monthly_revenue(Node *head, const char *year) {
    char months[12][MAX_LEN] = {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12"};
    for (int i = 0; i < 12; ++i) {
        float revenue = total_monthly_revenue(head, months[i]);
        printf("Total revenue for month %s %s: %.2f\n", months[i], year, revenue);
    }
}

int compare_descending(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

void top_5_best_selling_products(Node *head, const char *year) {
    int *quantities = (int*)calloc(1000, sizeof(int));
    if (quantities == NULL) {
        printf("Memory allocation error.\n");
        exit(1);
    }
    
    while (head != NULL) {
        quantities[head->transaction.product_id] += head->transaction.quantity_sold;
        head = head->next;
    }
    
    qsort(quantities, 1000, sizeof(int), compare_descending);
    printf("Top 5 best selling products in %s are:\n", year);
    for (int i = 0; i < 5; ++i) {
        printf("Product ID: %d, Quantity sold: %d\n", i+1, quantities[i]);
    }
    
    free(quantities);
}

void sales_distribution_by_categories(Node *head) {
    int electronics_sales = 0;
    int clothing_sales = 0;
    int home_decor_sales = 0;
    int furniture_sales = 0;
    while (head != NULL) {
        if (strcmp(head->transaction.product_category, "Electronics") == 0) {
            electronics_sales += head->transaction.quantity_sold;
        } else if (strcmp(head->transaction.product_category, "Clothing") == 0) {
            clothing_sales += head->transaction.quantity_sold;
        } else if (strcmp(head->transaction.product_category, "HomeDecor") == 0) {
            home_decor_sales += head->transaction.quantity_sold;
        } else if (strcmp(head->transaction.product_category, "Furniture") == 0) {
            furniture_sales += head->transaction.quantity_sold;
        }
        head = head->next;
    }
    printf("Sales Electronics: %d\n", electronics_sales);
    printf("Sales Clothes: %d\n", clothing_sales);
    printf("Sales Furniture: %d\n", furniture_sales);
    printf("Sales HomeDecor: %d\n", home_decor_sales);
}

void top_sales_by_country(Node *head, const char *country) {
    int max_sales = 0;
    char city_with_max_sales[MAX_LEN];
    while (head != NULL) {
        if (strcmp(head->transaction.country, country) == 0) {
            if (head->transaction.quantity_sold > max_sales) {
                max_sales = head->transaction.quantity_sold;
                strcpy(city_with_max_sales, head->transaction.city);
            }
        }
        head = head->next;
    }
    printf("City with the highest sales for %s: %s [%d]\n", country, city_with_max_sales, max_sales);
}

void display_menu(Node *head) {
    int option;
    do {
        printf("\nMenu:\n");
        printf("1. Total revenue generated in each month of the year\n");
        printf("2. Top 5 best selling products\n");
        printf("3. Sales distribution by product categories\n");
        printf("4. Cities with the highest sales for each country\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        
        switch(option) {
            case 1: {
                char year[MAX_LEN];
                printf("Enter the year: ");
                scanf("%s", year);
                display_monthly_revenue(head, year);
                break;
            }
            case 2: {
                char year[MAX_LEN];
                printf("Enter the year: ");
                scanf("%s", year);
                top_5_best_selling_products(head, year);
                break;
            }
            case 3: {
                sales_distribution_by_categories(head);
                break;
            }
            case 4: {
                char country[MAX_LEN];
                printf("Enter the country: ");
                scanf("%s", country);
                top_sales_by_country(head, country);
                break;
            }
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (option != 0);
}

int main() {
    FILE *file = fopen("D:\\PC Laboratory\\Lectii\\SDA_1\\sales.txt", "r");
    if (file == NULL) {
        printf("Could not open the file.\n");
        return 1;
    }

    Node *head = NULL;

    read_transactions(file, &head);

    fclose(file);

    display_menu(head);

    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
