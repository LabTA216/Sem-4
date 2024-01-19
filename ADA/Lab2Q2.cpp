// find first and last occurance of a given elmt in arr;
#include<bits/stdc++.h>
using namespace std;

int lastO(vector<int> arr, int n, int key){
    int s = 0, e = n - 1;
    int mid = s + (e-s)/2; 
    int ans = -1;
    while( s <= e){
        if(arr[mid] == key){
            ans = mid;
            s = mid + 1;
        }
       else if(arr[mid] > key){
        
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    if(arr[0] == 0 && ans == 0)
        return 0;

    return ans;
}


int firstO(vector<int> arr, int n, int key){
    int s = 0, e = n - 1;
    int mid = s + (e-s)/2; 
    int ans = -1;
    while( s <= e){
        if(arr[mid] == key){
            ans = mid;
            e = mid - 1;
        }
        else if(arr[mid] > key){
        
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    if(arr[0] == 0 && ans == 0)
        return 0;

    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> bin = { 1,1,2,2,2,2,3,4,4,5,6,7,8};
    int k;
    cin >> k;
    int f = firstO(bin,bin.size(),k);
    int s = lastO(bin,bin.size(),k);
    
    cout << "first occurance of "<< k << " is " << f << endl;
    cout << "last occurance of "<< k << " is " << s << endl;

    return 0;
}