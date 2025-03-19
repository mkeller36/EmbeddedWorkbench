#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(){
	if(0==fork()){
		printf("Child \n");
        execlp("ls","ls","-al", NULL);
        printf("after execlp"); /* This will not run */
	}
	else{
		printf("Parent \n");
	}
}