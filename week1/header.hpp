#include <iostream>
// stack linked list
void push(Node *&dau, int x) {
    chenDau(dau, x);
}

void pop(Node *&dau) {
    xoaDau(dau);
}

int top(Node *dau) {
    if (dau == NULL) return -1;
    return dau->data;
}

bool empty(Node *dau) {
    return dau == NULL;
}
//stack bang list
void push(List &L, int x) {
    insertLast(L, x);
}

void pop(List &L) {
    deleteLast(L);
}

int top(List L) {
    if (L.n == 0) return -1;
    return L.a[L.n - 1];
}

bool empty(List L) {
    return L.n == 0;
}
// queue bang linked list
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
// queue bang list
const int MAX = 1000;

struct QueueList {
    int a[MAX];
    int dau, cuoi, n;
};

void khoiTao(QueueList &q) {
    q.dau = q.cuoi = q.n = 0;
}

bool empty(QueueList q) {
    return q.n == 0;
}

bool full(QueueList q) {
    return q.n == MAX;
}

void enqueue(QueueList &q, int x) {
    if (full(q)) return;
    q.a[q.cuoi] = x;
    q.cuoi = (q.cuoi + 1) % MAX;
    q.n++;
}

void dequeue(QueueList &q) {
    if (empty(q)) return;
    q.dau = (q.dau + 1) % MAX;
    q.n--;
}

int front(QueueList q) {
    if (empty(q)) return -1;
    return q.a[q.dau];
}