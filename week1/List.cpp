#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *truoc, *sau;
};
Node* taoNode(int x) {
    Node *p = new Node;
    p->data = x;
    p->truoc = NULL;
    p->sau = NULL;
    return p;
}
// chen vao dau
void chenDau(Node *&dau, Node *&cuoi, int x) {
    Node *p = taoNode(x);
    if (dau == NULL) {
        dau = cuoi = p;
    } else {
        p->sau = dau;
        dau->truoc = p;
        dau = p;
    }
}
// chen vao cuoi
void chenCuoi(Node *&dau, Node *&cuoi, int x) {
    Node *p = taoNode(x);
    if (cuoi == NULL) {
        dau = cuoi = p;
    } else {
        cuoi->sau = p;
        p->truoc = cuoi;
        cuoi = p;
    }
}
// Truy cap phan tu tai vi tri
void truyCap(Node *dau, int viTri) {
    Node *p = dau;
    int i = 0;
    while (p != NULL && i < viTri) {
        p = p->sau;
        i++;
    }
    if (p == NULL)
        cout << "Vi tri khong ton tai\n";
    else
        cout << "Gia tri: " << p->data << endl;
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
        p = p->sau;
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
    q->sau = p->sau;
    q->truoc = p;
    p->sau->truoc = q;
    p->sau = q;
}

// Xoa phan tu dau
void xoaDau(Node *&dau, Node *&cuoi) {
    if (dau == NULL) return;
    Node *p = dau;
    dau = dau->sau;

    if (dau == NULL)
        cuoi = NULL;
    else
        dau->truoc = NULL;

    delete p;
}
// xoa phan tu cuoi
void xoaCuoi(Node *&dau, Node *&cuoi) {
    if (cuoi == NULL) return;

    Node *p = cuoi;
    cuoi = cuoi->truoc;

    if (cuoi == NULL)
        dau = NULL;
    else
        cuoi->sau = NULL;

    delete p;
}
// xoa tai vi tri
void xoaViTri(Node *&dau, Node *&cuoi, int viTri) {
    if (dau == NULL) return;

    if (viTri == 0) {
        xoaDau(dau, cuoi);
        return;
    }
    Node *p = dau;
    int i = 0;
    while (p != NULL && i < viTri) {
        p = p->sau;
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
    p->truoc->sau = p->sau;
    p->sau->truoc = p->truoc;
    delete p;
}

// duyet xuoi
void duyetXUoi(Node *dau) {
    Node *p = dau;

    while (p != NULL) {
        cout << p->data << " ";
        p = p->sau;
    }
    cout << endl;
}

// duyet nguoc
void duyetNguoc(Node *cuoi) {
    Node *p = cuoi;

    while (p != NULL) {
        cout << p->data << " ";
        p = p->truoc;
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
    duyetXUoi(dau);

    cout << "Truy cap vi tri 1: ";
    truyCap(dau, 1);

    chenDau(dau, cuoi, 5);
    cout << "Sau khi chen dau: ";
    duyetXUoi(dau);

    chenCuoi(dau, cuoi, 40);
    cout << "Sau khi chen cuoi: ";
    duyetXUoi(dau);

    chenViTri(dau, cuoi, 2, 15);
    cout << "Sau khi chen vi tri 2: ";
    duyetXUoi(dau);

    xoaDau(dau, cuoi);
    cout << "Sau khi xoa dau: ";
    duyetXUoi(dau);

    xoaCuoi(dau, cuoi);
    cout << "Sau khi xoa cuoi: ";
    duyetXUoi(dau);

    xoaViTri(dau, cuoi, 1);
    cout << "Sau khi xoa vi tri 1: ";
    duyetXUoi(dau);

    cout << "Duyet xuoi: ";
    duyetXUoi(dau);

    cout << "Duyet nguoc: ";
    duyetNguoc(cuoi);

    return 0;
}