#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
void error(char *msg)
{
        fprintf(stderr, "%s: %s\n", msg, strerror(errno));
        exit(1);
}

int main(int argc, char *argv[])
{
        // char *phrase = argv[1];
        // char *vars[] = {"RSS_FEED=http://www.cnn.com/rss/celebs.xml", NULL};
        char *feeds[][2] = {{"Bonface Munyoki",
                          "https://bonfacemunyoki.com/index.xml"},
                         {"Slashdot",
                          "http://rss.slashdot.org/Slashdot/slashdotMain"}};
        FILE *f = fopen("stories.txt", "w");
        if (!f) {
                error("Can't open stories.txt");
        }
        pid_t pid = fork();
        if (pid == -1) {
                error("Can't fork process");
        }
        if (!pid) {
                if (dup2(fileno(f), 1) == -1) {
                        error("Can't redirect Standard Output");
                }
                if (execl("/usr/bin/python2.7", "/usr/bin/python2.7",
                          "./rss/rssgossip.py", feeds[0][0], feeds[0][1], NULL) == -1) {
                        error("Can't run script");
                }
        }

        int pid_status;
        if(waitpid(pid, &pid_status, 0) == -1) {
                error("Error waiting for child process");
        }

        if(WEXITSTATUS(pid_status))
                puts("Error status non-zero");
        return 0;
}
