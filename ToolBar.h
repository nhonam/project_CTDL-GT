#pragma once
#include <winbgim.h>
#include "Define.h"
#include "VeHinh.h"
#include "SetIDvung.h"
void ToolBar()
{
	DrawRectangle(10,10,1380,680,MauDen); // Khung to
	DrawRectangle(10,10,1380,50,MauDen); // Khung dong dau
	DrawBar(10,10,210,50,MauXam); // Danh sach mon hoc
	DrawBar(210,10,410,50,MauXam); // Danh sach lop tin chi
	DrawBar(410,10,610,50,MauXam); // Danh sach sinh vien
	DrawBar(610,10,810,50,MauXam); // Dang ky lop tin chi
	DrawBar(1330,10,1380,50,MauXam); // Dau X
	DrawBar(810,10,1010,50,MauXam); // diem
	setbkcolor(MauXam);
	settextstyle(3,0,2);
	outtextxy(20,15,"Danh sach mon hoc");
	outtextxy(220,15,"Danh sach lop tin chi");
	outtextxy(420,15,"Danh sach sinh vien");
	outtextxy(620,15,"Dang ky lop tin chi");
	outtextxy(1345,15,"X");
	outtextxy(820,15,"Diem");
//	setIDvung(10,10,200,50,1); // Danh sach mon hoc
//	setIDvung(210,10,410,50,2); // Danh sach lop tin chi
//	setIDvung(410,10,610,50,3); // Danh sach sinh vien
//	setIDvung(610,10,810,50,4); // Dang ky lop tin chi
//	setIDvung(1330,10,1380,50,5); // Dau X
}
