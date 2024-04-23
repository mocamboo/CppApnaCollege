#include <bits/stdc++.h>
using namespace std;
int sortingSolution(vector<int> nums) {
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i] == nums[i + 1])
            return nums[i];
    }
    return -1;
}

int indexSolution(vector<int> nums) { // Doesn't work in all situations
    for (int i = 0; i < nums.size(); i++) {

        int index = abs(nums[i]) - 1;

        nums[index] *= -1;
        if (nums[index] > 0)
            return abs(nums[i]);
    }
    return -1;
}

int floydSolution(vector<int> nums) { // Won't if there is no duplicate & whole elements(infinite lopp)
    int hare = nums[0];
    int tortoise = nums[0];
    do {
        hare = nums[nums[hare]];
        tortoise = nums[tortoise];
    } while (hare != tortoise);
    tortoise = nums[0];
    while (hare != tortoise) {
        hare = nums[hare];
        tortoise = nums[tortoise];
    }
    return hare;
}

int main() {
    vector<int> num1 = {1, 3, 5, 2, 8, 9, 7, 6, 3, 4}; // 3
    vector<int> num2 = {1, 2, 7, 1, 8, 9, 6};          //-1
    cout << "Sorting Solution:" << endl;
    cout << sortingSolution(num1) << endl;
    cout << sortingSolution(num2) << endl;

    cout << "Index Solution:" << endl;
    cout << indexSolution(num1) << endl;
    cout << indexSolution(num2) << endl; // won't work

    cout << "FloydSolution:" << endl;
    cout << floydSolution(num1) << endl;
    cout << floydSolution(num2) << endl; // infinite loop

    return 0;
}