#include <stdio.h>

#include "calc.h"

int main(void) {

  double ans;

  calc(3, '-', 2, &ans);
  printf("3 - 2 = %lf\n\n", ans);
  ans = 0;
  
  calc(3, '+', 2, &ans);
  printf("3 + 2 = %lf\n\n", ans);
  ans = 0;
  
  calc(3, '*', 2, &ans);
  printf("3 * 2 = %lf\n\n", ans);
  ans = 0;
  
  calc(3, '/', 2, &ans);
  printf("3 / 2 = %lf\n\n\n", ans);

  return 0;
}
