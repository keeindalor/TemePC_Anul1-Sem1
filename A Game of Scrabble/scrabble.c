#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util/print_board.h"
#include "util/scrabble.h"

char board[15][15];

int power(int base, int a) 
{
    if (a != 0)
        return (base * power(base, a - 1));
    else
        return 1;
}

void initialise_board (char board [ 15 ] [ 15 ])
{
	int i, j;
	for ( i = 0; i < 15; i ++)
		for ( j = 0 ; j < 15; j ++)
			board [ i ] [ j ] = '.';
}
int calculate_points(char bonus_board [ 15 ] [ 15 ], char y[3],
			 char x[3], char d[3],size_t length, int points [26],
			 char word [16], char xx[4], char yy[4])
{	size_t k,j;
	int bonus_points = 0, count = 0;
	
	for (k = 0; k < length; k ++)
			bonus_points = bonus_points + points [ word [ k ] - 'A' ];
			
			
	if (strstr (word, xx) != NULL)
	{	
			
		if ( atoi(d) == 0)
		{	
			for (j = atoi(x); j < atoi(x) + length; j++)
			{	
				if ( bonus_board [ atoi(y) ] [ j ] == 1)
					count++;
			}
				bonus_points = bonus_points * power (2, count);
					
		}		
					
		else
		{
			for (j = atoi(y); j <= atoi(y) + length; j++)
			{
				if (bonus_board [ j ] [ atoi(x) ] == 1)
					count++;
						
			}
				bonus_points = bonus_points * power (2, count);
					
		}
	}
	count = 0;
	
	if (strstr (word, yy) != NULL)
	{
		if (word [length - 2] == yy[0] && word [length - 1] == yy[1])
		{
			if ( atoi(d) == 0)
			{	
				for (j = atoi(x); j < atoi(x) + length; j++)
				{	
					if ( bonus_board [ atoi(y) ] [ j ] == 2)
						count++;
				}
				bonus_points = bonus_points * power (3, count);
					
			}		
						
		
			else
			{
				for (j = atoi(y); j <= atoi(y) + length; j++)
				{
					if (bonus_board [ j ] [ atoi(x) ] == 2)
						count++;
						
				}
					bonus_points = bonus_points * power (3, count);
					
			}
		}
	}
	return bonus_points;
	
}


void insert_words (char board [ 15 ] [ 15 ])
{
	char word_data [ 30 ], N[5], x[3], y[3], d[3], word[16];
	size_t length, j, k;
	int i;
	
	fgets (N, 5, stdin);
	
	for (i = 1; i <= atoi (N); i ++)
	{
		fgets (word_data, 30, stdin);
		length = strlen (word_data);
		
		if (word_data [ length - 1 ] == '\n')
			word_data [ length - 1 ] = '\0';
			
		k = 0;
		
		strcpy(y, strtok(word_data , " "));
		strcpy(x, strtok(NULL, " "));
		strcpy(d, strtok(NULL, " "));
		strcpy(word, strtok(NULL, " "));
		
		length = strlen (word);
		
		if ( atoi(d) == 0)
		{
			for (j = atoi(x); j < atoi(x) + length; j++)
			{	
				board [ atoi(y) ] [ j ] = word [k];
				k++;
			}
		}
		
		else
		{
			for (j = atoi(y); j < atoi(y) + length; j++)
			{
				board [ j ] [ atoi(x) ] = word [k];
				k++;
			}
		}
					
	}
	
	
}

void points_simple ()
{
	int points [26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1,
	3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
	
	char word_data [ 30 ], N[5], x[3], y[3], d[3], word[16];
	size_t length, k;
	int i, score1 = 0, score2 = 0;
	
	fgets (N, 5, stdin);
	
	for (i = 1; i <= atoi (N); i ++)
	{
		fgets (word_data, 30, stdin);
		length = strlen (word_data);
		
		if (word_data [ length - 1 ] == '\n')
			word_data [ length - 1 ] = '\0';
			
		k = 0;
		
		strcpy(y, strtok(word_data , " "));
		strcpy(x, strtok(NULL, " "));
		strcpy(d, strtok(NULL, " "));
		strcpy(word, strtok(NULL, " "));
		
		length = strlen (word);
		
		if (i % 2 == 1 )
		{
			for (k = 0; k < length; k ++)
			{
				score1 = score1 + points [ word [ k ] - 'A' ];
			}
				
		}
		else 
		{
			for (k = 0; k < length; k ++)
			{
				score2 = score2 + points [ word [ k ] - 'A' ];
			}
		}
			
	}
	
	printf("Player 1: %d Points\n", score1);
	printf("Player 2: %d Points\n", score2);
	

}

void bonus_words ( )
{
	int points [26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1,
	3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
	
	char word_data [ 30 ], N[5], x[3], y[3], d[3], word[16], xx[4], yy[4];
	size_t length;
	int i, score1 = 0, score2 = 0;
	
	
	
	fgets (xx, 4, stdin);
	length = strlen (xx);
		if (xx [ length - 1 ] == '\n')
			xx [ length - 1 ] = '\0';
	
	fgets (yy, 4, stdin);
	length = strlen (yy);
		if (yy [ length - 1 ] == '\n')
			yy [ length - 1 ] = '\0';
			
	
	fgets (N, 5, stdin);
	
	for (i = 1; i <= atoi (N); i ++)
	{
		fgets (word_data, 30, stdin);
		length = strlen (word_data);
		
		if (word_data [ length - 1 ] == '\n')
			word_data [ length - 1 ] = '\0';
		
		strcpy(y, strtok(word_data , " "));
		strcpy(x, strtok(NULL, " "));
		strcpy(d, strtok(NULL, " "));
		strcpy(word, strtok(NULL, " "));
		
		length = strlen (word);
		
		
		if (i % 2 == 1)
			score1 = score1 + calculate_points (bonus_board,y, x, d,length,points,
			 word, xx,yy);
		else
			score2 = score2 + calculate_points(bonus_board,y, x, d,length,points,
			 word, xx,yy);
	}		
			
			
			
			
	printf("Player 1: %d Points\n", score1);
	printf("Player 2: %d Points\n", score2);
	
}

int remove_word (char words[][NUM_WORDS], char word[15], int n)
{
	int i;
	for (i = 0; i < n; i ++)
	{
		if (strcmp (words[i], word) == 0)
			break;
	}
	
	if (i < n)
	{
		n = n - 1;
		for (int j = i; j < n; j ++)
		{
			strcpy (words[j], words[j+1]);
		}
	}
	
	return n;
}


void insert_new_word(char board [ 15 ] [ 15 ], int n, char words[][NUM_WORDS])
{
	
	int row, column, i, k;
	size_t j, l;
	
	
	for (i = 0; i < n; i ++)
	{	
		
		k = 0;
		
		for (row = 0; row < 15; row ++)
		{
			for ( column = 0; column < 15; column++)
			{
				if (words[i][0] == board[row][column])
					break;
			}
			
			if (column < 15 )
				break;
		}
		
		
		if (row < 15 && (strlen (words[i]) + row <= 15 || strlen (words[i]) + column <= 15))
		{
			for (j = column + 1; j < column + strlen (words[i]); j ++)
			{
				if (board [row][j] != '.')
					break;
			}
			
			if (j == column + strlen (words[i]) && j <= 15)
			{
				for (l = column; l < column + strlen(words[i]); l++)
				{
					board[row][l] = words[i][k];
					k++;
				}
			}
			
			else
			{	
				
				
				for (j = row + 1; j < row + strlen(words[i]); j++)
				{
					if (board[j][column] != '.')
						break;
				}
				
				if (j == row + strlen(words[i]) && j <= 15)
				{
					for (l = row; l < row + strlen (words[i]); l++)
					{	
						board[l][column] = words[i][k];
						k++;
					}
					
				}
				else
					continue;
					
			}
			
			break;
		}
		
		else
			continue;
	}

}

void next_word (char board [ 15 ] [ 15 ])
{
	char xx[4], yy[4];
	size_t length, j;
	int i,  k = 0, n = 100;
	
	
	
	fgets (xx, 4, stdin);
	length = strlen (xx);
		if (xx [ length - 1 ] == '\n')
			xx [ length - 1 ] = '\0';
	
	fgets (yy, 4, stdin);
	length = strlen (yy);
		if (yy [ length - 1 ] == '\n')
			yy [ length - 1 ] = '\0';
			
	
	char word_data [ 30 ], N[5], x[3], y[3], d[3], word[16];
	
	fgets (N, 5, stdin);
	
	for (i = 1; i <= atoi (N); i ++)
	{
		fgets (word_data, 30, stdin);
		length = strlen (word_data);
		
		if (word_data [ length - 1 ] == '\n')
			word_data [ length - 1 ] = '\0';
			
		k = 0;
		
		strcpy(y, strtok(word_data , " "));
		strcpy(x, strtok(NULL, " "));
		strcpy(d, strtok(NULL, " "));
		strcpy(word, strtok(NULL, " "));
		
		length = strlen (word);
		
		if ( atoi(d) == 0)
		{
			for (j = atoi(x); j < atoi(x) + length; j++)
			{	
				board [ atoi(y) ] [ j ] = word [k];
				k++;
			}
		}
		
		else
		{
			for (j = atoi(y); j < atoi(y) + length; j++)
			{
				board [ j ] [ atoi(x) ] = word [k];
				k++;
			}
		}
		
		n = remove_word (words, word, n);
		
					
	}
	
	insert_new_word(board, n, words);
}


int main()
{
	char task_number[5];
	
	fgets (task_number, 5, stdin);
	
	if (task_number [ 0 ] == '0')
	{
		initialise_board (board);
		print_board (board);
	}
	
	else if (task_number [ 0 ] == '1')
		{	
			initialise_board (board);
			insert_words(board);
			print_board(board);
		}
	else if (task_number [ 0 ] == '2')
		{
			points_simple();
		}
	else if (task_number [ 0 ] == '3')
		{	
			bonus_words();
		}
	else if (task_number [ 0 ] == '4')
		{	
			initialise_board (board);
			next_word(board);
			print_board(board);
				
		}
		
}
