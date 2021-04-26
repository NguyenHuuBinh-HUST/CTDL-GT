#include<iostream>
using namespace std;
struct Node{
	int Key;
	Node* LP, *RP;
};
typedef Node* PNode;
typedef PNode BSearchTree;
void Init (BSearchTree & Root) {
	Root = NULL;
}
PNode SearchT (BSearchTree Root, int x){
	if (Root==NULL) return NULL;
	if (x == Root->Key) return Root;
	else if (x < Root->Key) return SearchT (Root->LP, x);
	else return SearchT (Root->RP, x);
}
void InsertT (BSearchTree & Root, int x){
	PNode Q;
	if (Root==NULL) { 
		Q = new Node;
		Q->Key = x;
		Q->LP =Q->RP = NULL;
	Root = Q;
	}
	else {
	if (x < Root->Key) InsertT (Root->LP, x);	
	else if (x > Root->Key) InsertT (Root->RP, x);
	}
}
void DelNode (PNode & P) { //X�a gi� tri o n�t P & sap xep lai c�y
	PNode Q, R;
	if (P->LP == NULL) { //X�a n�t chi c� c�y con phi
		Q = P;
		P = P->RP;
		delete Q; return;
	} else if (P->RP == NULL) //X�a n�t chi c� c�y con tr�i
	{
		Q = P;
		P = P->LP;
		delete Q; return;
	} else { //X�a n�t c� 2 c�y con
		Q = P->LP;
		if (Q->RP == NULL) {
			P->Key = Q->Key;
			P->LP = Q->LP;
			delete Q; return;
		} else {
			do { //D�ng R de luu parent cua Q
				R = Q;
				Q = Q->RP;
			} while (Q->RP != NULL);
		P->Key = Q->Key; //Lay gi� tri o Q dua l�n
		R->RP = Q->LP; //Chuyen con cua Q l�n vi tr� Q
		delete Q; return;
		}
	}
}
void DeleteT (BSearchTree & Root, int x){
	if (Root != NULL) {
		if (x < Root->Key) DeleteT (Root->LP, x);
		else if (x > Root->Key) DeleteT (Root->RP, x);
		else DelNode (Root); //Xo� goc cua c�y
	}
}
int Sum(BSearchTree Root){
	int sum=0;
	if(Root == NULL) return sum;
	else{
		sum+=Root->Key;
		sum+=Sum(Root->LP);
		sum+=Sum(Root->RP);
	} return sum;
}
int Count(BSearchTree Root,int &count){
	if(Root == NULL) return count;
	else{
		count++;
		Count(Root->LP,count);
		Count(Root->RP,count);
	} return count;
}
void show(BSearchTree Root){
	if(Root == NULL) return;
	else{
		cout<<Root->Key<<"\t";
		show(Root->LP);
		show(Root->RP);
	} 
}
int main(){
	BSearchTree T;
	Init (T);
	InsertT(T,12);
	InsertT(T,1);
	InsertT(T,15);
	InsertT(T,14);
	InsertT(T,8);
	InsertT(T,32);
	InsertT(T,20);
	show(T); 
	cout<<endl; int x=0;
	cout<<"Tong key = "<<Sum(T)<<"\nSo phan tu: "<<Count(T,x)<<endl;
	cout<<"Xoa 32"<<endl;
	DeleteT(T,32);
	show(T);
	cout<<endl; int y=0;
	cout<<"Tong key = "<<Sum(T)<<"\nSo phan tu: "<<Count(T,y)<<endl;
}
