#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char* argv[]){
    int arr[] = {1, 2, 3, 4, 1, 2};
    int arrSize = sizeof(arr)/sizeof(int);
    int start, end;
    int fd[2];
    if(-1 == pipe(fd)){
        printf("ERROR: PIPE failed\n");
        return 1;
    }

    int id = fork();
    if(-1 == id){
        return 1;
    }

    if(0 == id){
        /* if child */
        start = 0;
        end = start + 3;
    }
    else{
        /* if parent */
        start = arrSize / 2;
        end = arrSize;
    }

    int sum = 0;
    int i;
    for(i = start; i < end; i++){
        sum += arr[i];
    }

    printf("Calculated partial sum %d\n", sum);

    if(0 == id){
        close(fd[0]);
        write(fd[1], &sum, sizeof(sum));
        close(fd[1]);
    }
    else{
        close(fd[1]);
        int sumFromChild;
        read(fd[0],&sumFromChild, sizeof(sumFromChild));
        close(fd[0]);

        int total = sum + sumFromChild;
        printf("Total = %d\n", total);
        wait(NULL);
    }

    return 0;
}