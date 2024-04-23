#include <bits/stdc++.h>
using namespace std;

int andOfAll(int left, int right) {
    if (left == 0 || right == 0)
        return 0;

    // if number of digitd are different then answer will be zero
    if ((int)log2(left) != (int)log2(right))
        return 0;

    int res = left;
    for (int i = left; i <= right; i++) {
        res &= i;
    }
    return res;
}

int main() {
    cout << andOfAll(2, 3);
    return 0;
}