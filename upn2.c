/*
 *
 * Module: upn2.c
 * Author: mp3skater
 * Version: 0.1
 * License: MIT
 * Changelog:
 *            2024/03/04 -- mp3skater: Initial commit
 *            2
 *
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "calc.h"
#include "getNum.h"
#include "stack.h"

#define MAX_LEN 256

/*
 * Parameter: A char[] which containes the equation
 * Rückgabe: The answer in double
 * Schnittstellen: K.A
 * AIAIAIA: K.A
 * Aufgabe: Berechnung mehrer funktionen UPN mit Datei
 *
 */
double getUPN(char *);

int main(void)
{
  // OPEN FILE
  FILE * data;
  data = fopen("/home/derretter/c/stack/upn/equ.txt", "r");
  // ERROR FILE NOT FOUND
  if(data == NULL) {
    printf("Error, file \"/home/derretter/c/stack/upn/equ.txt\"");
    return 1;
  }

  char buffer[MAX_LEN];
    while(fgets(buffer, MAX_LEN, data))
    {
        // Remove trailing newline
        buffer[strcspn(buffer, "\n")] = 0;
        printf("%lf\n", getUPN(buffer));
    }

    fclose(data);
    return 0;
}

double getUPN(char *a) {
  // ANSWER VARIABLE
  double ans = 0;
  
  // STACK VARIABLES
  double left;
  double right;
  int nInd = -1;

  int l = strlen(a);

  for(int i = 0; i<l; i++) {
    
    // DIGIT
    if(isdigit(a[i])) {
      // FIRST DIGIT
      if(nInd == -1)
      	nInd = i;
      continue;
    }

    // SPACE
    else if(a[i] == 32) {
      push(getNum(a, nInd, i-1));
      nInd = -1;
      continue;
    }

    // OPERANT
    else {
      right = pop();
      left = pop();
      calc(left, a[i], right, &ans);
      push(ans);
      i++;
    }
  }
  return pop();
}
