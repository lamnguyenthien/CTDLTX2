//Chương trình cài đặt danh sách nối đơn-dùng con trỏ
#include<iostream>
#include<stdlib.h>
using namespace std;
typedef int item; //kieu cac phan tu dinh nghia la item
typedef struct Node //Xay dung mot Node trong danh sach
{
    item Data; //Du lieu co kieu item
    Node *next; //Truong next la con tro, tro den 1 Node tiep theo
};
typedef Node *List; //List la mot danh sach cac Node

void Init (List &L); //khoi tao danh sach rong
int len (List L); // Do dai danh sach
Node *Make_Node (Node *P, item x); //Tao 1 Node P voi thong tin chu trong no
void Insert_first (List &L, item x); //Chen phan tu vao dau danh sach
void Insert_k (List &L, item x, int k); //Chen phan tu vao vi tri k trong danh sach
void Input (List &L);//Nhap danh sach
void Output (List L);//Xuat danh sach
int Search (List L, item x); //Tim phan tu x trong danh sach, ham tre ve vi tri cua phan tu tim duoc
void Del_frist (List &L, item &x); //Xoa phan tu dau danh sach
void Del_k (List &L, item &x, int k); //Xoa phan tu vi tri k trong danh sach
void Del_x (List &L, item x);//Xoa phan tu co gia tri x trong danh sach

void Init (List &L) // &L lay dia chi cua danh sach ngay khi truyen vao ham
{
    L=NULL; //Cho L tro den NULL
}

int Isempty (List L)
{
    return (L==NULL);
}

int len (List L) 
{
    Node *P=L; //tao 1 Node P de duyet danh sach L
    int i=0; //bien dem
    while (P!=NULL) //trong khi P chua tro den NULL (cuoi danh sach thi lam)
    {
        i++; //tang bien dem
        P=P->next; //cho P tro den Node tiep theo
    }
    return i; //tra lai so Node cua l
}

Node *Make_Node (Node *P, item x) //tao 1 Node P chua thong tin la x 
{
    P = (Node *) malloc (sizeof (Node)); //Cap phat vung nho cho P
    P->next = NULL; //Cho truong Next tro den NULL
    P->Data = x; //Ghi du lieu vao Data
    return P; 
}

void Insert_first (List &L, item x)  //Chen x vao vi tri dau tien trong danh sach
{
    Node *P; 
    P = Make_Node(P,x); //tao 1 Node P
    P->next = L; //Cho P tro den L
    L = P; //L tro ve P
}

void Insert_k (List &L, item x, int k) //chen x vao vi tri k trong danh sach
{
    Node *P, *Q = L; 
    int i=1;
    if (k<1 || k> len(L)+1) cout<<"Vi tri chen khong hop le !"; //kiem tra dieu kien
    else
    {
        P = Make_Node(P,x); //tao 1 Node P
        if (k == 1) Insert_first(L,x); //chen vao vi tri dau tien
        else //chen vao k != 1
        {
            while (Q != NULL && i != k-1) //duyet den vi tri k-1
            {
                i++;
                Q = Q->next;
            }
            P->next = Q->next; 
            Q->next = P;
        }
    }
}

int Search (List L, item x) //tim x trong danh sach
{
    Node *P=L; 
    int i=1;
    while (P != NULL && P->Data != x) //duyet danh sach den khi tim thay hoac ket thuc danh sach
    {
        P = P->next;
        i++;
    }
    if (P != NULL) return i; //tra ve vi tri tim thay
    else return 0; //khong tim thay
}
 
void Del_frist (List &L, item &x) //Xoa phan tu dau tien
{
    x = L->Data; //lay gia tri ra neu can dung
    L = L->next; //Cho L tro den Node thu 2 trong danh sach
}
void Del_k (List &L, item &x, int k) //Xoa Node k trong danh sach
{
    Node *P=L;
    int i=1;
    if (k<1 || k>len(L)) cout<<"Vi tri xoa khong hop le !"; //kiem tra dieu kien
    else
    {
        if (k==1) Del_frist(L,x); //xoa vi tri dau tien
        else //xoa vi tri k != 1
        {
            while (P != NULL && i != k-1) //duyet den vi tri k-1
            {
                P=P->next;
                i++;
            }
            P->next = P->next->next; //cho P tro sang Node ke tiep vi tri k
        }
    }
}
void Del_x (List &L, item x) //xoa phan tu x trong danh sach
{
    while (Search(L,x)) Del_k (L,x,Search(L,x)); //trong khi van tim thay x thi van xoa
}
void Input (List &L) //nhap danh sach
{
    int i=0; 
    item x;
    do
    {
        i++;
        cout<<"Nhap phan tu thu "<<i<<": ";
        cin>>x;
        if (x != 0) Insert_k(L,x,len(L)+1);
    } while(x != 0); //nhap 0 de ket thuc
}

void Output (List L) //xuat danh sach
{
    Node *P=L;
    while (P != NULL)
    {
        cout<<"  "<<P->Data;
        P = P->next;
    }
    cout<<"\n";
}

int main()
{
    List L;
    Init(L);
    Input(L);
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
        case 2: cout<<"Do dai DS la: "<<len(L);break;
        case 3:
        {
            item x;
            int k;
            cout<<"Nhap phan tu can chen vao DS: ";
            cin>>x;
            cout<<"Nhap vi tri can chen: ";
            cin>>k;
            Insert_k (L,x,k);
            cout<<"DS sau khi chen:\n";
            Output(L);
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
            Del_k (L,x,k);
            cout<<"DS sau khi xoa:\n";
            Output(L);
            break;
        }
        case 6:
        {
            item x;
            cout<<"Nhap phan tu can xoa: ";
            cin>>x;
            Del_x (L,x);
            cout<<"DS sau khi xoa:\n";
            Output(L);
            break;
        }
        case 7: break;
    }
    }while (lua_chon !=7);
    return 0;
}


