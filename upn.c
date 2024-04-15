/*
 *
 * Module: upn.c
 * Author: mp3skater
 * Version: 0.1
 * Lizence: MIT Lizence
 * Changelog:
 *            2024/02/01 -- mp3skater: Initial commit
 *            2024/02/05 -- mp3skater: added getNum(), continue working on main, added calc(), calc with pointer and return value, calc() and getNum() as seperate modules (added getNum.c, getNum.h, calc.c, calc.h)
 *            2024/02/16 -- mp3skater: correct int l: from strlen(a-1) to strlen(a)-1, added comments to the variables, int l as only stop-parameter of the for loop, using numbers instead of char-notation( '' )(needs to be fixed for better mutability later, all comments with capital letters, debugged parameters of getNum()
 *            2024/02/17 -- mp3skater: changed left and right to be doubles
 *
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "calc.h"
#include "getNum.h"
#include "stack.h"

int main(void)
{
  // ANSWER VARIABLE
  double ans = 0;
  
  // STACK VARIABLES
  double left;
  double right;
  int nInd = -1;

  // OTHER
  char a[100];
  fgets(a, 99, stdin);
  int l = strlen(a)-1;

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

  fprintf(stdout, "\n\nThe answer is %lf\n\ndone...\n\n", pop());

  return 0;
}
