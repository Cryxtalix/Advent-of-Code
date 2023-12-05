#include "../lib/input.h"
#include <stdbool.h>

void part2(text_file *input)
{
        int total_power = 0;

        // For each line
        for (int i = 0; i < input->sentence_num; i++) {

                int colors[3] = {0, 0, 0}; // Red, Green, Blue

                int tmp = 0;

                // Tokenise each line with strtok loop
                for (char *token = strtok(input->text_body[i], " "), tok_idx = 0; token != NULL; token = strtok(NULL, " "), tok_idx++) {

                        if (tok_idx > 1) {
                                // Cube numbers
                                if (tok_idx % 2 == 0) {
                                        tmp = atoi(token);
                                }

                                // Cube colors
                                if (tok_idx % 2 == 1) {
                                        if (token[0] == 'r') {
                                                if (tmp > colors[0]) {
                                                        colors[0] = tmp;
                                                }
                                        }
                                        else if (token[0] == 'g') {
                                                if (tmp > colors[1]) {
                                                        colors[1] = tmp;
                                                }
                                        }
                                        else if (token[0] == 'b') {
                                                if (tmp > colors[2]) {
                                                        colors[2] = tmp;
                                                }
                                        }
                                }
                        }
                }

                total_power += (colors[0] * colors[1] * colors[2]);
        }

        printf("The total sum of the powers is %d.\n", total_power);
}

// Used in part 1
bool check_possibility(int colors[3])
{
        int actual[3] = {12, 13, 14};
        bool possibility = 1;

        for (int i = 0; i < 3; i++) {
                if (colors[i] > actual[i]) {
                        possibility &= 0;
                }
        }

        return possibility;
}

void part1(text_file *input)
{
        int ID_sum = 0;

        // For each line
        for (int i = 0; i < input->sentence_num; i++) {

                int ID = -1;
                int colors[3] = {0, 0, 0}; // Red, Green, Blue
                bool possible = 1;

                int tmp = 0;

                // Tokenise each line with strtok loop
                for (char *token = strtok(input->text_body[i], " "), tok_idx = 0; token != NULL; token = strtok(NULL, " "), tok_idx++) {

                        // Get ID at idx 1
                        if (tok_idx == 1) {
                                token[strlen(token) - 1] = '\0';
                                ID = atoi(token);
                        }

                        if (tok_idx > 1) {
                                // Cube numbers
                                if (tok_idx % 2 == 0) {
                                        tmp = atoi(token);
                                }

                                // Cube colors
                                if (tok_idx % 2 == 1) {
                                        if (token[0] == 'r') {
                                                colors[0] = tmp;
                                        }
                                        else if (token[0] == 'g') {
                                                colors[1] = tmp;
                                        }
                                        else if (token[0] == 'b') {
                                                colors[2] = tmp;
                                        }

                                        // End of set
                                        if (token[strlen(token) - 1] != ',') {
                                                possible &= check_possibility(colors);
                                                colors[0] = 0;
                                                colors[1] = 0;
                                                colors[2] = 0;
                                        }
                                }
                        }
                }

                if (possible == 1) {
                        ID_sum += ID;
                }
        }

        printf("The total sum of possible game IDs is %d.\n", ID_sum);
}

int main(void)
{
        text_file *input = read_input("./input.txt");
        part1(input);
        free_input(input);

        // strtok damaged previous input
        text_file *new_input = read_input("./input.txt");
        part2(new_input);
        free_input(input);

        return 0;
}