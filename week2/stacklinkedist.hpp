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