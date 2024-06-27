#pragma once
#include<iostream>
#include"easyx.h"
#include<conio.h>
#define EASY 10
#define NORMAL 20
#define DIFFICULT 58
class Bomb {
public:
	int left = 0;
	int top = 0;
	int right = 0;
	int bottom = 0;
	int exp = 0;
	int open = 0;
	int flag = 0;
	Bomb() {};
	Bomb(int, int, int, int);
	~Bomb() {};
	bool have();
	void get(int, int, int, int);
	void set(int);
	bool setflag();
};
void showbomb(Bomb, int);   			//右边显示剩余雷数
void showend(Bomb);				//游戏结束显示
bool init_bomb(int);				//初始化游戏难度
void init_game();				//游戏初始化
void init_g();					//界面初始化
void re_g();					//重开
void win();					//胜利
void lose();					//失败
void putall();					//失败后显示全图
void setbomb();					//随机放雷	
int countbomb(int, int);			//数周围的雷
bool getbomb(int, int, int&, int&);		//判读鼠标按的哪个格子
void leftclick_bomb(int, int);			//左键点击事件	
void openzero(int,int);				//自动开零周围的格子
void checkaround(int, int);
