
#ifndef LAB_5_FUNC_H
#define LAB_5_FUNC_H
void initialize_array(int *arr, int size);
void print_array(int *arr, int size);

void free_array(int *arr);

void selection_sort(int *arr, int size);

void quick_sort(int *arr, int left, int right);

int linear_search(int *arr, int size, int value);

int binary_search(int *arr, int size, int value);

void add_array_for_fibbo(int a[], int b[], int result[], int length);

void print_fibonacci(int result[], int length);

void calculate_fibonacci(int n);

void menu_for_first_problem();

void problem_1();

void menu_for_second_problem();


void problem_2();


#endif
