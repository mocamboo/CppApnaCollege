#include <bits/stdc++.h>
using namespace std;
int main()
{

    int k; // k=3=>o/p=10
    cin >> k;
    vector<int> a = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    int j = 0, zerocnt = 0, ans = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == 0)
        {
            zerocnt++;
        }
        while (zerocnt > k)
        {
            if (a[j] == 0)
            {
                zerocnt--;
            }
            j++;
        }

        ans = max(ans, (i - j + 1));
    }
    cout << ans << endl;

    return 0;
}