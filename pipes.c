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
    else{
        int id = fork();
    }
    return 0;
}