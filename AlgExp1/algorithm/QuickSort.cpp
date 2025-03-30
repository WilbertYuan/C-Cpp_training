#include "SortableList.h"

void SortableList::Swap(int i, int j) {
    int temp = l[i];
    l[i] = l[j];
    l[j] = temp;
}

int SortableList::Partition(int left, int right) {
    int i = left, j = right + 1;
    int pivot = l[left];
    do {
        do {
            i++;
        } while (l[i] < pivot);
        do {
            j--;
        } while (l[j] > pivot);
        if (i < j)
            Swap(i, j);
    } while (i < j);
    Swap(left, j);
    return j;
}
int SortableList::RandomizedPartition(int left, int right) {
    srand((unsigned)time(NULL));
    int i = left + rand() % (right - left + 1);
    Swap(i, left);
    return Partition(left, right);
}
void SortableList::QuickSort(int left, int right) {
    if (left < right) {
        int j = RandomizedPartition(left, right);
        QuickSort(left, j - 1);
        QuickSort(j + 1, right);
    }
}
void SortableList::QuickSort() {
    QuickSort(0, n - 1);
}
