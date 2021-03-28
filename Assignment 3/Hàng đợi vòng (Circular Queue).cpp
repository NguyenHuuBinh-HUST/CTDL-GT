#include<iostream>
#include<stdio.h>
using namespace std;

#define MAX 3

struct queue {
	int data[MAX];
	int n;
	int rear;//chi so cua phan tu tiep theo duoc them vao cuoi queue
	int front;//chi so cua phan tu bi xoa lan tiep theo
};

void init(queue& S)
{
	S.n = 0;
	S.rear = 0;
	S.front = 0;
}

bool IsEmpty(queue S)
{
	if (S.n == 0)
		return true;
	return false;
}

bool IsFull(queue S)
{
	if (S.n == MAX)
		return true;
	else
		return false;
}

//them vao cuoi hang doi
void Enqueue(int K, queue& S) {
	if (IsFull(S))
		return;
	else {
		S.data[S.rear] = K;
		if (S.n != 0)
		{
			S.rear = (S.rear + 1) % MAX;
			S.n++;
		}
		else
		{
			S.rear++;
			S.n++;
		}
	}

}

//xoa phan tu dau hang doi
void Dequeue(queue& S) {
	if (IsEmpty(S))
		return;
	else {
		S.data[S.front] = 0;
		S.front = (S.front + 1) % MAX;
		S.n--;
	}
}



void display(queue& S)
{

	cout << "display :" << endl;
	if (IsEmpty(S))
		cout << "empty" << endl;
	else
	{
		if (S.front < S.rear)
		{
			for (int i = S.front;i < S.rear;i++)
			{
				cout << S.data[i] << "\t";
			}
			cout << endl;
			cout << "so phan tu :" << S.n << endl;
		}
		else
		{
			for (int i = S.front;i < MAX;i++)
				cout << S.data[i] << "\t";
			for (int i = 0;i < S.rear;i++)
				cout << S.data[i] << "\t";
			cout << endl;
			cout << "so phan tu :" << S.n << endl;
		}
	}

}

int main()
{
	queue eg;
	init(eg);
	Enqueue(1, eg);
	Enqueue(2, eg);
	Enqueue(3, eg);
	display(eg);
	Dequeue(eg);
	display(eg);
	Dequeue(eg);
	display(eg);
	Enqueue(10, eg);
	display(eg);
	return 0;
}
