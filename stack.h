#ifndef __STACK_H__
#define __STACK_H__

double pop(void);
int push(double);

typedef
  struct stacklist_s {
    double value;
    struct stacklist_s *next;
  } list_t;

#endif
