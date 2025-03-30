#include "SortableList.h"

// 交换数组中两个元素的值
void SortableList::Swap(int i, int j) {
    int temp = l[i];
    l[i] = l[j];
    l[j] = temp;
}

// 单趟划分函数，使用最左侧元素作为主元
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

// 随机化划分，避免极端情况
int SortableList::RandomizedPartition(int left, int right) {
    srand((unsigned)time(NULL));
    int i = left + rand() % (right - left + 1);
    Swap(i, left);
    return Partition(left, right);
}

// 递归快速排序函数
void SortableList::QuickSort(int left, int right) {
    if (left < right) {
        int j = RandomizedPartition(left, right);
        QuickSort(left, j - 1);
        QuickSort(j + 1, right);
    }
}

// 公有接口：快速排序
void SortableList::QuickSort() {
    QuickSort(0, n - 1);
}
