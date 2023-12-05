#include "input.h"

text_file *read_input(char *path)
{
        FILE *fp = fopen(path, "r");

        if (fp == NULL) {
                printf("%s\n", "Cannot open file");
                text_file *myfile = NULL;
                return myfile;
        }

        text_file *myfile = malloc(sizeof(text_file));
        myfile->text_body = malloc(500 * sizeof(char *));
        int current_size = 500;
        int line_num = -1;

        do {
                line_num += 1;
                if (line_num + 1 >= current_size) {
                        current_size += 20;
                        myfile->text_body = realloc(myfile->text_body, current_size * sizeof(char *));
                }
                myfile->text_body[line_num] = malloc(500 * sizeof(char));
        } while(fgets(myfile->text_body[line_num], 500, fp) != NULL);

        // Loops adds additional line, but line_num counts from 0.
        myfile->sentence_num = line_num;

        fclose(fp);

        return myfile;
}

void free_input(text_file *file)
{
        for (int i = 0; i < file->sentence_num; i++) {
                free(file->text_body[i]);
        }
        free(file->text_body);
        free(file);
}
