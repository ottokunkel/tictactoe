#include <stdio.h>
#include <stdlib.h>

// List of to-do
// 		- fix number of dashes in printBoard so that it can accomodate different sized boards
// 		- possibly fix issues with different sized game boards in printBoard();
int box_height = 3;
int game_dimensions = 3;

struct Board{
	char board_values[3][3];
	
};

void initialize_board(struct Board *b){
	// grabs number of rows & columns
	int rows = sizeof(b->board_values)/sizeof(b->board_values[0]);
	int columns = sizeof(b->board_values)/rows;	

	// sets all values to null
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			b->board_values[i][j] = 'x';
		}
	}
}

void printBoard(struct Board *b){
	
	// grabs number of rows and columns
	int rows = sizeof(b->board_values)/sizeof(b->board_values[0]);
	int columns = sizeof(b->board_values)/rows;
	
	// note 9 characters long
	char *line = "--------";

	// prints header
	printf("   ");
	for(int i = 0; i < columns; i++){
		printf("|   %d   ",i);
	}
	printf("|\n--- ");
	
	for(int i = 0; i < columns; i++){
		printf("%s", line);
	}
	printf("\n");
	
	// prints side header & content
	for(int i = 0; i < rows; i++){
		
		// for box height
		for(int j = 0; j < box_height; j++){

			// for every column print the first line 
			for(int k = 0; k < columns; k++){
				if(k == 0){
					if(j == box_height%2){
						printf(" %d |   %c   |",i,b->board_values[i][k]);
					}else{
							printf("   |       |");
					}
				}else{
					if(j == box_height%2){
						printf("   %c   |",b->board_values[i][k]);
					}else{
							printf("       |");
					}
				}
			}
			printf("\n");
		}
		printf("--- ");
		for(int k = 0; k < columns; k++){
			printf("%s", line);
		}
			printf("\n");

	}
	
}

int* promptUser(){
	int *a = malloc(sizeof(int) * 2);
	int x;
	int y;

	printf("What column  would you like to choose? ");
	scanf("%d",&x);
	printf("\n");
	
	printf("What row would you like to choose? ");
	scanf("%d", &y);
	printf("\n");
	
	a[0] = x;
	a[1] = y;
	printf("address of malloc: %lu\n", a);
	return a;
}

int main(){
	

	//initialize character array
	char win = 0;

	struct Board mainBoard;
	initialize_board(&mainBoard);
	//printBoard(&mainBoard);
	while(!win){
		printBoard(&mainBoard);
		int *input = promptUser();
		
		printf("address of input: %lu\n", input+1);
		free(input);
		win = 1;
	}
	
	
	
}
