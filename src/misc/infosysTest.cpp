#include <bits/stdc++.h>
using namespace std;

bool yn(int* occ, int t, int o) { for (int i = t + 1) }
string properString(string s, int n) {
    int occ[5] = {0}; // occurence array
    occ[4] = INT_MAX;
    for (int i = 0; i < 4; i++) {
        occ[s[i] - 'a']++;
    }

    for (int i = 0; i < n; i++) {
        int t = s[i] - 'a';
        int o = n / 4 if (yn(occ, t, o) && occ[t] > o) {}
    }
}
int main() {
    int t;
    while (t--) {
        int n;
        string s;
        cout << "size, string(only a,b,c,d)\n";
        cin >> n >> s;
        cout << properString(s, n);
    }

    return 0;
}