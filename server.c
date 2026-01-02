// #include "minitalk.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

//função manipuladora de sinal (Sinal Handler)
void handle_sigusr1(int sig) {
    if (sig == SIGUSR1) {
        printf("\n Recebi o sinal SIGUSR1! Fui notificado. \n");
    }
}

void handle_sigusr2(int sig) {
    if (sig == SIGUSR2) {
        printf("\n Recebi o sinal SIGUSR2! Fui notificado. \n");
    }
}

int main()
{
    // Configura o manipulador para SIGUSR1
    if(signal(SIGUSR1, handle_sigusr1) == SIG_ERR) {
        perror("Erro ao configurar o manipulador de sinal");
        return EXIT_FAILURE;
    }

    if (signal(SIGUSR2, handle_sigusr2) == SIG_ERR) {
        perror("Erro ao configurar o manipulador de sinal");
        return EXIT_FAILURE;
    }

    pid_t meu_pid = getpid();
    printf("Receptor iniciado. Meu pid é:  %d\n", meu_pid);
    printf("\n Aguarando sinais... (precione Ctrl+C para sair)\n");

    // Mantendo o processo vivo.
    while (1)
    {
        sleep(1);
    }
    
    return EXIT_SUCCESS;
}