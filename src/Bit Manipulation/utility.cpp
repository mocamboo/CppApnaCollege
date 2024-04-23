#include <bits/stdc++.h>
using namespace std;
int years(int n) {
    n /= 4;
    n /= 365;
    return n;
}
int main() {

    cout << years(10000);
    return 0;
}