#include<bits/stdc++.h>
using namespace std;

//swap function
void swap(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}

int findMax(int arr[], int n){ 
    int max=INT_MIN;
    for(int i=0; i<n; i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}


void countSort(int arr[], int n){
    int max=findMax(arr,n);
    int *c;
    int i,j;
    j=0;
    
    c= new int[max+1];
    for( i=0; i<=max; i++){
        c[i]=0;
        
    }
    for(i=0; i<=max;i++){
        c[arr[i]]++;
        
    }
    i=0;
    
    cout<<"***********"<<endl;
    while(j<=max){
        if(c[j]>0){
            arr[i++]=j;
            c[j]--;
            
        }
        else{
            j++;
        }
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
        do{i++;}while(arr[i]<=pivot);
        do{j--;}while(arr[j]>pivot);
        if(i<j)swap(arr[i],arr[j]);
    } while (i<j);
    swap(arr[l],arr[j]);
    return j;
    
}

/*QuickSort*/
//Select the element and find its correct sorted position.

void QuickSort(int arr[], int l, int h){
    if(l<h){
         int j=partition(arr,l,h);
         QuickSort(arr,l,j);
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
        int j,k;
        for(j=k=i; j<n; j++ ){
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
        while(j>-1 && arr[j]>x){
            arr[j+1]=arr[j];
            j--;
        }
        swap(arr[j+1],x);
    }
}



int main(){
    int arr[]={3,2,6,0,1,5,9743,-111,834,43,8,0,0,0,8,5};
    int n=sizeof(arr)/sizeof(arr[0]);

    

    countSort(arr,n);
     for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    


   
    
    
    return 0;
    
    
}