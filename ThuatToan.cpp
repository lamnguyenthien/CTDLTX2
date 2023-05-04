#include<iostream>
#include<bits/stdc++.h>

using namespace std;


//Phuong phap tim kiem

//Day da sap xep
//Tim kiem nhi phan

int binarySearch(int *x, int l,  int r, int key)
{
    if(r<l) return -1;
    else {
        int m = (l+r)/2;
        if(x[m]==key) return m;
        else if(x[m]>key)
            return binarySearch(x,l,m-1,key);
        else return binarySearch(x,r,m_1,key);
    }
}

//Phuong phap sap xep co ban

//Sap xep noi bot (theo chieu tang dan)
void bubbleSort(int *x, int n)
{
    for(int i =0; i < n-1; i++)
    {
        for(int j = n-1; j >i; j--)
        {
            if(x[j] < x[j-1])
            {
                int tg = x[j];
                x[j] = x[j-1];
                x[j-1] = tg;
            }
        }
    }
}


//Sap xep lưa chon (theo chieu tang dan)
void selectSort(int *x, int n)
{
    for(int i =0; i < n; i++)
    {
        int m = i;
        for(int j = i + 1;j < n; j++)
        {
            if(x[j] < x[m])
                m = j;
        }
        int tg = x[m];
        x[m] = x[i];
        x[i] = tg;
    }
}

//Sap xep chen (theo chieu tang dan)
void insertionSort(int *x, int n)
{
    for(int i =1; i < n; i++)
    {
        int tam = x[i];
        int j = i-1;
        while (j > -1 && x[j] > tam)
        {
            x[j+1] = x[j];
            j--;
        }
        x[j+1] = tam;
    }
}


//Sap xep nang cao

//Sap xep phan doan
void quickSort(int *x, int left, int right) {
    if(left < right)
    {
        k = (left + right) / 2;
        t = x[k];
        i = left;
        j = right;
        do{
            while (x[i] < t) i = i + 1;
            while (x[j] > t) j = j - 1;
            if(i <= j) {
                int tg = x[i];
                x[i] = x[j];
                x[j] = tg;
                i = i+1;
                j = j-1;
            }
        }while (i <= j);
        quickSort(x,left,j);
        quickSort(x,i,right);
    }
}

//Sap xep vun dong

void vunDong(int *x, int k, int n)
{
    if(k <= n/2-1)
    {
        int j = 2 * k + 1;
        if(j < n-1 && x[j] < x[j+1])
            j = j+1;
        if(x[k] < x[j])
        {
            int tg = x[k];
            x[k] = x[j];
            x[j] = tg;
            vunDong(x,j,n);
        }
    }
}

void taoDongDauTien(int *x, int n)
{
    for(int k=n/2-1; k>=0; k--)
        vunDong(x,k,n);
}

void heapSort(int *x, int n)
{
    taoDongDauTien(x,n);
    for(int i = n; i>=2;i--)
    {
        int tg = x[0];
        x[0] = x[i-1];
        x[i-1] = tg
        vunDong(x,0,i-1);
    }
}

//Sap xep tron
//Giai thuat tron hay day da sap xep thanh mot day
//void merging(int *x,)

