#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "island.h"

int main()
{
  char name[80];
  fgets(name, 80, stdin);
  island *p_island0 = create(name);

  fgets(name, 80, stdin);
  island *p_island1 = create(name);
  p_island0->next = p_island1;

  display(p_island0);
  release(p_island0);

  return 0;
}
