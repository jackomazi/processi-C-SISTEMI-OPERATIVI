#include <stdio.h>
#include <ctype.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char * argv[]){
int i, n, l;
FILE * f;
char buffer[512];
i = mkfifo("myfifo", S_IRWXU);
if (i<0){
printf("Impossible creare la FIFO\n"); /* Potrebbe già esistere */
}
f = fopen("myfifo", "r");
if (f==NULL){
printf("Impossible aprire la FIFO\n");
exit(1);
}
while(fgets(buffer,sizeof(buffer),f)!=NULL){
l = strlen(buffer);
for (i=0; i<l; i++)
putc(toupper(buffer[i]), stdout);
}
}