#pragma once
#include <winbgim.h>
#include "Define.h"
#include "VeHinh.h"
#include "SetIDvung.h"
#include "ToolBar.h"
#include"HieuUng.h"
#include"DanhSachSinhVien.h"
#include <unistd.h>
void Thaotac_WIN3(int **mapID,SINH_VIEN &sv,ds_sinh_vien &l,Tree_MON_HOC Root);//1
void Thaotac_Xoa3(int **mapID,ds_sinh_vien &l,SINH_VIEN &sv);//2
//void Thaotac_Thongbao3(int **mapID,ds_sinh_vien &l)//4
void ThongBao(int x1, int y1, int x2, int y2, int Mau,int vtchu1, int vtchu2, char *s);//3 (1,2,3 ,4 o trong file .h HieuUng.h)

void Window3() // DANH SACH SINH VIEN 
{
	
	DrawRectangle(10,50,1380,680,MauDen); // Khung Window2
	DrawBar(10,50,1380,680,MauXamNhat); // to Khung Window2

	setbkcolor(MauXamNhat);
	setcolor(MauDo);
	settextstyle(4,0,4);
	outtextxy(400,70,"DANH SACH SINH VIEN");
	setbkcolor(MauXamNhat);
	setcolor(MauDen);
	settextstyle(3,0,3);
	outtextxy(50,150,"Ho : ");
	outtextxy(50,200,"Ten : ");
	outtextxy(600,150,"Ma SV : ");
	//outtextxy(600,200,"Ma Lop : ");
	outtextxy(1000,150,"So DT : ");
	outtextxy(1000,200,"Phai : ");
	DrawBar(150,145,500,185,MauTrang);	//Ho

	DrawBar(150,195,500,235,MauTrang);	//Ten

	DrawBar(700,145,950,185,MauTrang); //ma sv

	DrawBar(1100,145,1350,185,MauTrang); //So dien thoai 

	DrawBar(1100,195,1350,235,MauTrang); //phai

	
	DrawBar(500,250,830,290,MauTrang);// them, sua va xoa
	DrawBar(830,250,950,290,MauTrang);// xuat danh sach 
	DrawBar(430,250,500,290,MauTrang);//luu
	DrawBar(610,210,750,250,MauTrang);//xuat diem
	DrawRectangle(830,250,950,290,MauDen);//xuat danh sach  
	DrawRectangle(500,250,610,290,MauDen);//them
	DrawRectangle(610,250,720,290,MauDen);//sua 
	DrawRectangle(720,250,830,290,MauDen);// xoa
	DrawRectangle(610,210,750,250,MauDen);// xuat diem
	setbkcolor(MauTrang);
	setcolor(MauDen);
	settextstyle(3,0,3);
	outtextxy(435,255,"LUU");
	outtextxy(835,255,"XUAT DS") ;
	outtextxy(520,255,"THEM");
	outtextxy(630,255,"SUA");
	outtextxy(740,255,"XOA");
	outtextxy(620,215,"DS DIEM");
//	outtextxy()

	setcolor(MauDen);
	Taobang3(40,300,120,330);
	DrawBar(350,635,500,675,MauXam);//prev
	DrawBar(800,635,950,675,MauXam);//next
	setbkcolor(MauXam);
	setcolor(MauDen);
	settextstyle(3,0,3);
	outtextxy(400,640,"PREV");
	outtextxy(850,640,"NEXT");
		NutQuaylai(1330,50,1380,90);
}

void Thaotac_Thongbao3(int **mapID,ds_sinh_vien &l) { // trong window3 (4), case 24, 
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
				remove("filesanhsachsv3.txt");
				WriteFile(l);//luu vo file 
				return;// goi ham
			case 3:
				Window3();//no
				return;// khong lam gi ca
			
		}
		delay(0.001); 
	}
}

void Thaotac_Window3(int **mapID,SINH_VIEN &sv, ds_sinh_vien &l) {
	int x=-1,y=-1; 

	SINH_VIEN sv1;	
	NODE_SINH_VIEN *run;
	
	//set map id nut prev va next
		taoTextInput(350,635,500,675,11,mapID) ;//prev
		taoTextInput(800,635,950,675,12,mapID) ;//next
//	set map id cho bang	
		Set_MapID_table(mapID);

		//set map id chuc nang
		int trangso=1;
	//	taoTextInput(610,210,750,250,25,mapID);//xuat ds diem
		taoTextInput(150,145,500,185,13,mapID) ;//ho
		taoTextInput(150,195,500,235,14,mapID);//ten
		taoTextInput(700,145,950,185,15,mapID);//ma sv
	//	taoTextInput(700,195,950,235,16,mapID);//ma lop 
		taoTextInput(1100,145,1350,185,17,mapID);//sdt
		taoTextInput(1100,195,1350,235,18,mapID);//phai
		taoTextInput(500,250,610,290,19,mapID);//them
		taoTextInput(610,250,720,290,20,mapID);//sua 
		taoTextInput(720,250,830,290,21,mapID);// xoa 
		taoTextInput(830,250,950,290,22,mapID);// xuat danh sach 
		taoTextInput(1330,50,1380,90,23,mapID); // return
		taoTextInput(430,250,500,290,24,mapID);//luu vo file
		
		delay(0.001); 
	while(true) { 
		taoTextInput(150,145,500,185,0,mapID);
		taoTextInput(150,145,500,185,13,mapID);
		taoTextInput(150,195,500,235,0,mapID);
		taoTextInput(150,195,500,235,14,mapID);
	
		
		//bat chuot
		int id=0; 	
		if(ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN,x,y);
			id= mapID[y][x];  
			clearmouseclick(WM_LBUTTONDOWN);
		}
		char s[10]="";
		
			switch(id) {
				
		
			case 13: 
				fflush(stdin);
				DrawBar(150,145,500,185,MauTrang);	//Ho
				strcpy(sv1.HO,"");
				Nhap_Khong_So(152,147,sv1.HO) ;
		//		strcpy(sv.HO,Ho);
			    break;
				
			case 14: 
			fflush(stdin);
			DrawBar(150,195,500,235,MauTrang);	//Ten
			strcpy(sv1.TEN,"");
				Nhap_Khong_So(152,197,sv1.TEN) ;
			//	strcpy(sv.TEN,Ten);
			    break;
			case 15:
				fflush(stdin);
					DrawBar(700,145,950,185,MauTrang); //ma sv


				strcpy(sv1.MASV,"");
				Nhap_INHOA(702,147,sv1.MASV) ;
			//	strcpy(sv.MASV,Masv);
				if(strcmp(s,sv1.MASV)==0){
					ThongBao(500,200,900,400,MauTrang,550,220,"ket thuc qua trinh nhap");
					sleep(3);
					Window3();
					break;
				}
				if(Search3(l,sv1)!=NULL){
					ThongBao(500,200,900,400,MauTrang,550,220,"Ma so Sinh Vien bi trung");
					sleep(3);
					Window3();
					Nhap(702,147,sv1.MASV);
			//		strcpy(sv.MASV,Masv);
					break;
				}
					
				break;
				

			case 17 :
				DrawBar(1100,145,1350,185,MauTrang); //So dien thoai 
				fflush(stdin);
				strcpy(sv1.SDT,"");
				Nhap_SO(1102,147,sv1.SDT);
				if(strlen(sv1.SDT)!=10){
					ThongBao(500,200,900,400,MauTrang,550,220,"Nhap so dien thoai phu hop(10 chu so)!");
					sleep(2);
					Window3();
					Nhap_SO(1102,147,sv1.SDT);
					break;
				}
			
				break;
			case 18:
				DrawBar(1100,195,1350,235,MauTrang); //phai
				fflush(stdin);
				strcpy(sv1.PHAI,"");
				Nhap(1102,197,sv1.PHAI);
			//	strcpy(sv.PHAI,Phai);	
				break;
			case 19:
				strcpy(sv1.MALOP,sv.MALOP);
				ThemSVvaolop(l,sv1);
				Window3();	

			    break;   
			case 20://sua
			
				xoa_SV(l,sv1.MASV);
				
				break;
			case 21: // xoa  
			
				ThongBao(500,200,900,400,MauTrang,550,220,"Ban co chan muon xoa!!!");
				Thaotac_Xoa3(mapID,l,sv1);
				//goi ham xoa ra 
				break;
			case 22: // xuat danh sach  
				Window3(); 
				strcpy(sv1.MALOP,sv.MALOP);
			//	Selection_Sort(l);
				PrintList(l,trangso,sv1.MALOP);
				STT(40,330,trangso);
				break;
			case 23:// dau quay lai
				WindowMain();
			//	 resetMapID(mapID);
				//break;
				setIDvung(10,10,200,50,1,mapID); // Danh sach mon hoc
				setIDvung(210,10,410,50,2,mapID); // Danh sach lop tin chi
				setIDvung(410,10,610,50,3,mapID); // Danh sach sinh vien
				setIDvung(610,10,810,50,4,mapID); // Dang ky lop tin chi
				setIDvung(1330,10,1380,81,5,mapID); // Dau X
				return;
			case 24:
				ThongBao(500,200,900,400,MauTrang,550,220,"Ban co muon luu vo file ");
				Thaotac_Thongbao3(mapID,l);
			//	WriteFile(l);//luu vo file 
				break;
		
			case 11://prev
				if(trangso!=1)
				{
					trangso--;
				//	Selection_Sort(l);
					Window3();
					
					PrintList(l,trangso,sv1.MALOP);
						STT(40,330,trangso);
				//	id=0;
					break;
				}
				break;
			case 12://next
				trangso++;
				Window3();
				PrintList(l,trangso,sv1.MALOP);
			  	STT(40,330,trangso);
			   // id=0;
			    break;
		 }//ket thuc switch 
		 	if(id>=1&&id<=10)
		 	{
		 		Tim_SV_Table(l,id+10*(trangso-1),sv1,sv1.MALOP);
		 		DrawBar(150,145,500,185,MauTrang);	//Ho

				DrawBar(150,195,500,235,MauTrang);	//Ten

				DrawBar(700,145,950,185,MauTrang); //ma sv

				DrawBar(1100,145,1350,185,MauTrang); //So dien thoai 

				DrawBar(1100,195,1350,235,MauTrang); //phai
		 		outtextxy(152,147,sv1.HO);
		 		outtextxy(152,197,sv1.TEN);
		 		outtextxy(702,147,sv1.MASV);
		 	//	outtextxy(702,197,sv1.MALOP);
		 		outtextxy(1102,147,sv1.SDT);
		 		outtextxy(1102,197,sv1.PHAI);
		 		//break;
			 }
			 
		delay(0.001);
	}
}

