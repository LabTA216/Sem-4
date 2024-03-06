#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Structure to represent each task in the project
struct Task {
    public:
    char id; 
    int duration; 
    vector<char> dependencies; 
    int es = 0; 
    int ef = 0;
    int ls = 0; 
    int lf = 0;
};
vector<chr> 

int main() {

    vector<Task> tasks = {
        {'A', 1, {}, 0, 0, 0, 0},
        {'B', 2, {'A'}, 0, 0, 0, 0},
        {'C', 1, {'B'}, 0, 0, 0, 0},
        {'D', 3, {'A'}, 0, 0, 0, 0},
        {'E', 2, {'B', 'D'}, 0, 0, 0, 0},
        {'F', 1, {'A'}, 0, 0, 0, 0}
    };
    
    vector<char> criticalPath = findCriticalPath(tasks);
    cout << "Critical Path: ";
    for (char task : criticalPath) {
        cout << task << " ";
    }
    cout << endl;

    return 0;
}
