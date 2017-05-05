#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[])
{
  int stock = 180;
  int order;

  while (stock > 0) {
    printf("%i glasses left\n", stock);
    scanf("%i", &order);
    stock = stock - order;
    printf("You ordered %i glasses\n", order);
  }
  puts("We're out of stock, baby!");
  return 0;
}
