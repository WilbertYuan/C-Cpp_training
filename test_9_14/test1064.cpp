#include <cstdio>
#include <algorithm>

bool canCut(int* cables, int N, int len, int K) {
    int count = 0;
    for (int i = 0; i < N; ++i) {
        count += cables[i] / len;
        if (count >= K) return true;
    }
    return false;
}

int main() {
    int N, K;
    scanf_s("%d %d", &N, &K);

    int* cables = new int[N];

    for (int i = 0; i < N; ++i) {
        double length;
        scanf_s("%lf", &length);
        cables[i] = (int)(length * 100 + 0.5); // Convert to integer centimeters
    }

    int left = 1, right = *std::max_element(cables, cables + N);
    int result = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canCut(cables, N, mid, K)) {
            result = mid; // Update result
            left = mid + 1; // Try for a longer length
        }
        else {
            right = mid - 1; // Try for a shorter length
        }
    }

    if (result == 0) {
        printf("0.00\n");
    }
    else {
        printf("%.2f\n", result / 100.0);
    }

    delete[] cables; // Clean up dynamically allocated memory
    return 0;
}
