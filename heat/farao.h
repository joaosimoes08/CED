#ifndef _FARAO
#define _FARAO 1

extern double soma_integral(double (*fp)(double), double a, double b, int N);
extern double f(double);
extern void heat_diffusion();
extern void heat_diffusion_2d();

#endif
