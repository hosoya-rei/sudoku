#include "fanction.h"



int main(void) {
	struct sudoku su;	
	
	int ans[SIZE][SIZE];
	char bb[SIZE][SIZE];
	int x, y, num;
	add_sudoku(&su);

	printf("sudoku!!\n");
	init_game(su, ans, bb);
	
	while (1) {
		printf("1~9の座標と入れる数字を入力(x:横, y:縦)\n");
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


