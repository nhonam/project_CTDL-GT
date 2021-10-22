#pragma once
#include <winbgim.h>
#include "Define.h"
#include "VeHinh.h"
#include "SetIDvung.h"
#include "ToolBar.h"
#include"DanhSachDangKyLopTC.h"
#include"DanhSachSinhVien.h"
#include"DanhSachLopTinChi.h"
#include"DanhSachMonHoc.h"

void Taobang4(int x1,int y1,int x2,int y2)
{
	setbkcolor(MauTrang);
	setcolor(MauDen);
	settextstyle(3,0,2);

	int y;
	int id=12;
	for (int y=y1;y<625;y=y+30) 
	{
		DrawBar(x1,y,x2,y+30,MauTrang); // stt

		DrawBar(x2,y,x2+200,y+30,MauTrang);// ma mh

		DrawBar(x2+200,y,x2+450,y+30,MauTrang);//ten mh

		DrawBar(x2+450,y,x2+600,y+30,MauTrang);//nhom

		DrawBar(x2+600,y,x2+850,y+30,MauTrang);//so sv da dang ki

		DrawBar(x2+850,y,x2+1100,y+30,MauTrang);// so slot con trong

	}
}
void STT4(int x, int y, int trangso)
{
	char s[3];
	int y1=430;
	for(int i=1;i<300;i++)
	{
		if(i>7*(trangso-1)&&i<=7*trangso)
		{
		itoa(i,s,10);
		outtextxy(x+30,y1+5,s);
		y1=y1+30;
		};
	}
}
void SetID_Table4(int **mapID)
{
//	1250,430,1350,460
		int x=-1,y=-1;
		//set map id cho bang	
		int x1=1250,y1=430,x2=1350,y2=460;
		for(int i=1;i<=7;i++)
		{
			taoTextInput(x1,y1,x2,y2,i,mapID);
			y1=y1+30;
			y2=y2+30;
		}
}
void NodeDangKy(int x1,int y1,int x2, int y2,int mau)
{	
	for (int y=y1;y<625;y=y+30) 
	{
		DrawBar(x1,y,x2,y+30,MauXam);
		setbkcolor(MauXam);
		setcolor(MauDen);
		settextstyle(3,0,2);
		outtextxy(x1+10,y+5,"Dang Ky");
	}	
}
void Window4()// DANH SACH DANG KI LOP TIN CHI 
{
	DrawRectangle(10,50,1380,680,MauDen); // Khung Window2
	DrawBar(10,50,1380,680,MauXamNhat); // to Khung Window2

	setbkcolor(MauXamNhat);
	setcolor(MauDo);
	settextstyle(4,0,4);
	outtextxy(350,70,"DANH SACH DANG KY LOP TIN CHI");
	setbkcolor(MauXamNhat);
	setcolor(MauDen);
	settextstyle(3,0,3);
	outtextxy(200,150,"Ma Sinh Vien : ");
	DrawBar(400,145,700,185,MauTrang); // Masv
	
	setbkcolor(MauXam);
	setcolor(MauDen);
	settextstyle(3,0,3);
	
	// in cac thong tin cua sinh vien
	setbkcolor(MauXamNhat);
	settextstyle(3,0,2);
	outtextxy(15,200,"Thong tin: ");
	setbkcolor(MauTrang);
	settextstyle(3,0,2);
	DrawBar(120,195,500,235,MauTrang); // Ho ten
	outtextxy(170,200,"Ho Ten ");
	DrawBar(500,195,800,235,MauTrang);	// Ma lop
	outtextxy(550,200,"Ma Lop ");
	DrawBar(800,195,1100,235,MauTrang); // SDT
	outtextxy(850,200,"SDT ");
	DrawBar(1100,195,1300,235,MauTrang); // Phai
	outtextxy(1150,200,"Phai ");
	DrawBar(120,235,500,275,MauTrang); // Ho ten
	DrawBar(500,235,800,275,MauTrang);	// Ma lop
	DrawBar(800,235,1100,275,MauTrang); // SDT
	DrawBar(1100,235,1300,275,MauTrang); // Phai

	// lan nhap thu 2 
	setbkcolor(MauXamNhat);
	setcolor(MauDen);
	settextstyle(3,0,3);
	outtextxy(50,300,"Nien Khoa : ");
	outtextxy(650,300,"Hoc Ky : ");
	DrawBar(200,295,600,335,MauTrang);	//Nien Khoa
	DrawBar(750,295,1000,335,MauTrang); //Hoc Ky
	DrawBar(600,350,750,390,MauXam); // nhap
	setcolor(MauDen);
	
	DrawBar(350,635,500,675,MauXam); // next
	DrawBar(800,635,950,675,MauXam); // prev
	setbkcolor(MauXam);
	setcolor(MauDen);
	settextstyle(3,0,3);
	outtextxy(400,640,"PREV");
	outtextxy(850,640,"NEXT");
	
	setbkcolor(MauXam);
	setcolor(MauDen);
	settextstyle(3,0,3);
	outtextxy(650,355,"Nhap");
	Taobang4(40,400,100,430);  // tao bang
	setbkcolor(MauTrang);
	setcolor(MauDen);
	settextstyle(3,0,2);
	outtextxy(50,405,"STT");
	outtextxy(140,405,"Ma mon hoc"); 
	outtextxy(340,405,"Ten mon hoc");
	outtextxy(580,405,"Nhom");
	outtextxy(730,405,"SV da dang ky");
	outtextxy(980,405,"So luong con lai");
	NodeDangKy(1250,430,1350,460,MauXam); // dang ky	
		NutQuaylai(1330,50,1380,90);
}

void Xuat_LCTDK(int x1,int y1,int x2,int y2,LOP_TIN_CHI &l,Tree_MON_HOC Root) // xuat thong tin 1 sinh vien 
{	
		
		setbkcolor(15);
		outtextxy(x1+100,y1+1,l.MAMH);
		
		MON_HOC MonHoctmp;
		MonHoctmp= search11(Root,l.MAMH);// tim ten mon hoc bang ma mon hoc
	
		outtextxy(x1+300,y1+1,MonHoctmp.TENMH);// xuat ten mon hoc
		
		char n[5];
		itoa(l.NHOM,n,10);
		outtextxy(x1+600,y1+1,n);// xuat nhom	
	//	int i=0;

    	int Soluong= SoLuongSVDK(l.DSSVDK);
//    	cout <<SoluongSVDDK<<")):";
  	    char s[10];
    	itoa(Soluong,s,10);// chuyen doi kieu int sang char
		outtextxy(x1+800,y1+1,s);// xuat so sinh vien dang ki 
		
		int SV_ConLai=l.SO_SV_MAX-Soluong;//SoluongSVDDK;
		char x[10];
		itoa(SV_ConLai,x,10);
		outtextxy(x1+1050,y1+1,x);// so sv con lai
//		cout <<x<<endl;
	
}
void PrintList_LTCDK4(DS_LOP_TIN_CHI &l2, int trangso, char NienKhoa[15],int Hoc_Ky,Tree_MON_HOC Root) // in ra list
{
	int x1=20,y1=430,x2=1200,y2=460;
	int i;
	int a=0;
	for(i=0;i<l2.n;i++)
	{
		if(Hoc_Ky==l2.data[i]->HOC_KY&&strcmp(l2.data[i]->NIEN_KHOA,NienKhoa)==0)
		{
			
			if(a>=7*(trangso-1)&&a<7*trangso)
				{
				Xuat_LCTDK(x1,y1,x2,y2,*l2.data[i],Root);
				y1=y1+30;
				}
		a++;
		}
		
	}
}
//void Searh_ID_themvaoLTC(DS_LOP_TIN_CHI &ds,int id, LOP_TIN_CHI &LTC, int trangso, char NK[15], int HK) // tim lop tin chi  bang id de them sinh vien vao lop
//{
//	for(int i=0;i<ds.n;i++)
//	{
//		if(i==(trangso-1)*7+id && strcmp(ds.data[i].NIEN_KHOA,NK)==0 && ds.data[i].NHOM==HK)
//		{
//			LTC=ds.data[i];
//		}
//	}
//}
//int dem_sl_LTC(DS_LOP_TIN_CHI &ds, char NK[15], int HK)// dem so luong lop tin chi co nien khoa hoc ki nhap tu ban phim
//{
//	int i=0;
//	for(;i<ds.n;i++)
//	{
//		if(strcmp(NK,ds.data[i]->NIEN_KHOA)==0&&HK==ds.data[i]->HOC_KY)
//		{
//			i++;
//		}
//	}
//	return i;
//}
int Searh_ID_themvaoLTC(DS_LOP_TIN_CHI &dsltc,int vt,char nienkhoa[15],int hocky)// tim lop tc
{
	int i=0;
	for(;i<dsltc.n;i++)
	{
	//	if(hocky==dsltc.data[i]->HOC_KY)
		if(strcmp(nienkhoa,dsltc.data[i]->NIEN_KHOA)==0&&hocky==dsltc.data[i]->HOC_KY)// neu cung nien khoa hoc ki thi nhan
		{
			if(vt==1)
			{
				return i;
			}
			vt--;
		}
	}
	return i;
}


void Them_SVDK_vaoLTC4(DS_SV_DANG_KY &dsltc, SINH_VIEN sv)
{
	//sinh vien dang ki
	SINH_VIEN4 sv4;
//			char s[15]="";
//			strcat(s,sv.MASV);
			strcpy(sv4.MASV,sv.MASV);
		//	sv4.DIEM=0;
			SV_DANG_KY *node=CreateNode4(sv4) ;		
			Add_Head4(dsltc,node);
		//	cout <<dsltc.head->data.MASV<< " 999"<<endl;
}

void Thaotac_Window4(int **mapID,SINH_VIEN &sv, ds_sinh_vien &l,DS_LOP_TIN_CHI &l2, SINH_VIEN4 &sv4,Tree_MON_HOC Root) {
		int x=-1,y=-1; 

	char NienKhoa[15]="";
	char HocKy[15]="";
	int HK=0;// hoc ki

	SINH_VIEN svtmp=Search31(l,sv.MASV);
	strcat(svtmp.HO, " ");
	strcat(svtmp.HO,svtmp.TEN);
		//ve man hinh 
		int trangso=1;
		reset_MapID_table(mapID);
		SetID_Table4(mapID);
		
		taoTextInput(350,635+5,500,675,10,mapID) ;//next
		taoTextInput(800,635+5,950,675,12,mapID) ;//prev
		
		taoTextInput(200,295,600,335,32,mapID);//nien khoa
		taoTextInput(750,295,1000,335,42,mapID);//hoc ki
		taoTextInput(600,350,750,390,52,mapID);//nhap duoi hoc ki va nien khoa
		taoTextInput(1330,50,1380,90,62,mapID); // return
		 
	
	while(true) {
		//bat chuot
		int id=0; 
		if(ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN,x,y);
			id= mapID[y][x];  
			clearmouseclick(WM_LBUTTONDOWN);
		}
	
		switch(id) {
			
			case 32:
				fflush(stdin);
				Nhap(202,297,NienKhoa) ;
				break;
			case 42:
				fflush(stdin);
				Nhap_SO(752,297,HocKy) ;
				HK=atoi(HocKy);
				break;
			case 52 :
				//nhap vao hoc ki va nien khoa -> danh sach co hc ki va nien khoa
			//	return ;
				setbkcolor(MauTrang);
				PrintList_LTCDK4(l2,trangso,NienKhoa,HK,Root);
				STT4(40,330,trangso);
			//	Them_SVDK_vaoLTC(l2,MaSV,NienKhoa,HK);/// nha vo chu dang ki de them sinh vien vao lop tc mong muoon*****
				break;
			case 62:
				WindowMain();
				setIDvung(10,10,200,50,1,mapID); // Danh sach mon hoc
				setIDvung(210,10,410,50,2,mapID); // Danh sach lop tin chi
				setIDvung(410,10,610,50,3,mapID); // Danh sach sinh vien
				setIDvung(610,10,810,50,4,mapID); // Dang ky lop tin chi
				setIDvung(1330,10,1380,81,5,mapID); // Dau X
				return;
			case 10:// prev
			 
				if(trangso!=1)
				{
					trangso--;
				//	Selection_Sort(l);
				setbkcolor(MauTrang);
				Window4();
				PrintList_LTCDK4(l2,trangso,NienKhoa,HK,Root);
				setbkcolor(MauTrang);
				STT4(40,330,trangso);
			
				outtextxy(402,147,sv.MASV);	
				// xuat lai thong tin phia tren 	
				outtextxy(122+50,237,svtmp.HO);			
				outtextxy(802+50,237,svtmp.SDT);			
				outtextxy(502+50,237,svtmp.MALOP);
				outtextxy(1102+50,237,svtmp.PHAI);
				outtextxy(202,297,NienKhoa);
				outtextxy(752,297,HocKy);
				
				}
				break;
			case 12://next
				
				trangso++;
				setbkcolor(MauTrang);
				Window4();
				PrintList_LTCDK4(l2,trangso,NienKhoa,HK,Root);
				setbkcolor(MauTrang);
				STT4(40,330,trangso);
				
				outtextxy(402,147,sv.MASV);	
				// xuat lai thong tin phia tren 	
				
				outtextxy(122+50,237,svtmp.HO);			
				outtextxy(802+50,237,svtmp.SDT);			
				outtextxy(502+50,237,svtmp.MALOP);
				outtextxy(1102+50,237,svtmp.PHAI);
				outtextxy(202,297,NienKhoa);
				outtextxy(752,297,HocKy);
//				
			//	cout <<svtmp->data.HO<<endl;
			    break;
		}
		if(id>=1&&id<=7)
		{
			int x= Searh_ID_themvaoLTC(l2,(trangso-1)*7+id,NienKhoa,HK);	// x la vi tri sinh vien trong lop tin chi nhan duoc
			cout <<x<<"  + ";
			int sl=SoLuongSVDK(l2.data[x]->DSSVDK);// so luong sinh vien trong lop tin chi x
			if(l2.data[x]->SO_SV_MAX==sl)	//neu so sinh vien trong lop full thi thong bao lop da day
			{
				ThongBao(500,200,900,400,MauTrang,550,220,"Lop tin chi da du sinh vien!");
				sleep(1);
				Window4();
				setbkcolor(MauTrang);
				PrintList_LTCDK4(l2,trangso,NienKhoa,HK,Root);
				STT4(40,330,trangso);
		//	cout <<LTC.DSSVDK.head->data.MASV;
				outtextxy(402,147,sv.MASV);	
				// xuat lai thong tin phia tren 	
				
				outtextxy(122+50,237,svtmp.HO);			
				outtextxy(802+50,237,svtmp.SDT);			
				outtextxy(502+50,237,svtmp.MALOP);
				outtextxy(1102+50,237,svtmp.PHAI);
				outtextxy(202,297,NienKhoa);
				outtextxy(752,297,HocKy);
			}
			if(KT_Svdk_chua(l2.data[x]->DSSVDK.head,sv.MASV)==true)
			{
				ThongBao(500,200,900,400,MauTrang,550,220,"SV da co trong danh sach!");
				sleep(1);
				Window4();
				setbkcolor(MauTrang);
				PrintList_LTCDK4(l2,trangso,NienKhoa,HK,Root);
				STT4(40,330,trangso);
		//	cout <<LTC.DSSVDK.head->data.MASV;
				outtextxy(402,147,sv.MASV);	
				// xuat lai thong tin phia tren 	
				
				outtextxy(122+50,237,svtmp.HO);			
				outtextxy(802+50,237,svtmp.SDT);			
				outtextxy(502+50,237,svtmp.MALOP);
				outtextxy(1102+50,237,svtmp.PHAI);
				outtextxy(202,297,NienKhoa);
				outtextxy(752,297,HocKy);
			}
			else
			{
			Them_SVDK_vaoLTC4(l2.data[x]->DSSVDK, sv);
			ThongBao(500,200,900,400,MauTrang,550,220,"Dang ki thanh cong!");
			sleep(1);
			Window4();
			setbkcolor(MauTrang);
			PrintList_LTCDK4(l2,trangso,NienKhoa,HK,Root);
			STT4(40,330,trangso);
				outtextxy(402,147,sv.MASV);	
				// xuat lai thong tin phia tren 	
				
				outtextxy(122+50,237,svtmp.HO);			
				outtextxy(802+50,237,svtmp.SDT);			
				outtextxy(502+50,237,svtmp.MALOP);
				outtextxy(1102+50,237,svtmp.PHAI);
				outtextxy(202,297,NienKhoa);
				outtextxy(752,297,HocKy);
		    }
		}
			delay(0.001); 
   }
}

