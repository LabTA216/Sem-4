// Linear search
#include<iostream>
#include<vector>
using namespace std;

int linearSearch(vector<int> arr, int n, int key){
    for (int i = 0; i < n ; i++)
    {
        if(arr[i] == key)
            return i;
    }
    return -1;
}




int main(int argc, char const *argv[])
{
    vector<int> arr ={1,2,3,4,5,6,7}; 
    int k = linearSearch(arr,7,5);
    if( k == -1){
        cout << "Element Not Found\n";
    }
    else{
        cout << "Required element is present at index : " << k << endl;
    }
    return 0;
}
