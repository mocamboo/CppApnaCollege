#include<bits/stdc++.h>

using namespace std;
int main()
{
    vector<int> ip;
    string s="32, 33, 66";
    istringstream iss(s);
    int n;
    char c;
    while(iss>>n>>c||iss>>n)
        ip.push_back(n);
    
    for(int i:ip){
        cout << i << " ";
    }
        return 0;
}