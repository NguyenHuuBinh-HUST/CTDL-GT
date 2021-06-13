#include <iostream>
#include <string.h>

using namespace std;

struct Node{
	int x;
	Node* left;
	Node* right;
}; 
// Tao node moi
Node* makeTreeNode(int x){
	Node* temp= new Node;
	temp->left=NULL;
	temp->right=NULL;
	temp->x=x;
	return temp;
}
// Them
void add(Node *&root, int data){
	if(root==NULL)
		root = makeTreeNode(data);
	if(root->x > data){
		if(root->left == NULL){
			Node* temp=makeTreeNode(data);
			root->left = temp;
		}
		else add(root->left,data);
	}
	else if(root->x < data ){
		if(root->right == NULL){
			Node* temp=makeTreeNode(data);
			root->right = temp;
		}
		else add(root->right,data);
	}
		
}
// Xoa
void del(Node *&root){
	Node *temp = root;
	Node *Q,*R; 
	if(root->left == NULL && root->right == NULL){
		root = NULL;
		delete temp;
	}
	else if(root->left != NULL && root->right==NULL){
		root = root->left;
		delete temp;
	}
	else if(root->left == NULL && root->right!=NULL){
		root = root->right;
		delete temp;
	}
	else{
		Q = root->left;
            if(Q->right == NULL) {
                root->x = Q->x;
                root->left = Q->left;
            }
            else {
                do {
                    R = Q;
                    Q = Q->right;
                }while (Q->right != NULL);
                root->x = Q->x;
                R->right = Q->left;
            }
        }
        Q = NULL;
        delete Q;
	
}

void delete_value(Node*& root, int x){
	if(root == NULL)	return;
	if(root->x > x && root->left != NULL){
		delete_value(root->left,x);
	}
	else if(root->x <x && root->right != NULL){
		delete_value(root->right,x);
	}
	else if(root->x == x){
		del(root);
	}
	
}
// Tim kiem
Node *search(Node* root, int x){
	if(root == NULL)	return  NULL;
	if(root->x > x && root->left != NULL){
		return search(root->left,x);
	}
	else if(root->x <x && root->right != NULL){
		return search(root->right,x);
	}
	else if(root->x == x){
		return root;
	}
	return NULL;
}
//min max
Node* Node_Min(Node* root){
	Node* temp = root;
	while(temp->left){
		temp = temp->left;
	}
	return temp;
}
Node* Node_Max(Node* root){
	Node* temp = root;
	while(temp->right){
		temp = temp->right;
	}
	return temp;
}
int Value_Min(Node* root){
	return Node_Min(root)->x;
}
int Value_Max(Node* root){
	return Node_Max(root)->x;
}
// Tong
void SUM(Node* root, int &s){ // Ho tro ham sum
	if(root!=NULL){
		SUM(root->left,s);
		s += root->x;
		SUM(root->right,s);
	}
}
int sum(Node* root){
	int S=0;
	SUM(root,S);
	return S;
}
//	so phan tu Chan
void CHAN(Node* root,int &count){ //ho tro ham chan
	if(root!=NULL){
		CHAN(root->left,count);
		if(root->x%2 == 0)count++;
		CHAN(root->right,count);
	}
}
int chan(Node* root){
	int count=0;
	CHAN(root,count);
	return count;
}
// 	Hien thi
void display(Node* root){  
	if(root!=NULL){
		
		display(root->left);
		cout << root->x<<"\t";
		display(root->right);
	}
}
int main(){
	Node* root = NULL;
	
	int A[]={40, 30, 65, 25, 50, 76, 35, 10, 28, 27, 73, 36, 34};
	for(int i=0;i<sizeof(A)/4;i++){
		add(root,A[i]);
	}

	display(root);
	cout<< "\nMin:"<<Node_Min(root)->x;	// Node_Min(root)->x; tuong duong voi Value_Min(root);
	cout<< "\nMax:"<<Node_Max(root)->x; // Node_Max(root)->x; tuong duong voi Value_Max(root);
	
	cout <<"\nTong cac phan tu: "<<sum(root);
	// so phan tu chan
	cout <<"\nso phan tu chan: "<<chan(root);
	cout <<"\n";
	// xoa
	delete_value(root,40); // xoa node co key 40
	display(root);
	// Tim kiem
	Node *temp=search(root,9);	// tim kiem phan tu 9
	cout <<'\n';
	if(temp==NULL) cout << "Not found";
	else cout << temp->x;
	// Tong
	
	cout <<"\nTong cac phan tu: "<<sum(root);
	// so phan tu chan
	cout <<"\nTong cac phan tu: "<<chan(root);
	getchar();
	
	return 0;
}
