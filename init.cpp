#include<iostream>
#include"easyx.h"
#include<conio.h>
#include"bomb.h"
#include<ctime>
int close = 0;
int allbomb = 0;
int leftbomb = 0;
int end = 0;
int bombnum_length = 0, bombnum_width = 0;
int onebomb_length = 0, onebomb_width = 0;
int windows_length = 0, windows_width = 0;
int bpx = 0, bpy = 0;
Bomb bomb[100][100];
Bomb num(1000, 300, 1100, 420);
Bomb retry(10, 100, 100, 170);
bool init_bomb(int dif) {
	if (dif == 1) {
		num.get(1000, 300, 1100, 420);
		retry.get(10, 100, 100, 170);
		bombnum_length = 8;
		bombnum_width = 8;
		bpx = 300, bpy = 80;
		onebomb_length = 70, onebomb_width = 70;
		windows_length = 1280, windows_width = 720;
		leftbomb = EASY;
		allbomb = EASY;
		return true;
	}
	if (dif == 2) {
		num.get(1050, 300, 1150, 420);
		retry.get(10, 100, 100, 170);
		bombnum_length = 10;
		bombnum_width = 10;
		bpx = 200, bpy = 70;
		onebomb_length = 65, onebomb_width = 65;
		windows_length = 1360, windows_width = 810;
		leftbomb = NORMAL;
		allbomb = NORMAL;
		return true;
	}
	if (dif == 3) {
		num.get(1750, 400, 1850, 520);
		retry.get(10, 100, 100, 170);
		bombnum_length = 20;
		bombnum_width = 15;
		bpx = 200, bpy = 70;
		onebomb_length = 60, onebomb_width = 60;
		windows_length = 1960, windows_width = 1080;
		leftbomb = DIFFICULT;
		allbomb = DIFFICULT;
		return true;

	}
	else {
		std::cerr << "invalid input" << std::endl;
	}
	return false;
}
void init_g() {
	initgraph(windows_length, windows_width, EX_DBLCLKS);
	setbkcolor(WHITE);
	cleardevice();
	setlinecolor(BLACK);
}
void re_g() {
	setbkcolor(WHITE);
	cleardevice();
	setlinecolor(BLACK);
}
void lose() {
	TCHAR lo[] = _T("YOU LOSS THE GAME");
	settextcolor(RED);
	settextstyle(48, 24, _T("Courier"));
	outtextxy(370, 10, lo);
	putall();
}
void win() {
	TCHAR wi[] = _T("WIN!!!");
	settextcolor(RED);
	settextstyle(48, 24, _T("Courier"));
	outtextxy(450, 10, wi);
}
void init_game() {
	close = bombnum_length*bombnum_width;
	leftbomb = allbomb;
	setfillcolor(RGB(173, 216, 230));
	setlinecolor(BLACK);
	settextstyle(48, 24, _T("Courier"));
	settextcolor(BLACK);
	TCHAR s[] = _T("leftbomb");
	outtextxy(num.left - 20, num.top - 60, s);
	int x = bpx, y = bpy;
	int xi = onebomb_length, yi = onebomb_width;
	for (int i = 0; i < bombnum_length; i++) {
		for (int j = 0; j < bombnum_width; j++) {
			fillrectangle(x + xi * i, y + yi * j, x + (i + 1) * xi, y + (j + 1) * yi);
			bomb[i + 1][j + 1].get(x + xi * i, y + yi * j, x + (i + 1) * xi, y + (j + 1) * yi);
		}
	}
	setbomb();
}