/*

*  Author: Paul Bassey-Duke, pbasseyduke2017@my.

*  Course: CSE 1001, Section 01,02,03,04,05,06,E1 OR E2, Fall 2018

*  Project: tictactoe

*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
void draw_board(char board[3][3]);
int check_win(char board[3][3]);
void player_turn(char board[3][3],int number_board[3][3], int *turn, int* player);


int main (void){
	  int win=0;
	  char board [3][3];
    int number_board[3][3];
    int counter = 1;
    int turn = 0;
    int player = 0;
		int turn2 = 0;
    printf ("Tic Tac Toe!\n");
    printf ("Player 1 (X)  Player 2 (O)\n");
 	printf ("The number of the cells starts from 1 to 9.\n");

  //gives the board the initial 1-9 numbers to be printed
    for (int i = 0; i < 3; i++) {
      for (int column = 0; column < 3; column++) {
        number_board[i][column] = counter;
        counter++;
        printf("| %d |", number_board[i][column]);
        board[i][column] = '-';
      }
      printf("\n");
    }

    do {
    player_turn(board, number_board, &turn, &player);
    draw_board(board);
    win = check_win(board);

    if (win == 1) {
      printf("Player %d won!\n", player);
    }
		while (turn >= 9 && win == 0 ) {
			printf ("The game ended in a draw\n");
			exit(0);
		}

	}while(win != 1);
    return 0;
 }

  void player_turn(char board[3][3], int number_board[3][3], int *turn, int* player) {
      int cell;
      //turn is a counter variable for every time the game is played;
      *turn = *turn + 1;

      if (*turn % 2 == 1) {
        *player = 1;
      }else{
        *player = 2;
      }
			printf("Player %d choose a cell to play: ", *player);
      scanf (" %d",&cell);
			while (cell < 0 || cell > 10){
				printf("Error. Number not in boundary choose a number 1 and 9. Enter new number\n");
				scanf ("%d",&cell);
			}
      printf ("The cell choosen by player %d: %d\n", *player, cell);

      //changes the board to add the value of the player's coin into the selected cell
      for (int roww = 0;roww < 3;roww++){
        for (int col = 0; col < 3;col++){
            if(cell == number_board[roww][col]){
                if (*player == 1) {
                  board[roww][col] = 'X';
                }else {
                  board[roww][col] = 'O';
                }
            }
        }
      }


  }

  void draw_board(char board[3][3]){

        for (int row = 0; row < 3; row++) {
          for (int column = 0; column < 3; column++) {
            printf("| %c |", board[row][column]);

          }
          printf("\n");
        }

 }

  int check_win(char board[3][3]){
    	if (board[0][0] == board [0][1] && board[0][0] == board[0][2] && board[0][0] != '-' && board[0][1] != '-' && board[0][2] != '-'){
        return 1;
    	}
    	else if (board[1][0] == board [1][1] && board[1][1] == board[1][2] && board[1][0] != '-'  && board[1][1] != '-' && board[1][2] != '-'){
        return 1;
    	}
    	else if (board[2][0] == board [2][1] && board[2][1] == board[2][2] && board[2][0] != '-'  && board[2][1] != '-' && board[2][2] != '-'){
        return 1;
    	}
    	else if (board[0][0] == board [1][1] && board[1][1] == board[2][2] && board[0][0] != '-' && board[1][1] != '-' && board[2][2] != '-'){
        return 1;
    	}
    	else if (board[2][0] == board [1][1] && board[1][1] == board[0][2] && board[2][0] != '-' && board[1][1] != '-' && board[0][2] != '-'){
        return 1;
    	}
    	else if (board[0][0] == board [1][0] && board[1][0] == board[2][0] && board[0][0] != '-'  && board[1][0] != '-' && board[2][0] != '-'){
        return 1;
    	}
    	else if (board[0][1] == board [1][1] && board[1][1] == board[2][1] && board[0][1] != '-' && board[1][1] != '-' && board[2][1] != '-'){
        return 1;
    	}
    	else if (board[0][2] == board [1][2] && board[1][2] == board[2][2] && board[0][2] != '-'  && board[1][2] != '-' && board[2][2] != '-'){
        return 1;
    	} else {
        return 0;
      }

	}
