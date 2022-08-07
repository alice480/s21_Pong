#include <stdio.h>
#include <stdlib.h>

const char lines = 25, columns = 80, middle = 38;
char corner30 = 0, corner45 = 0;
char right_move = 1;
char command;
int right = 1, down = 1; // direction
int player1_score = 0, player2_score = 0;
int racket_left_y = 11, racket_right_y = 11;
int ball_x = 0, ball_y = 11;

// drawing field boundaries

void horizontal_border_rendering() {
    for (char i = 0; i < columns; i++)
        printf("-");
    printf("\n");
}

void vertical_border_rendering() {
    printf("|");
}

// drawing racket movement

int checking() {
    if (command == 'a' || command == 'A')
        return (command == 'a' || command == 'A');
    if (command == 'z' || command == 'Z')
        return (command == 'z' || command == 'Z');
    if (command == 'm' || command == 'M')
        return (command == 'm' || command == 'M');
    if (command == 'k' || command == 'K')
        return (command == 'k' || command == 'K');
    return (command == ' ');
}

void racket_movement() {
    if (checking()) {
        if ((command == 'a' || command == 'A') && !right_move && racket_left_y > 1)
            racket_left_y--;
        else if ((command == 'z' || command == 'Z') && !right_move && racket_left_y < 21)
            racket_left_y++;
        else if ((command == 'k' || command == 'K') && right_move && racket_right_y > 1)
            racket_right_y--;
        else if ((command == 'm' || command == 'M') && right_move && racket_right_y < 21)
            racket_right_y++;
    }
}

void racket_rendering(int y, int number) {
    if (number) {
        if ((racket_left_y - 1 <= y) && (y <= racket_left_y + 1))
            printf("|");
        else
            printf(" ");
    }
    else {
        if ((racket_right_y - 1 <= y) && (y <= racket_right_y + 1))
            printf("|");
        else
            printf(" ");
    }
}

// ball movement

// checking that the player who owns the queue is moving
int action_check() {
    if (checking()) {
        if (command == 'a' || command == 'A')
            return ((command == 'a' || command == 'A') && !right_move);
        else if (command == 'z' || command == 'Z')
            return ((command == 'z' || command == 'Z') && !right_move);
        else if (command == 'k' || command == 'K')
            return ((command == 'k' || command == 'K') && right_move);
        else if (command == 'm' || command == 'M')
            return ((command == 'm' || command == 'M') && right_move);
    }
    return (command == ' ');
}

int coordinate_calculation() {
    // x coordinate change
    if (action_check()) {
        ball_x += right;
        if (corner30 && (2 <= ball_y && ball_y <= 22))
            ball_y += down * 2;
        else if (corner45 || ball_y < 2 || ball_y > 22)
            ball_y += down;

        if (ball_x == 0 || ball_x == columns - 5) {
            right *= -1;
            right_move = !right_move;
            if (ball_y == racket_left_y || ball_y == racket_right_y) {
                corner45 = 1;
                corner30 = 0;
            }
            else if (ball_y == racket_left_y - 1 || ball_y == racket_left_y + 1 ||
                ball_y == racket_right_y - 1 || ball_y == racket_right_y + 1) {
                corner30 = 1;
                corner45 = 0;
            }
        }
        if (ball_y < 1 || ball_y >= 22)
            down *= -1;
    }
}

// drawing the inside of the field

void field_inner_part_rendering(int y) {
    for (char x = 0; x < columns - 4; x++) {
        if (y == ball_y && x == ball_x)
            printf("*");
        else if (x == middle || x == middle - 1)
            printf("|");
        else
            printf(" ");
    }
}

// rendering of the whole game

void rendering() {
    int left = 1, right = 0;
    system("cls");
    coordinate_calculation();
    horizontal_border_rendering();
    for (char i = 0; i < lines - 2; i++) {
        vertical_border_rendering();
        racket_rendering(i, left);
        field_inner_part_rendering(i);
        racket_rendering(i, right);
        vertical_border_rendering();
        printf("\n");
    }
    horizontal_border_rendering();
}

void event_handling() {
    char count = 0;
    rendering();
    //while(player1_score < 21 || player2_score < 21) {
    while (count < 200) {
        scanf_s("%c", &command);
        racket_movement();
        rendering();
        count++;
    }
}

int main() {
    event_handling();
    return 0;
}
