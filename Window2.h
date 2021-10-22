#pragma once
#include <winbgim.h>
#include "Define.h"
#include "VeHinh.h"
#include "SetIDvung.h"
#include "ToolBar.h"
#include "Define.h"
#include"DanhSachDangKyLopTC.h"
#include"DanhSachLopTinChi.h"
#include"HieuUng.h"
void Thaotac_Xoa2(int **mapID,ds_lop_tin_chi &dsltc,LOP_TIN_CHI &LTC);// trong ham hieu ung
void Thaotac_Thongbao2(int **mapID,ds_lop_tin_chi &l);// hieuung,h
void Window2() // DANH SACH LOP TIN CHI 
{
	
	DrawRectangle(10,50,1380,680,MauDen); // Khung Window2
	DrawBar(10,50,1380,680,MauXamNhat); // to Khung Window2

	setbkcolor(MauXamNhat);
	setcolor(MauDo);
	settextstyle(4,0,4);
	outtextxy(450,70,"DANH SACH LOP TIN CHI");
	setbkcolor(MauXamNhat);
	setcolor(MauDen);
	settextstyle(3,0,3);
	outtextxy(50,150,"Ma Mon Hoc : ");
	outtextxy(50,200,"Nien Khoa : ");
	outtextxy(650,150,"Hoc Ky : ");
	outtextxy(650,200,"Nhom : ");
	outtextxy(1000,150,"So SV Min : ");
	outtextxy(1000,200,"So SV Max : ");
	DrawBar(200,145,600,185,MauTrang);	//ma mon hoc

	DrawBar(200,195,600,235,MauTrang);	//Nien Khoa

	DrawBar(750,145,950,185,MauTrang); //Hoc Ky

	DrawBar(750,195,950,235,MauTrang); //Nhom

	DrawBar(1150,145,1350,185,MauTrang); //So SV Min

	DrawBar(1150,195,1350,235,MauTrang); //So SV Max

	DrawBar(500,250,830,290,MauTrang);// them, sua va xoa
	
	
	DrawRectangle(500,250,610,290,MauDen);
	DrawRectangle(610,250,720,290,MauDen);
	DrawRectangle(720,250,830,290,MauDen);
	DrawBar(830,250,950,290,MauTrang);// xuat danh sach 
	DrawBar(430,250,500,290,MauTrang);//luu
	DrawRectangle(830,250,950,290,MauDen);//xuat danh sach 
	DrawBar(300,250,430,290,MauTrang);//huy lop
	DrawRectangle(300,250,430,290,MauDen);// huy lop

	setbkcolor(MauTrang);
	setcolor(MauDen);
	settextstyle(3,0,3);
	outtextxy(520,255,"Them");
	outtextxy(630,255,"Sua");
	outtextxy(740,255,"Xoa");
	outtextxy(435,255,"LUU");
	outtextxy(835,255,"XUAT DS") ;
	outtextxy(305,255,"HUY LOP");

	setcolor(MauDen);
	Taobang2(40,300,120,330);
	DrawBar(350,635,500,675,MauXam);
	DrawBar(800,635,950,675,MauXam);
	setbkcolor(MauXam);
	setcolor(MauDen);
	settextstyle(3,0,3);
	outtextxy(400,640,"PREV");
	outtextxy(850,640,"NEXT");
	NutQuaylai(1330,50,1380,90);
}

void Thaotac_Thongbao22(int **mapID,ds_lop_tin_chi &l2) { 
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
				Huy_Lop_TC(l2);
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
void Thaotac_Window2(int **mapID,LOP_TIN_CHI &Ltc ,DS_LOP_TIN_CHI &l2,Tree_MON_HOC Root){
	int x=-1,y=-1; 
	resetMapID(mapID);
	//ve man hinh 
	LOP_TIN_CHI LTCtmp;
	char temp[10];	
		taoTextInput(200,145,600,185,0,mapID);
		Taoid(200,145,600,185,101,mapID);//ma mon hoc 
		taoTextInput(350,635,500,675,13,mapID) ;//prev
		taoTextInput(800,635,950,675,12,mapID) ;//next
	
		
		int trangso=1;
	
	
		taoTextInput(200,195,600,235,22,mapID) ;//nien khoa
		taoTextInput(750,145,950,185,33,mapID);//hoc ki
		taoTextInput(750,195,950,235,44,mapID);//nhom
		taoTextInput(1150,145,1350,185,55,mapID);//so sv min
		taoTextInput(1150,195,1350,235,66,mapID);//so sv max
		taoTextInput(500,250,610,290,77,mapID);//them
		taoTextInput(610,250,720,290,88,mapID);//sua
		taoTextInput(720,250,830,290,99,mapID);//xoa
		taoTextInput(830,250,950,290,100,mapID);//xuatds
		taoTextInput(430,250,500,290,111,mapID);//luu
		taoTextInput(1330,50,1380,90,122,mapID); // return
		taoTextInput(300,250,430,290,123,mapID); // return
		Set_MapID_table(mapID);
	char tmp1[50]="";	
	char tmp2[50]="";
	char tmp3[50]="";
	char tmp4[50]="";
		delay(0.001); 
	while(true) {
		
			taoTextInput(1150,145,1350,185,0,mapID);//so sv min
			taoTextInput(1150,145,1350,185,55,mapID);//so sv min
		//bat chuot
		int id=0; 
		if(ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN,x,y);
			id= mapID[y][x];  
			clearmouseclick(WM_LBUTTONDOWN);
		}
		char s[10]="";
		switch(id) {
			case 123 :
				ThongBao(500,200,900,400,MauTrang,550,220,"Xoa nhung lop chua du sinh vien?? ");
				Thaotac_Thongbao22(mapID,l2);
				break;
			case 101: // ma mon hoc
				
				fflush(stdin);
				DrawBar(200,145,600,185,MauTrang);	//ma mon hoc


				strcpy(LTCtmp.MAMH,"");
				Nhap(202,147,LTCtmp.MAMH) ;	
				if(search_11(Root,LTCtmp.MAMH)==NULL)
				{
					ThongBao(500,200,900,400,MauTrang,550,220,"Khong co Ma mon hoc nay!");
					sleep(2);
					Window2();
					fflush(stdin);
					strcpy(LTCtmp.MAMH,"");
					Nhap(202,147,LTCtmp.MAMH) ;	 
				} 
				break;
			case 22: // nien khoa
				fflush(stdin);
				DrawBar(200,195,600,235,MauTrang);	//Nien Khoa


				strcpy(LTCtmp.NIEN_KHOA,"");
				Nhap(202,197,LTCtmp.NIEN_KHOA) ;
				break;
			case 33:// hoc ki
				fflush(stdin);
				DrawBar(750,145,950,185,MauTrang); //Hoc Ky


				Nhap_SO(752,147,tmp1) ;
   				LTCtmp.HOC_KY=atoi(tmp1);// chuyen doi chuoi char ve so nguye 
				break;
			case 44://nhom
				fflush(stdin);
				DrawBar(750,195,950,235,MauTrang); //Nhom


				Nhap_SO(752,197,tmp2) ;
   				LTCtmp.NHOM=atoi(tmp2);// chuyen doi chuoi char ve so nguye 
				break;
			case 55 ://so sinh vien min
				fflush(stdin);
				DrawBar(1150,145,1350,185,MauTrang); //So SV Min

				DrawBar(1150,195,1350,235,MauTrang); //So SV Max
				Nhap_SO(1152,147,tmp3) ;
   				LTCtmp.SO_SV_MIN=atoi(tmp3);// chuyen doi chuoi char ve so nguye 
				break;
			case 66:// so sinh vien max
				fflush(stdin);
				DrawBar(1150,195,1350,235,MauTrang); //So SV Max
				Nhap_SO(1152,197,tmp4) ;
   				LTCtmp.SO_SV_MAX=atoi(tmp4);// chuyen doi chuoi char ve so nguye 
				break;
			case 77:
				
				//THEM
				Window2();
				
				if(Search_LTC(l2,LTCtmp)==-1)
			  		 Them_LopTC(l2,LTCtmp);
			  	else {
			   		ThongBao(500,200,900,400,MauTrang,550,220,"Lop Tin Chi nay da co!");
					sleep(2);
					Window2();
			   }
				
			//	cout <<LTCtmp.MAMH;
//				strcpy(Ltc.MAMH,"");
//				strcpy(Ltc.NIEN_KHOA,"");
//				strcpy(tmp1,"");
//				strcpy(tmp2,"");
//				strcpy(tmp3,"");
//				strcpy(tmp4,"");
				break;
			//	return;
			case 88://sua
				Xoa_LTC(l2,LTCtmp);
				break;
			case 99:	//xoa
		
				ThongBao(500,200,900,400,MauTrang,550,220,"Ban co chac muon xoa!!!");
				Thaotac_Xoa2(mapID,l2,LTCtmp);
		
				break;
			case 100://xuat
		
				Window2(); 
				setbkcolor(MauTrang);
				PrintList2(l2,trangso,Root);
				STT(40,330,trangso);
				break;
			case 111:// luu file
				ThongBao(500,200,900,400,MauTrang,550,220,"Ban co muon luu vo file ");
				Thaotac_Thongbao2(mapID,l2);// trong file hieu ung va phia tren window2
				
				break;
			case 122 :
				WindowMain();
				setIDvung(10,10,200,50,1,mapID); // Danh sach mon hoc
				setIDvung(210,10,410,50,2,mapID); // Danh sach lop tin chi
				setIDvung(410,10,610,50,3,mapID); // Danh sach sinh vien
				setIDvung(610,10,810,50,4,mapID); // Dang ky lop tin chi
				setIDvung(1330,10,1380,81,5,mapID); // Dau X
				return;
			case 13://prev
				if(trangso!=1)
				{
					trangso--;
				//	Selection_Sort(l);
					Window2();
					setbkcolor(MauTrang);
					PrintList2(l2,trangso,Root);
					STT(40,330,trangso);
					id=0;
					break;
				}
				break;
			case 12://next
				trangso++;
				Window2();
				setbkcolor(MauTrang);
				PrintList2(l2,trangso,Root);
				STT(40,330,trangso);
			    id=0;
			    break;
				
		}
		if(id>=1&&id<=10)
		 	{
		 //	Tim_SV_Table(l,id,sv1);
		 
		 		Searh_ID(l2,id-1,LTCtmp,trangso);
		 		
		 		// xuat ra nhung thong tin ben tren khi click vo bang
		 		outtextxy(202,147,LTCtmp.MAMH);
		 		outtextxy(202,197,LTCtmp.NIEN_KHOA);
		 		
		 	
    			itoa(LTCtmp.HOC_KY,temp,10);
		 		outtextxy(752,147,temp);
		 		
		 		
    			itoa(LTCtmp.NHOM,temp,10);
		 		outtextxy(752,197,temp);
		 		
    			itoa(LTCtmp.SO_SV_MIN,temp,10);
		 		outtextxy(1152,147,temp);
		 		
    			itoa(LTCtmp.SO_SV_MAX,temp,10);
		 		outtextxy(1152,197,temp);
		 		//break;
			 }
		delay(0.001); 
	}
}
	
