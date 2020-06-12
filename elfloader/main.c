#include <stdio.h>

#include "loadelf.h"


int main(int argc, char *argv[])
{
        int i;

        printf("Hello from elfloader!\n");

        for (i=0; i<argc; i++)
                printf("- argv[%d] = %s\n", i, argv[i]);
        
        if (argc < 1) {
                printf("Nothing to load!\n");
                return -1;
        }

        LoadELFFromFile(argv[0]);

        return 0;
}
