#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
bool check(long long int n) {
    int qsum = 0;

    long long int m = n;
    while (n != 0) {
        int rem = n % 10;

        qsum += pow(rem, 4);
        n /= 10;
    }
    n = m;
    while (n != 0) {
        int rem = n % 10;
        // for(int i=2;i<=rem;i++){
        //     if(rem%i==0){
        //         if(qsum%i==0){
        //             return true;
        //         }
        //     }
        // }
        if (gcd(rem, qsum) > 1) {
            return true;
        }
        n /= 10;
    }
    // if(gcd(psum,qsum)>1){
    //     return true;
    // }
    return false;
}
int main() {
    long long n = 1000;
    // for (int n = 100; n <= 10234; n++)
    // {
    if (check(n)) {
        cout << "__yes" << endl;
    } else {
        cout << "___No" << endl;
    }
    // }

    return 0;
}