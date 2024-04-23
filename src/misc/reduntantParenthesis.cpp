#include <bits/stdc++.h>
using namespace std;

int redP(string s) {
    stack<char> st;
    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            st.push(s[i]);
        } else if (s[i] == '(') {
            st.push(s[i]);
        } else if (s[i] == ')') {
            if (st.top() == '(') {
                ans = 1;
            }
            while (st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/' || st.top() == '(') {
                st.pop();
            }
            st.pop();
        }
    }
    return ans;
}
int main() {
    string s = "((a+b))";
    if (redP(s)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    return 0;
}