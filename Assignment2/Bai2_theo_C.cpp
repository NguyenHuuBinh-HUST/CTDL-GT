#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Node
{
	int mssv;
	string ten, lop;
	Node* next;
};

typedef Node* SV; //kieu con tro nut sv
typedef Node* Listsv; //con tro danh sach sv (noi don)

void initlistsv(Listsv& list)
{
	list = NULL;
}


SV initsv(int mssv, string ten, string lop)
{
	SV sv = new Node;
	sv->mssv = mssv;
	sv->ten = ten;
	sv->lop = lop;
	return sv;
}

bool isempty(Listsv list)
{
	return (list == NULL);
}

SV getsv(Listsv list,int index)
{
	SV p = list;
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
	return p;
}

void insertbegin(Listsv& list, SV sv)
{
	SV p = new Node;
	p = sv;
	if (list == NULL)
	{
		p->next = NULL;
		list = p;
	}
	else
	{
		p->next = list;
		list = p;
	}
}

void insertend(Listsv& list, SV sv, SV _sv)
{
	SV p = new Node;
	SV q = new Node;
	q = sv;
	p = _sv;
	if (list == NULL)
	{
		p->next = NULL;
		list = p;
	}
	else
	{
		p->next = q->next;
		q->next = p;
	}
}

SV searchsv(Listsv& list)
{
	string _name;
	cout << "nhap ten sinh vien can tim thong tin: ";
	getline(cin, _name);
	SV p = list;
	while (p != NULL)
	{
		if (p->ten == _name)
		{
			cout << "thong tin sinh vien can tim: ";
			cout << p->mssv << setw(10) << p->ten << setw(10) << p->lop << endl;
			return p;
		}
		else
		{
			p = p->next;
		}
	}
}

void deletesv(Listsv& list)
{
	SV a = list;
	SV p = list;
	if (list == NULL) cout << "danh sach sv rong";
	if (a->next == NULL) //neu ds chi co 1 phan tu
	{
		list = NULL;
		delete a;
	}
	else
	{	
		string _name;
		cout << "nhap ten sv can xoa thong tin: ";
		getline(cin, _name);
		
		if (list->ten == _name) //xoa phan tu dau tien
		{
			list = list->next;
			delete p;
		}
		else
		{
			while (p->next->ten != _name)
			{
				p = p->next;
			}
			SV q = p->next;
			p->next = p->next->next;
			delete q;
			cout << "thong tin sv " << _name << " da duoc xoa" << endl;
		}
	}
}

void show(Listsv list)
{
	SV p;
	p = list;
	while (p != NULL)
	{
		cout << p->mssv << setw(10) << p->ten << setw(10) << p->lop << endl;
		p = p->next;
	}
}

int main()
{
	Listsv sv;
	initlistsv(sv);
	SV sv1 = initsv( 1, "Le Van A", "ET1-01");
	SV sv2 = initsv( 2, "Le Van B", "ET1-02");
	SV sv3 = initsv( 3, "Le Van C", "ET1-03");
	insertbegin(sv, sv2);
	insertbegin(sv, sv1);
	insertend(sv,getsv(sv,1), sv3);
	show(sv);
	cout << "\n";
	searchsv(sv);
	cout << "\n";
	deletesv(sv);
	cout << "\n";
	show(sv);
	return 0;
}