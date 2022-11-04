#ifndef _SHUFFLE_H_
#define _SHUFFLE_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 9
int i, k, j;
void loop19(int t[], int s);
void make_template(int y[], int x[][SIZE]);
void put_int_array(int x[][SIZE]);
void shuffle_template(int x[][SIZE]);
void shuffle(int a, int b, int x[][SIZE]);
void shuffle_2(int a, int b, int x[][SIZE]);
void shuffle_tmp_2(int x[][SIZE]);
void create_dis_array(int x[][SIZE], char y[][SIZE]);

#endif //_SHUFFLE_H_
