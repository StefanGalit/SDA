//
// Created by Ștefan on 16.05.2024.
//

#include "benchmark.h"

double get_function_execution_time( int (*fun)(int*, int, int), int* p1, int p2, int p3 ) {

    clock_t start_t = clock();

    fun(p1, p2, p3);

    clock_t end_t = clock();

    return ((double)(end_t - start_t)) / CLOCKS_PER_SEC;
}