#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>


int main(int argc, char* argv[]){
    int pid_1 = fork();
    int pid_2 = fork();

    if(0 == pid_1){
        if(0 == pid_2){
            printf("We are process y \n");
        }
        else {
            printf("We are process x \n");
        }
    }
    else{
        if(0 == pid_2){
            printf("We are process z \n");
        }
        else{
            printf("We are the parent process \n");
        }
    }
    while(wait(NULL) != -1 || errno != ECHILD){
        printf("Waiting for child to finish\n");
    }
    return 0;
}