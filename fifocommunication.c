#include <std.io>
#include <stdlib.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>

int main(int argc, char* argv[]){
    int arr[5];
    srand(time(NULL));


    for(int i = 0; i < 5; i++){
        arr[i] = rand() % 100;
    }
    return 0;

    int fd = open("sum", O_WRONLY);
    if(fd == -1){
        return 1;
    }
}
