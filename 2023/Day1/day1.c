#include "../lib/input.h"

void part1(text_file *input)
{
        int total_value = 0;

        for (int i = 0; i < input->sentence_num; i++) {
                int sent_len = strlen(input->text_body[i]);
                int first_digit = -1;
                int last_digit = -1;

                // Check line
                for (int j = 0; j < sent_len; j++) {
                        char tmp[2];
                        tmp[0] = input->text_body[i][j];
                        tmp[1] = '\0';
                        if (atoi(tmp) != 0) {
                                if (first_digit == -1) {
                                        first_digit = atoi(tmp);
                                }
                                last_digit = atoi(tmp);
                        }
                }
                total_value += ((first_digit * 10) + last_digit);
        }

        printf("Part1: The sum of all calibration values is %d .\n", total_value);
}

// Part 2
int check_line(char *line)
{
        int sent_len = strlen(line);
        int first_digit = -1;
        int last_digit = -1;

        // Check line
        for (int i = 0; i < sent_len; i++) {
                char tmp[2];
                tmp[0] = line[i];
                tmp[1] = '\0';
                int detected_num = -1;

                if (atoi(tmp) != 0) {
                        detected_num = atoi(tmp);
                }
                else if(line[i] == 'o' && line[i+1] == 'n' && line[i+2] == 'e') {
                        detected_num = 1;
                }
                else if (line[i] == 't' && line[i+1] == 'w' && line[i+2] == 'o') {
                        detected_num = 2;
                }
                else if (line[i] == 't' && line[i+1] == 'h' && line[i+2] == 'r' && line[i+3] == 'e' && line[i+4] == 'e'){
                        detected_num = 3;
                }
                else if (line[i] == 'f' && line[i+1] == 'o' && line[i+2] == 'u' && line[i+3] == 'r'){
                        detected_num = 4;
                }
                else if (line[i] == 'f' && line[i+1] == 'i' && line[i+2] == 'v' && line[i+3] == 'e'){
                        detected_num = 5;
                }
                else if (line[i] == 's' && line[i+1] == 'i' && line[i+2] == 'x'){
                        detected_num = 6;
                }
                else if (line[i] == 's' && line[i+1] == 'e' && line[i+2] == 'v' && line[i+3] == 'e' && line[i+4] == 'n'){
                        detected_num = 7;
                }
                else if (line[i] == 'e' && line[i+1] == 'i' && line[i+2] == 'g' && line[i+3] == 'h' && line[i+4] == 't'){
                        detected_num = 8;
                }
                else if (line[i] == 'n' && line[i+1] == 'i' && line[i+2] == 'n' && line[i+3] == 'e'){
                        detected_num = 9;
                }

                if (detected_num != -1) {
                        if (first_digit == -1) {
                                first_digit = detected_num;
                        }
                        last_digit = detected_num;
                }
        }

        return ((first_digit * 10) + last_digit);
}

void part2(text_file *input)
{
        int total_value = 0;

        for (int i = 0; i < input->sentence_num; i++) {
                total_value += check_line(input->text_body[i]);
        }

        printf("Part2: The new sum of all calibration values is %d .\n", total_value);
}

int main(void)
{
        text_file *input = read_input("./input.txt");

        part1(input);

        part2(input);

        free_input(input);
        return 0;
}
