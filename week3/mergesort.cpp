#include <iostream>
using namespace std;

void Merge(int a[], int l, int m, int r) {
    int b[1000];
    int i = l, j = m + 1, k = 0;

    while (i <= m && j <= r) {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }

    while (i <= m)
        b[k++] = a[i++];

    while (j <= r)
        b[k++] = a[j++];

    for (i = 0; i < k; i++)
        a[l + i] = b[i];
}

void MergeSort(int a[], int l, int r) {
    if (l >= r) return;

    int m = (l + r) / 2;
    MergeSort(a, l, m);
    MergeSort(a, m + 1, r);
    Merge(a, l, m, r);
}
