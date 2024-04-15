#include <stdio.h>

int calc(double left, char op, double right, double *ans) {
  switch(op) {
  case '+': *ans = left + right;
        break;
  case '-': *ans = left - right;
        break;
  case '*': *ans = left * right;
        break;
  case '/': *ans = left / right;
        break;
  default: fprintf(stderr, "Simbol not recognized");
        return -1;
  }
  return 0;
}
