/******************************************************/
/* Program to run and test the integration functions. */
/* Creation date: 31 July, 2025                       */
/******************************************************/

#include "pfa.h"

/* Code here anything you want to test your pfa functions and to show your
 * numerical results */
int main() {

  init_integration("gauss3", 0.01);

  Option *op;
  op = malloc(sizeof(Option));
  op->type = PUT;
  op->S0 = 100;
  op->K = 114;
  op->T = 2;
  op->mu = 0.05;
  op->sig = 0.02;
  printf("test = %f\n", optionPrice(op));

  double x = 3;
  InsuredClient *client;
  client = malloc(sizeof(InsuredClient));
  client->m = 1;
  client->s = 1;
  client->p = malloc(3 * sizeof(double));
  client->p[0] = 0.9;
  client->p[1] = 0.05;
  client->p[2] = 0.05;
  printf("PDF of X(x) = %f, x = %f\n", clientPDF_X(client, x), x);
  printf("CDF of X(x) = %f, x = %f\n", clientCDF_X(client, x), x);
  printf("PDF of X1X2(x) = %f, x = %f\n", clientPDF_X1X2(client, x), x);
  printf("CDF of X1X2(x) = %f, x = %f\n", clientCDF_X1X2(client, x), x);
  printf("CDF of S(x) = %f, x = %f\n", clientCDF_S(client,x), x);
  free(client->p);
  free(client);
  return 0;
}
