#define INTEGRATION_C

#include "integration.h"

bool setQuadFormula(QuadFormula *qf, char *name) {
  strncpy(qf->name, name, sizeof(qf->name) - 1);
  qf->name[sizeof(qf->name) - 1] = '\0';

  if (strcmp(name, "left") == 0) {
    qf->n = 0;
    qf->xk = malloc((qf->n + 1) * sizeof(double));
    qf->wk = malloc((qf->n + 1) * sizeof(double));
    qf->xk[0] = 0;
    qf->wk[0] = 1;
    return true;
  } else if (strcmp(name, "right") == 0) {
    qf->n = 0;
    qf->xk = malloc((qf->n + 1) * sizeof(double));
    qf->wk = malloc((qf->n + 1) * sizeof(double));
    qf->xk[0] = 1;
    qf->wk[0] = 1;
    return true;
  } else if (strcmp(name, "middle") == 0) {
    qf->n = 0;
    qf->xk = malloc((qf->n + 1) * sizeof(double));
    qf->wk = malloc((qf->n + 1) * sizeof(double));
    qf->xk[0] = 0.5;
    qf->wk[0] = 1;
    return true;
  } else if (strcmp(name, "trapeze") == 0) {
    qf->n = 1;
    qf->xk = malloc((qf->n + 1) * sizeof(double));
    qf->wk = malloc((qf->n + 1) * sizeof(double));
    qf->xk[0] = 0;
    qf->xk[1] = 1;
    qf->wk[0] = 0.5;
    qf->wk[1] = 0.5;
    return true;
  } else if (strcmp(name, "simpson") == 0) {
    qf->n = 2;
    qf->xk = malloc((qf->n + 1) * sizeof(double));
    qf->wk = malloc((qf->n + 1) * sizeof(double));
    qf->xk[0] = 0;
    qf->xk[1] = 0.5;
    qf->xk[2] = 1;
    qf->wk[0] = 1.0 / 6;
    qf->wk[1] = 2.0 / 3;
    qf->wk[2] = 1.0 / 6;
    return true;
  } else if (strcmp(name, "gauss2") == 0) {
    qf->n = 1;
    qf->xk = malloc((qf->n + 1) * sizeof(double));
    qf->wk = malloc((qf->n + 1) * sizeof(double));
    qf->xk[0] = (1.0 / 2.0) - 1.0 / (2.0 * sqrt(3.0));
    qf->xk[1] = (1.0 / 2.0) + 1.0 / (2.0 * sqrt(3.0));
    qf->wk[0] = 1.0 / 2.0;
    qf->wk[1] = 1.0 / 2.0;
    return true;
  } else if (strcmp(name, "gauss3") == 0) {
    qf->n = 2;
    qf->xk = malloc((qf->n + 1) * sizeof(double));
    qf->wk = malloc((qf->n + 1) * sizeof(double));
    qf->xk[0] = (1.0 / 2.0) * (1.0 - sqrt(3.0 / 5.0));
    qf->xk[1] = 1.0 / 2.0;
    qf->xk[2] = (1.0 / 2.0) * (1.0 + sqrt(3.0 / 5.0));
    qf->wk[0] = 5.0 / 18;
    qf->wk[1] = 4.0 / 9;
    qf->wk[2] = 5.0 / 18;
    return true;
  } else
    return false;
}

/* This function is not required ,but it may useful to debug */
void printQuadFormula(QuadFormula *qf) {
  printf("Quadratic formula: %s\n", qf->name);
  printf("n = %d\n", qf->n);
  printf("xk = [ ");
  for (int i = 0; i < qf->n + 1; i++) {
    printf("%f ", qf->xk[i]);
  }
  printf("]\n");
  printf("wk = [ ");
  for (int i = 0; i < qf->n + 1; i++) {
    printf("%f ", qf->wk[i]);
  }
  printf("]\n");
}

/* Forward declaration so integrate can call integrate_dx */
double integrate_dx(double (*f)(double), double a, double b, double dx,
                    QuadFormula *qf);

/* Approximate the integral of function f from a to b.
   - f is a pointer to a function pointer
   - a and b are the integration bounds
   - Interval [a,b] is split in N subdivisions [ai,bi]
   - Integral of f on each subdivision [ai,bi] is approximated by the quadrature
   formula qf.
*/
double integrate(double (*f)(double), double a, double b, int N,
                 QuadFormula *qf) {
  return integrate_dx(f, a, b, (b - a) / N, qf);
}

double integrate_dx(double (*f)(double), double a, double b, double dx,
                    QuadFormula *qf) {
  double integral = 0.0;
  int N = (int)round((b - a) / dx);
  for (int i = 0; i < N; i++) {
    double ai = a + i * dx;
    double sum = 0.0;
    for (int k = 0; k <= qf->n; k++) {
      sum += qf->wk[k] * f(ai + dx * qf->xk[k]);
    }
    integral += sum * dx;
  }
  return integral;
}
