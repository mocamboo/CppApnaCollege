#include <iostream>
using namespace std;

// to return two values
struct Pair {
    int min;
    int max;
};

// function to find min and max of an array
Pair getMinMax(int arr[], int n) {
    struct Pair minMax;
    if (n == 1) {
        minMax.min = arr[0];
        minMax.max = arr[0];
        return minMax;
    }
    // first initialization
    if (arr[0] > arr[1]) {
        minMax.min = arr[1];
        minMax.max = arr[0];
    } else {
        minMax.min = arr[0];
        minMax.max = arr[1];
    }

    // loop
    for (int i = 2; i < n; i++) {
        if (arr[i] > minMax.max) {
            minMax.max = arr[i];
        } else if (arr[i] < minMax.min) {
            minMax.min = arr[i];
        }
    }
    return minMax;
}
// alt2. Tournament Method
Pair MaxMin(int arr[], int l, int h) {
    struct Pair minmax, mml, mmr;
    if (l == h) {
        minmax.max = arr[l];
        minmax.min = arr[h];
        return minmax;
    }
    if (h == l + 1) {
        if (arr[h] > arr[l]) {
            minmax.max = arr[h];
            minmax.min = arr[l];
        } else {
            minmax.min = arr[h];
            minmax.max = arr[l];
        }
        return minmax;
    }
    int mid = (l + h) / 2;
    mml = MaxMin(arr, l, mid);
    mmr = MaxMin(arr, mid + 1, h);
    if (mml.min > mmr.min) {
        minmax.min = mmr.min;
    } else {
        minmax.min = mml.min;
    }

    if (mml.max > mmr.max) {
        minmax.max = mml.max;
    } else {
        minmax.max = mmr.max;
    }

    return minmax;
}

// main driver function
int main() {
    int arr[] = {2, 5, 3, 36, 456, 86, 34, 9, 0, -13, 6, 0, -223, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    struct Pair minMax = getMinMax(arr, n);
    cout << "max is " << minMax.max << endl;
    cout << "min is " << minMax.min << endl;

    // with alternative method
    struct Pair minmax = MaxMin(arr, 0, n - 1);
    cout << "alternative " << minmax.max << " and " << minmax.min << endl;
    return 0;
}