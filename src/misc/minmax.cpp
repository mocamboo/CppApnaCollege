#include <iostream>
using namespace std;
struct pair1 {
    int min;
    int max;
};
// method 1;
struct pair1 getMinMax(int arr[], int n) {
    struct pair1 minmax;
    if (n == 1) {
        minmax.min = arr[0];
        minmax.max = arr[0];
        return minmax;
    }
    if (arr[0] > arr[1]) {
        minmax.min = arr[1];
        minmax.max = arr[0];
    } else {
        minmax.min = arr[0];
        minmax.max = arr[1];
    }
    for (int i = 2; i < n; i++) {
        if (arr[i] > minmax.max) {
            minmax.max = arr[i];
        } else if (arr[i] < minmax.min) {
            minmax.min = arr[i];
        }
    }
    return minmax;
}

// method 2;
struct pair1 getMinMax(int arr[], int low, int high) {
    struct pair1 minmax, mml, mmr;
    int mid;
    if (low == high) {
        minmax.min = arr[low];
        minmax.max = arr[low];
        return minmax;
    }
    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            minmax.min = arr[high];
            minmax.max = arr[low];
        } else {
            minmax.min = arr[low];
            minmax.max = arr[high];
        }
        return minmax;
    }
    mid = (low + high) / 2;
    mml = getMinMax(arr, low, mid);
    mmr = getMinMax(arr, mid + 1, high);
    if (mml.min < mmr.min) {
        minmax.min = mml.min;
    } else {
        minmax.min = mmr.min;
    }
    if (mml.max > mmr.max) {
        minmax.max = mml.max;
    } else {
        minmax.max = mmr.max;
    }
    return minmax;
}
int main() {
    int arr[] = {1, 2, -12, 43432, 432, 0, 953345, -3432};
    int n = 8;
    struct pair1 ans1 = getMinMax(arr, n);
    struct pair1 ans2 = getMinMax(arr, 0, n);
    cout << "By method 1=>  " << "min : " << ans1.min << " & max : " << ans1.max << endl;
    cout << "By method 2=>  " << "min : " << ans2.min << " & max : " << ans2.max << endl;
    return 0;
}