/*
 * This program resolves P1010:
 *  <https://www.luogu.com.cn/problem/P1010>
 *
 * Author: Vincent Wei <https://github.com/VincentWei>
 *
 * Copyright (C) 2024 FMSoft <https://www.fmsoft.cn>.
 * License: GPLv3
 */
#include <iostream>
#include <sstream>
#include <string>
#include <cassert>

using namespace std;

static void print_power_of_2(ostream &out, uint64_t n)
{
    bool pre = false;

    for (int i = 63; i >= 0; i--) {
        if (n & (0x01UL << i)) {
            if (pre) {
                out << "+";
            }
            else {
                pre = true;
            }

            if (i == 0) {
                out << "2(0)";
            }
            else if (i == 1) {
                out << "2";
            }
            else {
                out <<"2(";
                print_power_of_2(out, (uint64_t)i);
                out <<")";
            }
        }
    }
}

int main()
{
    // test
    ostringstream foo;
    print_power_of_2(foo, 3);
    assert(foo.str() == "2+2(0)");

    ostringstream bar;
    print_power_of_2(bar, 137);
    assert(bar.str() == "2(2(2)+2+2(0))+2(2+2(0))+2(0)");

    ostringstream foobar;
    print_power_of_2(foobar, 1315);
    assert(foobar.str() == "2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2(0))+2+2(0)");

    uint64_t n;
    cin >> n;
    print_power_of_2(cout, n);
    cout << endl;
    return 0;
}
