#include <winbgim.h>
using namespace std;
#include <iostream>

#include "Define.h"
#include "SetIDvung.h"
#include "VeHinh.h"
#include "ToolBar.h"
#include "WindowMain.h"
#include "Window1.h"
#include "Window2.h"
#include "Window3.h"
#include "Window4.h"
#include "HieuUng.h"
#include "DanhSachMonHoc.h"
#include "DanhSachSinhVien.h"
#include "DanhSachLopTinChi.h"
#include "DanhSachMonHoc.h"
//itoa chuyen int sang char
//atoi chuyen char sang int
// ten mon hoc =Del All xoa toan bo mon hoc
// nien khoa  = Del All xoa toan bo lop tin chi
int main(int argc, char *argv[])
{
	initwindow(1400, 700);          
    setbkcolor(MauXamNhat);                 
    cleardevice();
    
    
   int **mapID = new int*[2500];
   for(int i = 0; i<2500; i++)
   mapID[i] = new int[1000];
   resetMapID(mapID);
  	ToolBar();	
	WindowMain();
    

	char file3[50]="filedanhsachsv3.txt";// file sinh vien
	char file24[50]="DSLoptinchi24.txt";// file lop tin chi + sinh vien dang ki
	char file1[50]="monhoc.txt";// file mon hoc
	
	

	SINH_VIEN sv3;
   ds_sinh_vien l3;	// danh sach sinh vien 
	CreateDs_SV(l3);	
	
	SINH_VIEN4 sv4;
	LOP_TIN_CHI Ltc;

	DS_LOP_TIN_CHI l2;// danh sach lop tin chi 
	l2.n=0;
	
	DS_MonHoc_Tmp MonHoctmp;// ds mon hoc tam
	MonHoctmp.n=0;
	
	Tree_MON_HOC Root;// danh sach mon hoc
	Create_Tree(Root);
	
 	Read_File_Tree("monhoc.txt",Root);// doc gile vo cay
	ReadFile("filesanhsachsv3.txt",l3);
	
	Read_File_LTC("DSLoptinchi24.txt",l2);

	
	ChuyenMuc(mapID,sv3,l3,Ltc,l2,sv4,Root,MonHoctmp);

    while(!kbhit()) delay(1); 
  
    return 0;
}
