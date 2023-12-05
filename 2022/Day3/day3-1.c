#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int priority(char *rucksack)
{
    int total_size = strlen(rucksack);
    int comp_size = total_size / 2;

    char repeat_char;
    for (int i = 0; i < comp_size; i++) {
        for (int j = comp_size; j < comp_size * 2; j++) {
            if (rucksack[i] == rucksack[j]) {
                repeat_char = rucksack[i];
                break;
            }
        }
    }

    //uppercase
    if (repeat_char >= 65 && repeat_char <= 90) {
        repeat_char -= 64;
        repeat_char += 26;
    }

    //lowercase
    else if (repeat_char >= 97 && repeat_char <= 122) {
        repeat_char -= 96;
    }

    return repeat_char;

}

int main()
{
    FILE *fp = fopen("./day3input.txt", "r");

    if (fp == NULL) {
        printf("%s\n", "Cannot open file");
        return 1;
    }

    int sum = 0;
    char tmp[100];
    while(fgets(tmp, 99, fp) != NULL) {
        sum += priority(tmp);
    }

    fclose(fp);

    printf("The sum of the priorities is %d.\n", sum);

}