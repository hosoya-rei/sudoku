#include "fanction.h"
#include "shuffle.h"




int main(void) {
	int x, y, num;
	int array[SIZE][SIZE];
	int num19[SIZE];
	char ba[SIZE][SIZE]; //なんマスか消した表示用
	int difi;
	
	make_template(num19, array);	
	shuffle_template(array);
	shuffle_tmp_2(array);

	

	printf("sudoku!!\n");
	while (1) {
		printf("難易度を入力:(初級:1, 中級:2, 上級:3)=>"); scanf("%d", &difi);	
		if (difi < 4 && difi > 0) {	
			switch (difi) {
				case 1:
					create_dis_array(45, array, ba);
					break;
				case 2:
					create_dis_array(55, array, ba);
					break;
				case 3:
					create_dis_array(70, array, ba);
					break;
			}
			break;
		}
	}
	put_table(ba);
	
	while (1) {
		printf("1~9の座標と入れる数字を入力(x:横, y:縦)\n");

		printf("x="); scanf("%d", &x);
		printf("y="); scanf("%d", &y);
		printf("num="); scanf("%d", &num);
		
		if (x > 0 && x <= SIZE && y > 0 && y <= SIZE) {
			ba[y - 1][x - 1] = '0' + num;
		}else {
			printf("不正な数値です。\n");
			continue;
		}
		
		put_table(ba);
		
		if (end_judge(ba) == 0) {
			if (true_folse(ba, array) == SIZE * SIZE) {
				printf("クリア！！\n");
			}else {
				printf("失敗です。\n");
			}
			break;
		}	
				
	}
return 0;	
}


