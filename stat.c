#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <time.h>

int main(int argn, char** argv)
{
    if (argn < 2)
    {
        printf("Error: No filename given\n");
        return 1;
    }

    struct stat *s = malloc(sizeof(struct stat));
    if (stat(argv[1], s) < 0)
    {
        printf("Error: %s\n", strerror(errno));
        return 1;
    }

    printf("=====================================\n");
    printf("Metadata of %s\n", argv[1]); 
    printf("=====================================\n");
    printf("Size: %ld bytes\n", s->st_size);
    printf("Permissions: %o\n", s->st_mode % 01000);
    printf("Time of last access: %s", ctime(&(s->st_atime)));

    free(s);
    return 0;
}
