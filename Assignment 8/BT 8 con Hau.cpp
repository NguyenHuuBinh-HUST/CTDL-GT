#include <iostream>
#include <math.h>
#define MAX 8
using namespace std;
int Arr[MAX];
static int count = 0;
bool Ok(int x2,int y2){
    for(int i = 1; i < x2 ;i++)
        if(Arr[i] == y2 || abs(i-x2) == abs(Arr[i] - y2) )
            return false;

    return true;
}
static void Xuat(){
    cout<<"("<<++count<<"): ";
    for(int i=1;i<=MAX;i++){
        cout<<"Q"<< char(i+96) <<Arr[i];
        if(i != MAX) cout<<", ";
        else cout<<endl;
    }
}
void Try(int i,int n){
    for(int j = 1;j<=n;j++){
        if(Ok(i,j)){
            Arr[i] = j;
            if(i==n) Xuat();
            Try(i+1,n);
        }
    }
}
int main(){
    for(int i=0; i<MAX;i++){
        Arr[i]=-99;
    } 
    Try(1,MAX);
}
