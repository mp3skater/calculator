#include <math.h>

int getNum(char a[], int start, int end) {
  int sum = 0;
  for(int i = start; i<=end; i++) {
    sum += (a[i] - '0') * pow(10, end-i);
  }
  return sum;
}
