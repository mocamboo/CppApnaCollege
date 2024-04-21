#include<bits/stdc++.h>
using namespace std;

//swap function

void swap(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}

void countSort(int arr[], int n){
    int k=arr[0];
    for (int i = 0; i < n; i++){
        k = max(k, arr[i]);
    }
    int count[k+1] = {0};

    for (int i = 0; i < n; i++){
        count[arr[i]]++;
    }
    for (int i = 1; i <= k; i++){
        count[i]+= count[i - 1];
    }
    int temp[n];
    for (int i = n - 1; i >= 0; i--){
        temp[--count[arr[i]]] = arr[i];
    }
    for (int i = 0; i < n; i++){
        arr[i] = temp[i];
    }
}


/*______________________________MergeSort___________________________________*/
//Merge function
void merge(int arr[], int l, int mid, int h){
    int i,j,k;
    i=l;j=mid+1;k=l;
    int b[100];
    while(i<=mid && j<=h){
        if(arr[i]<arr[j])b[k++]=arr[i++];
        else b[k++]=arr[j++];
    }
    while(i<=mid)b[k++]=arr[i++];
    while(j<=h)b[k++]=arr[j++];
    for(i=l; i<=h; i++){
        arr[i]=b[i];
    }
}

void mergeSort(int arr[], int l, int h){
    if(l<h){
        int mid=(l+h)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,h);
        merge(arr,l,mid,h);
    }
}


/*____________________________________________QuickSort_______________________________________________*/
//partition function
int partition2(int arr[], int l, int h){
    int pi=arr[h];
    int i=l-1;
    for(int j=l; j<h; j++){
        if(arr[j]<pi){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1],arr[h]);
    return (i+1);
}
int partition(int arr[], int l , int h){
    int pivot=arr[l];
    int i=l;
    int j=h;
    
    do
    {
        do{i++;}while(arr[i]<=pivot);//////<=
        do{j--;}while(arr[j]>pivot);
        if(i<j)swap(arr[i],arr[j]);
    } while (i<j);
    swap(arr[l],arr[j]);
    return j;
    
}


//*QuickSort*/
//Select the element and find its correct position in sorted array
void QuickSort(int arr[], int l, int h){
    if(l<h){
         int j=partition(arr,l,h);
         QuickSort(arr,l,j-1);
         QuickSort(arr,j+1,h);
    }
}



/*_______________________________________________________________________________________________________________________________*/
//Selection Sort
/*
-----k-pass is useful
-----minimum element at the begining
-----Select a position and find the element for that position 
*/

void selectionSort(int arr[], int n){
    for(/*passes*/ int i=0;i<n-1; i++){
        int j=i,k=i;
        for(j; j<n; j++ ){
            if(arr[j]<arr[k]){
                k=j;
            }

        }//now k will point to sortest element in the unsorted array
        swap(arr[k], arr[i]);
    }
    
}

/*________________________________________________________________________________________________________________________________________*/
//Bubble Sort--
/*
---stable
---kPass is useful
---Biggest element at the end
---to make adaptive, introduce flag in outer loop
*/
void bubbleSort(int *arr, int n){
    for(/*passes*/ int i=0; i<n-1; i++){
        int flag=0;
        for(int j=0; j<n-(1+i); j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag=1;
            }
        }
        if(flag==0)break;
    }
}

/*____________________________________________________________________________________________________________________________________________________________*/
//Inserction Sort
/*find the correct position of a elemnt in sorted array*/
void inserctionSort(int arr[], int n){
    for(int i=1; i<n;  i++){
        int x=arr[i];
        int j=i-1;
        while( arr[j]>x && j>-1 ){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j + 1] = x;
    }
}



int main(){
    int arr[]={3,2,6,0,1,5,9743,834,43,8,0,0,0,8,5};
    int n=sizeof(arr)/sizeof(arr[0]);

    
    // 0 0 0 0 1 2 3 5 5 6 8 8 43 834 9743
    countSort(arr,n);
     for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    


   
    
    
    return 0;
    
    
}