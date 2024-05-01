#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
int main(){
    pid_t pid;
    printf("T1\n");
    pid = fork();
    if (pid == 0){ // child
        //sleep(1);
        printf("T3\n");
        return 0;
    }
    else{ // father
        printf("T2\n");
        //waitpid(pid, NULL, 0);
        wait((int *)0); // wait for any child to terminate
    }
    printf("T4\n");
    return 0;
    }