#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    char command[50] = "ls -lh ";

    if (argc ==2){
        strcat(command, argv[1]);
    }

    system(command);

    return 0;
}