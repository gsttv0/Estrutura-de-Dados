#ifndef MERGESORT_H_INCLUDED
#define MERGESORT_H_INCLUDED

#include <vector>
#include <iterator>
#include "FormattNumber.h"

using namespace std;

void merge(vector<int>& arr, vector<int>::iterator left, vector<int>::iterator mid, vector<int>::iterator right, double& comparacoes, double& movimentacoes) {
    vector<int> L(left, mid + 1);
    vector<int> R(mid + 1, right + 1);

    auto itL = L.begin(), itR = R.begin(), it = left;

    while (itL != L.end() && itR != R.end()) {
        comparacoes++;
        if (*itL <= *itR) {
            *it = *itL;
            ++itL;
        } else {
            *it = *itR;
            ++itR;
        }
        ++it;
        movimentacoes++;
    }

    while (itL != L.end()) {
        *it = *itL;
        ++it;
        ++itL;
        movimentacoes++;
    }

    while (itR != R.end()) {
        *it = *itR;
        ++it;
        ++itR;
        movimentacoes++;
    }
}

void mergeSort(vector<int>& arr, vector<int>::iterator left, vector<int>::iterator right, double& comparacoes, double& movimentacoes) {
    if (left < right) {
        auto mid = left + distance(left, right) / 2;

        mergeSort(arr, left, mid, comparacoes, movimentacoes);
        mergeSort(arr, mid + 1, right, comparacoes, movimentacoes);
        merge(arr, left, mid, right, comparacoes, movimentacoes);
    }
}

#endif // MERGESORT_H_INCLUDED
