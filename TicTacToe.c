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
}

void CPU()
{
    int size = 3;
    int* valid_rows;
    int* valid_columns;

    valid_rows = (int*)calloc(size, sizeof(int));
    valid_columns = (int*)calloc(size, sizeof(int));

    int row, column;
    int counter = 0;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] == ' ')
            {
                valid_columns[counter] = j;
                valid_rows[counter] = i;
                counter++;
            }
        }
    }
    
    
    
    while(1)
    {
        row = rand() % 3;
        column = rand() % 3;
        // printf("row: %d, column: %d\n", row, column);
        if(board[row][column] == ' ')
        {
            board[row][column] = CPU_char;
            break;
        }
    }
}

int check_board()
{
    char temp[3];
    int count = 0;
    int x = 0;

    // Checks for row wins
    for(int row = 0; row < 3; row++)
    {
        for(int column = 0; column < 3; column++)
        {
            if(board[row][column] == ' ' || board[row][column] != board[row][column+1])
            {
                x = 0;
                break;
            }
            else if(board[row][column] == board[row][column+1])
            {
                if(x == 1)
                {
                    if(temp[0] == player_char)
                    {
                        return 1;
                    }
                    else
                    {
                        return 2;
                    }
                }
                else
                {
                    x++;
                    temp[0] = board[row][column];
                }
            }
        }
    }

    // Checks for column wins
    for(int column = 0; column < 3; column++)
    {
        for(int row = 0; row < 3; row++)
        {
            if(board[row][column] == ' ' || board[row][column] != board[row+1][column])
            {
                x = 0;
                break;
            }
            else if(board[row][column] == board[row+1][column])
            {
                if(x == 1)
                {
                    if(temp[0] == player_char)
                    {
                        return 1;
                    }
                    else
                    {
                        return 2;
                    }
                }
                else
                {
                    x++;
                    temp[0] = board[row][column];
                }
            }
        }
    }

    // Checks for diagonal wins
    for(int i = 0; i < 3; i++)
    {
        if(board[i][i] == ' ' || board[i][i] != board[i+1][i+1])
        {
            x = 0;
            break;
        }
        else if(board[i][i] == board[i+1][i+1])
        {
            if(x == 1)
            {
                if(temp[0] == player_char)
                {
                    return 1;
                }
                else
                {
                    return 2;
                }
            }
            else
            {
                x++;
                temp[0] = board[i][i];
            }
        }
    }

    for(int i = 0; i < 3; i++)
    {
        if(board[i][2-i] == ' ' || board[i][2-i] != board[i+1][i-1])
        {
            x = 0;
            break;
        }
        else if(board[i][2-i] == board[i+1][i-1])
        {
            if(x == 1)
            {
                if(temp[0] == player_char)
                {
                    return 1;
                }
                else
                {
                    return 2;
                }
            }
            else
            {
                x++;
                temp[0] = board[i][2-i];
            }
        }
    }


    // for(int row = 0; row < 3; row++)
    // {
    //     for(int column = 0; column < 3; column++)
    //     {
    //         temp[count] = board[row][column];
    //         if(board[row][column+1] == temp[count])
    //         {
    //             continue;
    //         }
    //         else if(board[row+1][column] == temp[count])
    //         {
    //             break;
    //         }
    //         else if(board[row+1][column+1] == temp[count])
    //         {
    //             column++;
    //             row++;
    //         }
    //         else
    //         {
    //             return 0;
    //         }

    //         if(count == 3)
    //         {
    //             if(temp[0] == 'X')
    //             {
    //                 return 1;
    //             }
    //             else if(temp[0] == 'O')
    //             {
    //                 return 2;
    //             }
    //         }
    //     }
    // }
}

int main()
{
    char input, temp;
    int result;
    int turn_num = 0;
    slow_text(start);
    slow_text("Press enter to start");
    scanf("%c", &temp);
    printf("Do you want to go first or second?\n");
    scanf("%c", &input);
    first_second(input);

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
        if(turn_num >= 6)
        {
            result = check_board();
            if(result == 1)
            {
                printf("Player won!\n");
                break;
            }
            else if(result == 2)
            {
                printf("CPU won!\n");
                break;
            }
        }
        
        if(turn_num == 9)
        {
            printf("There is a draw\n");
            break;
        }
    }
    print_board();
    printf("Thanks for playing!\n");
}