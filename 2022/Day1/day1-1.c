#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct most_cal {
    int index;
    int cal;
};

int main()
{
    struct most_cal elf = {0, 0};

    FILE *fp = fopen("./day1input.txt", "r");

    if (fp == NULL) {
        printf("%s\n", "Cannot open file");
        return 1;
    }

    char tmp[20];
    int line_cal;
    int total_cal = 0;
    int index = 1;

    while(fgets(tmp, 19, fp) != NULL) {
        line_cal = atoi(tmp);
        total_cal += line_cal;

        if (strlen(tmp) == 1) {
            if (total_cal > elf.cal) {
                elf.index = index;
                elf.cal = total_cal;
            }
            index += 1;
            total_cal = 0;
        }
    }

    fclose(fp);

    printf("The elf with the most calories is number %d elf, with %d calories.\n", elf.index, elf.cal);
    return 0;
}
