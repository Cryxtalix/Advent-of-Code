#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct range {
        int elf1_start;
        int elf1_end;
        int elf2_start;
        int elf2_end;
};

int find_overlap(struct range *pair)
{
        //elf1 is a subset of elf2
        if (pair->elf1_start >= pair->elf2_start && pair->elf1_end <= pair->elf2_end) {
                return 1;
        }

        //elf1 is a superset of elf2
        if (pair->elf1_start <= pair->elf2_start && pair->elf1_end >= pair->elf2_end) {
                return 1;
        }

        //elf1 left overlap elf2
        //elf2 start is somewhere within elf1 range
        if (pair->elf2_start >= pair->elf1_start && pair->elf2_start <= pair->elf1_end) {
                return 1;
        }

        //elf1 right overlap elf2
        //elf2 end is somewhere within elf1 range
        if (pair->elf2_end >= pair->elf1_start && pair->elf2_end <= pair->elf1_end) {
                return 1;
        }

        return 0;
}

void extract_range(struct range *pair, char *line)
{
        int loc_dash1 = strcspn(line, "-");
        int loc_commar = strcspn(line, ",");
        int loc_dash2 = strcspn(line + loc_commar, "-") + loc_commar;
        
        size_t start;
        size_t end;
        // strncpy pointer addition to start location
        // size_t _n is the number of chars to be copied
        
        char elf1_start[4];
        start = 0;
        end = loc_dash1;
        strncpy(elf1_start, line + start, end - start);
        pair->elf1_start = atoi(elf1_start);

        char elf1_end[4];
        start = loc_dash1 + 1;
        end = loc_commar;
        strncpy(elf1_end, line + start, end - start);
        pair->elf1_end = atoi(elf1_end);

        char elf2_start[4];
        start = loc_commar + 1;
        end = loc_dash2;
        strncpy(elf2_start, line + start, end - start);
        pair->elf2_start = atoi(elf2_start);

        char elf2_end[4];
        start = loc_dash2 + 1;
        end = strlen(line) + 1;
        strncpy(elf2_end, line + start, end - start);
        pair->elf2_end = atoi(elf2_end);
}

int main(int argc, char **argv)
{
        FILE *fp = fopen("./day4input.txt", "r");

        if (fp == NULL) {
        printf("%s\n", "Cannot open file");
        return 1;
        }

        int sum = 0;
        char tmp[20];
        while(fgets(tmp, 19, fp) != NULL) {
                struct range pair;
                extract_range(&pair, tmp);
                sum += find_overlap(&pair);
        }

        fclose(fp);
        printf("There are %d pairs with ranges that fully contain the other.\n", sum);

        return 0;
}