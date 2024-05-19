/* This implementation is too slow.
   We need to optimize it forthmore.
*/

#include <iostream>
#include <string>

using namespace std;

void natural_add_ap(string &result, const string &a, const string &b)
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

bool natural_not_zero(const string &n)
{
    size_t len = n.length();
    for (size_t i = 0; i < len; i++) {
        if (n[i] != '0')
            return true;
    }

    return false;
}

void natural_mul_ap(string &result, const string &a, const string &b)
{
    string times = "0";
    string alt_b = b;

    result = "0";
    while (b != times) {
        string tmp;
        natural_add_ap(tmp, result, a);
        result = tmp;

        natural_add_ap(tmp, times, "1");
        times = tmp;
    }
}

void natural_factorial_ap(string &r, const string &n)
{
    string times = "1";

    r = n;
    while (n != times) {
        string tmp;
        natural_mul_ap(tmp, times, r);
        r = tmp;

        natural_add_ap(tmp, times, "1");
        times = tmp;
    }
}

void summary_of_factorials(string &r, const string &n)
{
    string times = "1";

    r = "0";
    while (true) {
        string factorial, summary;
        natural_factorial_ap(factorial, times);
        natural_add_ap(summary, r, factorial);

        r = summary;

        if (n == times)
            break;

        string tmp;
        natural_add_ap(tmp, times, "1");
        times = tmp;
    }
}

int main()
{
    string n;
    cin >> n;

    string summary;
    summary_of_factorials(summary, n);
    cout << summary << endl;
    return 0;

    string a, b;
    cin >> a >> b;

    string result;

    natural_add_ap(result, a, b);
    cout << result << endl;

    natural_mul_ap(result, a, b);

    cout << result << endl;

    return 0;
}
