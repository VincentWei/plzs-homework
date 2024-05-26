/*
 * This program implements arbitrary arithmetic for integer numbers:
 * addition, subtraction, and multiplication.
 *
 * XXX: NOT FINISHED.
 *
 * Copyright (C) 2024 FMSoft <https://www.fmsoft.cn>.
 * Author: Vincent Wei <https://github.com/VincentWei>.
 *
 * License: GPLv3
 */
#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

// complement number
// 7 - 3 = 7 + 6 - 10 + 1 = 13 - 10 + 1 = -4;
// 7 - 33 = 7 + 66 - 100 + 1 = 73 - 100 + 1 = 27 + 1 = -28;

void iap_add(string &result, const string &a, const string &b)
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

void iap_add_to(string &r, const string &a)
{
    size_t len_r = r.length();
    size_t len_a = a.length();
    size_t len_max = (len_r > len_a) ? len_r : len_a;

    int carry = 0;
    for (size_t i = 0; i < len_max; i++) {
        int digit_r = ((i < len_r) ? r[len_r - i - 1] : '0') - '0';
        int digit_a = ((i < len_a) ? a[len_a - i - 1] : '0') - '0';

        digit_r += digit_a + carry;
        if (digit_r >= 10) {
            carry = 1;
            digit_r -= 10;
        }
        else
            carry = 0;

        if (i >= len_r)
            r.insert(0, 1, '0' + digit_r);
        else
            r[len_r - i - 1] = '0' + digit_r;
    }

    if (carry > 0) {
        r.insert(0, 1, '1');
    }
}

bool iap_not_zero(const string &n)
{
    size_t len = n.length();
    for (size_t i = 0; i < len; i++) {
        if (n[i] != '0')
            return true;
    }

    return false;
}

void iap_mul(string &result, const string &a, const string &b)
{
    string times = "0";

    result = "0";
    while (b != times) {
        string tmp;
        iap_add(tmp, result, a);
        result = tmp;

        iap_add(tmp, times, "1");
        times = tmp;
    }
}

// 3 * (-10)
// -3 * 10
void iap_mul_op(string &result, const string &a, const string &b)
{
    string times = "0";
    result = "0";
    while (b != times) {
        iap_add_to(result, a);
        iap_add_to(times, "1");
    }
}

void iap_factorial(string &r, const string &n)
{
    string times = "1";

    r = n;
    while (n != times) {
        string tmp;
        iap_mul_op(tmp, r, times);
        r = tmp;

        iap_add_to(times, "1");
    }
}

void iap_dec(string &n)
{
    assert(n != "0" && n != "");

    size_t nr_digits = n.length();

    int digit0 = n[nr_digits - 1] - '0';
    int r = digit0 - 1;
    int borrow = 0;
    if (r < 0) {
        borrow = 1;
        r += 10;
    }
    n[nr_digits - 1] = '0' + r;

    size_t i = 1;
    while (borrow > 0) {
        int digit = n[nr_digits - i - 1] - '0';
        int r = digit - borrow;

        if (r < 0) {
            borrow = 1;
            r += 10;
        }
        else
            borrow = 0;

        n[nr_digits - i - 1] = '0' + r;
        i++;
    }

    if (n[0] == '0' && nr_digits > 1)
        n.erase(0, 1);
}

static vector<string> cached_factorial(50);

void iap_factorial_recursive(string &r, const string &n)
{
    if (n == "1") {
        r = "1";
        return;
    }

    int native_n;
    native_n = stoi(n);
    if (cached_factorial[native_n] != "") {
        r = cached_factorial[native_n];
        return;
    }

    string prev_n = n;
    iap_dec(prev_n);

    iap_factorial_recursive(r, prev_n);
    string tmp;
    iap_mul(tmp, r, n);
    r = tmp;

    // cached the result
    cached_factorial[native_n] = r;
}

void summary_of_factorials(string &r, const string &n)
{
    string times = "1";

    r = "0";
    if (!iap_not_zero(n))
        return;

    while (true) {
        string factorial;
        iap_factorial(factorial, times);
        iap_add_to(r, factorial);

        if (n == times)
            break;
        iap_add_to(times, "1");
    }
}

int main()
{
    string r;

    // test iap_add_to()
    r = "0";
    iap_add_to(r, "1");
    assert(r == "1");
    iap_add_to(r, "9");
    assert(r == "10");
    iap_add_to(r, "91");
    assert(r == "101");
    iap_add_to(r, "99");
    assert(r == "200");
    // cout << "test for iap_add_to() passed\n";

    // test iap_dec()
    r = "1";
    iap_dec(r);
    assert(r == "0");
    r = "2";
    iap_dec(r);
    assert(r == "1");
    r = "100";
    iap_dec(r);
    assert(r == "99");

    r = "10";
    iap_dec(r);
    assert(r == "9");
    // cout << "test for iap_dec() passed\n";

    // test iap_mul_op()
    iap_mul_op(r, "2", "2");
    assert(r == "4");
    iap_mul_op(r, "2", "10");
    assert(r == "20");
    iap_mul_op(r, "20", "20");
    assert(r == "400");
    iap_mul_op(r, "11", "11");
    assert(r == "121");
    // cout << "test for iap_mul_op() passed\n";

    // test for iap_factorial_recursive()
    r.clear();
    iap_factorial_recursive(r, "1");
    assert(r == "1");
    iap_factorial_recursive(r, "2");
    assert(r == "2");
    iap_factorial_recursive(r, "3");
    assert(r == "6");
    iap_factorial_recursive(r, "4");
    assert(r == "24");
    iap_factorial_recursive(r, "5");
    assert(r == "120");
    // cout << "test for iap_factorial_recursive() passed\n";

    // the real code for P1009
    string n;
    cin >> n;

    string summary;
    summary_of_factorials(summary, n);
    cout << summary << endl;
    return 0;
}
