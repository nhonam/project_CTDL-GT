#pragma once
void resetMapID(int **mapID)
{
	 
	for (int i=0;i<1500;i++)
	{
		for (int j=0;j<800;j++)
		mapID[i][j]=0;
	}
}
void STT(int x, int y, int trangso)
{	char s[3];
	int y1=330;
	for(int i=1;i<100;i++)
	{
		if(i>10*(trangso-1)&&i<=10*trangso)
		{
		itoa(i,s,10);
		outtextxy(x+30,y1+5,s);
		y1=y1+30;
		};
	}
}
void setIDvung(int x1, int y1, int x2, int y2, int id, int **mapID)
{

	for (int i=x1;i<x2;i++)
	{
		for (int j=y1;j<y2;j++)
		mapID[i][j]=id;
	}
}
char *Chuan_Hoa(char *a)// chuan hoa nhap vao, chuyen thanh dang Anh Em Oi  
{
    strlen(a);
	int start=0;
	char *res='\0';
	while(start< strlen(a) && a[start]==' ') start++;
	if(start== strlen(a)) return res;
	if(a[start]>='a'&&a[start<='z']) a[start]+='A'-'a';
	res+=a[start];
	for(int i=start+1;i< strlen(a);i++)
	{
		if(a[i-1]!=' '&&a[i]!=' ')
		{
			if(a[i]>='A'&&a[i]<='Z') a[i]+='a'-'A';
			res+=a[i];
		}
		else if(a[i-1]==' '&&a[i]!=' ') {
			if(a[i]>='a'&&a[i]<='z') a[i]+='A'-'a';
			res+=a[i];
		}
	}
	int i,j;
	int n=strlen(a);
		for(i=0;i<n;i++)
		{
		if((a[i]==' ')&&(a[i+1]==' '))
		{
			for(j=i;j<n;j++)
			{
				a[j]=a[j+1];
			}
			n--;
			i--; 
		}
	}
		
	return res;
}
void *INHOA(char *a){
	strupr(a);
	return a;
}
void Taoid(int x1,int y1,int x2,int y2, int id,int **mapid) {
	for(int i=y1;i<y2;i++)
		for(int j=x1;j<x2;j++)
			mapid[i][j]=id;	
}
void taoTextInput(int x1,int y1,int x2,int y2, int id,int **mapid) {
	 
	setcolor(MauDen);
	setbkcolor(MauTrang);
//	bar(x1,y1,x2,y2) ;
	rectangle(x1,y1,x2,y2);
	for(int i=y1;i<y2;i++)
		for(int j=x1;j<x2;j++)
			mapid[i][j]=id;	
}
void Nhap_SO_them_(int x, int y, char s[]) {// nhap so có them dau -
		int l=strlen(s) ;
	 s[l+1]='\0';
    s[l]='|';
//	setfillstyle()	 
     while(1){
       	
		outtextxy(x,y,s);
		
     	if(kbhit()){
	     	char c= getch();
	     	if('0'<=c&&c<='9')
	     	{
		     	s[l]=c;
				 l++;
				 s[l+1]='\0';
				 outtextxy(x,y,s);
			}
			else if(c==8){// xoa
					s[l-1]='|';
					s[l]=' ';
					outtextxy(x,y,s);
					l--;
			} 
			else if(c==13) {// enter
				s[l]='\0';// xoa dau cach o cuoi chuoi  
				break; 
			} 	
		 }
		 else{
			s[l]='|';
			delay(100);
			outtextxy(x,y,s);
			s[l]=' ';
			delay(100);
			outtextxy(x,y,s);
		 
		}
	 } 
}
void Nhap_SO(int x, int y, char s[]) {
	setbkcolor(MauTrang);
		int l=strlen(s) ;
	 s[l+1]='\0';
    s[l]='|';
//	setfillstyle()	 
     while(1){
       	
		outtextxy(x,y,s);
		
     	if(kbhit()){
	     	char c= getch();
	     	if('0'<=c&&c<='9')
	     	{
		     	s[l]=c;
		     	
				 l++;
				 s[l+1]='\0';
				 outtextxy(x,y,s);
			}
			else if(c==8){// xoa
					s[l-1]='|';
					s[l]=' ';
					outtextxy(x,y,s);
					l--;
			} 
			else if(c==13) {// enter
				s[l]='\0';// xoa dau cach o cuoi chuoi  
				break; 
			} 	
		 }
		 else{
			s[l]='|';
			delay(100);
			outtextxy(x,y,s);
			s[l]=' ';
			delay(100);
			outtextxy(x,y,s);
		 
		}
	 } 
}
void Nhap_Pass(int x, int y , char s[])
{
	char a[15]="";
	int l=strlen(s) ;
	for(int i=0;i<l;i++)
	{
		a[i]='*';
	}
    s[l]='\0'; 
    a[l+1]='\0';
    while(1){
       	
		outtextxy(x,y,a);
		
     	if(kbhit()){
	     	char c= getch();
	     	if('a'<=c&&c<='z'||'A'<=c&&c<='Z'||'0'<=c&&c<='9')
	     	{
	     		if('a'<=c&&c<='z')
	     		{
	     			c=c-32;
				 }
		     	s[l]=c;
		     	a[l]='*';
				 l++;
				 s[l+1]='\0';
				a[l+1]='\0';
				 outtextxy(x,y,a);
			}
			else if(c==8){
				if(l>0)
				{
					a[l-1]='|';
					a[l]=' ';
					outtextxy(x,y,a);
					l--;	
				}	
			} 
			else if(c==13) {
				s[l]='\0';// xoa dau cach o cuoi chuoi 
				a[l]='\0'; 
				return; 
			}		 				  	
		 }
		 else{
			a[l]='|';
			delay(100);
			outtextxy(x,y,a);
			a[l]=' ';
			delay(100);		 
			outtextxy(x,y,a);		 
		}	
	 } 	
}
void Nhap_INHOA(int x, int y, char s[]) {
		int l=strlen(s) ;
	 s[l+1]='\0';
    s[l]='|';
//	setfillstyle()	 
     while(1){
       	
		outtextxy(x,y,s);
		
     	if(kbhit()){
	     	char c= getch();
	     	if('a'<=c&&c<='z'||'A'<=c&&c<='Z'||'0'<=c&&c<='9'||c==' '||c=='-')
	     	{
		     	s[l]=c;
				 l++;
				 s[l+1]='\0';
				 outtextxy(x,y,s);
			}
			else if(c==8){// xoa 
					s[l-1]='|';
					s[l]=' ';
					outtextxy(x,y,s);
					l--;
			} 
			else if(c==13) {// enter
				s[l]='\0';// xoa dau cach o cuoi chuoi  
				break; 
			} 	
		 }
		 else{
			s[l]='|';
			delay(100);
			outtextxy(x,y,s);
			s[l]=' ';
			delay(100);
			INHOA(s);
			outtextxy(x,y,s);
		 
		}
	 } 
}
void Nhap(int x, int y, char s[]) {// xy la vi tri xuat ra chu , s la chuoi can xuat ra
	int l=strlen(s) ;
	 s[l+1]='\0';
    s[l]='|';
//	setfillstyle()	 
     while(1){
       	
		outtextxy(x,y,s);
		
     	if(kbhit()){
	     	char c= getch();
	     	if('a'<=c&&c<='z'||'A'<=c&&c<='Z'||'0'<=c&&c<='9'||c==' '||c=='-')
	     	{
		     	s[l]=c;
				 l++;
				 s[l+1]='\0';
				 outtextxy(x,y,s);
			}
			else if(c==8){
					s[l-1]='|';
					s[l]=' ';
					outtextxy(x,y,s);
					l--;
			} 
			else if(c==13) {
				s[l]='\0';// xoa dau cach o cuoi chuoi  
				break; 
			} 	
		 }
		 else{
			s[l]='|';
			delay(100);
			outtextxy(x,y,s);
			s[l]=' ';
			delay(100);
			Chuan_Hoa(s); 
			outtextxy(x,y,s);
		 
		}
	 } 
}
void Nhap_diem(int x, int y, char s[]) {// xy la vi tri xuat ra chu , s la chuoi can xuat ra
	int l=strlen(s) ;
	 s[l+1]='\0';
    s[l]='|';
//	setfillstyle()	 
     while(1){
       	
		outtextxy(x,y,s);
		
     	if(kbhit()){
	     	char c= getch();
	     	if('0'<=c&&c<='9'||c=='.')
	     	{
		     	s[l]=c;
				 l++;
				 s[l+1]='\0';
				 outtextxy(x,y,s);
			}
			else if(c==8){
					s[l-1]='|';
					s[l]=' ';
					outtextxy(x,y,s);
					l--;
			} 
			else if(c==13) {
				s[l]='\0';// xoa dau cach o cuoi chuoi  
				break; 
			} 	
		 }
		 else{
			s[l]='|';
			delay(100);
			outtextxy(x,y,s);
			s[l]=' ';
			delay(100);
			Chuan_Hoa(s); 
			outtextxy(x,y,s);
		 
		}
	 } 
}
void Nhap_Khong_So(int x, int y, char s[]) {// nhap chu k duoc nhap so 
	int l=strlen(s) ;
	 s[l+1]='\0';
    s[l]='|';
//	setfillstyle()	 
     while(1){
       	
		outtextxy(x,y,s);
		
     	if(kbhit()){
	     	char c= getch();
	     	if('a'<=c&&c<='z'||'A'<=c&&c<='Z'||c==' '||c=='-')
	     	{
		     	s[l]=c;
				 l++;
				 s[l+1]='\0';
				 outtextxy(x,y,s);
			}
			else if(c==8){
					s[l-1]='|';
					s[l]=' ';
					outtextxy(x,y,s);
					l--;
			} 
			else if(c==13) {
				s[l]='\0';// xoa dau cach o cuoi chuoi  
				break; 
			} 	
		 }
		 else{
			s[l]='|';
			delay(100);
			outtextxy(x,y,s);
			s[l]=' ';
			delay(100);
			Chuan_Hoa(s); 
			outtextxy(x,y,s);
		 
		}
	 } 
}
