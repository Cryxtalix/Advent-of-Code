#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
        char input[3][9];

        snprintf(input[0], 9, "Hello");
        snprintf(input[1], 9, "How");
        snprintf(input[2], 9, "are");

        printf("%s\n", input[0]);
        printf("%s\n", input[1]);
        printf("%s\n", input[2]);

        return 0;
}