#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *next;
};

Node* taoNode(int x) {
    Node *p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

// Truy cap
void truyCap(Node *dau, int viTri) {
    Node *p = dau;
    int i = 0;

    while (p != NULL && i < viTri) {
        p = p->next;
        i++;
    }

    if (p == NULL)
        cout << "Vi tri khong ton tai\n";
    else
        cout << "Gia tri: " << p->data << endl;
}

// chen vao dau
void chenDau(Node *&dau, int x) {
    Node *p = taoNode(x);
    p->next = dau;
    dau = p;
}

// chen vao cuoi
void chenCuoi(Node *&dau, int x) {
    Node *p = taoNode(x);

    if (dau == NULL) {
        dau = p;
        return;
    }

    Node *q = dau;
    while (q->next != NULL)
        q = q->next;

    q->next = p;
}

// chen vao vi tri
void chenViTri(Node *&dau, int viTri, int x) {
    if (viTri == 0) {
        chenDau(dau, x);
        return;
    }

    Node *q = dau;
    int i = 0;

    while (q != NULL && i < viTri - 1) {
        q = q->next;
        i++;
    }

    if (q == NULL) {
        cout << "Vi tri khong hop le\n";
        return;
    }

    Node *p = taoNode(x);
    p->next = q->next;
    q->next = p;
}

// xoa phan tu dau
void xoaDau(Node *&dau) {
    if (dau == NULL)
        return;

    Node *p = dau;
    dau = dau->next;
    delete p;
}

// xoa phan tu cuoi
void xoaCuoi(Node *&dau) {
    if (dau == NULL)
        return;

    if (dau->next == NULL) {
        delete dau;
        dau = NULL;
        return;
    }

    Node *p = dau;

    while (p->next->next != NULL)
        p = p->next;

    delete p->next;
    p->next = NULL;
}

// xoa tai vi tri
void xoaViTri(Node *&dau, int viTri) {
    if (dau == NULL)
        return;

    if (viTri == 0) {
        xoaDau(dau);
        return;
    }

    Node *p = dau;
    int i = 0;

    while (p->next != NULL && i < viTri - 1) {
        p = p->next;
        i++;
    }

    if (p->next == NULL) {
        cout << "Vi tri khong hop le\n";
        return;
    }

    Node *q = p->next;
    p->next = q->next;
    delete q;
}

// duyet xuoi
void duyetXuoi(Node *dau) {
    Node *p = dau;

    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }

    cout << endl;
}

// duyet nguoc
void duyetNguoc(Node *p) {
    if (p == NULL)
        return;

    duyetNguoc(p->next);
    cout << p->data << " ";
}

int main() {
    Node *dau = NULL;

    chenCuoi(dau, 10);
    chenCuoi(dau, 20);
    chenCuoi(dau, 30);

    cout << "Danh sach ban dau: ";
    duyetXuoi(dau);

    cout << "Truy cap vi tri 1: ";
    truyCap(dau, 1);

    chenDau(dau, 5);
    cout << "Chen dau: ";
    duyetXuoi(dau);

    chenCuoi(dau, 40);
    cout << "Chen cuoi: ";
    duyetXuoi(dau);

    chenViTri(dau, 2, 15);
    cout << "Chen vi tri 2: ";
    duyetXuoi(dau);

    xoaDau(dau);
    cout << "Xoa dau: ";
    duyetXuoi(dau);

    xoaCuoi(dau);
    cout << "Xoa cuoi: ";
    duyetXuoi(dau);

    xoaViTri(dau, 1);
    cout << "Xoa vi tri 1: ";
    duyetXuoi(dau);

    cout << "Duyet xuoi: ";
    duyetXuoi(dau);

    cout << "Duyet nguoc: ";
    duyetNguoc(dau);
    cout << endl;

    return 0;
}