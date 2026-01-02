// #include "minitalk.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

// 1. Definir um único signal handler
//    Em vez de dois handlers separados, pensar em um handler único
//    que trate SIGUSR1 e SIGUSR2 e identifique qual bit chegou.

// 2. Decidir a convenção de bits
//    Exemplo mental:
//    SIGUSR1 representa bit 0
//    SIGUSR2 representa bit 1
//    Cliente e servidor precisam concordar com isso.

// 3. Criar estado interno persistente
//    - Variável para acumular bits recebidos (ex: unsigned char)
//    - Contador de quantos bits já chegaram (0 a 7)
//    OBS: isso provavelmente será uma variável global ou static,
//    pois signal handler não recebe contexto externo.

// 4. A cada sinal recebido:
//    - Deslocar o acumulador de bits
//    - Inserir o bit correspondente ao sinal
//    - Incrementar o contador de bits

// 5. Quando 8 bits forem recebidos:
//    - Converter o acumulador em um caractere
//    - Decidir o que fazer com esse caractere:
//        - Se for '\0', finalizar a mensagem
//        - Caso contrário, imprimir o caractere
//    - Resetar acumulador e contador de bits

// 6. Substituir printf dentro do handler
//    printf não é async-signal-safe
//    Pensar em usar write para imprimir caracteres

// 7. Substituir o loop com sleep por pause
//    pause bloqueia até um sinal chegar
//    Isso evita wakeups desnecessários e é o padrão do projeto

// 8. Preparar o servidor para múltiplas mensagens em sequência
//    - Após receber '\0', resetar estado
//    - Continuar aceitando novos sinais sem reiniciar o processo

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