/*
 * Module: stacklist.c
 * Author: mp3skater
 * Version: 0.1
 * Last edit: 2024/01/18
 * Lizence: MIT Lizence
 * Changelog:
 * 	2024/01/18 -- mp3skater: Initial commit
 * 	2024/01/22 -- mp3skater: Finishing push(), correct stack.h to include return value, changing int inhalt to int value, starting pop();
 * 	2024/01/24 -- mp3skater: Implement free() and excurrent element to reset last pointer.
 * 	2024/01/25 -- mp3skater: Despared try to debug the code as push allways gives the latest number.
 * 	2024/01/31 -- mp3skater: Tidyed up code, corrected push to get the last inserted value not the last value of the list
 * 	2024/02/17 -- mp3skater: Changed value type to double, cleaned up pop(), changed error message in double
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

#include "stack.h"

static list_t *head = NULL; // The firt element of the stack

/*
 * Parameter: Integer Value that gets added to the list.
 * Return: -1: Error, stack wast't added. Probably becouse allocated memory is full.
 * 	    0: Push was successfull.
 * Sideeffects: A new list_t-element gets added,
 * 	pointer of that list_t-element directs to the last head;
 * Usage: This function adds a new element to the stack, increasing the space needed.
 *
 */
int push(double new_value)
{
  // ONE ELEMENT
  if(head == NULL) {
    head = (list_t*)malloc(sizeof(list_t));
    
    // MALLOC DIDN'T WORK
    if(head == NULL) {
      // Schimpfen...
      fprintf(stderr, "--> Error: Couldn't allocate memory, probably out of allocated memory.");
      return -1;
    }

    // MALLOC WORKED
    (*head).next = NULL;
    (*head).value = new_value;
  }


  // MULTIPLE ELEMENTS
  list_t *new_l = (list_t*)malloc(sizeof(list_t));

  // MALLOC DIDN'T WORK
  if(new_l == NULL) {
    // Schimpfen...
    fprintf(stderr, "--> Error: Couldn't allocate memory, probably out of allocated memory.");
    return -1;
  }

  // MALLOC WORKED

  // New list_t with pointer to last head
  (*new_l).value = new_value;
  (*new_l).next = head;
  head = new_l;

  return 0;
}

/*
 *
 * Parameter: /
 * Return:               -1: Error, there is no stack-element to pop.
 *         any other number: Pop was successfull.
 * Sideeffects: The last element gets deleted,
 *      pointer of the new last element gets reset to NULL;
 * Usage: The first element of the list gets returned and deleted.
 *
 */
double pop(void)
{
  // No Elements
  if(head == NULL) {
    fprintf(stderr, "Stacklist Notice: No elements available to pop(), add a new element to use this funktion.");
    return -1;
  }
 
  list_t *next_l = (*head).next;
  
  // One Element
  if(next_l == NULL) {
    double temp = head -> value;
    free(head);
    return temp;
  }

  // Multiple Elements
  double temp = head -> value;
  free(head);
  head = next_l;
  return temp;
}
