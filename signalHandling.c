#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void handler(int num){
    write(STDOUT_FILENO, "I cannot be canceled\n", 13);
    /* now the sig int signal will just make this write statement print */
}

int main(){
    signal(SIGINT, handler);
    while(1){
        printf("Cycle PID: %d\n",getpid());
        sleep(1);
    }
}