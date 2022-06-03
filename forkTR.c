#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>

void create_child(int p){

    int pid;
    
    if(p <= 0){
        return;
    }
    pid = fork();
    if(pid > 0){
        wait(NULL);
    } else if(pid == 0){
        printf("Sou processo %d, meu pai eh %d\n", getpid(), getppid());
        create_child(p-1);
    }
    // retorna onde o pai esta na arvore quando terminou de esperar pelo filho
    return p;
}

int main(int argc, char **argv)
{
    if (argc < 2){
        printf("Necessario pelo menos um argumento\n");
    }

    int pos;
    int f = atoi(argv[1]);
    
    printf("Processo %d root\n", getpid());
    
    create_child(argc-1);

    // verificar profundidade quando o pai retorna depois de esperar o filho
    if(filhos > ?)
    create_child
    



    printf("Processo %d terminou\n", getpid());
    
    return 0;
}
