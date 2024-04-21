#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, target;
    cin >> n >> target;
    bool ans = false;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;

    sort(a.begin(), a.end());

    for (int i = 0; i < n - 1; i++)
    {
        int lo = i + 1;
        int hi = n - 1;
        while (lo < hi)
        {
            int curr = (a[i] + a[lo] + a[hi]);
            if (curr == target)
            {
                goto truee;
            }
            else if (target < curr)
            {
                hi--;
            }
            else
            {
                lo++;
            }
        }
    }
    cout << "false";
    return 0;
truee:
    cout << "true";

    return 0;
}