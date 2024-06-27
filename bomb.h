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
void showbomb(Bomb, int);
void showend(Bomb);
bool init_bomb(int);
void init_game();
void init_g();
void re_g();
void win();
void lose();
void putall();
void setbomb();
int countbomb(int, int);
bool getbomb(int, int, int&, int&);
void leftclick_bomb(int, int);
void openzero(int,int);
void checkaround(int, int);