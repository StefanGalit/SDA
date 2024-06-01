//
// Created by Ștefan on 16.05.2024.
//

#ifndef LAB_5_BENCHMARK_H
#define LAB_5_BENCHMARK_H

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define get_execution_time(x) for(double start_time = (double)(clock())/CLOCKS_PER_SEC, run = 1.0; run == 1.0; run = 0, x=(double)( clock() / (CLOCKS_PER_SEC - start_time) )   )

#define GET_EXEC_TIME(x) for(clock_t start_time = clock(), run = start_time; run == start_time; run = clock(), x=(double)( (clock() - start_time) / (double)CLOCKS_PER_SEC ))

double get_function_execution_time( int (*fun)(int*, int, int), int* p1, int p2,int p3 );


#endif //LAB_5_BENCHMARK_H
