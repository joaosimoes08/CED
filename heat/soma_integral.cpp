#include <iostream>
#include <omp.h>
#include <cmath>
#include "farao.h"

 // a soma integral
double soma_integral(double (*fp)(double), double a, double b, int N){
double soma = 0.0;
double dx = (b-a)/N;

#pragma omp parallel for
	for (size_t k = 1; k <= N; k++) {
	int tid = omp_get_thread_num();
if (_OPENMP) {
 std::cout << tid << " " << soma << std::endl;
 }
 soma += fp( a + k*dx ) * dx;
 }
 return soma;
}
