#include<iostream>
#include<stack>
using namespace std;

int Postfix(char *p)
{
	stack<int> num;
    int i=0;
    while(p[i] != '\0'){
        int temp;
        if(p[i]>='0' && p[i]<='9'){
            num.push(p[i]-48);
        }
        switch(p[i]){
            case '+':
                temp = num.top();
                num.pop();
                temp+= num.top();
                num.pop();
                num.push(temp);
                break;
            case '-':
                temp = num.top();
                num.pop();
                temp= num.top() - temp;
                num.pop();
                num.push(temp);
                break;
            case '*':
                temp = num.top();
                num.pop();
                temp*= num.top();
                num.pop();
                num.push(temp);
                break;
            case '/':
                temp = num.top();
                num.pop();
                temp= num.top()/temp;
                num.pop();
                num.push(temp);
                break;
            case '%':
                temp = num.top();
                num.pop();
                temp= num.top()%temp;
                num.pop();
                num.push(temp);
                break;
        }
        i++;
    }
    return num.top();
}
int main(){
    char s[]="132*-"; // 1-3*2
    cout <<Postfix(s);
}