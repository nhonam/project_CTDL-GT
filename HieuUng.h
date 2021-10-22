#pragma once
#include "Window3.h"
#include <winbgim.h>
#include "Define.h"
#include "VeHinh.h"
#include "SetIDvung.h"
#include "ToolBar.h"
#include "WindowMain.h"
#include "Window1.h"
#include "Window2.h"
#include "Window3.h"
#include "Window4.h"
#include <unistd.h>
#include"DanhSachSinhVien.h"
#include<stdlib.h>
#include"diem.h"
void Thaotac_Window1(int **mapID,Tree_MON_HOC &Root,DS_MonHoc_Tmp &dstmp);
void Window1();
void ThongBao(int x1, int y1, int x2, int y2, int Mau,int vtchu1, int vtchu2, char *s)  { // s la noi dung thong bao , ve ra bang thong bao 
	DrawBar(x1, y1, x2, y2, Mau);//500,200,900,400 vi tri xy mac dinh 
	outtextxy(vtchu1,vtchu2,s);
	int a=x1,b=y2;
	DrawBar(a+370,y1,x2,b-170,MauDo);
	setbkcolor(MauDo);
	outtextxy(500+374,200+4,"X");
	DrawBar(575,340,575+50,390,MauXanhTroiNhat);// ve o yes
	setbkcolor(MauXanhTroiNhat);
	outtextxy(572+4,342+7,"YES");
	DrawBar(775,340,775+50,390,MauXanhTroiNhat);// ve o NO
	outtextxy(777+7,342+7,"NO");

}
void Window3();
void Thaotac_Window3(int **mapID,SINH_VIEN &sv,ds_sinh_vien &l); // trong window 3
void Thaotac_Xoa3(int **mapID,ds_sinh_vien &l,SINH_VIEN &sv){ // trong window3 , b
		int x=-1,y=-1; 
	//ve man hinh
		 Taoid(870,200,900,230,1,mapID);
		 Taoid(575,340,575+50,390,2,mapID);
		 Taoid(775,340,775+50,390,3,mapID);
		delay(0.001); 
	while(true) {
		//bat chuot
		int id=0; 
		if(ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN,x,y);
			id= mapID[y][x];  
			clearmouseclick(WM_LBUTTONDOWN);
		}
		switch(id) {
			case 1: 
				Window3();//dau x
				return;
			case 2:
				Window3();// yes
				xoa_SV(l,sv.MASV);
				id=22;
				return;// goi ham xoa sinh vien
			case 3:
				Window3();//no
				return;// khong lam gi ca
			
		}
		delay(0.001); 
	}
}
void Thaotac_Xoa2(int **mapID,ds_lop_tin_chi &dsltc,LOP_TIN_CHI &LTC){ // trong window3 , b
		int x=-1,y=-1; 
	//ve man hinh
		 Taoid(870,200,900,230,1,mapID);
		 Taoid(575,340,575+50,390,2,mapID);
		 Taoid(775,340,775+50,390,3,mapID);
		delay(0.001); 
	while(true) {
		//bat chuot
		int id=0; 
		if(ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN,x,y);
			id= mapID[y][x];  
			clearmouseclick(WM_LBUTTONDOWN);
		}
		switch(id) {
			case 1: 
				Window2();//dau x
				return;
			case 2:
				Window2();// yes
				if(Xoa1(dsltc,LTC)==1){
					setbkcolor(MauTrang);
					ThongBao(500,200,900,400,MauTrang,550,220,"Xoa k thanh cong! LTC da du SV");
					sleep(2);
					Window2();
					return;
				}
//				if(strcmp(LTC.NIEN_KHOA,"Del All")==0)
//				{
//					remove("DSLoptinchi24.txt");
//					Read_File_LTC("DSLoptinchi24.txt",dsltc);
//				}
//				else
				Xoa_LTC(dsltc,LTC);
				
				return;// goi ham xoa lop tc
			case 3:
				Window2();//no
				return;// khong lam gi ca
			
		}
		delay(0.001); 
	}
}
void Thaotac_Xoa1(int **mapID,Tree_MON_HOC &Root,MON_HOC mh){ // trong window3 , b
		int x=-1,y=-1; 
	//ve man hinh
		 Taoid(870,200,900,230,1,mapID);
		 Taoid(575,340,575+50,390,2,mapID);
		 Taoid(775,340,775+50,390,3,mapID);
		delay(0.001); 

	while(true) {
		//bat chuot
		int id=0; 
		if(ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN,x,y);
			id= mapID[y][x];  
			clearmouseclick(WM_LBUTTONDOWN);
		}
		switch(id) {
			case 1: 
				Window1();//dau x
				return;
			case 2:
				Window1();// yes
				if(strcmp(mh.TENMH,"Del All")==0)
				{
					remove("monhoc.txt");
					Read_File_Tree("monhoc.txt",Root);
					//return;
				}
				else
			
			//	XoaNode(Root,mh.MAMH);
				deleteNode(Root,mh.MAMH);
			//	coppy_MonHoc(Root,tmp);
				return;// goi ham xoa mon hoc
			case 3:
				Window1();//no
				return;// khong lam gi ca
			
		}
		delay(0.001); 
	}
}
void Thaotac_Thongbao1(int **mapID,Tree_MON_HOC &Root) { // trong window3 , b
		int x=-1,y=-1; 
	//ve man hinh
		 Taoid(870,200,900,230,1,mapID);
		 Taoid(575,340,575+50,390,2,mapID);
		 Taoid(775,340,775+50,390,3,mapID);
		delay(0.001); 
	while(true) {
		//bat chuot
		int id=0; 
		if(ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN,x,y);
			id= mapID[y][x];  
			clearmouseclick(WM_LBUTTONDOWN);
		}
		switch(id) {
			case 1: 
				Window1();//dau x
				return;
			case 2:
				Window1();// yes
				remove("monhoc.txt");
				vietMHvaofile(Root);
				return;// goi ham
			case 3:
				Window1();//no
				return;// khong lam gi ca
			
		}
		delay(0.001); 
	}
}
void Thaotac_Thongbao2(int **mapID,ds_lop_tin_chi &l2) { // trong window3 , b
		int x=-1,y=-1; 
	//ve man hinh
		 Taoid(870,200,900,230,1,mapID);
		 Taoid(575,340,575+50,390,2,mapID);
		 Taoid(775,340,775+50,390,3,mapID);
		delay(0.001); 
	while(true) {
		//bat chuot
		int id=0; 
		if(ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN,x,y);
			id= mapID[y][x];  
			clearmouseclick(WM_LBUTTONDOWN);
		}
		switch(id) {
			case 1: 
				Window2();//dau x
				return;
			case 2:
				Window2();// yes
				remove("DSLoptinchi24.txt");
			//	Write_File(l)
				vietLTCvaofile(l2);
				return;// goi ham
			case 3:
				Window2();//no
				return;// khong lam gi ca
			
		}
		delay(0.001); 
	}
}  

void Thaotac_WIN3(int **mapID,SINH_VIEN &sv,ds_sinh_vien &l) { // trong window3 , so 1
		int x=-1,y=-1; 
	//ve man hinh
		 Taoid(550,400,950,450,1,mapID);//ma lop
		 Taoid(650,500,800,550,2,mapID);// dong y
		  Taoid(1330,50,1380,90,3,mapID);// dau quay lai
		delay(0.001); 
	while(true) {
		//bat chuot
		int id=0; 
		if(ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN,x,y);
			id= mapID[y][x];  
			clearmouseclick(WM_LBUTTONDOWN);
		}
		switch(id) {
			case 1: 
			strcpy(sv.MALOP,"");
			setbkcolor(MauTrang);
				Nhap_INHOA(552,402,sv.MALOP);
				break;
			case 2:
				if(strcmp(sv.MALOP,"")==0)
				{
					settextstyle(1,0,1);
					ThongBao(500,200,900,400,MauTrang,550,220,"Sai thong tin!");
					sleep(3);
					DangNhap1();
					settextstyle(6,0,4);
					strcpy(sv.MALOP,"");
					setbkcolor(MauTrang);
					Nhap_INHOA(552,402,sv.MALOP);
				}
				else{
					Window3();
					Thaotac_Window3(mapID,sv,l);
					return;
				}
				
		
				
		}
		
		if(id==3)
		{
			WindowMain();
				return;
		}
		delay(0.001); 
	}
}
void Thaotac_WIN4(int **mapID,SINH_VIEN &sv, ds_sinh_vien &l,DS_LOP_TIN_CHI &l2, SINH_VIEN4 &sv4,Tree_MON_HOC &Root) { // trong window3 , so 1
		int x=-1,y=-1; 
	//ve man hinh
		 Taoid(600,400,1000,450,1,mapID);//ten dang nhap
		 Taoid(600,470,1000,520,2,mapID);// pass
		  Taoid(650,550,870,600,3,mapID);// dang nhap
		   Taoid(1330,50,1380,90,5,mapID);// quay lai
		
		delay(0.001); 
		SINH_VIEN svtmp;
		char tmp[10];
		
	while(true) {
		//bat chuot
		int id=0; 
		if(ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN,x,y);
			id= mapID[y][x];  
			clearmouseclick(WM_LBUTTONDOWN);
		}
		switch(id) {
			case 1: 
				strcpy(sv.MASV,"");
				setbkcolor(MauTrang);
				Nhap_INHOA(602,402,sv.MASV);
				break;
			case 2:
				
				strcmp(tmp,"");
				fflush(stdin);
				setbkcolor(MauTrang);
				Nhap_Pass(602,472,tmp);
				break;
			case 3:
				strcmp(svtmp.MASV,sv.MASV);
				SINH_VIEN sv1;
				strcmp(sv1.MASV,"");
				if(Search32(l,sv.MASV)==-1||strcmp(tmp,"123456")!=0)
				{
					setbkcolor(MauTrang);
					settextstyle(1,0,1);
					ThongBao(500,200,900,400,MauTrang,550,220,"Sai thong tin!");
					sleep(3);
					settextstyle(6,0,4);
					DangNhap2();
				}
				else{
					sv1=Search31(l,sv.MASV);	
					Window4();
					setbkcolor(MauTrang);
					outtextxy(402,147,sv.MASV);
					strcat(sv1.HO, " ");
					strcat(sv1.HO,sv1.TEN);
					outtextxy(122+50,237,sv1.HO);
					outtextxy(802+50,237,sv1.SDT);
					outtextxy(502+50,237,sv1.MALOP);
					outtextxy(1102+50,237,sv1.PHAI);
					Thaotac_Window4(mapID,sv,l,l2,sv4,Root);
				
				}
				return;
				};
				
			if(id==5){
				WindowMain();
		//		 resetMapID(mapID);
				return;
			}
		delay(0.001); 
			
		}
			
	
}

void ChuyenMuc(int **mapID,SINH_VIEN &sv, ds_sinh_vien &l,LOP_TIN_CHI &Ltc, DS_LOP_TIN_CHI &l2, SINH_VIEN4 &sv4,Tree_MON_HOC &Root,DS_MonHoc_Tmp &dstmp)
{	
	resetMapID(mapID);
	setIDvung(10,10,200,50,1,mapID); // Danh sach mon hoc
	setIDvung(210,10,410,50,2,mapID); // Danh sach lop tin chi
	setIDvung(410,10,610,50,3,mapID); // Danh sach sinh vien
	setIDvung(610,10,810,50,4,mapID); // Dang ky lop tin chi
	setIDvung(810,10,1010,50,6,mapID); // diem
	setIDvung(1330,10,1380,81,5,mapID); // Dau X

	int x,y;

    while (1)
	{	
    delay(0.0001);
 	if (ismouseclick(WM_LBUTTONDOWN))
	{
        getmouseclick(WM_LBUTTONDOWN, x, y);
        // nhan chuot phai
      
        if (mapID[x][y] == 1)
            {
             DrawBar(10,10,210,50,MauDo); // Danh sach mon hoc
            DrawRectangle(10,10,210,50,MauDen);
            setcolor(MauDen);
			setbkcolor(MauDo); 
			settextstyle(3,0,2);
			outtextxy(20,15,"Danh sach mon hoc");
			DrawBar(210,10,410,50,MauXam); // Danh sach lop tin chi
			DrawBar(410,10,610,50,MauXam); // Danh sach sinh vien
			DrawBar(610,10,810,50,MauXam); // Dang ky lop tin chi
			DrawBar(810,10,1010,50,MauXam); // diem
            setcolor(MauDen);
			setbkcolor(MauXam); 
			settextstyle(3,0,2);
			outtextxy(220,15,"Danh sach lop tin chi");
			outtextxy(420,15,"Danh sach sinh vien");
			outtextxy(620,15,"Dang ky lop tin chi");
			outtextxy(1345,15,"X");	
			outtextxy(870,15,"Diem");
            Window1();
            resetMapID(mapID);
            Thaotac_Window1(mapID,Root,dstmp);
            resetMapID(mapID);
      		setIDvung(10,10,200,50,1,mapID); // Danh sach mon hoc
			setIDvung(210,10,410,50,2,mapID); // Danh sach lop tin chi
			setIDvung(410,10,610,50,3,mapID); // Danh sach sinh vien
			setIDvung(610,10,810,50,4,mapID); // Dang ky lop tin chi
			setIDvung(810,10,1010,50,6,mapID); // diem
			setIDvung(1330,10,1380,81,5,mapID); // Dau X
		 
			}
		if (mapID[x][y] == 2)
		{
			DrawBar(210,10,410,50,MauDo); //Danh sach lop tin chi
        	setcolor(MauDen);
			setbkcolor(MauDo); 
			settextstyle(3,0,2);
			outtextxy(220,15,"Danh sach lop tin chi");
			DrawBar(10,10,210,50,MauXam); // Danh sach mon hoc
			DrawBar(410,10,610,50,MauXam); // Danh sach sinh vien
			DrawBar(610,10,810,50,MauXam); // Dang ky lop tin chi
			DrawBar(810,10,1010,50,MauXam); // diem
            setcolor(MauDen);
			setbkcolor(MauXam); 
			settextstyle(3,0,2);
			outtextxy(20,15,"Danh sach mon hoc");
			outtextxy(420,15,"Danh sach sinh vien");
			outtextxy(620,15,"Dang ky lop tin chi");
			outtextxy(1345,15,"X");
			outtextxy(870,15,"Diem");
			Window2();
			
         	resetMapID(mapID);
           Thaotac_Window2(mapID,Ltc,l2,Root);
            resetMapID(mapID);
      		setIDvung(10,10,200,50,1,mapID); // Danh sach mon hoc
			setIDvung(210,10,410,50,2,mapID); // Danh sach lop tin chi
			setIDvung(410,10,610,50,3,mapID); // Danh sach sinh vien
			setIDvung(610,10,810,50,4,mapID); // Dang ky lop tin chi
			setIDvung(810,10,1010,50,6,mapID); // diem
			setIDvung(1330,10,1380,81,5,mapID); // Dau X
			
		}
		if (mapID[x][y] == 3)
		{	 
			DrawBar(410,10,610,50,MauDo); // Danh sach sinh vien
        	setcolor(MauDen);
			setbkcolor(MauDo); 
			settextstyle(3,0,2);
			outtextxy(420,15,"Danh sach sinh vien");
			DrawBar(10,10,210,50,MauXam); // Danh sach mon hoc
			DrawBar(210,10,410,50,MauXam); // Danh sach lop tin chi
			DrawBar(610,10,810,50,MauXam); // Dang ky lop tin chi
			DrawBar(810,10,1010,50,MauXam); // diem
            setcolor(MauDen);
			setbkcolor(MauXam); 
			settextstyle(3,0,2);
			outtextxy(20,15,"Danh sach mon hoc");
			outtextxy(220,15,"Danh sach lop tin chi");
			outtextxy(620,15,"Dang ky lop tin chi");
			outtextxy(1345,15,"X");
			outtextxy(870,15,"Diem");
		//	Window3();
			DangNhap1();
			resetMapID(mapID);
			Thaotac_WIN3(mapID,sv,l);
			resetMapID(mapID);
      		setIDvung(10,10,200,50,1,mapID); // Danh sach mon hoc
			setIDvung(210,10,410,50,2,mapID); // Danh sach lop tin chi
			setIDvung(410,10,610,50,3,mapID); // Danh sach sinh vien
			setIDvung(610,10,810,50,4,mapID); // Dang ky lop tin chi
			setIDvung(810,10,1010,50,6,mapID); // diem
			setIDvung(1330,10,1380,81,5,mapID); // Dau X
			
		}
		if (mapID[x][y] == 4)
		{
			 {
			DrawBar(610,10,810,50,MauDo); // Dang ky lop tin chi
         	setcolor(MauDen);
			setbkcolor(MauDo); 
			settextstyle(3,0,2);
			outtextxy(620,15,"Dang ky lop tin chi");
			DrawBar(10,10,210,50,MauXam); // Danh sach mon hoc
			DrawBar(210,10,410,50,MauXam); // Danh sach lop tin chi
			DrawBar(410,10,610,50,MauXam); // Danh sach sinh vien
			DrawBar(810,10,1010,50,MauXam); // diem
            setcolor(MauDen);
			setbkcolor(MauXam); 
			settextstyle(3,0,2);
			outtextxy(20,15,"Danh sach mon hoc");
			outtextxy(220,15,"Danh sach lop tin chi");
			outtextxy(420,15,"Danh sach sinh vien");
			outtextxy(1345,15,"X");
			outtextxy(870,15,"Diem");
			// Window4();
			 DangNhap2();
				resetMapID(mapID);
			 Thaotac_WIN4(mapID,sv,l,l2,sv4,Root);
         	resetMapID(mapID);
      		setIDvung(10,10,200,50,1,mapID); // Danh sach mon hoc
			setIDvung(210,10,410,50,2,mapID); // Danh sach lop tin chi
			setIDvung(410,10,610,50,3,mapID); // Danh sach sinh vien
			setIDvung(610,10,810,50,4,mapID); // Dang ky lop tin chi
			setIDvung(810,10,1010,50,6,mapID); // diem
			setIDvung(1330,10,1380,81,5,mapID); // Dau X
			}
		
		}	
		if (mapID[x][y] == 5)
		{
			DrawBar(1330,10,1380,50,MauDo); // Dau X
         	setcolor(MauDen);
			setbkcolor(MauDo); 
			settextstyle(3,0,2);
			outtextxy(1345,15,"X");
			DrawBar(10,10,210,50,MauXam); // Danh sach mon hoc
			DrawBar(210,10,410,50,MauXam); // Danh sach lop tin chi
			DrawBar(410,10,610,50,MauXam); // Danh sach sinh vien
			DrawBar(610,10,810,50,MauXam); // Dang ky lop tin chi
			DrawBar(810,10,1010,50,MauXam); // diem
            setcolor(MauDen);
			setbkcolor(MauXam); 
			settextstyle(3,0,2);
			outtextxy(20,15,"Danh sach mon hoc");
			outtextxy(220,15,"Danh sach lop tin chi");
			outtextxy(420,15,"Danh sach sinh vien");
			outtextxy(620,15,"Dang ky lop tin chi");
			outtextxy(870,15,"Diem");
			exit(1);
		}
			if (mapID[x][y] == 6)
		{	 
			DrawBar(810,10,1010,50,MauDo); // diem
        	setcolor(MauDen);
			setbkcolor(MauDo); 
			settextstyle(3,0,2);
			outtextxy(870,15,"Diem");
			DrawBar(10,10,210,50,MauXam); // Danh sach mon hoc
			DrawBar(210,10,410,50,MauXam); // Danh sach lop tin chi
			DrawBar(410,10,610,50,MauXam); // Danh sach sinh vien
			DrawBar(610,10,810,50,MauXam); // Dang ky lop tin chi
            setcolor(MauDen);
			setbkcolor(MauXam); 
			settextstyle(3,0,2);
			outtextxy(420,15,"Danh sach sinh vien");
			outtextxy(20,15,"Danh sach mon hoc");
			outtextxy(220,15,"Danh sach lop tin chi");
			outtextxy(620,15,"Dang ky lop tin chi");
			outtextxy(1345,15,"X");
		//	Window3();
			Window_Diem();
			
		
		 	 resetMapID(mapID);
             Thaotac_Window_Diem(mapID,l2,l);
            resetMapID(mapID);
      		setIDvung(10,10,200,50,1,mapID); // Danh sach mon hoc
			setIDvung(210,10,410,50,2,mapID); // Danh sach lop tin chi
			setIDvung(410,10,610,50,3,mapID); // Danh sach sinh vien
			setIDvung(610,10,810,50,4,mapID); // Dang ky lop tin chi
			setIDvung(810,10,1010,50,6,mapID); // diem
			setIDvung(1330,10,1380,81,5,mapID); // Dau X
			
			
		}	
	}
	//*********************************************	
	
		if (ismouseclick(WM_MOUSEMOVE)) // di chuyen chuot
		{
			getmouseclick(WM_MOUSEMOVE, x, y);
			if (mapID[x][y] == 1) // danh sach mon hoc
			{
				
				DrawBar(10,10,210,50,MauDo); // Danh sach mon hoc
				DrawRectangle(10,10,210,50,MauDen);
			 	setcolor(MauDen);
				setbkcolor(MauDo); 
				settextstyle(3,0,2);
				outtextxy(20,15,"Danh sach mon hoc");
			}
				else
			{
				DrawBar(10,10,210,50,MauXam); // Danh sach mon hoc
				DrawRectangle(10,10,210,50,MauDen);
			 	setcolor(MauDen);
				setbkcolor(MauXam); 
				settextstyle(3,0,2);
				outtextxy(20,15,"Danh sach mon hoc");
			}
			if (mapID[x][y] == 2) // danh sach lop tin chi
			{
				
				DrawBar(210,10,410,50,MauDo); //Danh sach lop tin chi
         		setcolor(MauDen);
				setbkcolor(MauDo); 
				settextstyle(3,0,2);
				outtextxy(220,15,"Danh sach lop tin chi");
			}
				else
			{
				DrawBar(210,10,410,50,MauXam); //Danh sach lop tin chi
         		setcolor(MauDen);
				setbkcolor(MauXam); 
				settextstyle(3,0,2);
				outtextxy(220,15,"Danh sach lop tin chi");
			}
			if (mapID[x][y] == 3) // danh sach sinh vien
			{
				
				DrawBar(410,10,610,50,MauDo); // Danh sach sinh vien
        		setcolor(MauDen);
				setbkcolor(MauDo); 
				settextstyle(3,0,2);
				outtextxy(420,15,"Danh sach sinh vien");
			}
				else
			{
				DrawBar(410,10,610,50,MauXam); // Danh sach sinh vien
        		setcolor(MauDen);
				setbkcolor(MauXam); 
				settextstyle(3,0,2);
				outtextxy(420,15,"Danh sach sinh vien");
			}
				if (mapID[x][y] == 4)
			{
				DrawBar(610,10,810,50,MauDo); // Dang ky lop tin chi
        		setcolor(MauDen);
				setbkcolor(MauDo); 
				settextstyle(3,0,2);
				outtextxy(620,15,"Dang ky lop tin chi");
			}
				else
			{
				DrawBar(610,10,810,50,MauXam); // Dang ky lop tin chi
        		setcolor(MauDen);
				setbkcolor(MauXam); 
				settextstyle(3,0,2);
				outtextxy(620,15,"Dang ky lop tin chi");
			}
					if (mapID[x][y] == 5)
			{
				DrawBar(1330,10,1380,50,MauDo); // Dau X
         		setcolor(MauDen);
				setbkcolor(MauDo); 
				settextstyle(3,0,2);
				outtextxy(1345,15,"X");
			}
				else
			{
				DrawBar(1330,10,1380,50,MauXam); // Dau X
         		setcolor(MauDen);
				setbkcolor(MauXam); 
				settextstyle(3,0,2);
				outtextxy(1345,15,"X");
			}
			if (mapID[x][y] == 6)
			{
				DrawBar(810,10,1010,50,MauDo); // diem
         		setcolor(MauDen);
				setbkcolor(MauDo); 
				settextstyle(3,0,2);
				outtextxy(870,15,"Diem");
			}
				else
			{
				DrawBar(810,10,1010,50,MauXam); // diem
         		setcolor(MauDen);
				setbkcolor(MauXam); 
				settextstyle(3,0,2);
				outtextxy(870,15,"Diem");
			}
			
		}
	}
}


