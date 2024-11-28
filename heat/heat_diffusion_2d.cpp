#include <iostream>
#include <fstream>
#include <cmath>

#include "farao.h"

 void heat_diffusion_2d() {
 double alfa_gold = 127; // (mm2) / miliseconds

 int M = 100; // 100 mm
 int N = 100; // 100 mm
 // initial memory for the temperatures of the plate
 double** A = new double*[ M ];
 double** B = new double*[ M ];

 for(int m = 0; m < M; m++) {
 A[ m ] = new double[ N ];
 B[ m ] = new double[ N ];
 }

 double T0 = 25.0; // 25 degrees Celsius
 double Tb = 100.0; // 100 degrees Celsius

 // initial inner conditions
 for(int m = 0; m < M; m++) {
 for(int n = 0; n < N; n++) {
 A[ m ][ n ] = T0;
 B[ m ][ n ] = T0;
 }
 }

 // boundary conditions
 for(int m = 0; m < M; m++) {
 A[ m ][ 0 ] = Tb;
 B[ m ][ 0 ] = Tb;

 A[ m ][ N-1 ] = Tb;
 B[ m ][ N-1 ] = Tb;
 }
 for(int n = 0; n < N; n++) {
 A[ 0 ][ n ] = Tb;
 B[ 0 ][ n ] = Tb;

 A[ M-1 ][ n ] = Tb;

 B[ M-1 ][ n ] = Tb;
 }

 // time evolution in miliseconds
 double t = 0.0;
 double final_time = 30000.0; // 10 seconds = 10000 miliseconds
 double dt = 1.0; // miliseconds
 while( t < final_time ) {
 for(int m = 1; m < M-1; m++) {
 for(int n = 1; n < N-1; n++) {
 double a0 = A[ m ][ n ]; // center
 double aW = A[ m+1 ][ n ]; // West
 double aE = A[ m-1 ][ n ]; // East
 double aN = A[ m ][ n+1 ]; // North
 double aS = A[ m ][ n-1 ]; // South

 B[ m ][ n ] = a0 + ( aW + aE + aN + aS - 4.0 * a0) / alfa_gold;
 }
 }

 // the new array of temperatures is copied into A
 for(int m = 1; m < M-1; m++) {
 for(int n = 1; n < N-1; n++) {
 A[ m ][ n ] = B[ m ][ n ];
 }
 }

 t += dt;
 }

 // write the simulation result into a file
 // and use gnuplot to plot
 std::ofstream out_file;
 out_file.open( "simul30seg" );
 for(int m = 0; m < M; m++) {
 for(int n = 0; n < N; n++) {
 out_file << m << ' ' << n << ' ' << A[ m ][ n ] << std::endl;
 }
 out_file << std::endl;
 }
 out_file.close();

 for(int m = 0; m < M; m++) {
 delete [] A[ m ];
 delete [] B[ m ];
 }
delete [] A;

 delete [] B;
}
