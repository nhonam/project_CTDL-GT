#pragma once
#include <winbgim.h>
#include "Define.h"
#include "VeHinh.h"
#include "SetIDvung.h"
#include "ToolBar.h"

void WindowMain() // MAN HINH CHINH 
{
	DrawRectangle(10,50,1380,680,MauDen); // Khung WindowMain
	DrawBar(10,50,1380,680,MauXamNhat); // to Khung WindowMain
	setbkcolor(MauXamNhat);
	setcolor(MauDo);
	settextstyle(6,0,4);
	outtextxy(200,200,"QUAN LY DIEM SINH VIEN THEO HE TIN CHI");
	
	setbkcolor(MauXamNhat);
	setcolor(MauDo);
	settextstyle(4,0,1);
	outtextxy(950,400,"Tac Gia");
	outtextxy(900,450,"Dinh Nho Nam - N19DCCN113");
	outtextxy(900,500,"Bui Trong Anh - N19DCCN004");
	outtextxy(900,550,"Pham Van Khanh - N19DCCN090");
	DrawBar(850,410,930,415,MauDo); 
	DrawBar(1070,410,1350,415,MauDo); 
	DrawBar(850,600,1350,605,MauDo);

}
void DangNhap1()
{
	DrawRectangle(10,50,1380,680,MauDen); // Khung WindowMain
	DrawBar(10,50,1380,680,MauXamNhat); // to Khung WindowMain
	setbkcolor(MauXamNhat);
	setcolor(MauDo);
	settextstyle(6,0,4);
	outtextxy(450,200,"DANH SACH SINH VIEN");
	NutQuaylai(1330,50,1380,90);
	DrawBar(550,400,950,450,MauTrang); // Ma Lop
	DrawBar(650,500,800,550,MauXam);	// Dong y
	setbkcolor(MauXamNhat);
	setcolor(MauDen);
	settextstyle(4,0,3);
	outtextxy(400,410,"Ma Lop: ");
	setbkcolor(MauXam);
	outtextxy(660,510,"Dong Y");

}
void DangNhap2()
{
	DrawRectangle(10,50,1380,680,MauDen); // Khung WindowMain
	DrawBar(10,50,1380,680,MauXamNhat); // to Khung WindowMain
	setbkcolor(MauXamNhat);
	setcolor(MauDo);
	settextstyle(6,0,4);
	outtextxy(500,200,"DANG KY LOP TIN CHI");
	NutQuaylai(1330,50,1380,90);
	DrawBar(600,400,1000,450,MauTrang); // ten dang nhap
	DrawBar(600,470,1000,520,MauTrang); // mat khau
	DrawBar(650,550,870,600,MauXam);	// dang nhap
	setbkcolor(MauXamNhat);
	setcolor(MauDen);
	settextstyle(4,0,3);
	outtextxy(320,410,"Ten dang nhap: ");
	outtextxy(320,480,"Mat Khau: ");
	setbkcolor(MauXam);
	outtextxy(670,560,"Dang Nhap");

}
