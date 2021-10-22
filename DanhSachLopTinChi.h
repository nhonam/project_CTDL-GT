#pragma once
using namespace std;
#include<iostream>
#include<string.h>
#include<fstream>
#define MAX_MAMH 10
#define MAX_TENMH 50 
#define MAX_MASV 15 
#define MAX_MA_LOP 15 
#define MAX_PHAI 5 
#define MAX_SDT 11 
#define MAX_HO 20
#define MAX_TEN 15
#define MAX_NIEN_KHOA 10
#define MAX_LOP_TIN_CHI 10000
#include"DanhSachDangKyLopTC.h"
#include"DanhSachSinhVien.h"
//#include"DanhSachMonHoc.h"
using namespace std;
 //typedef struct dssv_dang_ky DS_SV_DANG_KY;

//khai bao
struct lop_tin_chi {
 	int MALOPTC;
 	char MAMH[MAX_MAMH];
 	char NIEN_KHOA[MAX_NIEN_KHOA];
 	int HOC_KY;
 	int NHOM;
 	int SO_SV_MAX;
 	int SO_SV_MIN;
 	DS_SV_DANG_KY DSSVDK;// danh sach4
 	bool HUY_LOP;
 	int tong_sv_dk;
 };
 typedef struct lop_tin_chi LOP_TIN_CHI;
 struct ds_lop_tin_chi {
 	LOP_TIN_CHI *data[MAX_LOP_TIN_CHI];
 	int n=0;
 };
 typedef ds_lop_tin_chi DS_LOP_TIN_CHI;
 //het khai bao 


//file lop tin chi + DS sinh vien DK
void WriteFileLTC(char *FileName,LOP_TIN_CHI &ltc)  
{
	FILE *f;      	
	f=fopen(FileName,"ab");  
	fwrite(&ltc,sizeof(ltc),1,f);//viet lop tin chi vao trong file
	int n=SoLuongSVDK(ltc.DSSVDK);// so luong sv dang ki
	fwrite(&n,sizeof(n),1,f);//luu so luong sinh vien dang ki vo file
	for(SV_DANG_KY* k=ltc.DSSVDK.head;k!=NULL;k=k->pNext)
		fwrite(&k->data,sizeof(k->data),1,f);// viet tung sv vo file
	fclose(f);
} 
void Read_File_LTC(char *FileName,DS_LOP_TIN_CHI &dsltc)
{
	FILE *f;   
	LOP_TIN_CHI ltc;   
	SINH_VIEN4 svdk;
	
	int n=0;//n so luong svdk
	f=fopen(FileName,"rb");
	while (fread(&ltc,sizeof(ltc),1,f))  
	{  
	//doc tu file de lay lop tin chi
		dsltc.data[dsltc.n]=new LOP_TIN_CHI;
		*dsltc.data[dsltc.n]=ltc;//gan lop tin chi vao dsltc[i]
	//	cout <<"0=+";
		dsltc.data[dsltc.n]->DSSVDK.head=NULL;
		fread(&n,sizeof(n),1,f);//doc tu file de lay so luong svdk
		for(int i=0;i<n;i++)
		{
			fread(&svdk,sizeof(svdk),1,f);//doc svdk trong file ra
			SV_DANG_KY *node=CreateNode4(svdk);
			Add_Head4(dsltc.data[dsltc.n]->DSSVDK,node);	
		}	
		if(!feof(f))//neu da o cuoi file thi ko tang so luong ltc 
		dsltc.n++;//tang so luong lop tin chi len 1
	}  	  
	
	fclose(f); 
	
}
void vietLTCvaofile(DS_LOP_TIN_CHI &dsltc)
{
	for(int i=0;i<dsltc.n;i++)//duyet danh sach lop tin chi de viet vao file
	{
		WriteFileLTC("DSLoptinchi24.txt",*dsltc.data[i]);

	}
}
void Xuat1Sv2(int x1,int y1,int x2,int y2,LOP_TIN_CHI l, Tree_MON_HOC Root) // xuat thong tin lop tc 
{	
		setbkcolor(15);
//		strcat(node->data.HO, " ");
//		strcat(node->data.HO, node->data.TEN);
		outtextxy(x2+20,y1+1,l.MAMH);
		
		MON_HOC MH=search11(Root,l.MAMH);
		outtextxy(x2+100,y1+1,MH.TENMH);
		
		outtextxy(x2+300,y1+1,l.NIEN_KHOA);
		
  	    char s[10];
    	itoa(l.HOC_KY,s,10);// chuyen doi kieu int sang char
		outtextxy(x2+600,y1+1,s);
		
		itoa(l.NHOM,s,10);
		outtextxy(x2+780,y1+1,s);
		
		itoa(l.SO_SV_MAX,s,10);
		outtextxy(x2+920,y1+1,s);
		
		itoa(l.SO_SV_MIN,s,10);
		outtextxy(x2+1070,y1+1,s);

	
}
void them_test(DS_LOP_TIN_CHI &ds,LOP_TIN_CHI Ltc){
		int j, k;
	if (ds.n ==0 )
	{
		ds.data[0]=new LOP_TIN_CHI;
		*ds.data[0]=Ltc;
		ds.data[ds.n]->MALOPTC=rand()%(10000);
		ds.n++;
	}
	else{
		for (j=0; j < ds.n && ds.data[j]->HOC_KY<=Ltc.HOC_KY ; j++ );
	for ( k = ds.n-1; k >=j  ; k--) 
	   ds.data[k+1]= ds.data[k];
	ds.data[j]= new LOP_TIN_CHI;
	*ds.data[j]=Ltc;
	ds.data[ds.n]->MALOPTC=ds.data[ds.n-1]->MALOPTC+1;
	 ds.n++;
	}	
}
void Them_LopTC(DS_LOP_TIN_CHI &l2,LOP_TIN_CHI Ltc)
{

	l2.data[l2.n]=new LOP_TIN_CHI;
	*l2.data [l2.n]=Ltc;	
	if(l2.n==0)
	l2.data[l2.n]->MALOPTC=rand()%(10000);// random 1 so tu 0->9999|||Ð? l?y s? ng?u nhiên t? a d?n b, ta s? d?ng a + rand()%(b-a+1)
	else l2.data[l2.n]->MALOPTC=l2.data[l2.n-1]->MALOPTC+1;

//	cout <<l2.data[l2.n]->MALOPTC<<"***";
	l2.n++;
}
void PrintList2(DS_LOP_TIN_CHI l2, int trangso,Tree_MON_HOC Root) // in ra list
{
	int x1=40,y1=330,x2=120,y2=360;
	for(int i=0;i<l2.n;i++)
	{
		if(i>=10*(trangso-1)&&i<10*trangso)
		{
		Xuat1Sv2(x1,y1,x2,y2,*l2.data[i],Root);
			y1=y1+30;
		}
	}
}
int Search_LTC(DS_LOP_TIN_CHI &ds, LOP_TIN_CHI x) {
  for (int i =0; i < ds.n ; i++)
     if (ds.data[i]->HOC_KY==x.HOC_KY&&ds.data[i]->SO_SV_MAX==x.SO_SV_MAX&&ds.data[i]->SO_SV_MIN==x.SO_SV_MIN&&strcmp(ds.data[i]->MAMH,x.MAMH)==0&&ds.data[i]->NHOM==x.NHOM) return i;
  return -1;
}

void Searh_ID(DS_LOP_TIN_CHI &ds,int id, LOP_TIN_CHI &LTC, int trangso)
{
	for(int i=0;i<ds.n;i++)
	{
		if(i==(trangso-1)*10+id)
		{
			LTC=*ds.data[i];
		}
	}
}

void Xoa_LTC(DS_LOP_TIN_CHI &ds, LOP_TIN_CHI LTC){
   int i = Search_LTC(ds,LTC) ;
  // if (i==-1) BaoLoi("Ma so sinh vien khong co trong danh sach");
    
    delete ds.data[i];
   if(i!=-1)
   {
   	 for (int j=i+1; j <ds.n; j++)
       ds.data[j-1]=ds.data[j];
       
     ds.n--;  
	
   }
    
}

int Xoa1(DS_LOP_TIN_CHI &ds, LOP_TIN_CHI Ltc)// neu da co du sinh vien dang ki thi k dc xoa lop tin chi
{


		int sl=SoLuongSVDK(Ltc.DSSVDK);
		if(sl>=Ltc.SO_SV_MIN)
		{
			return 1;// khong duoc xoa 
		}
	
	return -1;// se xoa duoc
}

void Huy_Lop_TC(DS_LOP_TIN_CHI &ds)// neu so luong sinh vien dang ki it hon so luong sv min thi xoa lop tin chi 
{
	int sl=0;
	for(int i=0;i<ds.n;i++)
	{
		sl=SoLuongSVDK(ds.data[i]->DSSVDK);
		if(sl<ds.data[i]->SO_SV_MIN)
		{
			Xoa_LTC(ds,*ds.data[i]);
		}
	}
}

