#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>



void create_child(int p, char **filhos, int pTotal, int* pf){

    
    if(p <= 0) return; // encerra recursao

    if (pf == NULL)
    {
        int f = atoi(filhos[pTotal - p]);
        pf = &f;
    }
    int pid;
    
    pid = fork(); // criar processo filho
    if(pid == -1) printf("Erro no fork\n");
    
    if(pid > 0){ // codigo do processo pai
        wait(NULL);
        *pf = *pf-1; 
        if (*pf > 0) create_child(p ,filhos, pTotal, pf); // criar novamente
        else return;
    
    }else if(pid == 0){
        printf("Sou processo %d, meu pai eh %d\n", getpid(), getppid());
        create_child(p-1, filhos,pTotal, pf); // criar os processos em cascata recursivamente
    }
}

int main(int argc, char **argv)
{
    if (argc < 2){
        printf("Necessario pelo menos um argumento\n");
    }

    int const pTotal = argc;
    int* ptr = NULL;
    
    printf("Processo %d root\n", getpid());
    create_child(argc - 1, argv, pTotal, ptr);



    printf("Processo %d terminou\n", getpid());
    
    return 0;
}