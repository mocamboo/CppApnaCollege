#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<int> v(n);
        for (auto& i : v) {
            cin >> i;
        }
        sort(v.begin(), v.end());
        int d = n / 2;

        int sum_blue = 0;
        int sum_red = 0;
        for (int i = 0; i < n; i++) {
            cout << v[i] << "--";
            if (n % 2 == 0) {
                if (i < d) {
                    sum_blue += v[i];
                } else {
                    sum_red += v[i];
                }
            } else {
                if (i <= d) {
                    sum_blue += v[i];
                } else {
                    sum_red += v[i];
                }
            }
        }
        cout << endl;
        if (sum_red > sum_blue) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}