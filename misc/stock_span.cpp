#include <bits/stdc++.h>
using namespace std;
vector<int> stockspan(vector<int> prices)
{
    vector<int> ans;
    stack<pair<int, int>> st;

    for (auto price : prices)
    {
        int day = 1;
        while (!st.empty() && st.top().first <= price)
        {
            day += st.top().second;
            st.pop();
        }
        st.push({price, day});
        ans.push_back(day);
    }

    return ans;
}
int main()
{
    vector<int> v = {100, 80, 60, 70, 60, 75, 85};
    vector<int> ans = stockspan(v);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}