#ifndef SORTABLELIST_H
#define SORTABLELIST_H

#include <iostream>
#include <climits>
#include <cstdlib>
#include <ctime>
using namespace std;

class SortableList {
public:
    SortableList(int mSize) {
        maxSize = mSize;
        l = new int[maxSize + 1];
        n = 0;
        l[maxSize] = INT_MAX;
    }
    ~SortableList() {
        delete[] l;
    }
    void Input(int n);
    void Output();
    void MergeSort();
    void QuickSort();
    int Select(int k, int left, int right, int r=5);
    int n;     

private:
    void MergeSort(int left, int right);
    void Merge(int left, int mid, int right);
    void QuickSort(int left, int right);
    void Swap(int i, int j);
    int Partition(int left, int right);
    int RandomizedPartition(int left, int right);
    void InsertSort(int left, int right);
private:
    int *l;        
    int maxSize; 
};

#endif
