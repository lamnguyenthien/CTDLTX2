#include<iostream>
#include<bits/stdc++.h>

using namespace std;


struct HANG
{
    char maHang[10];
    char tenHang[10];
    int soLuong;
};

struct Node
{
    HANG info;
    Node *next;
};

typedef Node *TRO;

HANG nhapHang()
{
    HANG x;
    cout << "Nhap ma hang: ";       fflush(stdin);      gets(x.maHang);
    cout << "Nhap ten hang: ";      fflush(stdin);      gets(x.tenHang);
    cout << "Nhap so luong hang: ";                     cin >> x.soLuong;
    return x;
}

void nhapDsHang(TRO &L, int &n)
{
    TRO p, Q;
    L = NULL;
    cout << "Nhap so luong mat hang = ";
    cin >> n;
    for(int i =  0; i < n; i++)
    {
        cout << "\nNhap thong tin hang thu "<<i+1<<endl;
        P = new Node;
        P->info = nhapHang();
        P->next = NULL;
        if(L == NULL)
            L = P;
        else
            Q-> next = P;
        Q = P;
    }
}

void xuatHang(Hang x)
{
    cout << setw(10) <<x.maHang<<setw(20)<<x.tenHang<<setw(10)<<x.soLuong;
}

void xuatDsHang(TRO &L)
{
    if(L == NULL)
    {
        cout << "Danh sach rong!";
        return;
    }
    TRO Q = L;
    int d = 0;
    cout << setw (5) << "STT";
	cout << setw (10) << "Ma hang";
	cout << setw (20) << "Ten hang";
	cout << setw (15) << "So luong" << endl;
	while (Q!=NULL)
    {
        cout << setw(5) <<++d;
        xuatHang(Q->info);
        Q = Q->next;
    }
}

//Hien thi thong tin hang co so luong nho nhat
void timHangMin(TRO &L)
{
    if(L == NULL)
    {
        cout << "\nDanh sach rong!";
        return;
    }
    //tim so luong min
    TRO Q = L;
    int soLuongMin = Q->info.soLuong;
    while (Q!=NULL)
    {
        if(Q -> info.soLuong <= soLuongMin)
            soLuongMin = Q->info.soLuong;
        Q = Q->next;
    }
    //hien thi thong tin
    Q = L;
	int count = 0;
	cout << "\n2. Mat hang co so luong it nhat:" << endl;
	cout << setw (5) << "STT";
	cout << setw (10) << "Ma hang";
	cout << setw (20) << "Ten hang";
	cout << setw (15) << "So luong" << endl;
	while (Q != NULL) {
		if (Q->info.soLuong == soLuongMin) {
			cout << setw(5) << count + 1;
			xuatHang(Q->info);
		}
		count += 1;
		Q = Q->next;
	}
}

TRO timViTri(TRO &L, int vt) {
	int d = 1;
	TRO Q = L;
	while (Q->next != NULL && d < vt - 1) {
		Q = Q->next;
		d++;
	}
	return Q;
}

void xoaViTri(TRO &L, int vt) {
	TRO Q, M;
	if (vt == 1) {
		Q = L;
		L = L->next;
		delete(Q);
	} else {
		Q = timViTri(L, vt);
		M = Q->next;
		Q->next = M->next;
	}
	delete(M);
}

// xoa mat hang co so luong it nhat
void xoaHangMin(TRO &L) {
	if (L == NULL) {
		cout << "\nDanh sach rong!";
		return;
	}
	TRO Q = L;
	int soLuongMin = Q->info.soLuong;
	while (Q != NULL) {
		if (Q->info.soLuong <= soLuongMin)
			soLuongMin = Q->info.soLuong;
		Q = Q->next;
	}
	Q = L;
	int count = 0;
	while (Q != NULL) {
		if (Q->info.soLuong == soLuongMin) {
			xoaViTri(L, count - 1);
		}
		count += 1;
		Q = Q->next;
	}
	cout << "\n3. Danh sach sau khi xoa mat hang it nhat:" << endl;
	xuatDsHang(L);
}

void chen(TRO &L, TRO Q, HANG x) {
	TRO P = new Node;
	P->info = x;
	P->next = Q->next;
	Q->next = P;
}

// chen mat hang moi vao truoc mat hang thu 2
void boSungHang(TRO &L, int vt) {
	cout << "\n4. Nhap thong tin mat hang can chen:" << endl;
	HANG x = nhapHang();
	TRO Q = timViTri(L, vt - 1);
	chen(L,Q,x);
	cout << "\n5. Danh sach sau khi chen mat hang moi:" << endl;
	xuatDsHang(L);
}

int main() {
	TRO L;
	int n;
	nhapDsHang(L, n);
	cout << "\n1. Danh sach hang sau khi nhap:" << endl;
	xuatDsHang(L);
	timHangMin(L);
	xoaHangMin(L);
	boSungHang(L, 2);
	return 0;
}


