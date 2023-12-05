#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct crate {
        struct crate *next;
        char letter;
};

struct stacks {
        struct crate *stack1;
        struct crate *stack2;
        struct crate *stack3;
        struct crate *stack4;
        struct crate *stack5;
        struct crate *stack6;
        struct crate *stack7;
        struct crate *stack8;
        struct crate *stack9;
};

void create_cargo(char input[9][50], struct stacks *base) {
        for (int i = 7; i > -1; i--) {
                for (int j = 1; j < 34; j += 4) {
                        if (input[i][j] != " ") {
                                
                        }
                }
        }
}

int main(int argc, char **argv)
{
        struct stacks *base = malloc(sizeof(struct stacks));

        FILE *fp = fopen("./day5input.txt", "r");

        if (fp == NULL) {
        printf("%s\n", "Cannot open file");
        return 1;
        }

        char input_lines[9][50];

        int counter = 0;
        char tmp[50];
        while(fgets(tmp, 49, fp) != NULL) {
                //Crates
                if (counter < 8) {
                        snprintf(input_lines[counter], 50, tmp);
                }

                //Build crates
                if (counter == 8) {
                        create_cargo(input_lines, base);
                }

                //Instructions

                counter += 1;
        }

        printf("%s\n", input_lines[0]);
        printf("%s\n", input_lines[8]);

        fclose(fp);

        return 0;
}