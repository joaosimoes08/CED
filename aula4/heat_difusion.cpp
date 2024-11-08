//lIBRARIES
#include <cmath>
#include <iostream>


//PROGRAM
//should be VOID
double heat_difusion() {
	const int N = 100; //mm
	double *T_n = new double[ N ];
	double *T_n1 = new double[ N ];
	double alpha_gold = 127.0; //127 mm^2/s, coeficiente de difusão térmica
	double t_f = 1000.0; //tempo final (segundos)
	double t = 0.0; //tempo inicial

	//initial temperature
	for ( int k = 0; k < N-2; k++) {
		T_n[ k ] = 25.0;
	}

	//Aquecimento nas duas pontas

	T_n[ 0 ] = 100.0; // warming up temperature on one edge
	T_n[ N-2 ] = 100.0; //warming up temperature on other edge	
	//time representation of each iteration in time
	double dt = 0.1; //seconds
	
	while (t < t_f) {
		for ( int k = 0; k < N-2 ; k++) {
			T_n1[ k ] = T_n[ k ] + (T_n [k + 2 ] - 2.0 * T_n [ k + 1 ] + T_n [ k ]) * dt / alpha_gold;
		}
		std::cout << "t = " << t << " " << " T(t) = " << T_n[ int(N / 2) ] << std::endl;
		t += dt;
		for ( int k = 0; k < N; k++ ) {
			T_n[ k ] = T_n1[ k ];
		}
	}
	
	delete [] T_n;
	delete [] T_n1;

	return 0;
}

//SHOULDN'T EXIST
int main() {
	heat_difusion();
}
