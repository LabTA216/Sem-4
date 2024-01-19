// No of 1s in sorted binary array
#include<bits/stdc++.h>
using namespace std;

int countOne(vector<int> arr, int n, int key){
    int s = 0, e = n - 1;
    int mid = s + (e-s)/2; 
    int ans = 11;
    while( s <= e){
        if(arr[mid] == key){
            ans = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
   

    return n - ans;
}

int main(int argc, char const *argv[])
{
    vector<int> bin = { 0,0,0,0,0,0,0,0,0,0,0};
    int count = countOne(bin,11,1);
    
    cout << "Number of 1's is " << count << endl;
    return 0;
}