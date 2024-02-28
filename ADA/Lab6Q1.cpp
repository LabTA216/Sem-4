#include<iostream>
#include<vector>
using namespace std;

int findPosition(vector<int> &arr, int s, int e, int pivot){
    int i = s, j = e;
    while( i < j){
        if( arr[i] > arr[j]){
            swap(arr[i],arr[j]);
            swap(arr[i+1],arr[j]);
            i++;
        }
        else{ j--;}
    }
    return i;
}

void quickSort(vector<int> &arr, int s, int e){
    if( s>= e){return;}
    int index = findPosition(arr,s,e,arr[s]);
    quickSort(arr,s,index-1);
    quickSort(arr,index+1,e);
}

void printArr(vector<int> arr, int n){
    for (int i = 0; i < n ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n ; i++)
    {
        cin >> arr[i];
    }
    quickSort(arr,0,n-1);
    printArr(arr,n);

    return 0;
}