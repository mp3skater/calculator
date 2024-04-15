#include <stdio.h>
#include <string.h>

#include "getNum.h"

int main(void) {
  char a[10];

  while(1) {
    fgets(a, 9, stdin);
    fprintf(stderr, "\n%s", a);
    double d = getNum(a, 2, 2);
    fprintf(stderr, "\ngetNum = %lf\n", d);

  }

  return 0;
}
