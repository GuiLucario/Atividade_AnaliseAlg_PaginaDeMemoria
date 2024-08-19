#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd;
    struct stat sb;
    char *addr;
    size_t page_size = sysconf(_SC_PAGE_SIZE); // Obter o tamanho da página do sistema

    // Abrir o arquivo
    fd = open("biblia.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    // Obter o tamanho do arquivo
    if (fstat(fd, &sb) == -1) {
        perror("fstat");
        exit(1);
    }

    // Mapear o arquivo na memória
    addr = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (addr == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    // Calcular o número de páginas
    int num_pages = (sb.st_size + page_size - 1) / page_size;

    printf("O arquivo biblia.txt equivale a %d páginas de memória.\n", num_pages);

    // Desmapear a memória e fechar o arquivo
    if (munmap(addr, sb.st_size) == -1) {
        perror("munmap");
        exit(1);
    }
    close(fd);

    return 0;
}