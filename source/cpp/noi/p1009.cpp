#include <iostream>
#include <string>

using namespace std;

void natural_add_ap(string &result, const string &a, const string &b)
{
    size_t len_a = a.length();
    size_t len_b = b.length();
    size_t len_max = (len_a > len_b) ? len_a : len_b;

    int c = 0;
    for (size_t i = 0; i < len_max; i++) {
        int n_a = ((i < len_a) ? a[len_a - i - 1] : '0') - '0';
        int n_b = ((i < len_b) ? b[len_b - i - 1] : '0') - '0';

        int r_org = n_a + n_b;
        int r = r_org + c;
        if (r > 10) {
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

void natural_reduce_ap(string &result, const string &a, const string &b)
{
}

void natural_mul_ap(string &result, const string &a, const string &b)
{
    string summary = "0";
    string alt_b = b;
    while (natural_not_zero(alt_b)) {
        string result;
        natural_add_ap(result, summary, a);
        summary = result;

        natural_reduce_ap(result, alt_b, "1");
        result = alt_b;
    }
}

int main()
{
    string a, b;

    cin >> a >> b;

    string result;
    natural_add_ap(result, a, b);

    cout << result << endl;

    return 0;
}
