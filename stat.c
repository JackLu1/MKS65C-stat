#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argn, char** argv)
{
    struct stat *s = malloc(sizeof(stat));

    stat(argv[1], s);
    printf("Size: %ld\n", s->st_size);
    printf("Permissions: %d\n", s->st_mode);
    // printf("Last Changed: %d\n", s->st_mtim);
    return 0;
}
