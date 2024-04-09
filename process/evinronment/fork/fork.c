#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;

int main()
{
    int pid = 0;
    int wstatus = 0;

    pid = fork();
    if (pid == 0) {
        printf("I am child\n");
        execl("./new_program", "new_program", NULL);
    } else {
        printf("I am parrent, child pid: %d\n", pid);
    }

    wait(&wstatus);

    while(1);

    return 0;
}