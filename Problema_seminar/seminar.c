#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100
#define MAX_PRODUCTS 1000

typedef struct {
    char date[MAX_LEN];
    int product_id;
    char product_name[MAX_LEN];
    char product_category[MAX_LEN];
    char product_subcategory[MAX_LEN];
    float unit_price;
    int quantity_sold;
    char country[MAX_LEN];
    char city[MAX_LEN];
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

int main() {
    FILE *file = fopen("D:\\PC Laboratory\\Lectii\\Problema_seminar\\sales.txt", "r");
    if (file == NULL) {
        printf("Could not open the file.\n");
        return 1;
    }

    Node *head = NULL;
    read_units(file, &head);
    fclose(file);

    display_menu(head);

    return 0;
}

void read_units(FILE *file, Node **head) {
    while (1) {
        Sale_unit unit;
        if (fscanf(file, "%s %d %s %s %s %f %d %s %s",
                   unit.date, &unit.product_id, unit.product_name,
                   unit.product_category, unit.product_subcategory,
                   &unit.unit_price, &unit.quantity_sold,
                   unit.country, unit.city) != 9) {
            break;
        }

        Node *new_node = (Node *)malloc(sizeof(Node));
        if (new_node == NULL) {
            printf("Memory allocation error.\n");
            exit(1);
        }
        new_node->unit = unit;
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
}

void display_file_contents(FILE *file) {
    char line[MAX_LEN];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
}

float total_monthly_income(Node *head, const char *month, const char *year) {
    float total_income = 0;
    Node *temp = head;

    while (temp != NULL) {
        char extracted_month[3];
        char extracted_year[5];

        sscanf(temp->unit.date, "%4s-%2s", extracted_year, extracted_month);

        if (strcmp(extracted_month, month) == 0 && strcmp(extracted_year, year) == 0) {
            total_income += temp->unit.unit_price * (float)temp->unit.quantity_sold;
        }
        temp = temp->next;
    }
    return total_income;
}

void display_monthly_income(Node *head, const char *year) {
    char months[12][MAX_LEN] = {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12"};
    for (int i = 0; i < 12; ++i) {
        float income = total_monthly_income(head, months[i], year);
        printf("Total income for %s %s: %.2f\n", months[i], year, income);
    }
}

void top_5_best_selling_products(Node *head, const char *year) {
    int quantities[MAX_PRODUCTS] = {0};
    Node *temp = head;
    while (temp != NULL) {
        char extracted_year[5];

        sscanf(temp->unit.date, "%4s", extracted_year);
        if (strcmp(year, extracted_year) == 0) {
            quantities[temp->unit.product_id] += temp->unit.quantity_sold;
        }
        temp = temp->next;
    }

    printf("Top 5 best selling products in %s:\n", year);
    int num_products_displayed = 0;
    for (int i = 0; i < MAX_PRODUCTS && num_products_displayed < 5; ++i) {
        if (quantities[i] > 0) {
            printf("Product ID: %d, Quantity sold: %d\n", i, quantities[i]);
            ++num_products_displayed;
        }
    }
}

void sales_distribution_by_category(Node *head) {
    char category[MAX_LEN];
    printf("Enter the category: ");
    scanf("%s", category);

    int total_sales = 0;
    Node *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->unit.product_category, category) == 0) {
            total_sales += temp->unit.quantity_sold;
        }
        temp = temp->next;
    }

    printf("Total sales for category %s: %d\n", category, total_sales);
}

void highest_sales_cities_per_country(Node *head, const char *country) {
    int max_sales = 0;
    char max_city[MAX_LEN];
    Node *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->unit.country, country) == 0) {
            if (temp->unit.quantity_sold > max_sales) {
                max_sales = temp->unit.quantity_sold;
                strcpy(max_city, temp->unit.city);
            }
        }
        temp = temp->next;
    }
    printf("City with the highest sales for %s: %s [%d]\n", country, max_city, max_sales);
}

void display_menu(Node *head) {
    int option;
    do {
        printf("\nMenu:\n");
        printf("1. Display category quantities\n");
        printf("2. Display total monthly income for a specific year\n");
        printf("3. Display top 5 best selling products for a specific year\n");
        printf("4. Sales distribution by category\n");
        printf("5. Highest sales cities per country\n");
        printf("6. Display file contents\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch(option) {
            case 1: {
                sales_distribution_by_category(head);
                break;
            }
            case 2: {
                char year[MAX_LEN];
                printf("Enter the year: ");
                scanf("%s", year);
                display_monthly_income(head, year);
                break;
            }
            case 3: {
                char year[MAX_LEN];
                printf("Enter the year: ");
                scanf("%s", year);
                top_5_best_selling_products(head, year);
                break;
            }
            case 4: {
                sales_distribution_by_category(head);
                break;
            }
            case 5: {
                char country[MAX_LEN];
                printf("Enter the country: ");
                scanf("%s", country);
                highest_sales_cities_per_country(head, country);
                break;
            }
            case 6: {
                FILE *file = fopen("D:\\PC Laboratory\\Lectii\\Problema_seminar\\sales.txt", "r");
                if (file == NULL) {
                    printf("Could not open the file.\n");
                    return;
                }
                printf("File contents:\n");
                display_file_contents(file);
                fclose(file);
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
