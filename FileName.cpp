#include<iostream>
#include"easyx.h"
#include<conio.h>
#include"bomb.h"
extern int close,allbomb,leftbomb,end;
extern int bombnum_length, bombnum_width;
extern Bomb bomb[100][100];
extern Bomb num, retry;
int main() {
	int di = 0;
	std::cout << "输入数字选择难度：1,简单  2，中等  3，困难 " << std::endl;
	std::cin >> di;
	if (!init_bomb(di)) {
		system("pause");
		return 0;
	}
	init_g();
	init_game();
	showbomb(num,leftbomb);
	ExMessage m;
	while (1) {
		m = getmessage(EX_MOUSE | EX_KEY);
		switch (m.message) {
		case WM_KEYDOWN:
			if (m.vkcode == 0x52) {
				end = 0;
				re_g();
				init_game();
				showbomb(num, leftbomb);
			}
			if (m.vkcode == VK_ESCAPE) {
				closegraph();
				return 0;
			}
		}
		if (m.lbutton) {
			int xi, yi;
			if (getbomb(m.x, m.y, xi, yi)) {
				if (bomb[xi][yi].flag)continue;
				leftclick_bomb(xi, yi);
				if (close == allbomb) {
					win();
					end = 1;
				}
			}
			while (m.lbutton) {
				m = getmessage(EX_MOUSE | EX_KEY);
			}
		}
		else if (m.rbutton) {
			int xi, yi;
			if (getbomb(m.x, m.y, xi, yi)) {
				if (!bomb[xi][yi].open) {
					if (bomb[xi][yi].setflag()) {
						leftbomb--;
					}
					else leftbomb++;
				}
				showbomb(num, leftbomb);
			}
			while (m.rbutton) {
				m = getmessage(EX_MOUSE | EX_KEY);
			}
		}
		else if (end) {
			showend(retry);
			m = getmessage(EX_KEY);
			if (m.vkcode == 0x52) {
				end = 0;
				re_g();
				init_game();
				showbomb(num, leftbomb);
			}
			if (m.vkcode == VK_ESCAPE) {
				break;
			}
		}
	}
	closegraph();
	return 0;
}