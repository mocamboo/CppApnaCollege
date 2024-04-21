#include <bits/stdc++.h>
using namespace std;
int maxSubArraySum(int arr[], int n, int k, int x)
{
    int sum = 0;
    int maxsum;
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    sum < x ? maxsum = sum : maxsum = 0;
    for (int i = 0; i < n - k; i++)
    {
        maxsum = max(maxsum, sum);
        sum += arr[k + i];
        sum -= arr[i];
    }
    return maxsum;
}
int smallestSubarrayWithSum(int arr[], int n, int x){
    int start=0;
    int ans=INT_MAX;
    int sum=0;
    int length=0;
    for(int i=0; i<n; i++){
        while(sum>x){
            ans=min(ans,length);
            length--;
            sum-=arr[start];
            start++;
        }
        sum+=arr[i];
        length++;
    }
    return ans;
}

int main()
{
    int arr[] = {7, 5, 4, 6, 8, 9};
    int n = 6;
    int k = 3;  /*size=3*/
    int x = 20; /*sum<x*/ 
    cout << maxSubArraySum(arr, n, k, x);//ans=18
    cout<<endl;
    int brr[]={1,4,45,7,10,19};
    int y=51;
    cout<<smallestSubarrayWithSum(brr,6,y);//ans=2

    return 0;
}