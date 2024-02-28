#include<iostream>
using namespace std;

void quickSort(int[], int, int);
int findPosition(int arr[], int s, int e, int pivot);
void Union(int a[], int b[], int n1, int n2){
    int i = 0, j = 0;
    while( i < n1 && j < n2){
        if(a[i] == b[j]){
            cout << a[i] << " ";
            i++;
            j++;
        }
        else if(a[i] > b[j]){
            while ( j < n2 && a[i] > b[j]){
                cout << b[j] << " ";
                j++;
            } 
        }
        else{
            while (i < n1 && a[i] < b[j]){
                cout << a[i] << " ";
                i++;
            }
        }
    }
    while (i < n1 ){
        cout << a[i] << " ";
        i++;
    }
    while ( j < n2 ){
        cout << b[j] << " ";
        j++;
    } 
    cout << endl;
}

void interSection(int a[], int b[], int n1, int n2){
    int i = 0, j = 0;
    while( i < n1 && j < n2){
        if(a[i] == b[j]){
            cout << a[i] << " ";
            i++;
            j++;
        }
        else if(a[i] > b[j]){
            while ( j < n2 && a[i] > b[j]){j++;} 
        }
        else{
            while (i < n1 && a[i] < b[j]){i++;}
        }
    }
    cout << endl;
}

void printArr(int arr[], int n){
    for (int i = 0; i < n ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int n1, n2;
    cout << "Enter number of elements in set 1 : ";
    cin >> n1;
    int a[n1];
    cout << "Enter Elements of set 1 : ";
    for (int i = 0; i < n1 ; i++){
        cin >> a[i];
    }
    cout << "Enter number of elements in set 2 : ";
    cin >> n2;
    int b[n2];
    cout << "Enter Elements of set 2 : ";
    for (int i = 0; i < n2 ; i++){
        cin >> b[i];
    }
    quickSort(a,0,n1-1);
    quickSort(b,0,n2-1);
    cout << "\nUnion is : ";
    Union(a,b,n1,n2);
    cout << "\ninterSection is : ";
    interSection(a,b,n1,n2);

    return 0;
}

int findPosition(int arr[], int s, int e, int pivot){
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

void quickSort(int arr[], int s, int e){
    if( s>= e){return;}
    int index = findPosition(arr,s,e,arr[s]);
    quickSort(arr,s,index-1);
    quickSort(arr,index+1,e);
}
