#include <iostream>
using namespace std;
int YearK(int A[], int N, int K)
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (A[i] <= K)
            count += 1;
    }
    return count;
}
void No_birth(int *A, int begin, int end)
{
    int i = 0;
    for (i; i < end - begin + 1; i++)
    {
        if (A[i] == 0)
        {
            cout << begin + i << endl;
        }
    }
}
int count50y(int A[], int X, int t, int Z)
{
    int sum = 0;
    for (int i = 0; i < Z - t - X; i++)
    {
        sum += A[i];
    }
    return sum;
}

int main()
{
    int A[100];
    int X, Y;
    cout << "Nhap nam bat dau: ";
    cin >> X;
    cout << "Nhap nam ket thuc: ";
    cin >> Y;

    int k = Y - X + 1;
    for (int i = 0; i < k; i++)
    {
        cout << "Nhap vao so dan nam " << X + i << ":";
        cin >> A[i];
    }
    int *a = A;
    //A
    cout << " Nam khong co ai duoc sinh ra la: ";
    No_birth(a, X, Y);
    //B
    cout << " So luong nhung nam ma so nguoi sinh ra khong qua 10 la:  ";
    cout << YearK(A, k, 10) << endl;
    //C
    int sum = count50y(A, X, 50, 1985);
    cout << "so nguoi tren 50 tuoi tinh den nam 1985 :" << sum;
    return 0;
}