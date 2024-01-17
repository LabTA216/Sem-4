#include<bits/stdc++.h>
using namespace std;

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

void printVec( vector)
int main(int argc, char const *argv[])
{

    

    return 0;
}