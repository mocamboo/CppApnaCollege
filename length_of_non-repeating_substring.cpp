#include <bits/stdc++.h>
using namespace std;
int main()
{

    string s;
    cin >> s;
    int ans = 0, start = -1;
    vector<int> dict(256, -1);
    for (int i = 0; i < s.size(); i++)
    {
        if (dict[s[i]] > start)
            start = dict[s[i]];
        dict[s[i]] = i;
        ans = max(ans, i - start);
    }
    cout << ans << endl;

    return 0;
}