#include <bits/stdc++.h>
using namespace std;

bool check(long int n) {
    long int m = n;
    long int qsum = 0;
    while (n != 0) {
        // sum = sum *(n % 10);
        qsum += pow(n % 10, 4);
        n /= 10;
    }
    n = m;
    while (n != 0) {
        long long rem = n % 10;

        if (qsum % rem == 0 && rem > 1) {
            return true;
        }
        n /= 10;
    }
    return false;
}
int main() {
    // code
    int t;
    cin >> t;
    while (t--) {
        long int n;
        cin >> n;
        long int ans = 0;
        for (long int i = 2; i <= n; i++) {
            if (check(i) == true) {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}