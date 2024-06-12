#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#define MAXLINE 1024

int main(int argc, char *argv[]){
    int pfd [2], status;
    char line[MAXLINE];
    pipe(pfd);
    if (fork() > 0){ // father
        close (pfd[0]); //  chiusura del lato di lettura, in questo modo il padre scrive e baste
        write(pfd[1], argv[1], strlen(argv[1]));
        wait(&status);
    } else { // child
        close(pfd[1]); // chiusura del lato di scrittura
        read(pfd[0], line, MAXLINE);
        printf("Received: %s\n", line);
    }
    exit(0);
}
