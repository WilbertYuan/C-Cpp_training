#include "SortableList.h"
#include <cmath>

void SortableList::InsertSort(int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = l[i];
        int j = i - 1;
        while (j >= left && l[j] > key) {
            l[j + 1] = l[j];
            j--;
        }
        l[j + 1] = key;
    }
}
int SortableList::Select(int k, int left, int right, int r) {
    int n = right - left + 1;
    if (n <= r) { 
        InsertSort(left, right);
        return left + k - 1;
    }
    int groups = n / r;
    for (int i = 0; i < groups; i++) {
        int groupLeft = left + i * r;
        int groupRight = groupLeft + r - 1;
        InsertSort(groupLeft, groupRight);
        Swap(left + i, groupLeft + (int)ceil(r / 2.0) - 1);
    }
    int midIndex = (groups % 2 == 0 ? groups / 2 : groups / 2 + 1);
    int j = Select(midIndex, left, left + groups - 1, r);
    Swap(left, j);
    j = Partition(left, right);
    int pos = j - left + 1;
    if (k == pos)
        return j;
    else if (k < pos)
        return Select(k, left, j - 1, r);
    else
        return Select(k - pos, j + 1, right, r);
}
