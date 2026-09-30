#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev;
    Node *next;
};

Node* taoNode(int x) {
    Node *p = new Node;
    p->data = x;
    p->prev = NULL;
    p->next = NULL;
    return p;
}

// truy cap
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
void chenDau(Node *&dau, Node *&cuoi, int x) {
    Node *p = taoNode(x);

    if (dau == NULL) {
        dau = cuoi = p;
    } else {
        p->next = dau;
        dau->prev = p;
        dau = p;
    }
}

// chen vao cuoi
void chenCuoi(Node *&dau, Node *&cuoi, int x) {
    Node *p = taoNode(x);

    if (cuoi == NULL) {
        dau = cuoi = p;
    } else {
        p->prev = cuoi;
        cuoi->next = p;
        cuoi = p;
    }
}

// chen vao vi tri
void chenViTri(Node *&dau, Node *&cuoi, int viTri, int x) {
    if (viTri == 0) {
        chenDau(dau, cuoi, x);
        return;
    }

    Node *p = dau;
    int i = 0;

    while (p != NULL && i < viTri - 1) {
        p = p->next;
        i++;
    }

    if (p == NULL) {
        cout << "Vi tri khong hop le\n";
        return;
    }

    if (p == cuoi) {
        chenCuoi(dau, cuoi, x);
        return;
    }

    Node *q = taoNode(x);

    q->next = p->next;
    q->prev = p;

    p->next->prev = q;
    p->next = q;
}

// xoa phan tu dau
void xoaDau(Node *&dau, Node *&cuoi) {
    if (dau == NULL)
        return;

    Node *p = dau;

    if (dau == cuoi) {
        dau = cuoi = NULL;
    } else {
        dau = dau->next;
        dau->prev = NULL;
    }

    delete p;
}

// xoa phan tu cuoi
void xoaCuoi(Node *&dau, Node *&cuoi) {
    if (cuoi == NULL)
        return;

    Node *p = cuoi;

    if (dau == cuoi) {
        dau = cuoi = NULL;
    } else {
        cuoi = cuoi->prev;
        cuoi->next = NULL;
    }

    delete p;
}

// xoa tai vi tri
void xoaViTri(Node *&dau, Node *&cuoi, int viTri) {
    if (dau == NULL)
        return;

    if (viTri == 0) {
        xoaDau(dau, cuoi);
        return;
    }

    Node *p = dau;
    int i = 0;

    while (p != NULL && i < viTri) {
        p = p->next;
        i++;
    }

    if (p == NULL) {
        cout << "Vi tri khong hop le\n";
        return;
    }

    if (p == cuoi) {
        xoaCuoi(dau, cuoi);
        return;
    }

    p->prev->next = p->next;
    p->next->prev = p->prev;

    delete p;
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
void duyetNguoc(Node *cuoi) {
    Node *p = cuoi;

    while (p != NULL) {
        cout << p->data << " ";
        p = p->prev;
    }

    cout << endl;
}

int main() {
    Node *dau = NULL;
    Node *cuoi = NULL;

    chenCuoi(dau, cuoi, 10);
    chenCuoi(dau, cuoi, 20);
    chenCuoi(dau, cuoi, 30);

    cout << "Danh sach ban dau: ";
    duyetXuoi(dau);

    cout << "Truy cap vi tri 1: ";
    truyCap(dau, 1);

    chenDau(dau, cuoi, 5);
    cout << "Chen dau: ";
    duyetXuoi(dau);

    chenCuoi(dau, cuoi, 40);
    cout << "Chen cuoi: ";
    duyetXuoi(dau);

    chenViTri(dau, cuoi, 2, 15);
    cout << "Chen vi tri 2: ";
    duyetXuoi(dau);

    xoaDau(dau, cuoi);
    cout << "Xoa dau: ";
    duyetXuoi(dau);

    xoaCuoi(dau, cuoi);
    cout << "Xoa cuoi: ";
    duyetXuoi(dau);

    xoaViTri(dau, cuoi, 1);
    cout << "Xoa vi tri 1: ";
    duyetXuoi(dau);

    cout << "Duyet xuoi: ";
    duyetXuoi(dau);

    cout << "Duyet nguoc: ";
    duyetNguoc(cuoi);

    return 0;
}