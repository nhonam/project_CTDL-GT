//DANH SACH SINH VIEN (3) DANH SACH LIEN KET DON 
#pragma once
#include<fstream> 

#include<iostream> 
#include<string.h> 
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
using namespace std;
//KHAI BAO SINH VIEN : danh sach lien ket don 
 struct sinh_vien {
 	char MASV[MAX_MASV];
 	char HO[MAX_HO];
 	char TEN[MAX_TEN];
 	char PHAI[MAX_PHAI];
 	char SDT[MAX_SDT];
 	char MALOP[MAX_MA_LOP];
 };
 typedef struct sinh_vien SINH_VIEN;
 struct node_sinh_vien{
 	SINH_VIEN data;
	struct node_sinh_vien* pNext;
 };
 typedef node_sinh_vien NODE_SINH_VIEN;
 struct ds_sinh_vien {
 	NODE_SINH_VIEN *head=NULL;
 	NODE_SINH_VIEN *tail=NULL; 
 	int tongSV;
 };
void CreateDs_SV(ds_sinh_vien &l){
	l.head=NULL;
	l.tail=NULL; 
} 
 
NODE_SINH_VIEN* CreateNode(SINH_VIEN sv) {// khoi tao mot sinh vien  
	NODE_SINH_VIEN* NODE=new NODE_SINH_VIEN();
	NODE->data=sv;
	NODE->pNext=NULL;
	return NODE; 
}

void Add_Head(ds_sinh_vien &l, NODE_SINH_VIEN *node) { // them 1 sinh vien vao cuoi danh sach   
	if(l.head==NULL) {
		l.head=node;
		l.tail=node; 
	} 
	else {
		node->pNext=l.head;
		l.head=node; 
	} 
} 

void Add_Tail(ds_sinh_vien &l,NODE_SINH_VIEN *node) {// them 1 sinh vien vao cuoi danh sach  
	if(l.head == NULL) {
		l.head=node;
		l.tail=node; 
	} 
	else {
		l.tail->pNext = node;
		l.tail = node; 
	} 
} 
void InsertAfterQ(ds_sinh_vien& l, NODE_SINH_VIEN* p, NODE_SINH_VIEN* q) // chen not p vao sau not q  
{
	if (q != NULL)
	{
		p->pNext = q->pNext;
		q->pNext = p;
		if (l.tail == q)
			l.tail = p;
	}
	else
		Add_Head(l, p);
}

bool RemoveHead(ds_sinh_vien &l, SINH_VIEN &s) { // xoa sinh vien dau danh sach 
	if(l.head!=NULL) {
		NODE_SINH_VIEN* node=l.head;
		s=node->data; // luu thong tin sinh vien 
		l.head=node->pNext;
		delete node; //xoa node
		if(l.head==NULL) l.tail=NULL;
		return true;
	} 
	return false;
} 

int RemoveAfterQ(ds_sinh_vien &l, NODE_SINH_VIEN* q, SINH_VIEN &s)// xoa sinh vien sau sinh vien q
{
	if (q != NULL)
	{
		NODE_SINH_VIEN* p = q->pNext;
		if (p != NULL)
		{
			if (l.tail == p)
				l.tail = q;
			q->pNext = p->pNext;
			s = p->data;
			delete p;
			return 1;
		}
		return 0;
	}
	return 0;
}
SINH_VIEN Search31(ds_sinh_vien l,char sv[])
{
  NODE_SINH_VIEN *pTmp=l.head; 

  while(pTmp!=NULL)
  {
    if(strcmp(pTmp->data.MASV,sv)==0) 
   {
   	return pTmp->data;//return sinh vien 
	  }   
    pTmp=pTmp->pNext;
  }
  return pTmp->data; // return NULL;
}

int Search32(ds_sinh_vien l,char sv[])
{
  NODE_SINH_VIEN *pTmp=l.head; 

  while(pTmp!=NULL)
  {
    if(strcmp(pTmp->data.MASV,sv)==0) 
   {
   	return 1;//return sinh vien 
	  }   
    pTmp=pTmp->pNext;
  }
  return -1; // return NULL;
}

NODE_SINH_VIEN* Search3(ds_sinh_vien l,SINH_VIEN sv)
{
  NODE_SINH_VIEN *pTmp=l.head; 
 
  while(pTmp!=NULL)
  {
    if(strcmp(pTmp->data.MASV,sv.MASV)==0) 
   {
   	return pTmp;
	  }   
    pTmp=pTmp->pNext; // chua tim thay thi tiep tuc duyet
  }
  return pTmp; // return NULL;
}

NODE_SINH_VIEN* Search_3(ds_sinh_vien l,char sv[])
{
  NODE_SINH_VIEN *pTmp=l.head; 
  
  while(pTmp!=NULL)
  {
    if(strcmp(pTmp->data.MASV,sv)==0) 
   {
   	return pTmp;
	  }   
    pTmp=pTmp->pNext; 
  }
  return NULL; // return NULL;
}

void Xuat1Sv(int x1,int y1,int x2,int y2,NODE_SINH_VIEN *node) // xuat thong tin 1 sinh vien 
{	
		setbkcolor(15);
//	strcat(node->data.HO, " ");
//	strcat(node->data.HO, node->data.TEN);
		outtextxy(x2+20,y1+1,node->data.HO);
		
		outtextxy(x2+300,y1+1,node->data.TEN);
	
		outtextxy(x2+470,y1+1,node->data.MASV);
		
		outtextxy(x2+680,y1+1,node->data.MALOP);
	
		outtextxy(x2+920,y1+1,node->data.SDT);
		
		outtextxy(x2+1090,y1+1,node->data.PHAI);
	
}


void PrintList(ds_sinh_vien l, int trangso, char MA_LOP[15]) // in ra list
{
	int i=1;
	if (l.head != NULL)
	{
		int x1=40,y1=330,x2=120,y2=330;
		NODE_SINH_VIEN* node = l.head;
		for(node = l.head;node!=NULL;node=node->pNext)
		{
			if(strcmp(node->data.MALOP,MA_LOP)==0) 
			{
				if(i>10*(trangso-1)&&i<=10*trangso)
				{
					Xuat1Sv(x1,y1,x2,y2,node);
					y1=y1+30;
	    		};
	    		i++;
			}
			
		}
   }
}


void xoa_SV(ds_sinh_vien &list, char d[20]){ // xoa bang ma sinh vien
  node_sinh_vien *pDel = list.head; // tao mot node pdel de xoa
  //danh sach rong thi khong lam gi
  if(pDel == NULL)
    {
	}
  //k rong thi xet dieu kien
  else{
    node_sinh_vien *pPre = NULL;
    //dung while tìm ra pDel và pPre (vi tri truoc pDel)
    while(pDel != NULL){
      if(strcmp(pDel->data.MASV, d)==0){
        break;
      }
      pPre = pDel;
      pDel = pDel->pNext;
    }
    //khong tim thay de xoa
    if(pDel == NULL)
    {
    	
	}
    //xet dieu kien
    else{
      //xoa dau danh sach
      if(pDel == list.head){
        list.head = list.head -> pNext;
        pDel -> pNext = NULL;
        delete pDel;
        pDel = NULL;
      }
      //xoa cuoi danh sach
      else if(pDel -> pNext == NULL){
        list.tail = pPre;
        pPre -> pNext = NULL;
        delete pDel;
        pDel = NULL;
      }
      // xoa giua danh sach
      else{
        pPre -> pNext = pDel -> pNext;
        pDel -> pNext = NULL;
        delete pDel;
        pDel = NULL; 
      }
    }
  }
}
void Tim_SV_Table(ds_sinh_vien l, int id, SINH_VIEN &sv,char MaLop[15])
{
	for(node_sinh_vien *k=l.head;k!=NULL;k=k->pNext)
		if(strcmp(k->data.MALOP,MaLop)==0)
		{

			if(id==1)
			{
				sv=k->data;
				break;
			}
			id--;
			
		}
   
}
void swap(SINH_VIEN &sv1, SINH_VIEN &sv2)// hoan doi data 2 sinh vien  
{
	SINH_VIEN sv=sv1;
	sv1=sv2;
	sv2=sv; 
 } 
void Selection_Sort(ds_sinh_vien &l)// sap xep sinh vien theo ten tang dan
{   NODE_SINH_VIEN  *p, *q, *pmin;
	char min[70];

	for(p = l.head; p->pNext != NULL; p = p->pNext)
	{	strcpy(min,p->data.TEN);
		pmin = p;
		for(q = p->pNext; q != NULL; q = q->pNext)
			if(strcmp(q->data.TEN, min) <0 )
			{
				strcpy(min,p->data.TEN);
				pmin = q;
			}
		// hoan doi truong info cua hai nut p va pmin
		swap(p->data,pmin->data); 
	}
}

 
int Length(ds_sinh_vien l)// dem so phan tu trong danh sach 
{
	int count = 0;
	NODE_SINH_VIEN* node = l.head;
	while (node != NULL)
	{
		count++;
		node = node->pNext;
	}
	return count;
}

void ThemSVvaolop(ds_sinh_vien &ds,SINH_VIEN &SV) // them vao lop co thu tu 
{
	NODE_SINH_VIEN *truoc=NULL;
	NODE_SINH_VIEN *p=CreateNode(SV);
	if(ds.head==NULL)
	{
		ds.head=p;
	}
	else		
	for(NODE_SINH_VIEN *k=ds.head;k!=NULL;k=k->pNext)
	{
		if(stricmp(k->data.MALOP,SV.MALOP)==0)//tim kiem lop de them
		{
			for (; k != NULL; k = k->pNext)
			{					
				if (stricmp(p->data.TEN,k->data.TEN)<0||stricmp(k->data.MALOP,SV.MALOP)!=0)
				//ten sv p <ten sv k thi them sao ds o vi tri truoc k||va malop cua sv k bang voi key
				{
					if(truoc==NULL)
					{
						Add_Head(ds,p);	
						break;
					}
					else
					{
						p->pNext=k;
						truoc->pNext=p;
						break;
					}		
				}
				else if(stricmp(p->data.TEN,k->data.TEN)==0)
				{
					 if(stricmp(p->data.HO,k->data.HO)<0&&truoc!=NULL)
					{
						p->pNext=k;
						truoc->pNext=p;
						break;
					}	
					else if(stricmp(p->data.HO,k->data.HO)<0&&truoc==NULL)
					{
						Add_Head(ds,p);	
						break;
					}			
				}
				if(k->pNext==NULL)
				{
					k->pNext = p; //them vao cuoi ds
					break;
				}
				truoc=k;
			}	
			break;
		}
		else if(k->pNext==NULL)
		{
			k->pNext=p;
			break;
		}
		truoc=k;
	}
}

//doc ghi file 
void WriteFileSV(char *FileName,SINH_VIEN SV)  // moi file khota
{  
	FILE *f;      	
	f=fopen(FileName,"ab");  
	fwrite(&SV,sizeof(SV),1,f); 
	fclose(f);   
}  
void ReadFile(char *FileName, ds_sinh_vien &l) // doc file luu vo danh ds lien ket
{
		FILE *f;   
		SINH_VIEN SV;   
	f=fopen(FileName,"rb");
	fread(&SV,sizeof(SV),1,f); 
	while (!feof(f))  
	{  
	NODE_SINH_VIEN* p = CreateNode(SV);
		Add_Tail(l,p);
		fread(&SV,sizeof(SV),1,f);  
	}  	  
	fclose(f); 
}
void WriteFile(ds_sinh_vien &l)// ghi tu ds lien ket vo file
{
	NODE_SINH_VIEN *run=l.head;
	for(NODE_SINH_VIEN *k=l.head;k!=NULL;k=k->pNext)
	{
		WriteFileSV("filesanhsachsv3.txt",k->data);
	}
}
void Set_MapID_table(int **mapID)
{
	int x=-1,y=-1;
		//set map id cho bang	
		int x1=40,y1=330,x2=1320,y2=360;
		for(int i=1;i<=10;i++)
		{
			taoTextInput(x1,y1,x2,y2,i,mapID);
			y1=y1+30;
			y2=y2+30;
		}
}
void reset_MapID_table(int **mapID)
{
	int x=-1,y=-1;
		//set map id cho bang	
		int x1=40,y1=330,x2=1320,y2=360;
		for(int i=1;i<=10;i++)
		{
			Taoid(x1,y1,x2,y2,0,mapID);
			y1=y1+30;
			y2=y2+30;
		}
}

