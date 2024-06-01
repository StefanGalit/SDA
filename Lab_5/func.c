#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "func.h"
#include "benchmark.h"

void initialize_array(int *arr, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100000;
    }
}

void print_array(int *arr, int size) {
    printf("Elementele tabloului: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void free_array(int *arr) {
    free(arr);
}

void selection_sort(int *arr, int size) {
    clock_t start = clock();

    for (int i = 0; i < size - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }

    clock_t end = clock();
    double execution_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Selection Sort a durat: %.6f secunde\n", execution_time);
}

void quick_sort(int *arr, int left, int right) {
    if (left < right) {
        int pivot = arr[(left + right) / 2];
        int i = left, j = right;
        while (i <= j) {
            while (arr[i] < pivot) i++;
            while (arr[j] > pivot) j--;
            if (i <= j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
            }
        }
        quick_sort(arr, left, j);
        quick_sort(arr, i, right);
    }
}



int linear_search(int *arr, int size, int value) {


    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            clock_t end = clock();
            return i;
        }
    }


    return -1;
}

int binary_search(int *arr, int size, int value) {
    clock_t start = clock();

    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value) {
            clock_t end = clock();
            double execution_time = ((double)(end - start)) / CLOCKS_PER_SEC;
            printf("Binary Search a durat: %.6f secunde\n", execution_time);
            return mid;
        }
        if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    clock_t end = clock();
    double execution_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Binary Search a durat: %.6f secunde\n", execution_time);
    return -1;
}

void add_array_for_fibbo(int a[], int b[], int result[], int length) {
    int carry = 0;
    for (int i = length - 1; i >= 0; i--) {
        int sum = a[i] + b[i] + carry;
        result[i] = sum % 10;
        carry = sum / 10;
    }
}

void print_fibonacci(int result[], int length) {
    int i = 0;
    while (i < length && result[i] == 0) {
        i++;
    }

    if (i == length) {
        printf("0");
    } else {
        for (; i < length; i++) {
            printf("%d", result[i]);
        }
    }
    printf("\n");
}

void calculate_fibonacci(int n) {
    clock_t start = clock();
    int maxLength = 200000;
    int *fib1 = calloc(maxLength, sizeof(int));
    int *fib2 = calloc(maxLength, sizeof(int));
    int *result = calloc(maxLength, sizeof(int));
    fib1[maxLength - 1] = 1;

    for (int i = 2; i <= n; i++) {
        add_array_for_fibbo(fib1, fib2, result, maxLength);
        int *temp = fib2;
        fib2 = fib1;
        fib1 = result;
        result = temp;
    }

    print_fibonacci(fib1, maxLength);
    free(fib1);
    free(fib2);
    free(result);
    clock_t end = clock();
    double execution_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Binary Search a durat: %.6f secunde\n", execution_time);
}

void menu_for_first_problem() {
    printf("\n");
    printf("Meniu:\n");
    printf("1. Initializare tablou cu numere aleatorii\n");
    printf("2. Afisare tablou\n");
    printf("3. Eliberare memorie tablou\n");
    printf("4. Sortare tablou folosind Selection Sort\n");
    printf("5. Sortare tablou folosind Quick Sort\n");
    printf("6. Iesire\n");
}
void problem_1()
{
    int *array = NULL;
    int dimensiune = 0;
    int optiune;

    do {
        menu_for_first_problem();
        printf("Alege o optiune: ");
        scanf("%d", &optiune);

        switch (optiune) {
            case 1:
                printf("Introdu dimensiunea tabloului: ");
                scanf("%d", &dimensiune);
                array = (int *)malloc(dimensiune * sizeof(int));
                initialize_array(array, dimensiune);
                break;
            case 2:
                if (array == NULL) {
                    printf("Tabloul nu este initializat.\n");
                } else {
                    print_array(array, dimensiune);
                }
                break;
            case 3:
                if (array != NULL) {
                    free_array(array);
                    array = NULL;
                    printf("Memoria tabloului a fost eliberata.\n");
                } else {
                    printf("Tabloul nu este initializat.\n");
                }
                break;
            case 4:
                if (array == NULL) {
                    printf("Tabloul nu este initializat.\n");
                } else {
                    selection_sort(array, dimensiune);
                }
                break;
            case 5:
                if (array == NULL) {
                    printf("Tabloul nu este initializat.\n");
                } else {
                    clock_t start = clock();
                    quick_sort(array, 0, dimensiune - 1);
                    clock_t end = clock();
                    double timp_executie = ((double)(end - start)) / CLOCKS_PER_SEC;
                    printf("Sortarea cu Quick Sort a durat: %.6f secunde\n", timp_executie);
                }
                break;
            case 6:
                printf("Iesire din program.\n");
                if (array != NULL) {
                    free_array(array);
                }
                break;
            case 7:
                return;
            default:
                printf("Optiune invalida!\n");
        }
    } while (optiune != 6);
}
void menu_for_second_problem()
{
    printf("1. Initializare tablou cu numere aleatorii\n");
    printf("2. Afisare tablou\n");
    printf("3. Eliberare memorie tablou\n");
    printf("4. Cautare numar utilizand Linear Search\n");
    printf("5. Cautare numar utilizand Binary Search\n");
    printf("6. Iesire\n");
}

void problem_2()
{
    int *array = NULL;
    int dimensiune = 0;
    int optiune;

    do {
        menu_for_second_problem();
        printf("Alege o optiune: ");
        scanf("%d", &optiune);

        switch (optiune) {
            case 1:
                printf("Introdu dimensiunea tabloului: ");
                scanf("%d", &dimensiune);
                array = (int *)malloc(dimensiune * sizeof(int));
                initialize_array(array, dimensiune);
                break;
            case 2:
                if (array == NULL) {
                    printf("Tabloul nu este initializat.\n");
                } else {
                    print_array(array, dimensiune);
                }
                break;
            case 3:
                if (array != NULL) {
                    free_array(array);
                    array = NULL;
                    printf("Memoria tabloului a fost eliberata.\n");
                } else {
                    printf("Tabloul nu este initializat.\n");
                }
                break;
            case 4:
                if (array == NULL) {
                    printf("Tabloul nu este initializat.\n");
                } else {
                    int valoare;
                    printf("Introdu valoarea pe care doresti sa o cauti: ");
                    scanf("%d", &valoare);
                    double rezultat = get_function_execution_time(linear_search,array,dimensiune,valoare);
                    printf("Timpul de executie %lf", &rezultat);

                }
                break;
            case 5:
                if (array == NULL) {
                    printf("Tabloul nu este initializat.\n");
                } else {
                    int valoare;
                    printf("Introdu valoarea pe care doresti sa o cauti: ");
                    scanf("%d", &valoare);
                    int rezultat = binary_search(array, dimensiune, valoare);
                    if (rezultat != -1) {
                        printf("Valoarea %d a fost gasita la indexul %d.\n", valoare, rezultat);
                    } else {
                        printf("Valoarea %d nu a fost gasita in tablou.\n", valoare);
                    }
                }
                break;
            case 6:
                printf("Iesire din program.\n");
                if (array != NULL) {
                    free_array(array);
                }
                break;
            case 7:
                return;
            default:
                printf("Optiune invalida!\n");
        }


    } while (optiune != 6);
}
