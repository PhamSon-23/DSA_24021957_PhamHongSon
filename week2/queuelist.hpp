#include<iostream>
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