#pragma once
#include <winbgim.h>
#include "Define.h"
void DrawBar(int x1, int y1, int x2, int y2,int Mau)// ve hinh chu nhat dac
{
	setfillstyle(SOLID_FILL,Mau);
	bar(x1,y1,x2,y2);
	rectangle(x1,y1,x2,y2);
	
}
void NutQuaylai(int x1,int y1,int x2,int y2)
{
	DrawBar(x1,y1,x2,y2,MauXam); // Dau quay lai
	setbkcolor(MauXam);
	settextstyle(3,0,2);
	outtextxy(x1+10,y1+5,"<-");
}

void DrawRectangle(int x1, int y1, int x2, int y2,int Mau)// ve hinh chu nhat rong 
{
	setcolor(Mau);
	rectangle(x1,y1,x2,y2);
}
void Taobang2(int x1,int y1,int x2,int y2)
{
	int y;
	for (int y=y1;y<625;y=y+30) 
	{

		DrawBar(x1,y,x2,y+30,MauTrang);
		DrawBar(x2,y,x2+270,y+30,MauTrang);
		DrawBar(x2+270,y,x2+550,y+30,MauTrang);
		DrawBar(x2+550,y,x2+750,y+30,MauTrang);
		DrawBar(x2+750,y,x2+900,y+30,MauTrang);
		DrawBar(x2+900,y,x2+1050,y+30,MauTrang);
		DrawBar(x2+1050,y,x2+1200,y+30,MauTrang);
	}	
	setbkcolor(MauTrang);
	setcolor(MauDen);
	settextstyle(3,0,2);
	outtextxy(x1+20,y1+2,"STT");
	outtextxy(x2+20,y1+2,"Ma mon hoc");
	outtextxy(x2+290,y1+2,"Nien khoa");
	outtextxy(x2+570,y1+2,"Hoc Ky");
	outtextxy(x2+770,y1+2,"Nhom");
	outtextxy(x2+920,y1+2,"So SV max");
	outtextxy(x2+1070,y1+2,"So SV min");
}
void Taobang3(int x1,int y1,int x2,int y2)
{
	int y;
	for (int y=y1;y<625;y=y+30) 
	{
//		setbkcolor(MauTrang);(40,300,120,330
//		setcolor(MauDen);
//		settextstyle(3,0,3);
//		outtextxy(520,255,"Them");
		DrawBar(x1,y,x2,y+30,MauTrang);
		DrawBar(x2,y,x2+230,y+30,MauTrang);
		DrawBar(x2+230,y,x2+450,y+30,MauTrang);
		DrawBar(x2+450,y,x2+660,y+30,MauTrang);
		DrawBar(x2+660,y,x2+900,y+30,MauTrang);
		DrawBar(x2+900,y,x2+1080,y+30,MauTrang);
		DrawBar(x2+1080,y,x2+1200,y+30,MauTrang);
	}	
	setbkcolor(MauTrang);
	setcolor(MauDen);
	settextstyle(3,0,2);
	outtextxy(x1+20,y1+2,"STT");
	outtextxy(x2+50,y1+2,"HO");
	outtextxy(x2+300,y1+2,"TEN");
	outtextxy(x2+470,y1+2,"MA SINH VIEN");
	outtextxy(x2+720,y1+2,"MA LOP");
	outtextxy(x2+920,y1+2,"SO DIEN THOAI");
	outtextxy(x2+1090,y1+2,"PHAI");
}
void Taobang_Diem(int x1,int y1,int x2,int y2)
{
	int y;
	for (int y=y1;y<625;y=y+30) 
	{
		DrawBar(x1,y,x2,y+30,MauTrang);//stt
		DrawBar(x2,y,x2+350,y+30,MauTrang);//ho
		DrawBar(x2+350,y,x2+700,y+30,MauTrang);//ten
		DrawBar(x2+700,y,x2+1050,y+30,MauTrang);//ma sv
		DrawBar(x2+1050,y,x2+1200,y+30,MauTrang);// ma lop

	}	
	setbkcolor(MauTrang);
	setcolor(MauDen);
	settextstyle(3,0,2);
	outtextxy(x1+20,y1+2,"STT");
	outtextxy(x2+150,y1+2,"HO");
	outtextxy(x2+450,y1+2,"TEN");
	outtextxy(x2+800,y1+2,"MA SINH VIEN");
	outtextxy(x2+1100,y1+2,"DIEM");
//	outtextxy(x2+920,y1+2,"SO DIEN THOAI");
//	outtextxy(x2+1080,y1+2,"PHAI");
}
void Taobang1(int x1,int y1,int x2,int y2)
{
		int y;
	for (int y=y1;y<625;y=y+30) 
	{
		DrawBar(x1,y,x2,y+30,MauTrang);
		DrawBar(x2,y,x2+300,y+30,MauTrang);
		DrawBar(x2+300,y,x2+700,y+30,MauTrang);
		DrawBar(x2+700,y,x2+950,y+30,MauTrang);
		DrawBar(x2+950,y,x2+1200,y+30,MauTrang);

	}	
		setbkcolor(MauTrang);
		setcolor(MauDen);
		settextstyle(3,0,2);
		outtextxy(x1+20,y1+2,"STT");
		outtextxy(x2+20,y1+2,"Ma mon hoc");
		outtextxy(x2+320,y1+2,"Ten mon hoc");
		outtextxy(x2+720,y1+2,"So tin chi LT");
		outtextxy(x2+970,y1+2,"So tin chi TH");
}
