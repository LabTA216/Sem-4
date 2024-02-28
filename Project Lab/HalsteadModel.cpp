#include <bits/stdc++.h>
using namespace std;

bool isOperator(string c) {
   return c == "+" || c == "-" || c == "*" || c == "/" || c == "=" || c == "(" || c == "{" || c == "%" || c == ";" || c == "," || c == "main" || c == "return" || c == "\"";
}


vector<int> guigerMullerCounter(const string& code) {
    map<string, int> wordCounts;
    string word;

    // Variables to track word boundaries
    int start = 0;
    int end = 0;

    while (start < code.length()) {
        end = code.find(' ', start);
        
        if (end == -1) {
            word = code.substr(start);
        } else {
            word = code.substr(start, end - start);
        }
        
            wordCounts[word]++;
        start = (end == -1) ? code.length() : end + 1;
    }
    int op = 0, oor = 0, top = 0, tor = 0;
    for ( auto &it : wordCounts) {
        if( isOperator(it.first)){
            top+=it.second;
            op++;
        }  
        else{   
            tor+=it.second;
            oor++;
        }
    }

    vector<int> counts = {top,op,tor,oor};

    return counts;
}

int main() {
    // Test program
    string testProgram = R"(
        int main () {
            int a , b , c , avg ;
            scanf ( " %d %d %d ", &a , &b , &c ) ;
            avg = ( a + b + c ) / 3 ;
            printf ( " avg = %d ", avg ) ;
            return 0 ;
        }
    )";

    vector<int> counts = guigerMullerCounter(testProgram);
    cout << "Number of total operands: " << counts[0] << endl;
    cout << "Number of operands: " << counts[1] << endl;
    cout << "Number of total operators: " << counts[2] << endl;
    cout << "Number of operators: " << counts[3] << endl;

    return 0;
}
