#include "fanction.h"


int true_folse(char bb[][SIZE], int y[][SIZE]) {
	j = 0;
	char test[5];
	int count = 0;
	for (i = 0; i < SIZE; i++) {
		for (k = 0; k < SIZE; k++) {
			test[0] = '0' + y[i][k];
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

