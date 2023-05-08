#include <iostream>
#include <mem.h>
#include <string.h>
#include<conio.h>
using namespace std;
#define MAX 100
struct sinhvien {
  char mslop[5];
  char hoten[35];
  float toan;
  float hoa;
  float ly;
} danhsach[MAX];
int n = 0;
void nhapmoi()
{ char mslop[5], tmp[3];
  int i;
  do {
    cout<<"\nCho biet ma so lop(khac rong) : ";
    gets(mslop);
    if (strlen(mslop))
    { strcpy(danhsach[n].mslop, mslop);
      cout<<"\nCho biet ho ten : ";
      gets(danhsach[n].hoten);
      cout<<"\nDiem toan : ";
      cin>>danhsach[n].toan;
      cout<<"\nDiem hoa : ";
      cin>>danhsach[n].hoa;
	  cout<<"\nDiem ly : ";
      cin>>danhsach[n].ly;  
      gets(tmp);
      n++;
    }
  } while (strlen(mslop));
}

void timkiem()
{
  char mslop[5];
  int i = 0, found = 0;
  cout<<"\nCho biet ma so lop : ";
  gets(mslop);
  if (strlen(mslop))  //ma lop khac rong
    while (i<n)
      if (stricmp(danhsach[i].mslop, mslop) == 0)
      {
         cout<<"\nMa so lop : "<<danhsach[i].mslop;
         cout<<"\nHo va ten : "<<danhsach[i].hoten;
         cout<<"\nDiem Toan : "<< danhsach[i].toan;
         cout<<"\nDiem Ly   : "<< danhsach[i].ly;
         cout<<"\nDiem Hoa  : "<< danhsach[i].hoa;
         found = 1;
         break;
      }
      else
        i++;
  if (found==0)
    cout<<"\nKhong tim thay!!!";
}

void xoa()
{
  char mslop[5], traloi;
  int i = 0, j;
  cout<<"\nCho biet ma so lop : ";
  gets(mslop);
  if (strlen(mslop))
    while (i<n)
      if (stricmp(danhsach[i].mslop, mslop) == 0)
      {
         cout<<"\nMa so lop : "<<danhsach[i].mslop;
         cout<<"\nHo va ten : "<<danhsach[i].hoten;
         cout<<"\nDiem Toan : "<< danhsach[i].toan;
         cout<<"\nDiem Ly   : "<< danhsach[i].ly;
         cout<<"\nDiem Hoa  : "<< danhsach[i].hoa;
         cout<<"\nCo muon xoa khong (C/K)? ";
         do {
           traloi = toupper(getch());
         } while (traloi != 'C' && traloi != 'K');
         putc(traloi, stdout);
         if (traloi == 'C')
         {
           n--;
           memcpy(&danhsach[i], &danhsach[i+1], sizeof(struct sinhvien) * (n-i));
           break;
         }
      }
      else
        i++;
}

void menu()
{
	char traloi;
  cout<<"\n***************";
  cout<<"\n* 1. Them     *";
  cout<<"\n* 2. Xoa      *";
  cout<<"\n* 3. Tim kiem *";
  cout<<"\n* 0. Thoat    *";
  cout<<"\n***************";
  cout<<"\nChon lua ? ";
  }
int main()
{
  char traloi;
  do {
    menu();
    do {
      traloi = getch();
    } while (traloi < '0' || traloi > '3');
    putc(traloi, stdout);
    switch (traloi)
    {
       case '1' : nhapmoi();
                  break;
       case '2' : xoa();
                  break;
       case '3' : timkiem();
                  break;
    }
  } while (traloi != '0');
  return 0;
}

