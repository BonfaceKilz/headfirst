#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{
        char *feeds[][2] = {{"Bonface Munyoki",
                          "https://bonfacemunyoki.com/index.xml"},
                         {"Slashdot",
                          "http://rss.slashdot.org/Slashdot/slashdotMain"}};

        int times = 2;
        char *phrase = argv[1];
        int i;
        for (i = 0; i < times; i++) {
                char var[255];
                // sprintf(var, ' ""%s" "%s" ' , feeds[i][0], feeds[i][1]);
                char *vars[] = {var, NULL};
                pid_t pid = fork();

                if (pid == -1) {
                        fprintf(stderr, "Can't fork process: %s\n",
                                strerror(errno));
                        return 1;
                }
                printf("%s", var);
                if (!pid) {

                        if (execl("/usr/bin/python2",
                                   "/usr/bin/python2",
                                   "./rssgossip.py",
                                  feeds[i][0], feeds[i][1], NULL) == -1) {
                                fprintf(stderr, "Can't run script: %s\n",
                                        strerror(errno));
                                return 1;
                        }
                }
        }
        return 0;
}
