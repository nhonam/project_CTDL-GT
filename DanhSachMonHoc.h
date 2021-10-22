#pragma once
#include<iostream>
using namespace std;
#include<string.h>
#include "Define.h"

struct MON_HOC{
	char MAMH[MAX_MAMH];
	char TENMH[MAX_TENMH];
	int STCLT;
	int STCTH;
}; 

struct ds_mon_hoc {
	MON_HOC data;
	ds_mon_hoc* left;
	ds_mon_hoc* right;
};
typedef struct ds_mon_hoc* Tree_MON_HOC;


void Create_Tree(Tree_MON_HOC &t)
{
	t=NULL;
}
void Add_MonHoc(Tree_MON_HOC &t, MON_HOC mh)// them mon hoc vao cay
{
	if(t==NULL)
	{
		ds_mon_hoc *p=new ds_mon_hoc;// khoi tao 1 mon hoc de them vao cay
		p->data=mh;
		p->left=NULL;
		p->right=NULL;
		t=p;
	}
	else 
	{
		if(strcmp(t->data.MAMH,mh.MAMH)>0)// be hon thi dua qua trai
			Add_MonHoc(t->left,mh);
		else if(strcmp(t->data.MAMH,mh.MAMH)<0)// lon hon thi dua qua phai
			Add_MonHoc(t->right,mh);
	}
}

void Remove_Tree(Tree_MON_HOC &root)// xoa toan bo cay
{
	 if (root!=NULL)
    {
        Remove_Tree(root->left);
        Remove_Tree(root->right);
        delete root;
    }
}


Tree_MON_HOC minValueNode(Tree_MON_HOC node) // tim node be nhat cua tree truyen vo
{ 
	Tree_MON_HOC current = node; 

	while (current && current->left != NULL) 
		current = current->left; 

	return current; 
} 
Tree_MON_HOC deleteNode(Tree_MON_HOC root, char key[10]) 
{ 
	// caay trong
	if (root == NULL) return root; 

	
	// key can xoa be hon data cua node thi qua ben tren
	if (strcmp(key,root->data.MAMH)<0) 
		root->left = deleteNode(root->left, key); 

	//key can xoa lon hon data cua node thi qua ben phai
	else if (strcmp(key,root->data.MAMH)>0) 
		root->right = deleteNode(root->right, key); 

	// day la nut can xoa
	else
	{ 
		// node xoa la node la hoac la node co 1 node con
		if (root->left == NULL) //1 con
		{ 
			Tree_MON_HOC temp = root->right; 
			delete root; 
			return temp; 
		} 
		else if (root->right == NULL) //la
		{ 
			Tree_MON_HOC temp = root->left; 
			delete root;
			return temp; 
		} 

		//node can xoa co 2 node con
		Tree_MON_HOC temp = minValueNode(root->right); 

		// sao chep noi dung cua node lon hon vao node bi xoa
		root->data = temp->data; 

		// xoa node can xoa
		root->right = deleteNode(root->right, temp->data.MAMH); 
	} 
	return root; 
} 

void Xuat_MH(int x1,int y1,int x2,int y2,MON_HOC mh) // xuat thong tin 1 mon hoc 
{	
		char s[5]="";
		char a[5]="";
		setbkcolor(15);

		outtextxy(x2+10,y1+1,mh.MAMH);
	//	cout <<mh.MAMH;
		outtextxy(x2+350,y1+1,mh.TENMH);
		
		itoa(mh.STCLT,a,10);//
		outtextxy(x2+770,y1+1,a);
	//	puts(s);
		itoa(mh.STCTH,s,10);//
		outtextxy(x2+1000,y1+1,s);
}

void Tim_MonHoc_table(Tree_MON_HOC root,int id,MON_HOC &mh)// tim mon hoc tu id nhan duoc 
{
	ds_mon_hoc *pre;
	ds_mon_hoc *current=root;
	while (current)
    {
		if (!current->left)
    	{
			id=id-1;
			if(id==1)
			{
				mh=current->data;
			}
    	    current = current->right;
    	}
    	else
    	{
     		pre = current->left;
     		while (pre->right&&pre->right != current)
     		{
      			pre = pre->right;
     		}
     		if (!pre->right)
     		{
      			pre->right = current;
      			current = current->left;
     		}
     		else
     		{
     			id=id-1;
				if(id==1)
				{
					mh=current->data;
				}						
      			pre->right = NULL;
      			current = current->right;
     		}
    	}
   	}	
}

void LNR(Tree_MON_HOC root,int trangso)// in ds mon hoc theo trang so
{
	ds_mon_hoc *pre;
	ds_mon_hoc *current=root;
	int x1=40,y1=330,x2=120,y2=360;
	int i=1;
	while (current)
    {
		if (!current->left)
    	{
    		if(i>10*(trangso-1)&&i<=10*trangso)
    		{
    		
   			    	Xuat_MH(x1,y1,x2,y2,current->data);	y1=y1+30;
   			    //	cout <<current->data.MAMH<<endl;
			}
			i++;
			current = current->right;	
    	}
    	else
    	{
     		pre = current->left;
     		while (pre->right&&pre->right != current)
     		{
      			pre = pre->right;
     		}
     		if (!pre->right)
     		{
      			pre->right = current;
      			current = current->left;
     		}
     		else
     		{
     			if(i>10*(trangso-1)&&i<=10*trangso)
     			{
     				Xuat_MH(x1,y1,x2,y2,current->data);	y1=y1+30;
     			//	cout <<current->data.MAMH<<endl;
				}
				pre->right = NULL;
				i++;
				current = current->right;     			
     		}
    	}
   	}
}

MON_HOC search11( Tree_MON_HOC root, char key[10])
{ 
    if (root == NULL || strcmp(root->data.MAMH,key)==0)
       return root->data;
   
    if (strcmp(root->data.MAMH, key)<0)
       return search11(root->right,key);

    return search11(root->left, key);
}

Tree_MON_HOC search_11( Tree_MON_HOC root, char key[10])
{ 
    if (root == NULL || strcmp(root->data.MAMH,key)==0)
       return root;
   
    if (strcmp(root->data.MAMH, key)<0)
       return search_11(root->right,key);

    return search_11(root->left, key);
}

//doc ghi file mon hoc
void WriteFileMH(char *FileName,MON_HOC mh)  
{  
	FILE *f;      	
	f=fopen(FileName,"ab");  
	fwrite(&mh,sizeof(mh),1,f); 
	fclose(f);   
}  
void Read_File_Tree(char *FileName,Tree_MON_HOC &root)
{
	FILE *f;   
	MON_HOC monhoc;   	
	f=fopen(FileName,"rb");
	fread(&monhoc,sizeof(monhoc),1,f);  
	while (!feof(f))  
	{  
		 Add_MonHoc(root,monhoc);
		fread(&monhoc,sizeof(monhoc),1,f);  
	}  	  
	fclose(f); 
}
void vietMHvaofile(Tree_MON_HOC &root)
{
	if (root != NULL)
	{
		vietMHvaofile(root->left);
		WriteFileMH("monhoc.txt",root->data);
		vietMHvaofile(root->right);
	}
		
}


 
// begin : de tao danh sach tam de xuat mon hoc theo ten mon hoc abc

struct DS_MonHoc_Tmp {
 	MON_HOC *data[MAX_LOP_TIN_CHI];
 	int n=0;
 };

void chencothutu (DS_MonHoc_Tmp &ds, MON_HOC sv){
	int j, k;
	if (ds.n ==0 )
	{
		ds.data[0]=new MON_HOC;
		*ds.data[0]=sv;
		ds.n++;
	}
	else{
		for (j=0; j < ds.n && strcmp(ds.data[j]->TENMH, sv.TENMH)<0 ; j++ );
	for ( k = ds.n-1; k >=j  ; k--) 
	   ds.data[k+1]= ds.data[k];
	ds.data[j]= new MON_HOC;
	*ds.data[j]=sv; ds.n++;
	}	
}
void Them_tmp(DS_MonHoc_Tmp &l2,MON_HOC MH)
{

	l2.data[l2.n]=new MON_HOC;
	*l2.data [l2.n]=MH;	
	//	cout <<l2.n<<" | ";
//	cout <<l2.data[l2.n]->MALOPTC<<"***";
	l2.n++;
}
void DoVaoMang(Tree_MON_HOC root, DS_MonHoc_Tmp &ds){
	Tree_MON_HOC p;

	while( root ){
		if( root->left == NULL ){
		//	cout<< root->data << " ";
		
			chencothutu(ds,root->data);
	//	Them_tmp(ds,root->data);
			root = root->right;
		}
		else{
			p = root->left;
			while(p->right && p->right != root ){
				p = p->right;
			}
			if( p->right == NULL ){
				p->right = root;
			//	cout<< root->data << " ";
				root = root->left;
			}
			else{
				p->right = NULL;
				//	Them_tmp(ds,root->data);
				chencothutu(ds,root->data);
				root = root->right;
			}
		}
	}
}
void xuattmp(DS_MonHoc_Tmp l2, int trangso1)// xuat ds mon hoc tam
{
	int x1=40,y1=330,x2=120,y2=360;
	for(int i=0;i<l2.n;i++)
	{
		if(i>=10*(trangso1-1)&&i<10*trangso1)
		{
		Xuat_MH(x1,y1,x2,y2,*l2.data[i]);
		y1=y1+30;
		}
	}
}
void clearlist(DS_MonHoc_Tmp &plist)// xoa ds 
{
	plist.n = 0;
}

    

