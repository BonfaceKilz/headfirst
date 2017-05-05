#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int NUM_ADS = 7;
char *ADS[] = {
  "William: SBM GSOH likes sports, TV, dining",
  "Matt: SWM NS likes art, movies, theater",
  "Luis: SLM ND likes books, theater, art",
  "Mike: DWM DS likes trucks, sports and bieber",
  "Peter: SAM likes chess, working out and art",
  "Josh: SJM likes sports, movies and theater",
  "Jed: DBM likes theater, books and dining"
};

int sports_no_bieber(char *s) {
  return strstr(s, "sports") && !strstr(s, "bieber");
}

int sports_or_workout(char *s) {
  return strstr(s, "sports") || strstr(s, "working out");
}

int ns_theater(char *s) {
  return strstr(s, "NS") && strstr(s, "theatre");
}

int arts_theatre_or_dining(char *s) {
  return strstr(s, "arts") || strstr(s, "theater") || strstr(s, "dining");
}

void find( int (*match)(char*)) {
  int i;
  puts("Search results");
  puts("-------------------");

  for (i = 0; i < NUM_ADS; i++) {
    if (match(ADS[i])) {
      printf("%s\n", ADS[i]);
    }
  }
  puts("------------------");
}

int main()
{
  find(sports_no_bieber);
  find(sports_or_workout);
  find(ns_theater);
  find(arts_theatre_or_dining);
  return 0;
}

/*
Search results
-------------------
William: SBM GSOH likes sports, TV, dining
Josh: SJM likes sports, movies and theater
------------------
Search results
-------------------
William: SBM GSOH likes sports, TV, dining
Mike: DWM DS likes trucks, sports and bieber
Peter: SAM likes chess, working out and art
Josh: SJM likes sports, movies and theater
------------------
Search results
-------------------
------------------
Search results
-------------------
William: SBM GSOH likes sports, TV, dining
Matt: SWM NS likes art, movies, theater
Luis: SLM ND likes books, theater, art
Josh: SJM likes sports, movies and theater
Jed: DBM likes theater, books and dining
------------------
*/
