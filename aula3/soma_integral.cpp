#include <cmath>
#include <farao.h>

double soma_integral(double a, double b, int N,
                     double (*f)(double) ) {
    double s = 0.0;
    double dx = (b - a) / N;

    for (int k = 0; k < N; k++) {
        s += f(a + k * dx) * dx;
    }
    return s;
}
