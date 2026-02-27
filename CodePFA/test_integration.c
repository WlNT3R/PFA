/******************************************************/
/* Program to run and test the integration functions. */
/* Creation date: 31 July, 2025                       */
/******************************************************/

#include "integration.h"

/* Code here everything you need to test the integration methods and show your
 * numerical results */

double f(double t) { return sin(t * t); }

int main() {
  int N = 50;
  double a = -1;
  double b = 4;
  char fun[] = "sin(t*t)";
  QuadFormula qf;
  setQuadFormula(&qf, "left");
  double integral = integrate(f, a, b, N, &qf);
  printf("Integration de %d a %d de %s avec la formule de quadrature "
         "'left': %f\n",
         (int)a, (int)b, fun, integral);

  setQuadFormula(&qf, "right");
  integral = integrate(f, a, b, N, &qf);
  printf("Integration de %d a %d de %s avec la formule de quadrature "
         "'right': %f\n",
         (int)a, (int)b, fun, integral);

  setQuadFormula(&qf, "middle");
  integral = integrate(f, a, b, N, &qf);
  printf("Integration de %d a %d de %s avec la formule de quadrature "
         "'middle': %f\n",
         (int)a, (int)b, fun, integral);

  setQuadFormula(&qf, "trapeze");
  integral = integrate(f, a, b, N, &qf);
  printf("Integration de %d a %d de %s avec la formule de quadrature "
         "'trapeze': %f\n",
         (int)a, (int)b, fun, integral);

  setQuadFormula(&qf, "simpson");
  integral = integrate(f, a, b, N, &qf);
  printf("Integration de %d a %d de %s avec la formule de quadrature "
         "'simpson': %f\n",
         (int)a, (int)b, fun, integral);

  setQuadFormula(&qf, "gauss2");
  integral = integrate(f, a, b, N, &qf);
  printf("Integration de %d a %d de %s avec la formule de quadrature "
         "'gauss-2': %f\n",
         (int)a, (int)b, fun, integral);

  setQuadFormula(&qf, "gauss3");
  integral = integrate(f, a, b, N, &qf);
  printf("Integration de %d a %d de %s avec la formule de quadrature "
         "'gauss-3': %f\n",
         (int)a, (int)b, fun, integral);

  free(qf.xk);
  free(qf.wk);
  return 0;
}
