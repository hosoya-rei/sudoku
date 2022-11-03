#ifndef _FANCTION_H_
#define _FANCTION_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define SIZE 9
struct sudoku {
	int a[81]; 
	int a2[16]; 
	int a3[16]; 
	int a4[16]; 
	int a5[16];
	char b[81]; 
	char b2[16]; 
	char b3[16]; 
	char b4[16]; 
	char b5[16];
};
int i, k, j;
void put_table(char bb[][SIZE]);
int end_judge(char bb[][SIZE]);
int true_folse(char bb[][SIZE], struct sudoku s);
void init_game(struct sudoku s, int ans[][SIZE], char bb[][SIZE]);
void add_sudoku(struct sudoku *s);



#endif //_FANCTION_H_
