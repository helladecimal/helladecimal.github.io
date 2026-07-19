#include <stdio.h>

int main(void)
{

    FILE *test = fopen("./blog/md/test.md", "r");

    char buffer[256];

    fgets(buffer, 256, test);

    printf(buffer);

    fclose(test);
}