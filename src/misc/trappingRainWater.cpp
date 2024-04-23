#include <bits/stdc++.h>
using namespace std;
int totalWater_brute(vector<int> v) {
    int lmax[v.size()], rmax[v.size()];
    lmax[0] = 0;
    rmax[v.size() - 1] = 0;
    int lm = 0;
    for (int i = 1; i < v.size(); i++) {
        lm = max(lm, v[i - 1]);
        lmax[i] = lm;
    }
    lm = 0;
    for (int i = v.size() - 2; i >= 0; i--) {
        lm = max(lm, v[i + 1]);
        rmax[i] = lm;
    }
    int minLR[v.size()];
    int ans = 0;
    for (int i = 0; i < v.size(); i++) {
        ans += max((min(lmax[i], rmax[i])) - v[i], 0);
    }
    return ans;
}
int totalWater_opt(vector<int> v) {
    stack<int> st;
    int ans = 0, n = v.size();

    for (int i = 0; i < v.size(); i++) {

        while (!st.empty() && v[st.top()] < v[i]) {
            int curr = st.top();
            st.pop();
            if (st.empty()) {
                break;
            }
            int diff = i - st.top() - 1;
            ans += (min(v[st.top()], v[i]) - v[curr]) * diff;
        }

        st.push(i);
    }
    return ans;
}
int main() {
    vector<int> v = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << totalWater_opt(v) << endl;
    return 0;
}