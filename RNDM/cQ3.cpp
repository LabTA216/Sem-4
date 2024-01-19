#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int city;
        cin >> city;
        vector<int> c(city), next(city), prev(city); 
        for (int i = 0; i < city ; i++)
        {
            cin >> c[i];
        }

        int d,e;
        next[0] = 1;
        
            d = c[1] - c[0];    
        for (int i = 1; i < city ; i++)
        {
           

            if(i != city-1)
            e = c[i+1] - c[i];
            else
            e = 1;

            
                
            if (d > e)
            {
                next[i] = 1;
                prev[i-1] = d;
            }
            else{
                next[i] = 1;
                prev[i-1] = e;
            }
                


            d = e;
        }
        prev[city-1] = 1;
         for (int i = 1; i < city ; i++)
         {
            next[i]+=next[i-1];
            prev[city-i-1] += prev[city-i];
         }
         
         int m;
         cin >> m;
         while (m-- )
         {
            int i,f;
            cin >> i >> f;
            if(i > f){
                cout << prev[i] - prev[f] << endl;
            }
            else{
                cout << next[f] - next[i] << endl;
            }
         }
         
        
    }
    
    return 0;
}
