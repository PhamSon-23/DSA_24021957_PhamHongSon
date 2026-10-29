#include <iostream>
using namespace std;

void SelectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int vitri = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[vitri]) {
                vitri = j;
            }
        }
        swap(a[i], a[vitri]);
    }
}
