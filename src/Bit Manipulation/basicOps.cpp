#include<bits/stdc++.h>
using namespace std;
int setBit(int n,int pos){
    return n | (1 << pos);
}
int getBit(int n, int pos){
    return n & (1 << pos);
}
int unsetBit(int n,int pos){
    return n & ~(1 << pos);
}

int main(){
    int arr[5] = {8, 5, 7, 15, 2};
    for(int i:arr){
        cout << unsetBit(i,0) << " ";
    }

    return 0;
}