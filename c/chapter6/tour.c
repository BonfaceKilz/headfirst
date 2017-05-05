#include <stdio.h>
#include <stdlib.h>
#include "island.h"

int main()
{
  island amity = {"Amity",
                  "09:00",
                  "17:00",
                  NULL};

  island craggy = {"Craggy",
                   "09:00",
                   "17:00",
                   NULL};

  island isla_nublar = {"Isla Nublar",
                        "09:00",
                        "17:00",
                        NULL};

  island shutter = {"Shutter",
                    "09:00",
                    "17:00",
                    NULL};

  island skull = {"Skull",
                  "09:00",
                  "17:00",
                  NULL};

  amity.next = &craggy;
  craggy.next = &isla_nublar;
  isla_nublar.next = &skull;
  skull.next = &shutter;

  display(&amity);
  return 0;
}
// -*- compile-command: "gcc -Wall -o dest file" -*-
