#ifndef __CALC_H__
#define __CALC_H__

/* 
 *
 * Parameter: (double) first Number, (char) operant (+,-,*,/), (double) second Number
 * Return:
 * 	0: Successful operation
 *     -1: operant not recognized
 * Seiteneffekte: *ans will be changed to the new value
 * Error: *ans will not be changed if operant not recognized
 * Funktion: A simple arithmetic problem with two numbers will be calculated
 *
 */
int calc(double left, char op, double right, double *ans);

#endif
