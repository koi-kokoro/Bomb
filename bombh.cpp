#include<iostream>
#include"easyx.h"
#include<conio.h>
#include"bomb.h"
extern int close, allbomb, leftbomb, end;
extern int bombnum_length, bombnum_width;
extern Bomb bomb[100][100];
extern Bomb num, retry;
Bomb::Bomb(int le, int to, int ri, int bo) {
	left = le;
	top = to;
	right = ri;
	bottom = bo;
}
bool Bomb::have() {
	return exp;
}
void Bomb::get(int le, int to, int ri, int bo) {
	left = le;
	top = to;
	right = ri;
	bottom = bo;
	exp = 0;
	flag = 0;
	open = 0;
}
void Bomb::set(int a) {
	exp = a & 1;
}
bool Bomb::setflag() {
	if (this->flag) {
		this->flag = 0;
		setfillcolor(RGB(173, 216, 230));
		fillrectangle(this->left, this->top, this->right, this->bottom);
		return false;
	}
	else {
		setfillcolor(GREEN);
		this->flag = 1;
		int x = (this->left + this->right) / 2;
		int y = (this->top + this->bottom) / 2;
		solidcircle(x, y, 20);
		return true;
	}
	return true;
}