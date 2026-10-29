#include<iostream>
struct Queue {
    Node *dau;
    Node *cuoi;
};

void khoiTao(Queue &q) {
    q.dau = q.cuoi = NULL;
}

void enqueue(Queue &q, int x) {
    Node *p = taoNode(x);
    if (q.dau == NULL) {
        q.dau = q.cuoi = p;
    } else {
        q.cuoi->next = p;
        q.cuoi = p;
    }
}

void dequeue(Queue &q) {
    if (q.dau == NULL) return;
    xoaDau(q.dau);
    if (q.dau == NULL) q.cuoi = NULL;
}

int front(Queue q) {
    if (q.dau == NULL) return -1;
    return q.dau->data;
}

bool empty(Queue q) {
    return q.dau == NULL;
}