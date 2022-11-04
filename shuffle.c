#include "shuffle.h"

void create_dis_array(int x[][SIZE], char y[][SIZE]) {
	j = 0;
	char xx[SIZE * SIZE];
	int dis_num[45];
	for (i = 0; i < SIZE; i++) {
		for (k = 0; k < SIZE; k++) {
			char i_c = '0' + x[i][k];
			xx[j++] = i_c;  //ばらし
		}
	}
	srand((unsigned int)time(NULL));
	i = 0;
	while (i < 45) {  //空白の場所をランダムで
		dis_num[i] = rand() %81 +0;
		if (i != 0) {
			for (k = 0; k < i; k++) {	
				if (dis_num[i] == dis_num[k]) {
					continue;
				}
			}
		}
		i++;
	}	
	for (i = 0; i < 45; i++) {  //空白の位置に'.'を代入
		int n = dis_num[i];
		xx[n] = '.';
	}		
	j = 0;
	for (i = 0; i < SIZE; i++) {  //表示するy配列にxxを代入
		for (k = 0; k < SIZE; k++) {
			y[i][k] = xx[j++];
		}
	}
}
 
void shuffle(int a, int b, int x[][SIZE]) {
	int y, z;
	int p = 0;
	while (p < 1) {
		p++;
		y = rand() %a +b; 
		z = rand() %a +b;
		if (y == z) {
			p--;
		}
	}
	int f = 0;
	while (f < SIZE) {
		int tmp;
		tmp = x[f][y];
		x[f][y] = x[f][z];
		x[f][z] = tmp;
		f++;
	}
	
}

void shuffle_2(int a, int b, int x[][SIZE]) {
	int y, z;
	int p = 0;
	while (p < 1) {
		p++;
		y = rand() %a +b; 
		z = rand() %a +b;
		if (y == z) {
			p--;
		}
	}
	int f = 0;
	while (f < SIZE) {
		int tmp;
		tmp = x[y][f];
		x[y][f] = x[z][f];
		x[z][f] = tmp;
		f++;
	}
	
}


void shuffle_tmp_2(int x[][SIZE]) {
	int coshky = rand() %6 +1;
	int tmp_array[SIZE][SIZE];
	for (i = 0; i < SIZE; i++) {
		for (k = 0; k < SIZE; k++) {
			tmp_array[i][k] = x[i][k];
		}
	}
	
	switch (coshky) {
		case 1:
			//1をシャッフル		
			shuffle(3, 0, tmp_array);	
			break;
		case 2:
			//2をシャッフル
			shuffle(3, 3, tmp_array);
		break;
		case 3:
			//3をシャッフル
			shuffle(3, 6, tmp_array);
		break;
		case 4:
			//1と2をシャッフル
			shuffle(3, 0, tmp_array);
			shuffle(3, 3, tmp_array);
		break;
		case 5:
			//1と3をシャッフル
			shuffle(3, 0, tmp_array);
			shuffle(3, 6, tmp_array);
		break;
		case 6:
			//2と3をシャッフル
			shuffle(3, 3, tmp_array);
			shuffle(3, 6, tmp_array);
		break;
	}
	coshky = rand() %3 +4;
	switch (coshky) {  //横シャッフル
		case 1:
			//1をシャッフル		
			shuffle_2(3, 0, tmp_array);	
			break;
		case 2:
			//2をシャッフル
			shuffle_2(3, 3, tmp_array);
		break;
		case 3:
			//3をシャッフル
			shuffle_2(3, 6, tmp_array);
		break;
		case 4:
			//1と2をシャッフル
			shuffle_2(3, 0, tmp_array);
			shuffle_2(3, 3, tmp_array);
		break;
		case 5:
			//1と3をシャッフル
			shuffle_2(3, 0, tmp_array);
			shuffle_2(3, 6, tmp_array);
		break;
		case 6:
			//2と3をシャッフル
			shuffle_2(3, 3, tmp_array);
			shuffle_2(3, 6, tmp_array);
		break;
	}
	for (i = 0; i < SIZE; i++) {
		for (k = 0; k < SIZE; k++) {
			x[i][k] = tmp_array[i][k];
		}	
	}
}


//テンプレートをシャッフル(templateのxをansのyに代入)
void shuffle_template(int x[][SIZE]) {
	int y, z;
	int key[] = {1, 3, 2, 6, 5, 7};
	srand((unsigned int)time(NULL));
	int f = 0;
	while (f < SIZE) {
		i = 0;
		while (i < 5) {
			y = key[i];
			z = key[i + 1];
			int tmp;
			tmp = x[f][y];
			x[f][y] = x[f][z];
			x[f][z] = tmp;
			i += 2;
		}
		f++;
	}
}

//シャッフル前の初期値を配列に入力
void make_template(int y[], int x[][SIZE]) {
	for (i = 0; i < SIZE; i++) {
		for (k = 0; k < SIZE; k++) {
			loop19(y, i + 1);
			x[i][k] = y[k];
		}
	}
}

//1~9までの数字を、ループして配列に格納（任意の数字から始められる）
void loop19(int y[], int s) {
	int a, b = 0, c;
	c = s;
	while (b < SIZE + 1) {
		a = c % 10;
		if (a != 0) {	
			y[b++] = a;	
		}
		c++;
	}
}


void put_int_array(int x[][SIZE]) {
	for (i = 0; i < SIZE; i++) {
		for (k = 0; k < SIZE; k++) {
			printf("%d ", x[i][k]);
		}printf("\n");
	}
}



