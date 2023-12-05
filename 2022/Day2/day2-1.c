#include <stdio.h>
#include <string.h>

int score(char opp, char me)
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

    int score = 0;
    struct node *current;

    switch (me) {
        case 'X':
            current = &rock;
            break;
        case 'Y':
            current = &paper;
            break;
        case 'Z':
            current = &scissors;
            break;
        default:
            break;
    }

    score += current->default_score;

    //If draw
    if (opp == current->opp) {
        score += 3;
        return score;
    } 
    
    //Not draw
    //Win
    if (opp == current->win->opp) {
        score += 6;
        return score;
    }

    //Lose
    if (opp == current->lose->opp) {
        return score;
    }

    return 0;
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