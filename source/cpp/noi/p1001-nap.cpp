/*
 * This program calculates the summary of two integer less then 10^9
 * by using the arbitrary precision arithmetic of natural numbers.
 *
 * It resolves problem P1001:
 *  <https://www.luogu.com.cn/problem/P1001>
 *
 * Author: Vincent Wei <https://github.com/VincentWei>
 *
 * Copyright (C) 2024 FMSoft <https://www.fmsoft.cn>.
 * License: GPLv3
 */
#include <iostream>
#include <string>

using namespace std;

void nap_add(string &result, const string &a, const string &b)
{
    size_t len_a = a.length();
    size_t len_b = b.length();
    size_t len_max = (len_a > len_b) ? len_a : len_b;

    result.clear();
    int c = 0;
    for (size_t i = 0; i < len_max; i++) {
        int n_a = ((i < len_a) ? a[len_a - i - 1] : '0') - '0';
        int n_b = ((i < len_b) ? b[len_b - i - 1] : '0') - '0';

        int r = n_a + n_b + c;
        if (r >= 10) {
            c = 1;
            r -= 10;
        }
        else
            c = 0;

        result.insert(0, 1, '0' + r);
    }

    if (c > 0) {
        result.insert(0, 1, '1');
    }
}

int main()
{
    string a, b;

    cin >> a >> b;

    string result;
    nap_add(result, a, b);
    cout << result << endl;

    return 0;
}
