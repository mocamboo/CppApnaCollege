#include <bits/stdc++.h>
using namespace std;

int largestPowerOf2(int n) {
    int x = 0;
    while ((1 << x) <= n)
        x++;
    return (x - 1);
}

int bitsTillN(int n) {
    if (n <= 0)
        return 0;
    int x = largestPowerOf2(n);
    int a = x * (1 << (x - 1)); /*largestpower*(2^(largestPower-1))*/
    int b = n - (1 << x) + 1;

    return a + b + bitsTillN(n - (1 << x));
}

int main() {
    cout << bitsTillN(11) << endl;

    return 0;
}