#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
    if(mkfifo("myFifo1", 0777) == -1){
        if(errno != EEXIST){
            printf("Could not create fifo\n");
            return 1;
        }

    }

    int fd = open("myfifo1", O_WRONLY);
    /* Execution will stop here untill we open the fifo with another process */
    /* You can do this by running "cat myfifo1" in another terminal */
    int x = 97;
    write(fd, &x, sizeof(x));
    close(fd);

    return 0;
}