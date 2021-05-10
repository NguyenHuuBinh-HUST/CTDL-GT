#include <iostream>
#include <iomanip>
using namespace std;

struct SV {
    int mssv;
    string name, Class;
    float avgP;
    SV* LP, * RP;
};

typedef SV* PNode;
typedef PNode BinaryTree;
typedef BinaryTree BSearchTree;

//khoi tao cay rong
void InitBST(BSearchTree& Root) {
    
    Root = NULL;
}

//bo sung sinh vien va sap xep theo chieu tang dan cua mssv
void InsertT(BSearchTree& Root, int _mssv, string _name, string _Class, float _avgP) {
    PNode Q;
    if (Root == NULL) { //khi cay rong
        Q = new SV; //tao ra dinh moi
        Q->mssv = _mssv; Q->name = _name; Q->Class = _Class; Q->avgP = _avgP;
        Q->LP = Q->RP = NULL;
        Root = Q;
    }
    else {
        if (_mssv < Root->mssv) InsertT(Root->LP, _mssv, _name, _Class, _avgP);
        else if (_mssv > Root->mssv) InsertT(Root->RP, _mssv, _name, _Class, _avgP);
    }
}

void DelNode(PNode& P) { //xoa gia tri o nut P & sap lai cay
    PNode Q, R;
    if (P->LP == NULL) { //xoa nut chi co cay con phai
        Q = P;
        P = P->RP;
    }
    else if (P->RP == NULL) //xoa nut chi co cay con trai
    {
        Q = P;
        P = P->LP;
    }
    else { //xoa nut co 2 cay con
        Q = P->LP;
        if (Q->RP == NULL) {
            P->mssv = Q->mssv;
            P->name = Q->name;
            P->Class = Q->Class;
            P->avgP = Q->avgP;
            P->LP = Q->LP;
        }
        else {
            do { //dung R de luu parent cua Q
                R = Q;
                Q = Q->RP;
            } while (Q->RP != NULL);
            P->mssv = Q->mssv; //lay gia tri o Q dua len
            P->name = Q->name;
            P->Class = Q->Class;
            P->avgP = Q->avgP;
            R->RP = Q->LP; //chuyen con cua Q len vi tri Q
        }
    }
    delete Q; //xoa Q
}

//loai bo sinh vien khoi cay theo mssv
void DeleteT(BSearchTree& Root, int _mssv) {
    if (Root != NULL) {
        if (_mssv < Root->mssv) DeleteT(Root->LP, _mssv);
        else if (_mssv > Root->mssv) DeleteT(Root->RP, _mssv);
        else DelNode(Root); //Xoa goc cua cay
    }
}

void show(BSearchTree& Root)
{
    PNode P = Root;
    cout << P->mssv << setw(20) << P->name << setw(10) << P->Class << setw(10) << P->avgP << endl;
}

//tinh diem trung binh cua toan bo sinh vien
float DiemTB(BSearchTree Root)
{
    PNode p = Root;
    static float total = 0;
    static float num = 0;
    if (Root == NULL) return NULL;
    total = total + p->avgP;
    num++;
    DiemTB(p->LP);
    DiemTB(p->RP);
    return (total / num);
}

//tim sinh vien theo mssv
PNode Find_sv_using_mssv(BSearchTree Root, int _mssv) {
    if (Root == NULL) return NULL;
    if (_mssv == Root->mssv) return Root;
    else if (_mssv < Root->mssv) return Find_sv_using_mssv(Root->LP, _mssv);
    else return Find_sv_using_mssv(Root->RP, _mssv);
}

//tim sinh vien theo ten
void Find_sv_using_name(BSearchTree Root, string _name) {
    if (Root == NULL) return;
    if (_name == Root->name) show(Root);
    Find_sv_using_name(Root->LP, _name);
    Find_sv_using_name(Root->RP, _name);
}


float Find_max_avgP(BSearchTree Root)
{
    if (Root == NULL) return NULL;
    static float max = 0;
    if (max < Root->avgP) max = Root->avgP;
    Find_max_avgP(Root->LP);
    Find_max_avgP(Root->RP);
    return max;
}

//tim sinh vien co diem trung binh cao nhat
void Find_sv_using_maxAvgP(BSearchTree Root, float max)
{
    if (Root == NULL) {
        return;
    }
    if (max == Root->avgP) show(Root);
    Find_sv_using_maxAvgP(Root->LP, max);
    Find_sv_using_maxAvgP(Root->RP, max);
}

//hien thi thong tin cua toan bo sinh vien
void HienThiToanBoSV(BSearchTree Root) {
    if (Root == NULL) return;
    HienThiToanBoSV(Root->LP);
    show(Root);
    HienThiToanBoSV(Root->RP);
}


int main()
{
    BSearchTree T; int y; string b;
    InitBST(T);
    InsertT(T, 3, "Nguyen Huu Binh", "ET1-01", 8.0);
    InsertT(T, 4, "Nguyen Van B", "ET1-02", 10.0);
    InsertT(T, 2 , "Le Van An", "ET1-03", 9.0);
    InsertT(T, 5, "Do Quang K", "ET1-05", 7.0);
    InsertT(T, 1, "Dao Thi Y", "ET1-06", 7.5);
    cout << "danh sach sinh vien: " << endl; HienThiToanBoSV(T);
    cout << "\nnhap mssv ban muon xoa: "; cin >> y;
    DeleteT(T, y);
    cout << "sinh vien vua nhap da duoc xoa";
    cout << "\ndanh sach sinh vien: " << endl; HienThiToanBoSV(T);
    cout << "\ndiem trung binh cua toan bo sinh vien trong danh sach: "; cout << DiemTB(T) << endl;
    cin.ignore();
    cout << "nhap ten sinh vien muon tim info: "; getline(cin, b);
    Find_sv_using_name(T, b);
    cout << "\ninfo sinh vien co diem trung binh cao nhat: " << endl; Find_sv_using_maxAvgP(T, Find_max_avgP(T));
    
}
