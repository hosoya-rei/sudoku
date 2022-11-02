#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define SIZE 4
int i, k, j;
void init_game(int a[], char b[], int ans[][SIZE], char bb[][SIZE]);
void put_table(char bb[][SIZE]);
int end_judge(char bb[][SIZE]);
int true_folse(char bb[][SIZE], int a[]);



int main(void) {
	int a[] = {2, 3, 4, 1, 4, 1, 2, 3, 3, 4, 1, 2, 1, 2, 3, 4};
	char b[] = {'.', '.', '.', '1', '4', '.', '.', '3', '.', '.', '.', '.', '1', '2', '.', '4'};
	int ans[SIZE][SIZE];
	char bb[SIZE][SIZE];
	int x, y, num;

	printf("sudoku!!\n");
	init_game(a, b, ans, bb);
	
	while (1) {
		printf("1~4の座標と入れる数字を入力(x:横, y:縦)\n");
		put_table(bb);

		printf("x="); scanf("%d", &x);
		printf("y="); scanf("%d", &y);
		printf("num="); scanf("%d", &num);
		
		if (x > 0 && x < 5 && y > 0 && y < 5) {
			bb[y - 1][x - 1] = '0' + num;
		}else {
			printf("不正な数値です。\n");
			continue;
		}
		
		put_table(bb);
		
		if (end_judge(bb) == 0) {
			if (true_folse(bb, a) == 16) {
				printf("クリア！！\n");
			}else {
				printf("失敗です。\n");
			}
			break;
		}	
				
	}
return 0;	
}

int true_folse(char bb[][SIZE], int a[]) {
	j = 0;
	char test[5];
	int count = 0;
	for (i = 0; i < SIZE; i++) {
		for (k = 0; k < SIZE; k++) {
			test[0] = '0' + a[j++];
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
	printf("\n  1 2 3 4\n");
	printf("  ーーーー\n");	
	for (i = 0; i < SIZE; i++) {
		printf("%d|", i + 1);
		for (k = 0; k < SIZE; k++) {
			printf("%c ", bb[i][k]);
		}printf("|\n");
	}printf("  ーーーー\n");
}
		


void init_game(int a[], char b[], int ans[][SIZE], char bb[][SIZE]) {
	for (i = 0; i < SIZE; i++) {
		for (k = 0; k < SIZE; k++) {
			ans[i][k] = a[j++];
		}
	}
	j = 0;
	for (i = 0; i < SIZE; i++) {
		for (k = 0; k < SIZE; k++) {
			bb[i][k] = b[j++];		 	
		}
	}
}
