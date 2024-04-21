#include <bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}
int expo(int n, int m)
{
    if (m == 0)
        return 1;
    return n * expo(n, m - 1);
}
int Mexpo(int n, int m)
{
    if (m == 0)
        return 1;
    if (m % 2 == 0)
        return Mexpo(n * n, m / 2);
    else
        return n * Mexpo(n * n, (m - 1) / 2);
}

double tayler(int x, int n)
{
    static double p = 1, f = 1;
    if (n == 0)
        return 1;

    double r = tayler(x, n - 1);
    p = p * x;
    f = f * n;
    return r + p / f;
}

int main()
{
    int n = 6;
    cout << factorial(n) << endl;

    int m = 3;
    n = 4;
    cout << Mexpo(4, 3) << endl;

    cout << tayler(1, 3) << "_______" << endl;
    return 0;
}