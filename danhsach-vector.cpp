#include<iostream>
#include<stdlib.h>
using namespace std;
#define N 100 //so phan tu toi da la 100
typedef int item;
/*kieu cac phan tu la item
ma cu the o day item la kieu int */
typedef struct
{
    item Elems[N]; //mang kieu item
    int size; //so phan tu toi da cua mang
}List; //kieu danh sach List

void Init(List *L); //ham khoi tao danh sach rong
void Init(List *L); //ham khoi tao danh sach rong
int Isempty (List L); //kiem tra danh sach rong
int Isfull (List L); //kiem tra danh sach day
int Insert_k (List *L, item x, int k); //chen x vao vi tri k
void Input (List *L);//nhap danh sach
void Output (List L);//xuat danh sach
int Search (List L, item x); //tim phan tu x trong danh sach
int Del_k (List *L, item *x, int k);//xoa phan tu tai vi tri k
int Del_x(List *L, item x);//xoa phan tu x trong danh sach
item init_x(); //tao phan tu x.

//-----------------------------------

void Init(List *L) //ham khoi tao danh sach rong
/*Danh sach L duoc khai bao kieu con tro
de khi ra khoi ham no co the thay doi duoc*/
{
    (*L).size = 0; //size = 0.
}

int Isempty (List L)
{
    return (L.size==0);
}

int Isfull (List L)
{
    return (L.size==N);
}

int init_x() //khoi tao gia tri x
{   int tem;
     cin>>tem;
	return tem ;
}

int Insert_k (List *L, item x, int k)//chen x vao vi tri k
{
    if (Isfull(*L)) //kiem tra danh sach day
    {
        cout<<"Danh sach day !";
        return 0;
    }

    if (k<1 || k>(*L).size+1) //kiem tra dieu kien vi tri chen
    {
        cout<<"Vi tri chen khong hop le !\n";
        return 0;
    }
    cout<<"\nNhap thong tin: ";
    x = init_x(); //gan x = ham khoi tao x
    int i;
    //di chuyen cac phan tu ve cuoi danh sach
    for (i = (*L).size; i >= k; i--)
        (*L).Elems[i] = (*L).Elems[i-1];
        (*L).Elems[k-1]=x;//chen x vao vi tri k
        (*L).size++;//tang size len 1 don vi.
    return 1;
}

void Input (List *L)
{
    int n;
    cout<<"Nhap so phan tu cua danh sach: ";
    cin>>(*L).size;
    int i;
    for (i=0; i<(*L).size; i++)
    {
        cout<<"Nhap phan tu thu "<<i+1<<" :";
        (*L).Elems[i] = init_x();
    }
}

void Output (List L)
{
    cout<<"Danh sach: \n";
    int i;
    for (i=0; i<L.size; i++)
        cout<<L.Elems[i];
    cout<<"\n";
}

int Search (List L, item x)
{
    int i;
    for (i=0; i<L.size; i++)
        if (L.Elems[i] == x)
            return i+1;
    return 0;
}

int Del_k (List *L, item *x, int k)
{
    if (Isempty(*L))
    {
        cout<<"Danh sach rong !";
        return 0;
    }
    if (k<1 || k>(*L).size)
    {
        cout<<"Vi tri xoa khong hop le !";
        return 0;
    }
    *x=(*L).Elems[k-1]; //luu lai gia tri cua phan tu can xoa
    int i;
    for (i=k-1; i<(*L).size-1; i++) //don cac phan tu ve truoc
    	(*L).Elems[i]=(*L).Elems[i+1];
    (*L).size--; //giam size
    return 1;
}

int Del_x (List *L, item x)
{
    if (Isempty(*L))
    {
        cout<<"Danh sach rong !";
        return 0;
    }

    int i = Search(*L,x);
    if (!i)
    {
        cout<<"Danh sach khong co "<<x;
        return 0;
    }
    do
    {
        Del_k(L,&x,i);
        i = Search(*L,x);
    }
    while (i);
    return 1;
}


int main()
{
    List L;
    Init(&L);
    Input(&L);
    Output(L);

    int lua_chon;
    cout<<"Moi ban chon phep toan voi DS LKD:";
    cout<<"\n1: Kiem tra DS rong";
    cout<<"\n2: Do dai DS";
    cout<<"\n3: Chen phan tu x vao vi tri k trong DS";
    cout<<"\n4: Tim mot phan tu trong DS";
    cout<<"\n5: Xoa phan tu tai vi tri k";
    cout<<"\n6: Xoa phan tu x trong DS";
    cout<<"\n7: Thoat";
    do
    {
        cout<<"\nBan chon: ";
        cin>>lua_chon;
    switch (lua_chon)
    {
        case 1:
        {
            if (Isempty(L)) cout<<"DS rong !";
            else cout<<"DS khong rong !";
            break;
        }
        case 2: cout<<"Do dai DS la: "<<L.size;break;
        case 3:
        {
            item x;
            int k;
            cout<<"Nhap vi tri can chen: ";
            cin>>k;
            if (Insert_k(&L,x,k))
            {
                cout<<"DS sau khi chen:\n"; //xuat danh sach sau khi chen
                Output(L);
            }
            break;
        }
        case 4:
        {
            item x;
            cout<<"Moi ban nhap vao phan tu can tim: ";
            cin>>x;
            int k=Search(L,x);
            if (k) cout<<"Tim thay "<<x<<" trong DS tai vi tri thu: "<<k;
            else cout<<"Khong tim thay "<<x<<" trong danh sach !";
            break;
        }
        case 5:
        {
            int k;
            item x;
            cout<<"Nhap vi tri can xoa: ";
            cin>>k;
            if (Del_k (&L,&x,k))
            {
                cout<<"DS sau khi xoa:\n";
                Output(L);
            }
            break;
        }
        case 6:
        {
            item x;
            cout<<"Nhap phan tu can xoa: ";
            cin>>x;
            if (Del_x(&L,x))
            {
                cout<<"DS sau khi xoa:\n";
                Output(L);
            }
            break;
        }
        case 7: break;
    }
    }while (lua_chon !=7);
    return 0;
}

