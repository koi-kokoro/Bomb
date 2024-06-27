#include<iostream>
#include"easyx.h"
#include<conio.h>
#include"bomb.h"
extern int close,allbomb,leftbomb,end;
extern int bombnum_length, bombnum_width;
extern Bomb bomb[100][100];
extern Bomb num, retry;
int main() {
	//选择难度
	int di = 0;
	std::cout << "输入数字选择难度：1,简单  2，中等  3，困难 " << std::endl;
	std::cin >> di;
	if (!init_bomb(di)) {
		system("pause");
		return 0;
	}
	
	//初始化游戏
	init_g();
	init_game();
	showbomb(num,leftbomb);
	ExMessage m;
	
	//游戏主体
	while (1) {
		m = getmessage(EX_MOUSE | EX_KEY);
		switch (m.message) {

			//响应按键事件
		case WM_KEYDOWN:

			//按下R键重开
			if (m.vkcode == 0x52) {
				end = 0;
				re_g();
				init_game();
				showbomb(num, leftbomb);
			}

			//按下ESC键重开
			if (m.vkcode == VK_ESCAPE) {
				closegraph();
				return 0;
			}
		}

		//鼠标左键
		if (m.lbutton) {
			int xi, yi;
			if (getbomb(m.x, m.y, xi, yi)) {
				if (bomb[xi][yi].flag)continue;
				leftclick_bomb(xi, yi);

				//胜利条件
				if (close == allbomb) {
					win();
					end = 1;
				}
			}
			while (m.lbutton) {
				m = getmessage(EX_MOUSE | EX_KEY);
			}
		}

		//鼠标右键
		else if (m.rbutton) {
			int xi, yi;

			//插旗
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

		//游戏结束
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
