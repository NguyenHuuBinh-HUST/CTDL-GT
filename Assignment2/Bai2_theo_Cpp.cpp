#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class SV
{
	int mssv;
	string ten, lop;
	SV* next;
public:
	friend class Listsv;
};

class Listsv
{
	SV* sv;
public:
	Listsv()
	{
		sv = NULL;
	}

	~Listsv()
	{
		delete sv;
	}

	SV* initsv(int mssv, string ten, string lop)
	{
		SV* sv = new SV;
		sv->mssv = mssv;
		sv->ten = ten;
		sv->lop = lop;
		return sv;
	}

	void insertbegin(SV* sinhvien)
	{
		SV* p = new SV;
		p = sinhvien;
		if (sv == NULL)
		{
			p->next = NULL;
			sv = p;
		}
		else
		{
			p->next = sv;
			sv = p;
		}
	}

	SV* getsv(int index)
	{
		SV* p = sv;
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

	void insertend(SV* sinhvien, SV* _sinhvien)
	{
		SV* p = new SV;
		SV* q;
		q = sinhvien;
		p = _sinhvien;
		if (sv == NULL)
		{
			p->next = NULL;
			sv = p;
		}
		else
		{
			p->next = q->next;
			q->next = p;
		}
	}

	SV* searchsv()
	{
		string _name;
		cout << "nhap ten sinh vien can tim thong tin: ";
		getline(cin, _name);
		SV*p = sv;
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

	void deletesv()
	{
		SV* p = sv;
		if (sv == NULL) cout << "danh sach sv rong";
		else
		{
			string _name;
			cout << "nhap ten sv can xoa thong tin: ";
			getline(cin, _name);

			if (sv->ten == _name) //xoa phan tu dau tien
			{
				sv = sv->next;
				delete p;
			}
			else
			{
				while (p->next->ten != _name)
				{
					p = p->next;
				}
				SV* q = p->next;
				p->next = p->next->next;
				delete q;
				cout << "thong tin sv " << _name << " da duoc xoa" << endl;
			}
		}
	}


	void show()
	{
		SV* p = sv;
		while (p != NULL)
		{
			cout << p->mssv << setw(10) << p->ten << setw(10) << p->lop << endl;
			p = p->next;
		}
	}

};

int main()
{
	Listsv sv;
	SV* sv1 = sv.initsv(1, "Le Van A", "ET1-01");
	SV* sv2 = sv.initsv(2, "Le Van B", "ET1-02");
	SV* sv3 = sv.initsv(3, "Le Van C", "ET1-03");
	sv.insertbegin(sv2);
	sv.insertbegin(sv1);
	sv.insertend(sv.getsv(1), sv3);
	sv.show();
	cout << "\n";
	sv.searchsv();
	cout << "\n";
	sv.deletesv();
	cout << "\n";
	sv.show();
	return 0;
}