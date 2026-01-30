#ifndef HEAPSORT_H_INCLUDED
#define HEAPSORT_H_INCLUDED

#include <vector>
#include "FormattNumber.h"

using namespace std;

void heapify(vector<int>& arr, int n, int i, double& comparacoes, double& movimentacoes) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n) {
        comparacoes++;
        if (arr[left] > arr[largest]) largest = left;
    }
    if (right < n) {
        comparacoes++;
        if (arr[right] > arr[largest]) largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        movimentacoes++;
        heapify(arr, n, largest, comparacoes, movimentacoes);
    }
}

void heapSort(vector<int>& arr, double& comparacoes, double& movimentacoes) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, comparacoes, movimentacoes);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        movimentacoes++;
        heapify(arr, i, 0, comparacoes, movimentacoes);
    }
}

#endif // HEAPSORT_H_INCLUDED
