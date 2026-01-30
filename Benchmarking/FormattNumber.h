#ifndef FORMATTNUMBER_H_INCLUDED
#define FORMATTNUMBER_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

// Formata um numero double para string com pontos (ex: 1.000.000)
inline string formatNumber(double numero) {
    stringstream ss;
    ss << fixed << setprecision(0) << numero; // Garante que não saia notação científica

    string str = ss.str();
    int n = str.length();
    int count = 0;

    string formatted;
    for (int i = n - 1; i >= 0; --i) {
        if (count > 0 && count % 3 == 0) {
            formatted += '.';
        }
        formatted += str[i];
        count++;
    }

    reverse(formatted.begin(), formatted.end());
    return formatted;
}

#endif // FORMATTNUMBER_H_INCLUDED
