/*
 * This program resolves P1009 by using the longest native integer type:
 *  <https://www.luogu.com.cn/problem/P1009>
 *
 * Author: Vincent Wei <https://github.com/VincentWei>
 *
 * Copyright (C) 2024 FMSoft <https://www.fmsoft.cn>.
 * License: GPLv3
 */
#include <iostream>
#include <cassert>

using namespace std;

uint64_t uint64_t_factorial(uint64_t n)
{
    uint64_t factorial = 1;
    uint64_t r = 2;
    while (r <= n) {
        factorial *= r;
        r++;
    }

    return factorial;
}

uint64_t summary_of_factorials(uint64_t maxn)
{
    uint64_t summary = 0;
    uint64_t n = 1;

    while (true) {
        summary += uint64_t_factorial(n);

        if (n == maxn)
            break;
        n++;
    }

    return summary;
}

int main()
{
    uint64_t n;
    cin >> n;

    uint64_t summary;
    summary = summary_of_factorials(n);
    cout << summary << endl;
    return 0;
}
