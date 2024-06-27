#include<iostream>
#include"easyx.h"
#include<conio.h>
#include"bomb.h"
void showbomb(Bomb num,int leftbomb) {
	setfillcolor(WHITE);
	solidrectangle(num.left, num.top, num.right, num.bottom);
	int x = (num.left + num.right) / 2;
	int y = (num.top + num.bottom) / 2;
	settextcolor(BLACK);
	settextstyle(48, 24, _T("Courier"));
	TCHAR number[5] = { 0 };
	_stprintf_s(number, _T("%d"), leftbomb);
	outtextxy(x, y, number);
}
void showend(Bomb retry) {
	setfillcolor(WHITE);
	solidrectangle(retry.left, retry.top, retry.right, retry.bottom);
	int x = (retry.left + retry.right) / 2;
	int y = (retry.top + retry.bottom) / 2;
	settextcolor(BLACK);
	settextstyle(48, 24, _T("Courier"));
	TCHAR re[] = _T("press 'R' to retry");
	outtextxy(x, y, re);
}