#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#define input_size 2

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
const char* start = "TicTacToe!";
char test[4] = "test";
int turn;
char player_char, CPU_char;

void print_board()
{
    // printf("\n");
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("[%c]", board[i][j]);
        }
        printf("\n");
    }
}

void slow_text(const char* text)
{
    for(int i = 0; i < strlen(text); i++)
    {
        printf("%c", text[i]);
        fflush(stdout);
        usleep(185000);
    }
    printf("\n");
}

void first_second(char input)
{
    while(1)
    {
        switch(input)
        {
            case '1':
                turn = 1;
                player_char = 'X';
                CPU_char = 'O';
                return;
            case '2':
                turn = 2;
                player_char = 'O';
                CPU_char = 'X';
                return;
            default:
                printf("Invalid input\nTry again\n");
        }
    }
}

void player()
{
    int row, column;
    while(1)
    {
        printf("What row you want?\n");
        scanf("%d", &row);

        printf("What column you want?\n");
        scanf("%d", &column);

        if(board[row][column] == ' ')
        {
            board[row][column] = player_char;
            return;
        }
        else
        {
            printf("Invalid position\nTry again\n");
        }
    }
    
    // scanf("%d", );
}

void CPU()
{
    int row, column;
    while(1)
    {
        row = rand() % 3;
        column = rand() % 3;
        printf("row: %d, column: %d\n", row, column);
        if(board[row][column] == ' ')
        {
            board[row][column] = CPU_char;
            break;
        }
    }
}

void check_board()
{
    printf("check\n");
}

int main()
{
    char input, temp;
    int turn_num = 0;
    //input = (char *) malloc(50);
    slow_text(start);
    slow_text("Press enter to start");
    // char temp[input_size];
    scanf("%c", &temp);
    // fgets(temp, input_size, stdin);
    // fflush(stdin);
    printf("Do you want to go first or second?\n");
    // fgets(temp, input_size, stdin);
    scanf("%c", &input);
    first_second(input);
    // print_board();

    while(1)
    {
        turn_num++;
        printf("Turn #%d\n", turn_num);
        print_board();
        switch(turn)
        {
            case 1:
                printf("Your turn:\n");
                player();
                turn = 2;
                break;
            case 2:
                printf("CPU's turn:\n");
                CPU();
                turn = 1;
                break;
        }
        if(turn_num >= 3)
        {
            check_board();
        }
    }

    printf("Thanks for playing!");
}