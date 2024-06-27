#include<iostream>
#include"easyx.h"
#include<conio.h>
#include"bomb.h"
extern int close, allbomb, leftbomb, end;
extern int bombnum_length, bombnum_width;
extern int onebomb_length, onebomb_width;
extern int bpx, bpy;
extern Bomb bomb[100][100];
extern Bomb num, retry;
void putall() {
	setfillcolor(RED);
	setlinecolor(BLACK);
	settextstyle(30, 15, _T("Courier"));
	for (int i = 1; i < 1 + bombnum_length; i++) {
		for (int j = 1; j < 1 + bombnum_width; j++) {
			if (bomb[i][j].exp) {
				fillrectangle(bomb[i][j].left, bomb[i][j].top, bomb[i][j].right, bomb[i][j].bottom);
			}
			else {
				int s = countbomb(i, j);
				outtextxy((bomb[i][j].left + bomb[i][j].right) / 2, (bomb[i][j].top + bomb[i][j].bottom) / 2, s + 48);
			}
		}
	}
}
int countbomb(int x, int y) {
	int sum = 0;
	for (int i = x - 1; i < x + 2; i++) {
		for (int j = y - 1; j < y + 2; j++) {
			if (bomb[i][j].exp)sum++;
		}
	}
	return sum;
}
bool getbomb(int xi, int yi, int& x, int& y) {
	if (xi < bpx || xi>bpx + onebomb_length * bombnum_length || yi < bpy || yi>bpy + onebomb_width * bombnum_width)return false;
	for (int i = 1; i < 1 + bombnum_length; i++) {
		for (int j = 1; j < 1 + bombnum_width; j++) {
			if (bomb[i][j].left < xi && bomb[i][j].right > xi) {
				if (bomb[i][j].top<yi && bomb[i][j].bottom>yi) {
					x = i;
					y = j;
					return true;
				}
			}
		}
	}
	return false;
}
void leftclick_bomb(int x, int y) {
	if (x < 1 || x>bombnum_length || y < 1 || y>bombnum_width)return;
	if (bomb[x][y].exp) {
		lose();
		end = 1;
		return;
	}
	if (bomb[x][y].open) {
		checkaround(x, y);
		return;
	}
	bomb[x][y].open = 1;
	close--;
	int s = countbomb(x, y);
	setfillcolor(WHITE);
	setlinecolor(BLACK);
	fillrectangle(bomb[x][y].left, bomb[x][y].top, bomb[x][y].right, bomb[x][y].bottom);
	if (s) {
		settextcolor(BLACK);
		settextstyle(30, 15, _T("Courier"));
		outtextxy((bomb[x][y].left + bomb[x][y].right)/2, (bomb[x][y].top + bomb[x][y].bottom)/2, s + 48);
	}
	else {
		openzero(x, y);
	}
}
void setbomb() {
	srand((unsigned)time(NULL));
	int n = 0;
	int i = 1, j = 1;
	while (n < allbomb) {
		i = (i + rand() + 1) % bombnum_length + 1;
		j = (j + rand() + 1) % bombnum_width + 1;
		if (bomb[i][j].exp)continue;
		bomb[i][j].exp = 1;
		n++;
	}
}
void openzero(int x, int y) {
	if (x < 1 || x>bombnum_length || y < 1 || y>bombnum_width)return;
	for (int i = x - 1; i < x + 2; i++) {
		for (int j = y - 1; j < y + 2; j++) {
			if (i == x && j == y)continue;
			leftclick_bomb(i, j);
		}
	}
}
void checkaround(int x, int y) {
	int sb = countbomb(x, y);
	int sf = 0;
	for (int i = x - 1; i < x + 2; i++) {
		for (int j = y - 1; j < y + 2; j++) {
			if (bomb[i][j].flag)sf++;
		}
	}
	if (sb == sf) {
		for (int i = x - 1; i < x + 2; i++) {
			for (int j = y - 1; j < y + 2; j++) {
				if (!bomb[i][j].open && !bomb[i][j].flag) {
					leftclick_bomb(i, j);
				}
			}
		}
	}
	return;
}