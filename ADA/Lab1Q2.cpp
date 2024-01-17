// binary search
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr, int n, int key){
    int s = 0, e = n - 1;
    int mid = s + (e-s)/2; 
    while( s <= e){
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] > key){
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
}

void merge(vector<int> &arr, int s , int e){
    if(s >= e){
        return;
    }


    int mid = (s+e)/2;
    int len1 = mid, len2 = e - s - mid + 1; 
    int *first = new int[len1];
    int *second = new int[len2];
    int arrptr = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[arrptr++];
    }
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[arrptr++];
    }
    arrptr = 0;
    int fptr = 0, sptr = 0;
    while (fptr < len1 && sptr < len2)
    {
        if( first[fptr] <= second[sptr]){
            arr[arrptr++] = first[fptr++];
        }
        else{
            arr[arrptr++] = second[sptr++];
        }
    }
    
    while (fptr < len1)
    {
        arr[arrptr++] = first[fptr++];
    }

    while (sptr < len2)
    {
        
        arr[arrptr++] = second[sptr++];

    }

    
    


}

void mergeSort(vector<int> &arr, int s , int e){
    if(s >= e){
        return;
    }
    int mid = (s+e)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    merge(arr,s,e);
}



int main(int argc, char const *argv[])
{
    vector<int> arr ={1,2,3,4,5,6,7}; 
    int k = binarySearch(arr,7,7);
    if( k == -1){
        cout << "Element Not Found\n";
    }
    else{
        cout << "Required element is present at index : " << k << endl;
    }
    return 0;
}
