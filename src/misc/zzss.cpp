#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;
        int ans = s / (n * n);
        cout << ans << endl;
    }

    return 0;
}