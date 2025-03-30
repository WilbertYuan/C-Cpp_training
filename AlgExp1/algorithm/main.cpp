#include "SortableList.h"
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;

int main() {
    int size;
    cout << "请输入数组大小:" << endl;
    cin >> size;
    cout << size << endl;
    SortableList list(size);
    list.n = size;

    // 测试归并排序
    cout << "请输入归并排序使用的数据:" << endl;
    list.Input(size);
    auto start = high_resolution_clock::now();
    list.MergeSort();
    auto end = high_resolution_clock::now();
    auto durationMerge = duration_cast<nanoseconds>(end - start).count();
    cout << "归并排序结果：" << endl;
    list.Output();
    cout << "归并排序耗时：" << durationMerge << " 纳秒" << endl;

    // 测试快速排序
    cout << "请输入快速排序使用的数据:" << endl;
    list.Input(size);
    start = high_resolution_clock::now();
    list.QuickSort();
    end = high_resolution_clock::now();
    auto durationQuick = duration_cast<nanoseconds>(end - start).count();
    cout << "快速排序结果：" << endl;
    list.Output();
    cout << "快速排序耗时：" << durationQuick << " 纳秒" << endl;

    // 测试选择算法：寻找第 k 小的元素
    int k;
    cout << "请输入要查找的第 k 小元素的 k 值:" << endl;
    cin >> k;
    start = high_resolution_clock::now();
    int index = list.Select(k, 0, size - 1, 5);
    end = high_resolution_clock::now();
    cout << "第 " << k << " 小的元素的下标为: " << index << endl;
    auto durationSelect = duration_cast<nanoseconds>(end - start).count();


    
    ofstream csvFile("Project/result/sorting_results.csv", ios::app);

    // static bool firstTime = true;
    // if (firstTime) {
    //     csvFile << "Data Size, Merge Sort Time (ns), Quick Sort Time (ns), Select Time (ns)\n";
    //     firstTime = false;
    // }
    csvFile << size << "," << durationMerge << "," << durationQuick << "," << durationSelect << "\n";  // 选择算法时间可扩展

    csvFile.close();
    cout << "结果已记录到 sorting_results.csv" << endl;
    
    return 0;
}
