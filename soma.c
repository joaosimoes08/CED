#include <stdio.h>

double f(double x) {
	return 1.0;
}

int main() {
	double a = 0.0;
	double b = 1.0;
	
	int N = 8;
	double dx = (b-a) / N;

	double soma = 0.0;

	for(int k = 1; k<=N; k++) {
		soma += f(k * dx) * dx;
	}	

	printf("area = %g \n", soma);
	return 0;
}
