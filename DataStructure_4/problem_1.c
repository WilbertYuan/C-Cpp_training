#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


typedef int KeyType;
typedef struct {
    KeyType key;
    char data[10];
} Entry;

#define MaxSize 100000

typedef struct {
    int n;
    Entry* D;
} List;

void simpleSelectionSort(List* L) {
    int i, j, min;
    Entry temp;
    for (i = 0; i < L->n - 1; i++) {
        min = i;
        for (j = i + 1; j < L->n; j++) {
            if (L->D[j].key < L->D[min].key)
                min = j;
        }
        temp = L->D[i];
        L->D[i] = L->D[min];
        L->D[min] = temp;
    }
}

void directInsertionSort(List* L) {
    int i, j;
    Entry temp;
    for (i = 1; i < L->n; i++) {
        temp = L->D[i];
        j = i - 1;
        while (j >= 0 && L->D[j].key > temp.key) {
            L->D[j + 1] = L->D[j];
            j--;
        }
        L->D[j + 1] = temp;
    }
}

void bubbleSort(List* L) {
    int i, j;
    Entry temp;
    for (i = 0; i < L->n - 1; i++) {
        for (j = 0; j < L->n - i - 1; j++) {
            if (L->D[j].key > L->D[j + 1].key) {
                temp = L->D[j];
                L->D[j] = L->D[j + 1];
                L->D[j + 1] = temp;
            }
        }
    }
}

int partition(List* L, int low, int high) {
    Entry pivot = L->D[low];
    while (low < high) {
        while (low < high && L->D[high].key >= pivot.key)
            high--;
        L->D[low] = L->D[high];
        while (low < high && L->D[low].key <= pivot.key)
            low++;
        L->D[high] = L->D[low];
    }
    L->D[low] = pivot;
    return low;
}

void quickSortRecursive(List* L, int low, int high) {
    if (low < high) {
        int pivot = partition(L, low, high);
        quickSortRecursive(L, low, pivot - 1);
        quickSortRecursive(L, pivot + 1, high);
    }
}

void quickSort(List* L) {
    quickSortRecursive(L, 0, L->n - 1);
}

void merge(List* L, int left, int mid, int right) {
    int i, j, k;
    Entry* temp = (Entry*)malloc((right - left + 1) * sizeof(Entry));
    if (!temp) exit(EXIT_FAILURE);
    for (i = left, j = mid + 1, k = 0; i <= mid && j <= right;) {
        if (L->D[i].key <= L->D[j].key)
            temp[k++] = L->D[i++];
        else
            temp[k++] = L->D[j++];
    }
    while (i <= mid)
        temp[k++] = L->D[i++];
    while (j <= right)
        temp[k++] = L->D[j++];
    for (i = 0; i < k; i++)
        L->D[left + i] = temp[i];
    free(temp);
}

void mergeSortRecursive(List* L, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSortRecursive(L, left, mid);
        mergeSortRecursive(L, mid + 1, right);
        merge(L, left, mid, right);
    }
}

void mergeSort(List* L) {
    mergeSortRecursive(L, 0, L->n - 1);
}

void heapify(List* L, int n, int i) {
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < n && L->D[left].key > L->D[largest].key)
        largest = left;
    if (right < n && L->D[right].key > L->D[largest].key)
        largest = right;
    if (largest != i) {
        Entry temp = L->D[i];
        L->D[i] = L->D[largest];
        L->D[largest] = temp;
        heapify(L, n, largest);
    }
}

void heapSort(List* L) {
    int i;
    for (i = L->n / 2 - 1; i >= 0; i--)
        heapify(L, L->n, i);
    for (i = L->n - 1; i > 0; i--) {
        Entry temp = L->D[0];
        L->D[0] = L->D[i];
        L->D[i] = temp;
        heapify(L, i, 0);
    }
}

void generateRandomData(List* L, int n) {
    int i;
    L->n = n;
    srand((unsigned int)time(0));
    for (i = 0; i < n; i++) {
        L->D[i].key = rand() % 100000;
        snprintf(L->D[i].data, sizeof(L->D[i].data), "data%d", i);
    }
}

double measureSort(void (*sortFunc)(List*), List* L) {
   clock_t start, end;
   start = clock();
   sortFunc(L);
   end = clock();
   //printf("%lf,%lf,%lf\n", (double)end-start, (double)CLOCKS_PER_SEC,(double)(((double)(end - start)) / (double)CLOCKS_PER_SEC));
   return (double)(((double)(end - start)) / (double)CLOCKS_PER_SEC) * 1000;
}


// double measureSort(void (*sortFunc)(List*), List* L) {
//     struct timespec start, end;
//     clock_gettime(CLOCK_MONOTONIC, &start);
//     sortFunc(L);
//     clock_gettime(CLOCK_MONOTONIC, &end);

//     double elapsed = (end.tv_sec - start.tv_sec) * 1000.0;         
//     elapsed += (end.tv_nsec - start.tv_nsec) / 1000000.0;          
//     return elapsed;
// }




int main() {
    //int sizes[] = { 500, 10000, 50000, 100000 };
    int sizes[] = { 500, 10000, 50000, 100000 };
    int i, j;
    double timeTaken[6][4];
    void (*sorts[])(List*) = { simpleSelectionSort, directInsertionSort, bubbleSort, quickSort, mergeSort, heapSort };
    char* names[] = { "Selection(ms):", "Insertion(ms):", "Bubble(ms):", "Quick(ms):", "Merge(ms):", "Heap(ms):" };

    List L;
    L.D = (Entry*)malloc(MaxSize * sizeof(Entry));
    if (!L.D) exit(EXIT_FAILURE);

    for (i = 0; i < 4; i++) {
        generateRandomData(&L, sizes[i]);
        for (j = 0; j < 6; j++) {
            List temp;
            temp.D = (Entry*)malloc(sizes[i] * sizeof(Entry));
            if (!temp.D) exit(EXIT_FAILURE);
            memcpy(temp.D, L.D, sizes[i] * sizeof(Entry));
            temp.n = L.n;
            timeTaken[j][i] = measureSort(sorts[j], &temp);
            free(temp.D);
        }
    }

    FILE* fp = fopen("sort_results.csv", "w");
    if (!fp) {
        free(L.D);
        return EXIT_FAILURE;
    }

    fprintf(fp, "Algorithm,500,10000,50000,100000\n");
    for (i = 0; i < 6; i++) {
        fprintf(fp, "%s", names[i]);
        for (j = 0; j < 4; j++) {
            fprintf(fp, ",%.3lf", timeTaken[i][j]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
    free(L.D);
    return 0;
}
