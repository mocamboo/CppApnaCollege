#include <bits/stdc++.h>
using namespace std;
int opr(string s, string temp)
{
    int st = s.find(temp);
    cout << st << " st";
    int size_temp = temp.size();
    int size_s = s.size();
    if (st == 0)
    {
        return size_s - size_temp;
    }
    else
    {
        return size_s + size_temp;
    }
}
int ans(string t, string t) int main()
{
    string t, s;
    getline(cin, t);
    cin >> s;

    return 0;
}