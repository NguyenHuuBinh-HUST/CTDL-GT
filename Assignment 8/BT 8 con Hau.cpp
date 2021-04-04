#include <iostream>
#include <math.h>
#define MAX 8
using namespace std;
int Arr[MAX];
static int count = 0;
bool Ok(int x2,int y2){
    //kiểm tra cách đặt có thỏa mãn không
    for(int i = 1; i < x2 ;i++)
        if(Arr[i] == y2 || abs(i-x2) == abs(Arr[i] - y2) )
            return false;
    //Nếu kiểm tra hết các trường hợp vẫn không sai thì trả về true
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
        // thử đặt quân hậu vào các cột từ 1 đến n
        if(Ok(i,j)){
            //nếu cách đặt này thỏa mãn thì lưu lại vị trí
            Arr[i] = j;
                        //nếu đặt xong quân hậu thứ n thì xuất ra một kết quả
            if(i==n) Xuat();
            Try(i+1,n);
        }
    }
}
int main(){
    for(int i=0; i<MAX;i++){
        Arr[i]=-99;
    } 
    // Arr[0]=0;
    Try(1,MAX);
}