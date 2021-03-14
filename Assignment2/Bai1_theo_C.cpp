#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};
typedef Node* PNode;//kieu con tro nut
typedef Node* LinkedList;//kieu danh sach noi don
//Khoi tao danh sach
void InitList(LinkedList& H) {
	H = NULL;
}
//Kiem tra danh sach rong
bool IsEmpty(LinkedList H) {
	return (H == NULL);
}
//Bo sung mot phan tu moi vao dau danh sach
void InsertBegin(LinkedList& H, int K) {
	PNode Q = new Node;
	Q->data = K;
	if (H == NULL) {
		Q->next = NULL;
		H = Q;
	}
	else {
		Q->next = H;
		H = Q;
	}
}
//Bo sung mot phan tu moi vao sau phan tu hien tai duoc tro boi P trong danh sach H
void InsertAfter(LinkedList& H, PNode P, int K) {
	PNode Q = new Node;
	Q->data = K;
	if (H == NULL) {
		Q->next = NULL;
		H = Q;
	}
	else {
		if (P == NULL) return;
		Q->next = P->next;
		P->next = Q;

	}
}
//Bo sung mot phan tu moi vao truoc phan tu hien tai P trong danh sach H
void InsertBefore(LinkedList& H, PNode P, int K) {
	PNode Q = new Node;
	Q->data = K;
	if (H == NULL) {
		H = Q;
		Q->next = NULL;
	}
	else {
		if (P == NULL) return;
		Q->data = P->data;
		P->data = K;
		Q->next = P -> next;
		P->next = Q;
	}
}
//Lay con tro tai vi tri mong muon trong danh sach
PNode getNode(LinkedList& H, int index) {
	PNode P = new Node;
	P = H;
	int count = 0;
	while (P != NULL) {
		if (count == index) {
			return P;
		}
		else {
			count++;
			P = P->next;
		}
	}
	return P;
}
//Xoa phan tu o dau danh sach
void DeleteNode(LinkedList& H) {
	if (H == NULL) {
		cout << "Danh sach rong";
	}
	else {
		PNode P = H;
		H = H->next;
		delete P;
	}
}
//Xoa phan tu hien tai ma con tro P tro toi trong danh sach
void DeleteNodeNow(LinkedList& H,PNode P) {
	if (H == NULL) {
		cout << "Danh sach rong";
	}
	if (H == P && P->next == NULL) {//Neu danh sach chi co 1 phan tu
		H = NULL;
		delete P;
	}
	else {
		if (H == P) {//Neu P la nut dau tien
			H = H->next;
			delete P;
		}
		else {
			PNode R = H;
			while (R->next != P) R = R->next;
			R->next = P->next;
			delete P;
		}
	}
}
//Tim kiem mot phan tu trong danh sach H co du lieu bang K cho truoc
void SearchNode(LinkedList& H, int K) {
	PNode P = H;
	while (P != NULL){
		if (P->data == K) return;
		else P = P->next;
	}
}
//Ham hien thi
void Show(LinkedList H) {
	PNode P;
	P = H;
	while (P != NULL) {
		cout << P->data<<"\t";
		P = P->next;
	}
}
int main() {
	LinkedList H;
	InitList(H);
	InsertBegin(H, 1);
	InsertBegin(H, 2);
	InsertAfter(H,getNode(H,1),4);
	InsertBefore(H, getNode(H, 2), 6);
	Show(H);
	return 0;
}