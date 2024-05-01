#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    pid_t pid;

    printf("T1\n");
    pid = fork();
    if (pid == 0){ // first child T3
        printf("T3 DNS: a.com \n");
        pid_t pid_2;
        pid_2 = fork();
        if (pid_2 == 0){ // second child T6
            printf("T6 HTTP: http://b.com/2\n");
            return 0;
        }else{ // second parent T5
            printf("T5 HTTP: http://b.com/1\n");
            waitpid(pid_2, NULL, 0);
            return 0;
        }
    } else{ // parent T2
        printf("T2 DNS: a.com\n");
        printf("T4 HTTP: http://a.com/\n");
        waitpid(pid, NULL, 0);
    }
    printf("T7\n");
    return 0;
}