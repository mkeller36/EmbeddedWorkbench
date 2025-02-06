#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(){
	if(0==fork()){
		printf("Child \n");
	}
	else{
		printf("Parent \n");
	}
}
