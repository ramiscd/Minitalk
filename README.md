# Minitalk

O minitalk é um projeto em C que implementa comunicação entre processos (IPC) utilizando apenas signals do Unix. Ele consiste em um servidor e um cliente, onde o cliente envia uma mensagem para o servidor bit a bit usando SIGUSR1 e SIGUSR2.

O objetivo do projeto é aprofundar o entendimento sobre processos, sinais, comportamento assíncrono e representação binária de dados em sistemas Unix.

## Conceitos abordados

* Comunicação entre processos (IPC)
* Uso de signals no Unix (SIGUSR1 e SIGUSR2)
* Codificação e decodificação de dados em nível de bits
* Sincronização entre processos
* Concorrência e código assíncrono
* Manipulação de PIDs
* Boas práticas de programação em C

## Funcionamento

* O servidor é iniciado e exibe seu PID.
* O cliente recebe o PID do servidor e a mensagem a ser enviada.
* Cada caractere da mensagem é convertido em bits.
* Cada bit é enviado como um signal para o servidor.
* O servidor reconstrói os caracteres a partir dos bits recebidos e imprime a mensagem.

## Estrutura do projeto

* server.c
  Responsável por receber os signals, reconstruir os bytes e exibir a mensagem.

* client.c
  Responsável por converter a string em bits e enviar os signals ao servidor.

* minitalk.h
  Contém as definições e protótipos usados no projeto.

## Compilação

Use o Makefile para compilar o projeto:

```
make
```

Isso irá gerar os binários `server` e `client`.

## Uso

1. Inicie o servidor:

```
./server
```

O servidor exibirá seu PID.

2. Em outro terminal, execute o cliente:

```
./client <PID_DO_SERVIDOR> "Sua mensagem aqui"
```

A mensagem será exibida no terminal do servidor.

## Observações

* O projeto não utiliza sockets, arquivos ou memória compartilhada.
* Toda a comunicação ocorre exclusivamente via signals.
* É necessário cuidado com sincronização para evitar perda de sinais.
* O código foi desenvolvido seguindo as restrições e boas práticas do projeto da 42.

## Código fonte

Repositório no GitHub:
[https://github.com/ramiscd/Minitalk](https://github.com/ramiscd/Minitalk)

