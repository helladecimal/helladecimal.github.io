#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *test;
    char buffer[256];

    struct Identifier {
        char* md;
        char* html;
    }

    test = fopen("blog/md/test.md", "r");

    while (fgets(buffer, 256, test)){
        printf("%s", buffer);
    }
    fclose(test);
}