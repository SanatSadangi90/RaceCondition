// Sanat Sadangi: Question 3 A)
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define FILENAME "shared_file.txt"

int main(){
    if (fork() == 0){
       printf("Starting Process 2\n");
       if (fork() == 0){
          printf("Starting Process 3\n");
       }
    }

    int counter = 0;
    pid_t pid = getpid();
    FILE *file = fopen(FILENAME, "r+");

    while(counter < 200) {
        int N;
        fscanf(file, "%d", &N);
        printf("Process P%d: Read %d from file. PID: %d\n", pid, N, getpid());
        N++;
        rewind(file);
        fprintf(file, "%d", N);
        fseek(file, 0, SEEK_END);
        counter++;
        //fflush(file);
    }
    fclose(file);
    return 0;
}