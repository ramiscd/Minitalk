
#include <stdio.h>
#include <signal.h>

int main()
{
    printf("Hello Client \n");

    // kill(134057, SIGUSR1);
    kill(135563, SIGUSR2);
    
    return 0;
}