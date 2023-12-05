#include <stdio.h>
#include <string.h>

/**
 * @brief Takes opponent selection and requirement, returns score
 * 
 * @param opp 
 * @param condition 
 * @return int 
 */
int score(char opp, char condition)
{
    /* Asinine way to find the result compared 
    to a table, but shows the cyclic
    structure of rock paper scissors. */

    struct node {
        char me;
        char opp;
        int default_score;
        struct node *lose;
        struct node *win;
    };

    struct node rock = {'X', 'A', 1};
    struct node paper = {'Y', 'B', 2};
    struct node scissors = {'Z', 'C', 3};
    //lose and win in terms of the opponent
    //Opponent chooses rock, opponent loses, I choose paper, etc.
    rock.lose = &paper;
    rock.win = &scissors;
    paper.lose = &scissors;
    paper.win = &rock;
    scissors.lose = &rock;
    scissors.win = &paper;

    struct node *current;

    switch (opp) {
        case 'A':
            current = &rock;
            break;
        case 'B':
            current = &paper;
            break;
        case 'C':
            current = &scissors;
            break;
        default:
            break;
    }

    int score = 0;

    switch (condition) {
        //Lose
        case 'X':
            score += current->win->default_score; //To lose, opponent has to win
            break;

        //Draw
        case 'Y':
            score += 3;
            score += current->default_score;
            break;

        //Win
        case 'Z':
            score += 6;
            score += current->lose->default_score; //To win, opponent has to lose
            break;

        default:
            break;
    }

    return score;
}

int main()
{
    FILE *fp = fopen("./day2input.txt", "r");

    if (fp == NULL) {
        printf("%s\n", "Cannot open file");
        return 1;
    }

    int total_score = 0;

    char tmp[6];
    while(fgets(tmp, 5, fp) != NULL) {
        int result = score(tmp[0], tmp[2]);
        total_score += result;
    }

    fclose(fp);

    printf("The total score is %d.\n", total_score);

    return 0;
}