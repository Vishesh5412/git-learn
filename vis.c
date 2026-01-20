#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>


int main(){
pid_t p1, p2;
p1 = fork(); 
if (p1 < 0){
    exit(1);
}
if (p1 == 0){
       printf("c2 id is %d and parent pid is %d \n", getpid(), getppid());
    p2 = fork();
    if (p2 < 0){
        exit(1);    
    }
    if (p2 == 0){
       printf("c4 id is %d and parent pid is %d \n", getpid(), getppid());
       exit(0);
    } else {
       printf("c3 id is %d and parent pid is %d \n", getpid(), getppid());
    }
    exit(0);
} else {
    printf("c1 id is %d and parent pid is %d \n", getpid(), getppid());
}


    printf("P id is %d and parent pid is %d \n", getpid(), getppid());

    return 0;
}