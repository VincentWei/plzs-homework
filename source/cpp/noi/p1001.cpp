/*
 * This program calculates the summary of two integer less then 10^9
 * by using the longest unsigned integer type (uint64_t).
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

int main()
{
    int64_t a, b;

    // 123456 1234567
    cin >> a >> b;
    cout << a + b << endl;

    return 0;
}
