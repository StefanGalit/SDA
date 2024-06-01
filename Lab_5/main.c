#include <stdio.h>

#include "func.h"
#include "benchmark.h"
int main()
{
    int n;
    do {
        printf("1.Problema 1\n");
        printf("2.Problema 2\n");
        printf("3.Problema 3\n");
        printf("Alegeti problema\n");
        printf("Alege o optiune: ");
        scanf("%d", &n);

        switch (n) {
            case 1:
                problem_1();
                break;
            case 2:
                problem_2();
                break;
            case 3:
                int number;
                printf("Introdu numarul unui element din sirul Fibonacci\n ");
                scanf("%d", &number);
                calculate_fibonacci(number);
                break;
            case 4:
                printf("Iesire din program.\n");
                return 0;
            default:
                printf("Optiune invalida!\n");
        }
    } while (n != 4);

//    double execution_time = 0.0;
//    get_execution_time(execution_time) {
//        calculate_fibonacci(50);
//    }
//    printf("Execution time = %lf\n", execution_time);
//
//    execution_time = 0.0;
//    GET_EXEC_TIME(execution_time) {
//        calculate_fibonacci(50);
//    }
//    printf("==Execution time = %lf\n", execution_time);
    return 0;

}



