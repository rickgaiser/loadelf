#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#include "elf.h"


int LoadELFFromFile(const char *filename)
{
        int fd, i;
        elf_header_t eh;
        elf_pheader_t eph;

        printf("Loading %s\n", filename);

	if ((fd = open(filename, O_RDONLY)) <= 0) {
		printf("Could not find '%s'\n", filename);
		return -1;
	}

        // Read ELF header
        read(fd, &eh, sizeof(elf_header_t));

        if (_lw((u32)&eh.ident) != ELF_MAGIC) {
		printf("Invalid ELF magic\n");
		return -2;
        }
                
        // Loop through all headers
        for (i = 0; i < eh.phnum; i++) {
                // Seek to program header
                lseek(fd, eh.phoff + (i * sizeof(elf_pheader_t)), SEEK_SET);
                // Load program header
                read(fd, &eph, sizeof(elf_pheader_t));

                if (eph.type != ELF_PT_LOAD)
                        continue;

                // Seek to section
                lseek(fd, eph.offset, SEEK_SET);
                // Load section
                //read(fd, eph.vaddr, eph.filesz);

                printf("- Section %d: vaddr=0x%x, filesz=%d\n", i, (int)eph.vaddr, eph.filesz);

                // Clear section if needed
                //if (eph.memsz > eph.filesz)
                //        memset(eph.vaddr + eph.filesz, 0, eph.memsz - eph.filesz);
        }

	close(fd);

        return 0;
}
