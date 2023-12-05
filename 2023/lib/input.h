#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
        char **text_body;
        uint16_t sentence_num;
}text_file;

text_file *read_input(char *path);

void free_input(text_file *file);