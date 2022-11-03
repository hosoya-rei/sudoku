#include "fanction.h"

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
	j = 0;
	for (i = 0; i < SIZE; i++) {
		for (k = 0; k < SIZE; k++) {
			ans[i][k] = s.a[j++];
			j--;
	      		bb[i][k] = s.b[j++]; 
		}
	}

}
