/*
 * This program implements arbitrary arithmetic for natural numbers:
 * addition, subtraction (decrement), and multiplication.
 *
 * Copyright (C) 2024 FMSoft <https://www.fmsoft.cn>.
 * License: GPLv3
 */
#include <iostream>
#include <string>
#include <vector>
#include <cassert>

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

void nap_add_to(string &r, const string &a)
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

bool nap_not_zero(const string &n)
{
    size_t len = n.length();
    for (size_t i = 0; i < len; i++) {
        if (n[i] != '0')
            return true;
    }

    return false;
}

void nap_mul(string &result, const string &a, const string &b)
{
    string times = "0";

    result = "0";
    while (b != times) {
        string tmp;
        nap_add(tmp, result, a);
        result = tmp;

        nap_add(tmp, times, "1");
        times = tmp;
    }
}

void nap_mul_op(string &result, const string &a, const string &b)
{
    string times = "0";
    result = "0";
    while (b != times) {
        nap_add_to(result, a);
        nap_add_to(times, "1");
    }
}

void nap_factorial(string &r, const string &n)
{
    string times = "1";

    r = n;
    while (n != times) {
        string tmp;
        nap_mul_op(tmp, r, times);
        r = tmp;

        nap_add_to(times, "1");
    }
}

void nap_dec(string &n)
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

void nap_factorial_recursive(string &r, const string &n)
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
    nap_dec(prev_n);

    nap_factorial_recursive(r, prev_n);
    string tmp;
    nap_mul(tmp, r, n);
    r = tmp;

    // cached the result
    cached_factorial[native_n] = r;
}

void summary_of_factorials(string &r, const string &n)
{
    string times = "1";

    r = "0";
    if (!nap_not_zero(n))
        return;

    while (true) {
        string factorial;
        nap_factorial(factorial, times);
        nap_add_to(r, factorial);

        if (n == times)
            break;
        nap_add_to(times, "1");
    }
}

int main()
{
    string r;

    // test nap_add_to()
    r = "0";
    nap_add_to(r, "1");
    assert(r == "1");
    nap_add_to(r, "9");
    assert(r == "10");
    nap_add_to(r, "91");
    assert(r == "101");
    nap_add_to(r, "99");
    assert(r == "200");
    // cout << "test for nap_add_to() passed\n";

    // test nap_dec()
    r = "1";
    nap_dec(r);
    assert(r == "0");

    r = "10";
    nap_dec(r);
    assert(r == "9");
    // cout << "test for nap_dec() passed\n";

    // test nap_mul_op()
    nap_mul_op(r, "2", "2");
    assert(r == "4");
    nap_mul_op(r, "2", "10");
    assert(r == "20");
    nap_mul_op(r, "20", "20");
    assert(r == "400");
    nap_mul_op(r, "11", "11");
    assert(r == "121");
    // cout << "test for nap_mul_op() passed\n";

    // test for nap_factorial_recursive()
    r.clear();
    nap_factorial_recursive(r, "1");
    assert(r == "1");
    nap_factorial_recursive(r, "2");
    assert(r == "2");
    nap_factorial_recursive(r, "3");
    assert(r == "6");
    nap_factorial_recursive(r, "4");
    assert(r == "24");
    nap_factorial_recursive(r, "5");
    assert(r == "120");
    // cout << "test for nap_factorial_recursive() passed\n";

    // the real code for P1009
    string n;
    cin >> n;

    string summary;
    summary_of_factorials(summary, n);
    cout << summary << endl;
    return 0;
}
