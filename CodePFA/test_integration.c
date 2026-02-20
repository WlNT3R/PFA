/******************************************************/
/* Program to run and test the integration functions. */
/* Creation date: 31 July, 2025                       */
/******************************************************/

#include "integration.h"

/* Code here everything you need to test the integration methods and show your
 * numericzal results */

double f(double t) { return t * t; }

int main() {
  QuadFormula qf;
  setQuadFormula(&qf, "left");
  double integral = integrate(f, 0, 2, 1000, &qf);
  printf("Integral of t from 0 to 2 with left quadrature formula: %f\n",
         integral);
  setQuadFormula(&qf, "right");
  integral = integrate(f, 0, 2, 1000, &qf);
  printf("Integral of t from 0 to 2 with right quadrature formula: %f\n",
         integral);
  setQuadFormula(&qf, "mid");
  integral = integrate(f, 0, 2, 1000, &qf);
  printf("Integral of t from 0 to 2 with mid quadrature formula: %f\n",
         integral);
  setQuadFormula(&qf, "trapeze");
  integral = integrate(f, 0, 2, 1000, &qf);
  printf("Integral of t from 0 to 2 with trapeze quadrature formula: %f\n",
         integral);
  setQuadFormula(&qf, "simpson");
  integral = integrate(f, 0, 2, 1000, &qf);
  printf("Integral of t from 0 to 2 with simpson quadrature formula: %f\n",
         integral);
  setQuadFormula(&qf, "gauss-2");
  integral = integrate(f, 0, 2, 1000, &qf);
  printf("Integral of t from 0 to 2 with gauss-2 quadrature formula: %f\n",
         integral);
  setQuadFormula(&qf, "gauss-3");
  integral = integrate(f, 0, 2, 1000, &qf);
  printf("Integral of t from 0 to 2 with gauss-3 quadrature formula: %f\n",
         integral);
  return 0;
}
