/*
  Creating a variadic function that calculates
  the total of a bunch of drinks
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

enum drink {
  MUDSLIDE, FUZZY_NAVEL, MONKEY_GLAND, ZOMBIE
};

double price(enum drink d) {
  switch (d) {
  case MUDSLIDE:
    return 6.79;
  case FUZZY_NAVEL:
    return 5.31;
  case MONKEY_GLAND:
    return 4.82;
  case ZOMBIE:
    return 5.89;
  }
  return 0;
}

double total(int args, ...) {
  double total = 0;
  va_list drink_list;
  va_start(drink_list, args);
  int i;
  for (i = 0; i < args; i++) {
    total += price(va_arg(drink_list, enum drink));
  }
  va_end(drink_list);
  return total;
}

int main(int argc, char *argv[])
{
  printf("Price is %.2f\n", total(2, MONKEY_GLAND, MUDSLIDE));
  printf("Price is %.2f\n", total(3, MONKEY_GLAND, MUDSLIDE, FUZZY_NAVEL));
  printf("Price is %.2f\n", total(1, ZOMBIE));

  return 0;
}
