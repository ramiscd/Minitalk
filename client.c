
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

void send_bit(int bit, int pid)
{
    if (bit == 0)
        kill(pid, SIGUSR1);
    else
        kill(pid, SIGUSR2);
}

void send_char(int pid, char c)
{
    int i;
    int bit;

    i = 7;
    while (i >= 0)
    {
        bit = (c >> i) & 1;
        send_bit(bit, pid);
        usleep(500);
        i--;
    }
}

void send_string(int pid, char *string)
{
    int i;

    i = 0;
    while (string[i])
    {
        send_char(pid, string[i]);
        i++;
    }
    send_char(pid, '\0');
}

int main(int argc, char **argv)
{
    int pid;

    if(argc != 3)
    {
        write(1, "Uso: ./client <PID> <mensagem>\n", 32);
        return (1);
    }    

    pid = atoi(argv[1]);
    send_string(pid, argv[2]);
    return (0);
}