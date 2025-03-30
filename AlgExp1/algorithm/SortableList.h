#ifndef SORTABLELIST_H
#define SORTABLELIST_H

#include <iostream>
#include <climits>
#include <cstdlib>
#include <ctime>
using namespace std;

class SortableList {
public:
    // 构造函数：分配数组空间，多预留一个位置用于哨兵
    SortableList(int mSize) {
        maxSize = mSize;
        l = new int[maxSize + 1];
        n = 0;
        // 设置哨兵，保证快速排序时不越界
        l[maxSize] = INT_MAX;
    }
    ~SortableList() {
        delete[] l;
    }
    // 输入函数，读入待排序数据
    void Input(int n);
    // 输出函数，打印排序后的序列
    void Output();

    // 两路归并排序
    void MergeSort();
    // 快速排序
    void QuickSort();
    // 快速选择，返回第k小元素的下标
    int Select(int k, int left, int right, int r=5);
    int n;          // 实际数据个数

private:
    // 辅助归并排序的递归函数
    void MergeSort(int left, int right);
    // 合并两个有序子序列
    void Merge(int left, int mid, int right);

    // 辅助快速排序的递归函数
    void QuickSort(int left, int right);
    // 交换数组中下标i和j的值
    void Swap(int i, int j);
    // 单趟划分操作
    int Partition(int left, int right);
    // 随机主元划分（改进版快速排序）
    int RandomizedPartition(int left, int right);
    
    // 插入排序，用于小规模子序列排序（用于选择算法中）
    void InsertSort(int left, int right);
private:
    int *l;         // 存放序列的数组
    int maxSize;    // 数组最大容量
};

#endif
