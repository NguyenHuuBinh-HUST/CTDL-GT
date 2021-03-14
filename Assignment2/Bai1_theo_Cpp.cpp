#include <iostream>
using namespace std;

class node
{
public:
	int data;
	node* next;
};

class linkedlist
{
	node* Node;
public:
	linkedlist()
	{
		Node = NULL;
	}             
	~linkedlist()
	{
		delete Node;
	}
	void insertbegin(int k)
	{
		node* p = new node;
		p->data = k;
		if (Node == NULL)
		{
			p->next = NULL;
			Node = p;
		}
		else
		{
			p->next = Node;
			Node = p;
		}
	}

	node* getnode(int index)
	{
		node* p = new node;
		p = Node;
		int count = 0;
		while (p != NULL)
		{
			if (count == index)
			{
				return p;
			}
			else
			{
				count++;
				p = p->next;
			}
		}
	}

	void insertafter(node* n,int k)
	{
		node* p = new node;
		p->data = k;
		if (Node == NULL)
		{
			p->next = NULL;
			Node = p;
		}
		else
		{
			p->next = n->next;
			n->next = p;
		}
	}

	void insertbefore(node* n, int k)
	{
		node* p = new node;
		p->data = k;
		if (Node == NULL)
		{
			Node = p;
			p->next = NULL;
		}
		else
		{
			p->data = n->data;
			n->data = k;
			p->next = n->next;
			n->next = p;
		}
	}

	void deletenode(node* n)
	{
		if (Node == NULL) cout << "danh sach rong";
		if (Node == n && Node->next == NULL)
		{
			Node = NULL;
			delete n;
		}
		else
		{
			if (Node == n)
			{
				Node = n->next;
				delete n;
			}
			else
			{
				node* p = Node;
				while (p->next != n)
				{
					p = p->next;
				}
				p->next = n->next;
				delete n;
			}
		}
	}

	node* searchnode(int k)
	{
		node* p = Node;
		while (p != NULL)
		{
			if (p->data == k)
			{
				return p;
			}
			else
			{
				p = p->next;
			}
		}
	}

	int listlength()
	{
		node* p = new node;
		p = Node;
		int count = 0;
		while (p != NULL)
		{
			count++;
			p = p->next;
		}
		return count;
	}

	int listsum()
	{
		node* p = new node;
		p = Node;
		int sum = 0;
		while (p != NULL)
		{
			sum = sum + p->data;
			p = p->next;
		}
		return sum;
	}

	void show()
	{
		node* p = new node;
		p = Node;
		while (p != NULL)
		{
			cout << p->data << " ";
			p = p->next;
		}
	}
};

int main()
{
	linkedlist H; 
	H.insertbegin(10);
	H.insertbegin(20);
	H.insertbegin(40);
	H.insertafter(H.getnode(1), 30);
	H.insertbefore(H.getnode(2), 50);
	cout << "day so da nhap: ";
	H.show();
	cout << "\n" << "so phan tu co trong day: " << H.listlength();
	cout << "\n" << "tong cua day so da nhap: " << H.listsum() << endl;
	int k;
	cout << "nhap vi tri muon xoa: "; cin >> k; cout << "\n";
	cout << "so tai vi tri vua nhap la: " << H.getnode(k)->data << " da bi xoa" << endl;
	H.deletenode(H.getnode(k));
	cout << "day so bay gio la: "; 
	H.show();
	cout << "\n" << "so phan tu co trong day bay gio: " << H.listlength();
	cout << "\n" << "tong cua day so bay gio: " << H.listsum() << endl;
	return 0;
}