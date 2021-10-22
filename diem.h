#pragma once
#include <winbgim.h>
#include "Define.h"
#include "VeHinh.h"
#include "SetIDvung.h"
#include "ToolBar.h"
#include"HieuUng.h"
#include"DanhSachSinhVien.h"
#include <unistd.h>
#include <math.h>
void chuyenFloatquachuoi(char s[], float diem){
	strcpy(s,"");
	int a = floor(diem);
	char chrA[5]="";
	itoa(a, chrA, 10);
	strcat(s, chrA);
	a = floor((1.0*diem-a)*100*1.0);
	itoa(a, chrA, 10);
	strcat(s, ".");
	strcat(s, chrA);
}

void Window_Diem() 
{
	
	DrawRectangle(10,50,1380,680,MauDen); // Khung Window2
	DrawBar(10,50,1380,680,MauXamNhat); // to Khung Window2
	setbkcolor(MauXamNhat);
	setcolor(MauDo);
	settextstyle(4,0,4);
	outtextxy(400,70,"DIEM SINH VIEN");
	setbkcolor(MauXamNhat);
	setcolor(MauDen);
	settextstyle(3,0,3);
	outtextxy(30,150,"Nien Khoa : ");
	outtextxy(600,150,"Hoc Ky : ");
	outtextxy(1000,150,"Nhom : ");
	outtextxy(1000,200,"Mon Hoc : ");
	DrawBar(150,145,500,185,MauTrang);	//nien khoa
	DrawBar(700,145,950,185,MauTrang); //hoc ki
	DrawBar(1100,145,1350,185,MauTrang); //nhom
	DrawBar(1100,195,1350,235,MauTrang); //Mon hoc
	DrawBar(830,250,980,290,MauTrang);// nhap diem
		DrawBar(610,250,750,290,MauTrang);//xuat ds diem
	DrawBar(430,250,500,290,MauTrang);//luu
	DrawRectangle(830,250,980,290,MauDen);// nhap diem
	DrawRectangle(610,250,750,290,MauDen);//xuat ds diem

	setbkcolor(MauTrang);
	setcolor(MauDen);
	settextstyle(3,0,3);
	outtextxy(435,255,"LUU");
	outtextxy(835,255,"NHAP DIEM") ;
	outtextxy(614,255,"XUAT DIEM");

	setcolor(MauDen);
	Taobang_Diem(40,300,120,330);
	DrawBar(350,635,500,675,MauXam);//prev
	DrawBar(800,635,950,675,MauXam);//next
	setbkcolor(MauXam);
	setcolor(MauDen);
	settextstyle(3,0,3);
	outtextxy(400,640,"PREV");
	outtextxy(850,640,"NEXT");
	NutQuaylai(1330,50,1380,90);
}

void Xuat_Diem(dssv_dang_ky DS, int trangso, ds_sinh_vien l) // xuat thong tin 1 sinh vien 
{	
	//	float tmp;
		setbkcolor(15);
		char tmp[10]="";
		int x1=40,y1=330,x2=120,y2=330;
		int i=1;
		for(SV_DANG_KY *node=DS.head;node!=NULL;node=node->pNext)
		{
			if(i>10*(trangso-1)&&i<=10*trangso)
			{
				outtextxy(x2+800,y1+1,node->data.MASV);
				node_sinh_vien* nod=Search_3(l,node->data.MASV);
				outtextxy(x2+100,y1+1,nod->data.HO);
				outtextxy(x2+400,y1+1,nod->data.TEN);
				chuyenFloatquachuoi(tmp,node->data.DIEM);
			//	tmp=node->data.DIEM;
				outtextxy(x2+1100,y1+1,tmp);
			}
			y1=y1+30; 
			i++;
		}
		
}

void Print_DS_Diem(DS_LOP_TIN_CHI dsltc,int trangso, char Nien_Khoa[15], int Hocki, int Nhom, char Ma_MonHoc[50],ds_sinh_vien l)
{
	int x1=40,y1=330,x2=120,y2=330;
	for(int i=0;i<dsltc.n;i++)
	{
		if(dsltc.data[i]->NHOM==Nhom&&dsltc.data[i]->HOC_KY==Hocki&&strcmp(dsltc.data[i]->NIEN_KHOA,Nien_Khoa)==0,strcmp(Ma_MonHoc,dsltc.data[i]->MAMH)==0)
		{
			Xuat_Diem(dsltc.data[i]->DSSVDK,trangso,l);
		}
		
	}
}
void Tim_SVDK_Table(DS_LOP_TIN_CHI &dsltc, int id, SINH_VIEN4 &sv,char Nien_Khoa[15], int Hocki, int Nhom, char Ma_MonHoc[50],int trangso)
{
	char diem[10]="";
	int x=id+(trangso-1)*10;
	char tmp[5];
	for(int i=0;i<dsltc.n;i++)
	{
		if(dsltc.data[i]->NHOM==Nhom&&dsltc.data[i]->HOC_KY==Hocki&&strcmp(dsltc.data[i]->NIEN_KHOA,Nien_Khoa)==0,strcmp(Ma_MonHoc,dsltc.data[i]->MAMH)==0)
		{
			for(SV_DANG_KY* node=dsltc.data[i]->DSSVDK.head;node!=NULL;node=node->pNext)
			{
				
				if(x==1)
				{
					sv=node->data;
					
					Nhap_diem(1220,331+30*(id-1),diem) ;
					float a=atof(diem);// chuyen tu chuoi thanh float hoac double
					node->data.DIEM=a;
					if(node->data.DIEM<0||node->data.DIEM>10)
					{
						ThongBao(500,200,900,400,MauTrang,550,220,"Vui long nhap diem tu 0 -> 10!");
						sleep(1);
						Window_Diem();
						setbkcolor(MauTrang);
						outtextxy(152,147,Nien_Khoa);
						itoa(Hocki,tmp,10);
						outtextxy(702,147,tmp);
						itoa(Nhom,tmp,10);
						outtextxy(1102,147,tmp);
						outtextxy(1102,197,Ma_MonHoc);
						Nhap_diem(1220,331+30*(id-1),diem) ;
						 break;
			   
					}
					break;
				}
				x--;
			}	
		}
	} 
}
void Thaotac_Window_Xuat_Diem(int **mapID,ds_lop_tin_chi &l,ds_sinh_vien lsv) {
	int x=-1,y=-1; 
	char tmp[5];
	SINH_VIEN sv1;	
	NODE_SINH_VIEN *run;
	int trangso=1;
	char MonHoc[50];
	char Nien_Khoa[10];
	int Hoc_Ki;
	int Nhom;
	SINH_VIEN4 sv4;
//	LOP_TIN_CHI LTC;
	reset_MapID_table(mapID);
	//set map id nut prev va next
		taoTextInput(350,635,500,675,11,mapID) ;//prev
		taoTextInput(800,635,950,675,12,mapID) ;//next
//	set map id cho bang	
	
		Set_MapID_table(mapID);
		//set map id chuc nang
	
		taoTextInput(150,145,500,185,13,mapID) ;//nien khoa
		taoTextInput(700,145,950,185,15,mapID);//hoc ki
		taoTextInput(1100,145,1350,185,17,mapID);//nhom
		taoTextInput(1100,195,1350,235,18,mapID);//mon hoc
		taoTextInput(610,250,750,290,20,mapID);// xuat ds diem
		taoTextInput(830,250,980,290,22,mapID);// nhap diem
		taoTextInput(1330,50,1380,90,23,mapID); // return
		taoTextInput(430,250,500,290,24,mapID);//luu vo file
		
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
				
			case 13: 
				fflush(stdin);
				strcpy(Nien_Khoa,"");
				Nhap(152,147,Nien_Khoa) ;
			    break;
		
			case 15:
				fflush(stdin);
		
				char s[10];
				strcpy(s,"");
				Nhap_SO(702,147,s) ;
				Hoc_Ki=atoi(s);
				break;
			case 17 :
				fflush(stdin);
				char a[10];
				strcpy(a,"");
				Nhap_SO(1102,147,a);
				Nhom=atoi(a);
				break;
			case 18:
				fflush(stdin);
				strcpy(MonHoc,"");
				Nhap(1102,197,MonHoc);
				
		// tim kiem mon hoc
				break;
			case 24 :
				ThongBao(500,200,900,400,MauTrang,550,220,"Ban co muon luu vo file ");
				Thaotac_Thongbao2(mapID,l);// trong file hieu ung va phia tren window2
			case 22: // xuat danh sach  
			
				Window_Diem(); 
				//in lai thong tin nhap o tren 	
			
				setbkcolor(MauTrang);
				outtextxy(152,147,Nien_Khoa);
				outtextxy(702,147,s);
				outtextxy(1102,147,a);
				outtextxy(1102,197,MonHoc);
				Print_DS_Diem(l,trangso,Nien_Khoa,Hoc_Ki,Nhom,MonHoc,lsv);
				STT(40,330,trangso);
				break;
			case 20:// xuat ds diem mon hoc 
				Window_Diem(); 
				setbkcolor(MauTrang);
				outtextxy(152,147,Nien_Khoa);
				outtextxy(702,147,s);
				outtextxy(1102,147,a);
				outtextxy(1102,197,MonHoc);
				Print_DS_Diem(l,trangso,Nien_Khoa,Hoc_Ki,Nhom,MonHoc,lsv);
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
		
			case 11://prev
				if(trangso!=1)
				{
					trangso--;
					Window_Diem();
					setbkcolor(MauTrang);
					outtextxy(152,147,Nien_Khoa);
					outtextxy(702,147,s);
					outtextxy(1102,147,a);
					outtextxy(1102,197,MonHoc);
					Print_DS_Diem(l,trangso,Nien_Khoa,Hoc_Ki,Nhom,MonHoc,lsv);
					STT(40,330,trangso);
					id=0;
					break;
				}
				break;
			case 12://next
				trangso++;
				
				Window_Diem();
				setbkcolor(MauTrang);
				outtextxy(152,147,Nien_Khoa);
				
				outtextxy(702,147,s);
				
				outtextxy(1102,147,a);
				outtextxy(1102,197,MonHoc);
				Print_DS_Diem(l,trangso,Nien_Khoa,Hoc_Ki,Nhom,MonHoc,lsv);
			  	STT(40,330,trangso);
			    id=0;
			    break;
		 }//ket thuc switch 
		 	if(id>=1&&id<=10)
		 	{
		 		Tim_SVDK_Table(l,id,sv4,Nien_Khoa,Hoc_Ki,Nhom, MonHoc,trangso);
		 		Window_Diem();
				setbkcolor(MauTrang);
				outtextxy(152,147,Nien_Khoa);
				itoa(Hoc_Ki,tmp,10);
				outtextxy(702,147,tmp);
				itoa(Nhom,tmp,10);
				outtextxy(1102,147,tmp);
				outtextxy(1102,197,MonHoc);
				Print_DS_Diem(l,trangso,Nien_Khoa,Hoc_Ki,Nhom,MonHoc,lsv);
			  	STT(40,330,trangso);
		 		
		 	
			 }
			 
		delay(0.001);
	}
}
void Thaotac_Window_Diem(int **mapID,ds_lop_tin_chi &l,ds_sinh_vien lsv) {
	int x=-1,y=-1; 
	char tmp[5];
	SINH_VIEN sv1;	
	NODE_SINH_VIEN *run;
	int trangso=1;
	char MonHoc[50];
	char Nien_Khoa[10];
	int Hoc_Ki;
	int Nhom;
	SINH_VIEN4 sv4;
//	LOP_TIN_CHI LTC;
	reset_MapID_table(mapID);
	//set map id nut prev va next
		taoTextInput(350,635,500,675,11,mapID) ;//prev
		taoTextInput(800,635,950,675,12,mapID) ;//next
//	set map id cho bang	
	
		Set_MapID_table(mapID);
		//set map id chuc nang
	
		taoTextInput(150,145,500,185,13,mapID) ;//nien khoa
		taoTextInput(700,145,950,185,15,mapID);//hoc ki
		taoTextInput(1100,145,1350,185,17,mapID);//nhom
		taoTextInput(1100,195,1350,235,18,mapID);//mon hoc
		taoTextInput(610,250,750,290,20,mapID);// xuat ds diem
		taoTextInput(830,250,980,290,22,mapID);// nhap diem
		taoTextInput(1330,50,1380,90,23,mapID); // return
		taoTextInput(430,250,500,290,24,mapID);//luu vo file
		
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
				
			case 13: 
				fflush(stdin);
				strcpy(Nien_Khoa,"");
				Nhap(152,147,Nien_Khoa) ;
			    break;
		
			case 15:
				fflush(stdin);
		
				char s[10];
				strcpy(s,"");
				Nhap_SO(702,147,s) ;
				Hoc_Ki=atoi(s);
				break;
			case 17 :
				fflush(stdin);
				char a[10];
				strcpy(a,"");
				Nhap_SO(1102,147,a);
				Nhom=atoi(a);
				break;
			case 18:
				fflush(stdin);
				strcpy(MonHoc,"");
				Nhap(1102,197,MonHoc);
				
		// tim kiem mon hoc
				break;
			case 24 :
				ThongBao(500,200,900,400,MauTrang,550,220,"Ban co muon luu vo file ");
				Thaotac_Thongbao2(mapID,l);// trong file hieu ung va phia tren window2
			case 22: // xuat danh sach  
			
				Window_Diem(); 
				//in lai thong tin nhap o tren 	
			
				setbkcolor(MauTrang);
				outtextxy(152,147,Nien_Khoa);
				outtextxy(702,147,s);
				outtextxy(1102,147,a);
				outtextxy(1102,197,MonHoc);
				Print_DS_Diem(l,trangso,Nien_Khoa,Hoc_Ki,Nhom,MonHoc,lsv);
				STT(40,330,trangso);
				break;
			case 20:// xuat ds diem mon hoc 
				Window_Diem(); 
				setbkcolor(MauTrang);
				outtextxy(152,147,Nien_Khoa);
				outtextxy(702,147,s);
				outtextxy(1102,147,a);
				outtextxy(1102,197,MonHoc);
				Print_DS_Diem(l,trangso,Nien_Khoa,Hoc_Ki,Nhom,MonHoc,lsv);
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
		
			case 11://prev
				if(trangso!=1)
				{
					trangso--;
					Window_Diem();
					setbkcolor(MauTrang);
					outtextxy(152,147,Nien_Khoa);
					outtextxy(702,147,s);
					outtextxy(1102,147,a);
					outtextxy(1102,197,MonHoc);
					Print_DS_Diem(l,trangso,Nien_Khoa,Hoc_Ki,Nhom,MonHoc,lsv);
					STT(40,330,trangso);
					id=0;
					break;
				}
				break;
			case 12://next
				trangso++;
				
				Window_Diem();
				setbkcolor(MauTrang);
				outtextxy(152,147,Nien_Khoa);
				
				outtextxy(702,147,s);
				
				outtextxy(1102,147,a);
				outtextxy(1102,197,MonHoc);
				Print_DS_Diem(l,trangso,Nien_Khoa,Hoc_Ki,Nhom,MonHoc,lsv);
			  	STT(40,330,trangso);
			    id=0;
			    break;
		 }//ket thuc switch 
		 	if(id>=1&&id<=10)
		 	{
		 		Tim_SVDK_Table(l,id,sv4,Nien_Khoa,Hoc_Ki,Nhom, MonHoc,trangso);
		 		Window_Diem();
				setbkcolor(MauTrang);
				outtextxy(152,147,Nien_Khoa);
				itoa(Hoc_Ki,tmp,10);
				outtextxy(702,147,tmp);
				itoa(Nhom,tmp,10);
				outtextxy(1102,147,tmp);
				outtextxy(1102,197,MonHoc);
				Print_DS_Diem(l,trangso,Nien_Khoa,Hoc_Ki,Nhom,MonHoc,lsv);
			  	STT(40,330,trangso);
		 		
		 	
			 }
			 
		delay(0.001);
	}
}

