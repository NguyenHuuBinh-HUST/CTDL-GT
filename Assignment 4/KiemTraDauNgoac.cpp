#include<iostream>
#include<stack>
using namespace std;

bool KiemTraDauNgoac(string s){

    stack<int> test;
    int ch;
    
    for(int i=0;i<s.length();i++){
        ch = s[i];
        switch (ch){
            case (int)'(':
                test.push('(');
                
                break;
            case '[':
                test.push('[');
                break;
            case '{':
                test.push('{');
                break;
            case ')':
                if(test.empty())
                    return false;
                if(test.top()=='('){
                    test.pop();
                    
                }
                    
                else
                    return false;
                break;
            case ']':
                if(test.empty())
                    return false;
                if(test.top()=='['){
                    test.pop();
                    
                }
                    
                else
                    return false;
                break;
            case '}':
                if(test.empty())
                    return false;
                if(test.top()=='{'){
                    test.pop();
                    
                }
                else
                    return false;
                break;
            default:
                break;
        }
        
    }
    if(test.empty())
        return true;
    return false;
}

int main(){
    string s="{((){})[]}";
    
    if(KiemTraDauNgoac(s)){
        cout << "Dau Ngoac Dung";
    }
    else    
        cout << "Dau Ngoac Sai";



}