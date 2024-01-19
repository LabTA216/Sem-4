#include<bits/stdc++.h>
using namespace std;

// Min-max  


void minMax(vector<int> arr, int n, int min, int max){
    for (int i = 1; i < n ; i++)
    {
        if( arr[i] < min){
            min = arr[i];
        }
        else if ( arr[i] > max){
            max = arr[i];
        }
    }
    
    cout << "\nMin : " << min;
    cout << "\nMin : " << max << endl;

}



int main(int argc, char const *argv[])
{

    vector<int> arr = {1,2,3,4,5,6};
    int min = arr[0], max = arr[0];

    minMax(arr,6,min,max);

    return 0;
}