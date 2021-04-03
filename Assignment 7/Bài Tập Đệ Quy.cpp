#include<stdio.h>
#include<iostream>
using namespace std;

// Bai1: Viết hàm tính tổng của n phần tử đầu tiên của dãy số TN.
long tong(int n)
{
  int s;
  if(n=0) return 0;
  else(n =! 0) return n+tong(n-1);
}

// Bai2: Tính tổ hợp chập k của n
longlong ToHop(int k, int n)
{
  if(k == 0|| k==n+1) return 1;
  else if (k==1|| k==n-1) return n;
  return ToHop(k,n-1)+ToHop(k-1,n-1);
}

// Bai3: Tìm ước chung lớn nhất của hai số nguyên a và b
int UCLN(int a; int b){
  if(a<b) return UCLN(b,a);
int r = a%b;
if(r==0) return b;
else return UCLN(b,r);
}

// Bai4: Tìm vị trí của số bé nhất trong một dãy số nguyên
int Min(int a[], int dau, int cuoi)
{
  int m;
  int min1, min2;
  if(dau==cuoi) return dau;
  else if(dau<cuoi) {
    m= (dau+cuoi)/2;
    min1 = Min(a,dau,m);
    min2= Min(a,m+1,cuoi);
    if(a[min1]<=a[min2]) return min1;
    else return min2;
  }
}
//Bai5: Tìm giá trị bé nhất của một dãy số nguyên
#define MIN(x1, x2) (((x1) > (x2)) ? (x2) : (x1))
int min(int *arr, int n)
{
  if (n == 2)
  {
    return MIN(arr[0], arr[1]);
  }

  return MIN(arr[n - 1], min(arr, n - 1));
}

