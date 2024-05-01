#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(){
	pid_t pid;
	pid = fork();
	printf("%d\n", pid);
	if (pid == 0){
		printf("Sono il figlio\n");
	} else{
		printf("Sono il padre\n");
	}
	return 0;
}

