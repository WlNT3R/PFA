#define INTEGRATION_C

#include "integration.h"

bool setQuadFormula(QuadFormula* qf, char* name)
{
	
	if(strcmp(name,"left") == 0){
		qf->n = 0;
		double arrx[qf->n+1];
		double arrw[qf->n+1];
		arrx[0] = 0;
		arrw[0] = 1;
		qf->xk = arrx;
		qf->wk = arrw;
		return true;
	}
	if(strcmp(name,"right") == 0){
		qf->n = 0;
		double arrx[qf->n+1];
		double arrw[qf->n+1];
		arrx[0] = 1;
		arrw[0] = 1;
		qf->xk = arrx;
		qf->wk = arrw;
		return true;
	}
	if(strcmp(name,"mid") == 0){
		qf->n = 0;
		double arrx[qf->n+1];
		double arrw[qf->n+1];
		arrx[0] = 0.5;
		arrw[0] = 1;
		qf->xk = arrx;
		qf->wk = arrw;
		return true;
	}
	/*if(strcmp(name,"trapeze") == 0){
		qf->n = 1;
		double arrx[qf->n+1];
		double arrw[qf->n+1];
		arrx[0] = 0;
		arrx[1] = 1;
		arrw[0] = 0.5;
		arrw[1] = 0.5;
		qf->xk = arrx;
		qf->wk = arrw;
		return true;
	}
	if(strcmp(name,"simpson") == 0){
		qf->n = 2;
		double arrx[qf->n+1];
		double arrw[qf->n+1];
		arrx[0] = 0;
		arrx[1] = 0.5;
		arrx[2] = 1;
		arrw[0] = 1/6;
		arrw[1] = 4/6;
		arrw[2] = 1/6;
		qf->xk = arrx;
		qf->wk = arrw;
		return true;
	}
	if(strcmp(name,"gauss-2") == 0){
		qf->n = 2;
		double arrx[qf->n+1];
		double arrw[qf->n+1];
		arrx[0] = 0;
		arrx[1] = 0.5;
		arrx[2] = 1;
		arrw[0] = 1/6;
		arrw[1] = 4/6;
		arrw[2] = 1/6;
		qf->xk = arrx;
		qf->wk = arrw;
		return true;
	}
	if(strcmp(name,"gauss-3") == 0){
		qf->n = 3;
		double arrx[qf->n+1];
		double arrw[qf->n+1];
		arrx[0] = 0;
		arrx[1] = 0.5;
		arrx[2] = 1;
		arrw[0] = 1/6;
		arrw[1] = 4/6;
		arrw[2] = 1/6;
		qf->xk = arrx;
		qf->wk = arrw;
		return true;
	}*/
	return false;
}

/* This function is not required ,but it may useful to debug */
void printQuadFormula(QuadFormula* qf)
{
  printf("Quadratic formula: %s\n", qf->name);
  printf("n = %d\n", qf->n);
  printf("xk = [ ");
  for(int i = 0; i < qf->n+1; i++){
    printf("%f ", qf->xk[i]);
  }
  printf("]\n");
  printf("wk = [ ");
  for(int i = 0; i < qf->n+1; i++){
    printf("%f ", qf->wk[i]);
  }
  printf("]\n");
}

/* Approximate the integral of function f from a to b.
   - f is a pointer to a function pointer
   - a and b are the integration bounds
   - Interval [a,b] is split in N subdivisions [ai,bi]
   - Integral of f on each subdivision [ai,bi] is approximated by the quadrature formula qf.
*/
double integrate(double (*f)(double), double a, double b, int N, QuadFormula* qf)
{
	return integrate_dx((*f)(double),a,b,(b-a)/N,qf);
}

double integrate_dx(double (*f)(double), double a, double b, double dx, QuadFormula* qf)
{
	double integral = 0.0;
	double rect = 0.0;
	for(int i = a;i < b;i += dx){
		double t = f(i + dx*qf->xk);
		rect = t * dx;
		integral += rect;}
	return integral;
}


