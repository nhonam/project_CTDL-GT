#pragma once
#include <winbgim.h>
#include "Define.h"
#include "VeHinh.h"
#include "SetIDvung.h"
#include "ToolBar.h"
#include"DanhSachSinhVien.h"
#include"DanhSachMonHoc.h"
#include"HieuUng.h"
void Window1() // DANH SACH MON HOC
{

	DrawRectangle(10,50,1380,680,MauDen); // Khung Window1
	DrawBar(10,50,1380,680,MauXamNhat); // to Khung Window1

	setbkcolor(MauXamNhat);
	setcolor(MauDo);
	settextstyle(4,0,4);
	outtextxy(450,70,"DANH SACH MON HOC");
	//nhap mon hoc
	setbkcolor(MauXamNhat);
	setcolor(MauDen);
	settextstyle(3,0,3);
	outtextxy(100,150,"Ma Mon Hoc : ");
	outtextxy(100,200,"Ten Mon Hoc : ");
	outtextxy(750,150,"So Tin Chi Ly Thuyet : ");
	outtextxy(750,200,"So Tin Chi Thuc Hanh : ");
	
	DrawBar(300,145,600,185,MauTrang);	//ma mon hoc
	DrawBar(300,195,600,235,MauTrang);	//ten mon hoc
	DrawBar(1000,145,1300,185,MauTrang); //STCLT
	DrawBar(1000,195,1300,235,MauTrang); //STCTH
	DrawBar(500,250,830,290,MauTrang);// them, sua va xoa
	DrawBar(830,250,950,290,MauTrang);// xuat danh sach 
	DrawBar(430,250,500,290,MauTrang);//luu
	DrawRectangle(500,250,610,290,MauDen);
	DrawRectangle(610,250,720,290,MauDen);
	DrawRectangle(720,250,830,290,MauDen);
	DrawBar(300,250,430,290,MauTrang);//ds tmp
	DrawRectangle(300,250,430,290,MauDen);// ds tmp

	setbkcolor(MauTrang);
	setcolor(MauDen);
	settextstyle(3,0,3);
	outtextxy(305,255,"XUAT ABC");
	outtextxy(435,255,"LUU");
	outtextxy(835,255,"XUAT DS") ;
	outtextxy(520,255,"THEM");
	outtextxy(630,255,"SUA");
	outtextxy(740,255,"XOA");	

	Taobang1(40,300,120,330); // id=66
	//Xuat1sv(40,330,120,360);// xuat them them them test
	DrawBar(350,635,500,675,MauXam);
	DrawBar(800,635,950,675,MauXam);
	setbkcolor(MauXam);
	setcolor(MauDen);
	settextstyle(3,0,3);
	outtextxy(400,640,"PREV");
	outtextxy(850,640,"NEXT");
	NutQuaylai(1330,50,1380,90);
}
void Thao_tac_DSTmp(int **mapID, Tree_MON_HOC Root, DS_MonHoc_Tmp &dstmp)
{
	int x=-1, y=-1;
	taoTextInput(350,635,500,675,0,mapID) ;//prev
		taoTextInput(800,635,950,675,0,mapID) ;//next
		reset_MapID_table(mapID);
		taoTextInput(300,195,600,235,0,mapID) ;//ten mon hoc
		taoTextInput(1000,145,1300,185,0,mapID);//stclt
		taoTextInput(1000,195,1300,235,0,mapID);//STCTH
		taoTextInput(300,145,600,185,0,mapID);//ma mon hoc 
		taoTextInput(1330,50,1380,90,0,mapID); // return
		taoTextInput(430,250,500,290,0,mapID); // LUU
		taoTextInput(830,250,950,290,0,mapID); // XUAT DS
		taoTextInput(500,250,610,290,0,mapID);//them
		taoTextInput(610,250,720,290,0,mapID);//sua 
		taoTextInput(720,250,830,290,0,mapID);// xoa 
		taoTextInput(300,250,430,290,0,mapID);// xuat ds abc
	taoTextInput(300,250,430,290,0,mapID);
//	Window1();
	taoTextInput(300,250,430,290,1,mapID);// xuat ds abc
	taoTextInput(1330,50,1380,90,2,mapID); // return
		taoTextInput(350,635,500,675,13,mapID) ;//prev
		taoTextInput(800,635,950,675,12,mapID) ;//next
	DoVaoMang(Root,dstmp);
	
	int trangso=1;
	while(true){
		
		//Bat chuot
		int id=0;
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			id = mapID[y][x];
			clearmouseclick(WM_LBUTTONDOWN);
		}
		
		switch(id){
			case 1:
				
				xuattmp(dstmp,trangso);
				STT(40,330,trangso);
				break;
			case 13://prev
				if(trangso!=1)
				{
					trangso--;
		
					Window1();
					setbkcolor(MauTrang);
					xuattmp(dstmp,trangso);
					STT(40,330,trangso);
					id=0;
					break;
				}
				break;
			case 12://next
				trangso++;
				Window1();
				setbkcolor(MauTrang);
				xuattmp(dstmp,trangso);
				STT(40,330,trangso);
			    id=0;
			    break;
				
		
			case 2:
				WindowMain();
				clearlist(dstmp);
				setIDvung(10,10,200,50,1,mapID); // Danh sach mon hoc
				setIDvung(210,10,410,50,2,mapID); // Danh sach lop tin chi
				setIDvung(410,10,610,50,3,mapID); // Danh sach sinh vien
				setIDvung(610,10,810,50,4,mapID); // Dang ky lop tin chi
				setIDvung(1330,10,1380,81,5,mapID); // Dau X
				return;
		}
		
		delay(0.001);
	}
}
void Thaotac_Window1(int **mapID,Tree_MON_HOC &Root,DS_MonHoc_Tmp &dstmp){
	int x=-1,y=-1; 

	char STCLT1[5];
	char STCTH1[5];
	int trangso=1;
	char temp[10];
	//ve man hinh 
	MON_HOC MH;
		taoTextInput(350,635,500,675,12,mapID) ;//prev
		taoTextInput(800,635,950,675,13,mapID) ;//next
		Set_MapID_table(mapID);
		taoTextInput(300,195,600,235,21,mapID) ;//ten mon hoc
		taoTextInput(1000,145,1300,185,31,mapID);//stclt
		taoTextInput(1000,195,1300,235,41,mapID);//STCTH
		taoTextInput(300,145,600,185,11,mapID);//ma mon hoc 
		taoTextInput(1330,50,1380,90,61,mapID); // return
		taoTextInput(430,250,500,290,71,mapID); // LUU
		taoTextInput(830,250,950,290,81,mapID); // XUAT DS
		taoTextInput(500,250,610,290,91,mapID);//them
		taoTextInput(610,250,720,290,101,mapID);//sua 
		taoTextInput(720,250,830,290,111,mapID);// xoa 
		taoTextInput(300,250,430,290,112,mapID);// xuat ds abc
		
		
		delay(0.001); 
	while(true) {
	
		
		//bat chuot
		int id=0;
		if(ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN,x,y);
			id= mapID[y][x];  
			clearmouseclick(WM_LBUTTONDOWN);
		}
		char s[10]="";
		switch(id) {
			case 112 :
				Thao_tac_DSTmp(mapID,Root,dstmp);
				return;
			case 11: 
				fflush(stdin);
			
				DrawBar(300,145,600,185,MauTrang);
				strcpy(MH.MAMH,"");
				Nhap(302,147,MH.MAMH) ;	 
				if(search_11(Root,MH.MAMH)!=NULL)
				{
					ThongBao(500,200,900,400,MauTrang,550,220,"Mon hoc nay da co !");
					sleep(3);
					Window1();
					fflush(stdin);
					strcpy(MH.MAMH,"");
					Nhap(302,147,MH.MAMH) ;	 
				}
				break;
			case 21: 
		
				
				DrawBar(300,195,600,235,MauTrang);
				fflush(stdin);
				strcpy(MH.TENMH,"");
				Nhap(302,197,MH.TENMH) ;
			
				break;
			case 31:
				fflush(stdin);
				DrawBar(1000,145,1300,185,MauTrang);
				strcpy(STCLT1,"");
				Nhap_SO(1002,147,STCLT1) ;
				MH.STCLT=atoi(STCLT1);
				break;
			case 41:
				fflush(stdin);
				DrawBar(1000,195,1300,235,MauTrang);
				strcpy(STCTH1,"");
				Nhap_SO(1002,197,STCTH1) ;
				MH.STCTH=atoi(STCTH1);
				break;
			case 61 :
				WindowMain();
					setIDvung(10,10,200,50,1,mapID); // Danh sach mon hoc
					setIDvung(210,10,410,50,2,mapID); // Danh sach lop tin chi
					setIDvung(410,10,610,50,3,mapID); // Danh sach sinh vien
					setIDvung(610,10,810,50,4,mapID); // Dang ky lop tin chi
					setIDvung(1330,10,1380,81,5,mapID); // Dau X
			//	 resetMapID(mapID);
				return;
			case 71: //luu
				ThongBao(500,200,900,400,MauTrang,550,220,"Ban co muon luu vo file ");
				Thaotac_Thongbao1(mapID,Root);
			//	WriteFile(l);//luu vo file 
				break;
			case 81: //xuat ds
				LNR(Root,trangso);
			//	testLNR(Root);
				STT(42,332,trangso);
//				coppy_MonHoc(Root,tmp);
//				LNR1(tmp);
				break;
			case 91 : // them
			
				Add_MonHoc(Root,MH);
				Window1();
			//		testLNR(Root);		
			//	LNR(Root,trangso);		
				break;
			case 101 :// sua
					deleteNode(Root,MH.TENMH);
				//	coppy_MonHoc(Root,tmp);
				break;
			case 111 :// xoa
				ThongBao(500,200,900,400,MauTrang,550,220,"Ban co chan muon xoa!!!");
				Thaotac_Xoa1(mapID,Root,MH);
				break;
			case 12://prev
				if(trangso!=1)
				{
					trangso--;
					Window1();
					LNR(Root,trangso);	
					STT(42,332,trangso);
					id=0;
					break;
				}
				break;
			case 13://next
				trangso++;
				Window1();
				LNR(Root,trangso);
				STT(42,332,trangso);
			    id=0;
			    break;
		}
		
		if(id>=1&&id<=10)
		 	{
		 		
		// tao lai o mau trang de khi nhap k bi de chu len nhau
			 	DrawBar(300,195,600,235,MauTrang);
				DrawBar(1000,145,1300,185,MauTrang);
				DrawBar(1000,195,1300,235,MauTrang);
				DrawBar(300,145,600,185,MauTrang);
				
				
		 		Tim_MonHoc_table(Root,(trangso-1)*10+id+1,MH);
		 		
		 		// in ra thong tin mon hoc khi click vo bang
		 		outtextxy(302,147,MH.MAMH);
		 		outtextxy(302,197,MH.TENMH);
		 		
		 	
    			itoa(MH.STCLT,temp,10);
		 		outtextxy(1102,147,temp);
		 		
		 		
    			itoa(MH.STCTH,temp,10);
		 		outtextxy(1102,197,temp);
		 		
		 		
		 		//break;
			 }
		delay(0.001); 
	}
}

