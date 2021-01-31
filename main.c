#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    pid_t pid;
    printf("processo pai (PID = %d) foi criado\n", getpid());
    for(int i = 1; i <= 14; i++){
        printf("Ano %d\n", i);
        sleep(1);
    }    
    pid = fork();
    if(pid<0){
        exit(-1);
    }else if(pid == 0){//processo filho1
        printf("filho 1 (PID = %n) foi criado\n", getpid());
        sleep(12);
        pid = fork();
        if(pid < 0){
            exit(-1);
        }else if(pid == 0){//processo neto1
            printf("neto 1 (PID = %d) foi criado\n", getpid());
        }else{//processo filho1

        }
    }else{//processo pai
        for(int i = 15; i <= 16; i++){
            printf("Ano %d\n", i);
            sleep(1);
        }
        pid = fork();
        if(pid < 0){
            exit(-1);
        }else if(pid == 0){//processo filho2
            printf("filho 2 (PID = %d) foi criado\n", getpid());
            sleep(14);
            pid = fork();
            if(pid < 0){
                exit(-1);
            }else if(pid == 0){//processo neto2
                printf("neto 1 (PID = %d) foi criado\n", getpid());
            }else{//processo filho2

            }
        }else{//processo pai
            for(int i = 16; i <= 60; i++){
                printf("Ano %d\n", i);
                sleep(1);
            }
        }
    }
    return 0;
}