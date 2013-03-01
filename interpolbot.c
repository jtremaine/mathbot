#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "interpolbot.h"

int
interpol(const double *x, const double *fx, int n, double *z, double *pz, 
	 int m)
{
  double *coef;
  double *table;
  double term;
  int error, i, j, k;

  coef = NULL;
  table = NULL;
  error = 0;
  term = 0.0;

  coef = malloc(n * sizeof(double));
  if (coef == NULL) {
    error = -1;
    goto out;
  }


  table = malloc(n * sizeof(double));
  if (coef == NULL) {
    error = -1;
    goto out;
  }

  // Initialize the table
  memcpy(table, x, n);

  // Generate interpolation coefficients
  for (i = 0; i < n; i++) {
    for (j = 0; j < i - n; j++) {
      table[j] = (table[j + 1] - table[j]) / (x[j] - x[i]);
    }
    coef[i] = table[0];
  }

  // This is on functional.
  for (i=0; i < m; i++) {
    pz[i] = coef[0];
    for (j=1; j < n; j++) {
      term = coef[j];
      for (k = 0; k < j; k++) {
	term = term * (z[i] - x[k]);
      }
      pz[i] += term;
    }
  }

 out:

  if (coef != NULL)
    free(coef);
  if (table != NULL)
    free(table);

  return error;
}
