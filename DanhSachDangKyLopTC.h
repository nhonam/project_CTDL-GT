//danh sach sinh vien dang ki4
#pragma once

#include"DanhSachSinhVien.h"
#include"DanhSachMonHoc.h"

#include<iostream>
#include<fstream>
#include<string.h>
#define MAX_MASV 15 

using namespace std;

//khai bao danh sach sinh vien dang ki : danh sach lien ket don 
struct SINH_VIEN4{
	char MASV[MAX_MASV];
 	float DIEM;
}; 
 struct sv_dang_ky {
 	SINH_VIEN4 data; 
 	sv_dang_ky* pNext;
 };
 typedef struct sv_dang_ky SV_DANG_KY;
 
 struct dssv_dang_ky {
 	SV_DANG_KY* head=NULL;
 	SV_DANG_KY* tail=NULL;
 };
 typedef struct dssv_dang_ky DS_SV_DANG_KY;
 

 bool KT_Svdk_chua(sv_dang_ky *first,char maSV[])
{
	for(sv_dang_ky *k=first;k!=NULL;k=k->pNext)
	{
		if(strcmp(k->data.MASV,maSV)==0)
		return true;
	}
	return false;
}

void CreateDsSVDK(DS_SV_DANG_KY &l) {
 	l.head=NULL;
 	l.tail=NULL;
 }
 
 
SV_DANG_KY* CreateNode4(SINH_VIEN4 sv4) {
	SV_DANG_KY* node=new SV_DANG_KY();
	node->data=sv4;
	node->pNext=NULL;
	return node;
}

void Add_Head4(DS_SV_DANG_KY &l, SV_DANG_KY *node) {
		if(l.head==NULL) {
		l.head=node;
		l.tail=node; 
	} 
	else {
		node->pNext=l.head;
		l.head=node; 
	} 
	
}

int SoLuongSVDK(DS_SV_DANG_KY l)
{
	int i=0;
//	cout <<l.head->data.MASV;
	SV_DANG_KY *run;
	for(run=l.head;run!=NULL;run=run->pNext)
	{
		i++;
	}
	return i;
}
void Add_Tail4(DS_SV_DANG_KY &l, SV_DANG_KY *node) {
		if(l.head == NULL) {
		l.head=node;
		l.tail=node; 
	} 
	else {
		l.tail->pNext = node;
		l.tail = node; 
	} 
}

void InsertAfterQ(DS_SV_DANG_KY& l, SV_DANG_KY* p,SV_DANG_KY* q) // chen not p vao sau not q  
{
	if (q != NULL)
	{
		p->pNext = q->pNext;
		q->pNext = p;
		if (l.tail == q)
			l.tail = p;
	}
	else
		Add_Head4(l, p);
}
bool RemoveHead(DS_SV_DANG_KY &l, SINH_VIEN4 &s) { // xoa sinh vien dau danh sach 
	if(l.head!=NULL) {
		SV_DANG_KY* node=l.head;
		s=node->data; // luu thong tin sinh vien 
		l.head=node->pNext;
		delete node; //xoa node
		if(l.head==NULL) l.tail=NULL;
		return true;
	} 
	return false;
} 

int RemoveAfterQ( DS_SV_DANG_KY &l, SV_DANG_KY* q, SINH_VIEN4 &s)// xoa sinh vien sau sinh vien q
{
	if (q != NULL)
	{
		SV_DANG_KY* p = q->pNext;
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

SV_DANG_KY* Search4(DS_SV_DANG_KY l,SINH_VIEN4 sv)
{
  SV_DANG_KY *pTmp=l.head;
  
  while(pTmp!=NULL)
  {

    if(strcmp(pTmp->data.MASV,sv.MASV)==0) 
   {
   	return pTmp;
	  }   
    pTmp=pTmp->pNext; // chua tìm th?y thì ti?p t?c duy?t ph?n t? k?t ti?p
  }
  return NULL;
}
bool KT_Svdk_chua(DS_SV_DANG_KY ds,char maSV[])
{
	for(SV_DANG_KY *k=ds.head;k!=NULL;k=k->pNext)
	{
		if(strcmp(k->data.MASV,maSV)==0)
		return true;
	}
	return false;
}
SV_DANG_KY* Search4_theoMasv(DS_SV_DANG_KY &l,char sv[15])
{

  SV_DANG_KY *pTmp=l.head; 
  while(pTmp!=NULL)
  {
    if(strcmp(pTmp->data.MASV,sv)==0) 
   {
   	return pTmp;
	  }   
    pTmp=pTmp->pNext; // chua tìm th?y thì ti?p t?c duy?t ph?n t? k?t ti?p
  }
  return NULL;
}
void swap(SINH_VIEN4 &sv1, SINH_VIEN4 &sv2)// hoan doi data 2 sinh vien  
{
	SINH_VIEN4 sv=sv1;
	sv1=sv2;
	sv2=sv; 
 } 
void Selection_Sort(DS_SV_DANG_KY &l)// sap xep sinh vien theo diem tang dan  
{   SV_DANG_KY  *p, *q, *pmin;
	float min;

	for(p = l.head; p->pNext != NULL; p = p->pNext)
	{	min = p->data.DIEM;
		pmin = p;
		for(q = p->pNext; q != NULL; q = q->pNext)
			if(q->data.DIEM  < min )
			{
				min = q->data.DIEM;
				pmin = q;
			}
		// hoan doi truong info cua hai nut p va pmin
		swap(p->data,pmin->data); 
	}
}
int Length(DS_SV_DANG_KY l)// dem so phan tu trong danh sach 
{
	int count = 0;
	SV_DANG_KY* node = l.head;
	while (node != NULL)
	{
		count++;
		node = node->pNext;
	}
	return count;
}


