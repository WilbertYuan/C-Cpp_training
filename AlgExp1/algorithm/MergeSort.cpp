#include "SortableList.h"

void SortableList::Input(int n) {
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
}
void SortableList::Output() {
    for (int i = 0; i < n; i++) {
        cout << l[i] << " ";
    }
    cout << endl;
}
void SortableList::MergeSort() {
    MergeSort(0, n - 1);
}

void SortableList::MergeSort(int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        MergeSort(left, mid);
        MergeSort(mid + 1, right);
        Merge(left, mid, right);
    }
}
void SortableList::Merge(int left, int mid, int right) {
    int *temp = new int[right - left + 1];
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
        if (l[i] <= l[j])
            temp[k++] = l[i++];
        else
            temp[k++] = l[j++];
    }
    while (i <= mid)
        temp[k++] = l[i++];
    while (j <= right)
        temp[k++] = l[j++];
    for (i = 0, k = left; k <= right; i++, k++) {
        l[k] = temp[i];
    }
    delete[] temp;
}
