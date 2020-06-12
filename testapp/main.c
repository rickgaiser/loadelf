#include <stdio.h>

#include "loadelf.h"


int main(int argc, char *argv[])
{
        int i;

        printf("Hello from test app!\n");

        for (i=0; i<argc; i++)
                printf("- argv[%d] = %s\n", i, argv[i]);

        LoadELFFromFile("host:test_loader.elf");

        return 0;
}
