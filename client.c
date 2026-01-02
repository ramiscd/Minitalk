
#include <stdio.h>
#include <signal.h>

// 1. Ler e validar argumentos da linha de comando
//    - Verificar quantidade de argumentos
//    - Converter PID de string para inteiro
//    - Validar se o PID parece válido

// 2. Definir a mesma convenção de bits do servidor
//    - SIGUSR1 = 0
//    - SIGUSR2 = 1
//    Essa decisão precisa ser idêntica no server

// 3. Criar função para enviar um bit
//    - Recebe PID do servidor
//    - Recebe valor do bit (0 ou 1)
//    - Envia o sinal correspondente usando kill

// 4. Criar função para enviar um caractere
//    - Percorrer os 8 bits do caractere
//    - Enviar cada bit na ordem correta
//    - Inserir um pequeno delay entre sinais (usleep)

// 5. Decidir a ordem dos bits
//    - Do bit mais significativo para o menos?
//    - Ou o contrário?
//    Importante: servidor precisa reconstruir na mesma ordem

// 6. Criar função para enviar a string completa
//    - Iterar sobre cada caractere da string
//    - Enviar caractere por caractere
//    - Ao final, enviar o caractere '\0' para indicar fim

// 7. Lidar com possíveis erros de kill
//    - PID inválido
//    - Servidor inexistente
//    - Permissão negada

int main()
{
    printf("Hello Client \n");

    // kill(134057, SIGUSR1);
    kill(135563, SIGUSR2);
    
    return 0;
}