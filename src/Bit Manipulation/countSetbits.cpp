#include<bits/stdc++.h>
using namespace std;
int countSetbits(int n){
    int count = 0;
    while(n){
        count += n & 1;
        n=n >> 1;
    }
    return count;
}
int countSetBits2(int n){
    int count=0;
    while(n){
        count++;
        n &= (n - 1);
    }
    return count;
}
int main(){

    cout << countSetbits(15) << endl;
    cout << countSetbits(16) << endl;
    cout << countSetbits(10) << endl;
    return 0;
}