#include<iostream>
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