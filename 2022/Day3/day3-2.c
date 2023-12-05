#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct rucksack {
    char elf1[100];
    char elf2[100];
    char elf3[100];
};

int get_priority(char badge)
{
    //uppercase
    if (badge >= 65 && badge <= 90) {
        badge -= 64;
        badge += 26;
    }

    //lowercase
    else if (badge >= 97 && badge <= 122) {
        badge -= 96;
    }

    return badge;
}

char find_badge(struct rucksack *group)
{
    for (int i = 0; i < strlen(group->elf1); i++) {
        for (int j = 0; j < strlen(group->elf2); j++) {

            if (group->elf1[i] == group->elf2[j]) {
                for (int k = 0; k < strlen(group->elf3); k++) {
                    if (group->elf1[i] == group->elf3[k]) {
                        return group->elf1[i];
                    }
                }
            }
        }
    }
}

int main()
{
    FILE *fp = fopen("./day3input.txt", "r");

    if (fp == NULL) {
        printf("%s\n", "Cannot open file");
        return 1;
    }

    int sum = 0;
    int mem_counter = 1;
    struct rucksack group;
    char tmp[100];
    char badge;
    while(fgets(tmp, 99, fp) != NULL) {
        if (mem_counter == 1) {
            snprintf(group.elf1, 100, tmp);
            mem_counter = 2;
        }
        else if (mem_counter == 2) {
            snprintf(group.elf2, 100, tmp);
            mem_counter = 3;
        }
        else if (mem_counter == 3) {
            snprintf(group.elf3, 100, tmp);

            //Find badge from group
            badge = find_badge(&group);
            sum += get_priority(badge);

            mem_counter = 1;
        }
    }

    fclose(fp);

    printf("The sum of the priorities is %d.\n", sum);
}