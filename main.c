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
        printf("filho 1 (PID = %d) foi criado\n", getpid());
        sleep(13);
        pid = fork();
        if(pid < 0){
            exit(-1);
        }else if(pid == 0){//processo neto1
            printf("neto 1 (PID = %d) foi criado\n", getpid());
            sleep(12);
            printf("neto 1 morreu (nascido no ano 26, viveu 12 anos)\n");
            exit(3);
        }else{//processo filho1
       		sleep(18);
            printf("filho 1 morreu (nascido no ano 14, viveu 30 anos)\n");
       		exit(1);
        }
    }else{//processo pai
        for(int i = 15; i <= 16; i++){
            sleep(1);
            printf("Ano %d\n", i);
        }
        pid = fork();
        if(pid < 0){
            exit(-1);
        }else if(pid == 0){//processo filho2
            printf("filho 2 (PID = %d) foi criado\n", getpid());
            sleep(15);
            pid = fork();
            if(pid < 0){
                exit(-1);
            }else if(pid == 0){//processo neto2
                printf("neto 2 (PID = %d) foi criado\n", getpid());
            	sleep(18);
	            printf("neto 2 morreu (nascido no ano 30, viveu 18 anos)\n");
            	exit(4);
            }else{//processo filho2
            	sleep(16);
	            printf("filho 2 morreu (nascido no ano 16, viveu 30 anos)\n");
       			exit(2);
            }
        }else{//processo pai
            for(int i = 17; i <= 60; i++){
                sleep(1);
                printf("Ano %d\n", i);
                if(i == 60)
    	        printf("Pai morreu (nascido no ano 1, viveu 60 anos)\n");
            }
        }
    }
    return 0;
}