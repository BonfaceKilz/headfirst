#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char *argv[])
{
  char *my_env = {"FOOD=coffee", NULL};
  if (execle("./coffee", "./coffee", "donuts", NULL, my_env) == -1) {
    fprintf(stderr, "Can't run process : %s\n", strerror(errno));
  }

  char *my_env1 = {"FOOD=donuts", NULL};
  if (execle("./coffee", "./coffee", "cream", NULL, my_env1) == -1) {
    fprintf(stderr, "Can't run process 0:  %s\n", strerror(errno));
    return 1;
  }

  if (execl("./coffee", "coffee", NULL) == -1) {
    fprintf(stderr, "Can't run process 0: %s\n", strerror(errno));
  }
  return 0;
}
