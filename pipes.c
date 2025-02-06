#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char* argv[]){
    int fd[2];
    if(-1==pipe(fd)){
        printf("ERROR: pipe \n");
        return 1;
    }

    int id = fork();
    if(0 == id){
        /* Child process */
        /* Close end of pipe you are not using */
        close(fd[0]);
        int x;
        printf("Input a number\n");
        scanf("%d", &x);
        /* create space for x in pipe and write it there */
        write(fd[1], &x , sizeof(int));
        close(fd[1]);
    }
    else{
        close(fd[1]);
        int y; 
        read(fd[0],&y,sizeof(int));
        close(fd[0]);
        printf("From Child process: %d\n", y);
    }
    return 0;
}