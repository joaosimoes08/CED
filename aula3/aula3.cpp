/*
HPC
aula3.cpp
João Simões
2024-10-30
um exemplo de soma integral para cálculo de áreas
*/

#include <iostream>
#include <cmath>
#include <omp.h>
#include <unistd.h>

// função que devolve uma constante
double f1(double x) {
    return 1.0;
}

double f2(double x) {
    return x * x;
}

double f_pi(double x) {
    return sqrt(1.0 - x * x);
}


double soma_integral(double a, double b, int N,
                     double (*f)(double) ) {
    double s = 0.0;
    double dx = (b - a) / N;

    for (int k = 0; k < N; k++) {
        s += f(a + k * dx) * dx;
    }
    return s;
}

int main() {
    std::cout << "Hello World!"
              << std::endl;

    double a = 0.0;
    double b = 1.0;
    int N = 5000000;

    double s = soma_integral(a, b, N, f_pi);
    double pi = 4 * s;

    std::cout << "pi = " << pi << std::endl;

    // for(int k = 0; k < 10; k++) {
    //     std::cout << k << std::endl;
    // }

    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        for (int n = 0; n < 5; n++) {
            double s = soma_integral(a, b, N, f_pi);
            std::cout << thread_id << std::endl;
        }
    }
    return 0;
}
