#include<bits/stdc++.h>
using namespace std;



int main(int argc, char const *argv[])
{

    priority_queue<int, vector<int>, greater<int>> pq;
    int num;
    cin >> num;
    cout << "enter sizes of files\n";  
    for (int i = 0; i < num; i++)
    {
        int x;
        cin >> x;
        pq.push(x);
    }
    while(!pq.empty()){
        if(pq.size() == 1 ){
            cout << "Final file size : " << pq.top() << endl;
            pq.pop();
        }
        else{
            int f = pq.top();
            pq.pop();
            int s = pq.top();
            pq.pop();
            cout << "merging " << f << " and " << s << endl;
            pq.push(f+s);
        }
    }
     

    return 0;
}