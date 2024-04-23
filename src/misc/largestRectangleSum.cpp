#include <bits/stdc++.h>
using namespace std;
int maxArea_brute(vector<int> a) {
    int ans = 0;

    for (int i = 0; i < a.size(); i++) {

        int minh = i;
        for (int j = i; j < a.size(); j++) {
            minh = min(minh, a[j]);
            int len = j - i;
            ans = max(ans, minh * len);
        }
    }
    return ans;
}
int maxArea_opti(vector<int> a) {
    int ans = 0;
    stack<int> st;
    st.push(0);
    for (int i = 0; i < a.size(); i++) {
        int len = 1;
        while (a[i] < st.top()) {
            ans = max(ans, st.top() * (len++));
            st.pop();
        }
        st.push(a[i]);
    }

    return ans;
}
int main() {

    vector<int> a = {2, 1, 5, 6, 2, 3};
    int ans = 0;

    cout << maxArea_opti(a) << endl;

    return 0;
}