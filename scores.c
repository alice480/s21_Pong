#include <stdio.h>
int player1_score = 0;
int player2_score = 0;

int score(int number) {
    //если начало игры
    if (number1 == 1) {
        //Если первый забивает
        player1_score++;
    } else if (number2 == 2) {
        // Если второй забивает
        player2_score++;
    }
    print_score();
    return 0;
}
int print_score() {
    //печать счета
    printf("-------------- Player 1 -------------- || -------------- Player 2 --------------\n\n");
    if (player1_score < 10 && player2_score < 10) {
        printf("------------------%d------------------- |", player1_score);
        printf("| ------------------%d------------------", player2_score);
        return 0;
    } else if (player1_score < 10 && player2_score >= 10) {
        printf("------------------%d------------------- |", player1_score);
        printf("| -----------------%d-------------------", player2_score);
        return 0;
    } else if (player1_score >= 10 && player2_score < 10) {
        printf("-----------------%d------------------- |", player1_score);
        printf("| ------------------%d-------------------", player2_score);
        return 0;
    } else if (player1_score >= 10 && player2_score >= 10) {
        printf("-----------------%d------------------- |", player1_score);
        printf("| -----------------%d-------------------", player2_score);
        return 0;
    } else if (player1_score == 21 || player2_score == 21) {
        //вызов функции(1)
        return 0;
    }
}
