#ifndef SHELLSORT_H_INCLUDED
#define SHELLSORT_H_INCLUDED

#include <vector>
#include "FormattNumber.h"

using namespace std;

void shellSort(vector<int>& arr, double& comparacoes, double& movimentacoes) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap; j -= gap) {
                comparacoes++;
                if (arr[j - gap] > temp) {
                    arr[j] = arr[j - gap];
                    movimentacoes++;
                } else {
                    break;
                }
            }
            arr[j] = temp;
            movimentacoes++;
        }
    }
}

#endif // SHELLSORT_H_INCLUDED
