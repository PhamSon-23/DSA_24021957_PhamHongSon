#include <iostream>
using namespace std;
int Partition(int a[], int l, int r) {
    int chot = a[r];
    int i = l - 1;

    for (int j = l; j < r; j++) {
        if (a[j] <= chot) {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[r]);
    return i + 1;
}

void QuickSort(int a[], int l, int r) {
    if (l < r) {
        int chot = Partition(a, l, r);
        QuickSort(a, l, chot - 1);
        QuickSort(a, chot + 1, r);
    }
}