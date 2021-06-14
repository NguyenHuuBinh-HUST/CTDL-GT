#include <iostream>
#include<iomanip>
#define TEN_HP_MAX 50
#define TINCHI_MAX 30
using namespace std;

class HocPhan{
public:
    int TinChi;
    string TenHP;
    string MaHP;
    HocPhan(string TenHP="\0",int TinChi=0, string MaHP="\0"){
        this->TenHP=TenHP;
        this->TinChi=TinChi;
        this->MaHP=MaHP;
    }
    void NhapHP(){
        cout <<"\tTen Hoc Phan: ";     getline(cin,TenHP);
        cout <<"\tSo tin chi: ";       cin>>TinChi;    getchar();
        cout <<"\tMa hoc phan: ";        getline(cin,MaHP);
    }
    void InDanhSachHP(){
        cout << TenHP << setw(TEN_HP_MAX - TenHP.length());
        cout << TinChi << setw(TINCHI_MAX);
        cout << MaHP <<endl;
    }    
};



struct Node{
    HocPhan data;
    Node* next;
};

// tao 1 node
Node* createNode(HocPhan x){
    Node* temp = new Node;
    temp->next = NULL;
    temp->data = x;
    return temp;
}

class List{
    Node* head;
    int size;
    void push_front(HocPhan x);
    void push_back(HocPhan x);
public:
    List(){
        head = NULL;
        size = 0;
    };
    bool isEmpty();
    HocPhan getFront();
    void push(HocPhan x);
    void pop_front();
    void display();
    void XoaHP(string s);
};

// Private
void List::push_back(HocPhan x){
    if(size == 0){
        push_front(x);
    }
    else{
        Node* temp=createNode(x);
        Node* p=head;
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=temp;
        size++;
    }
}
void List::push_front(HocPhan x){
    Node* temp = createNode(x);
        temp->next = head;
        head = temp;
        size++;
}

// Public
void List::pop_front(){
    if(!isEmpty()){
        Node* temp = head;
        head = head->next;
        size--;
        delete temp;
    }
}
HocPhan List::getFront(){
    return head->data;
}
void List::push(HocPhan x){
    if(isEmpty() || head->data.TinChi >= x.TinChi){
        push_front(x);
    }
    else if(head->next == NULL){
        push_back(x);
    }
    else{
        Node* p=head;
        while(p->next->data.TinChi < x.TinChi){
            p=p->next;
            if(p->next==NULL){
                push_back(x);
                return;
            }
        }
        Node* temp = createNode(x);
        temp->next = p->next;
        p->next = temp;
        size++;
        
    }
}
bool List::isEmpty(){
    return (size==0);
}
void List::display(){
    Node* p = head;
        int i=0;
        cout << "***DANH SACH HOC PHAN***"<<endl;
        cout <<"     TEN HOC PHAN"<<setw(TEN_HP_MAX - 13);
        cout <<"SO TIN CHI"<<setw(TINCHI_MAX);
        cout <<"MA HOC PHAN"<<endl;
        while(p != NULL){
            cout <<'('<<i<<") ";
            p->data.InDanhSachHP();
            p=p->next;
            i++;        
        }
}
void List::XoaHP(string Ma_HP){
    Node* p=head;
    bool temp = false; // kiem tra co ton tai hp khong

    if(isEmpty())               // Neu rong ket thuc
        return;

    if(p->next != NULL){     
            // xoa tat ca hp co MA_HP tru head
        while(p->next!=NULL){   
            if(p->next->data.MaHP == Ma_HP){
                temp = true;
            }
            else{
                temp = false;
            }
            if(temp){
                Node* temp = p->next;
                p->next = temp->next;
                delete temp;
                size--;
            }
            else p=p->next;
        }
        
    }

    if(head->data.MaHP == Ma_HP)
        pop_front();
    
}
    



int main(){
    List H;
    /* Them nhanh danh sach*/
    HocPhan st[10];
    for(int i=0;i<10;i++){
        st[i].TenHP=i+'A'; 
        st[i].TinChi=i;
        st[i].MaHP=i+'a';
    }

    for(int i=0;i<10;i+=2){
        H.push(st[i]);
    }
    st[5].MaHP="PH1122";
    H.push(st[5]);

    H.XoaHP("A");
    
    H.display();

    return 0;
}