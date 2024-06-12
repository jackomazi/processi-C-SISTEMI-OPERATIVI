#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#define MAXSIZE 1000

int main(int argc, char *argv[]){
    int pfd [2], status;
    pipe(pfd);
    if (fork()>0){
        close (pfd[0]);
        FILE * fp;
        char line[MAXSIZE];
        fp = fopen(argv[1], "r");
        while(fgets(line, MAXSIZE, fp) != NULL){ // legge riga per riga nel file
            write(pfd[1], line, strlen(line)); // scrive nella pipe
        }
        close(pfd[1]);
        wait(&status);
        exit(0);    
    }
    else{
        char buffer[MAXSIZE];
        close(pfd[1]);
        while (read(pfd[0], buffer, MAXSIZE) > 0){
            printf("Received: %s\n", buffer);
        }
        exit(0);
}
}