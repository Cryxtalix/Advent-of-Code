#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct top_cal {
    int top1;
    int top2;
    int top3;
};

int main()
{
    struct top_cal record = {0, 0, 0};

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
            if (total_cal > record.top1) {
                record.top3 = record.top2;
                record.top2 = record.top1;
                record.top1 = total_cal;
            }
            else if (total_cal > record.top2) {
                record.top3 = record.top2;
                record.top2 = total_cal;
            }
            else if (total_cal > record.top3) {
                record.top3 = total_cal;
            }
            total_cal = 0;
        }
    }

    fclose(fp);

    printf("The top 3 calories are %d, %d and %d.\n", record.top1, record.top2, record.top3);
    int sum = record.top1 + record.top2 + record.top3;
    printf("The total amount is %d.\n", sum);
    return 0;
}
