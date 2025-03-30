#include "SortableList.h"

// 输入函数：从标准输入读入数据
void SortableList::Input(int n) {
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
}

// 输出函数：输出排序后的序列
void SortableList::Output() {
    for (int i = 0; i < n; i++) {
        cout << l[i] << " ";
    }
    cout << endl;
}

// 公有接口：两路归并排序
void SortableList::MergeSort() {
    MergeSort(0, n - 1);
}

// 递归实现归并排序
void SortableList::MergeSort(int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        MergeSort(left, mid);
        MergeSort(mid + 1, right);
        Merge(left, mid, right);
    }
}

// 合并两个有序子序列
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
