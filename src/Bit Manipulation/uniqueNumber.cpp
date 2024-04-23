#include <bits/stdc++.h>
using namespace std;
int getBit(int n, int pos) { return n & (1 << pos); }
int setBit(int n, int pos) { return n | (1 << pos); }
int oneUniqueTwice(vector<int> nums) {
    int xorsum = 0;
    for (int i : nums) {
        xorsum ^= i;
    }
    return xorsum;
}

int oneUniqueThrice(vector<int> nums) {
    int result = 0;
    for (int i = 0; i < 64; i++) {
        int sum = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (getBit(nums[j], i))
                sum++;
        }
        if (sum % 3 != 0)
            result = setBit(result, i);
    }
    return result;
}
vector<int> twoUniqueTwice(vector<int> nums) {
    vector<int> ans;

    int xorsum = 0;
    for (int i : nums) {
        xorsum ^= i;
    }

    /*to find rightmost setbit in xorsum*/
    int pos = 0;
    int setbit = 0;
    int temp = xorsum;
    while (!setbit) {
        setbit = xorsum & 1;
        pos++;
        xorsum >>= 1;
    }
    pos -= 1;
    int newxor = 0;
    /*new xor of numbers which have setbit at pos*/
    for (int i : nums) {
        if (getBit(i, pos))
            newxor ^= i;
    }
    ans.push_back(newxor);
    ans.push_back(newxor ^ temp);
    return ans;
}

int main() {
    vector<int> nums = {1111,

                        65,   5768, 37686, 8, 78,

                        65,   5768, 37686, 8, 78,

                        65,   5768, 37686, 8, 78};
    // vector<int> ans = twoUniqueTwice(nums);
    // for(int i:ans){
    //     cout << i << " ";
    // }
    cout << oneUniqueThrice(nums);
    return 0;
}