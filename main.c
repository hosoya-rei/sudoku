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



int main(void) {
	struct sudoku su;	
	
	int ans[SIZE][SIZE];
	char bb[SIZE][SIZE];
	int x, y, num;
	add_sudoku(&su);

	printf("sudoku!!\n");
	init_game(su, ans, bb);
	
	while (1) {
		printf("1~4の座標と入れる数字を入力(x:横, y:縦)\n");
		put_table(bb);

		printf("x="); scanf("%d", &x);
		printf("y="); scanf("%d", &y);
		printf("num="); scanf("%d", &num);
		
		if (x > 0 && x <= SIZE && y > 0 && y <= SIZE) {
			bb[y - 1][x - 1] = '0' + num;
		}else {
			printf("不正な数値です。\n");
			continue;
		}
		
		put_table(bb);
		
		if (end_judge(bb) == 0) {
			if (true_folse(bb, su) == SIZE * SIZE) {
				printf("クリア！！\n");
			}else {
				printf("失敗です。\n");
			}
			break;
		}	
				
	}
return 0;	
}

void add_sudoku(struct sudoku *s) {
	char a_tenta[SIZE * SIZE] = {7, 1, 2, 9, 8, 4, 3, 5, 6, 5, 3, 4, 1, 6, 7, 2, 8, 9, 9, 6, 8, 3, 5, 2, 7, 1, 4, 2, 8, 1, 5, 3, 9, 6, 4, 7, 6, 7, 3, 2, 4, 1, 5, 9, 8, 4, 5, 9, 6, 7, 8, 1, 2, 3, 8, 4, 5, 7, 2, 6, 9, 3, 1, 1, 2, 6, 4, 9, 3, 8, 7, 5, 3, 9, 7, 8, 1, 5, 4, 6, 2};
	char b_tenta[SIZE * SIZE] = {'7', '1', '2', '.', '.', '4', '.', '5', '6', '.', '3', '4', '1', '.', '.', '.', '8', '9', '.', '.', '8', '3', '5', '2', '.', '.', '.', '.', '.', '1', '.', '3', '9', '6', '4', '7', '6', '7', '.', '2', '.', '.', '5', '.', '.', '4', '5', '.', '.', '.', '8', '1', '2', '3', '8', '4', '5', '.', '.', '6', '9', '.', '1', '.', '.', '6', '4', '9', '.', '.', '.', '.', '3', '9', '.', '8', '1', '5', '.', '.', '2'};

	for (i = 0; i < SIZE * SIZE; i++) {
		s->a[i] = a_tenta[i];
		s->b[i] = b_tenta[i];
	}
}


int true_folse(char bb[][SIZE], struct sudoku s) {
	j = 0;
	char test[5];
	int count = 0;
	for (i = 0; i < SIZE; i++) {
		for (k = 0; k < SIZE; k++) {
			test[0] = '0' + s.a[j++];
			if (bb[i][k] == test[0]) {
				count++;
			}
		}
	}
return count;
}



int end_judge(char bb[][SIZE]) {
	int count = 0;
	for (i = 0; i < SIZE; i++) {
		for (k = 0; k < SIZE; k++) {
			if (bb[i][k] == '.') {
				count++;
			}
		}
	}
return count;
}			


void put_table(char bb[][SIZE]) {
	printf("\n  1 2 3  4 5 6  7 8 9\n");
	printf("  ーーーーーーーーーー\n");	
	for (i = 0; i < SIZE; i++) {
		printf("%d|", i + 1);
		for (k = 0; k < SIZE; k++) {
			printf("%c ", bb[i][k]);
			if (k != 8) {
				if ((k + 1) % 3 == 0) {
					printf("|");
				}
			}
		}printf("|\n");
	if ((i + 1) % 3 == 0) {
		printf("  ーーーーーーーーーー\n");
	}
	}
}
		


void init_game(struct sudoku s, int ans[][SIZE], char bb[][SIZE]) {
	for (i = 0; i < SIZE; i++) {
		for (k = 0; k < SIZE; k++) {
			ans[i][k] = s.a[j++];
		}
	}
	j = 0;
	for (i = 0; i < SIZE; i++) {
		for (k = 0; k < SIZE; k++) {
			bb[i][k] = s.b[j++];		 	
		}
	}
}
