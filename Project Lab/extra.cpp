#include <bits/stdc++.h>
using namespace std;

struct Task {
    char id;      
    int duration;     
    vector<char> dependencies; 
    int eS;     
    int eF;   
    int lS;        
    int lF;       
};


void findCriticalPath(const vector<Task>& tasks) {
    unordered_map<char, Task> mpp;

    for (const auto& task : tasks) {
        mpp[task.id] = task;
    }
    

    for (const auto& task : tasks) {
        for (char dependency : task.dependencies) {
            mpp[task.id].eS = max(mpp[task.id].eS, mpp[dependency].eF);
        }
        mpp[task.id].eF = mpp[task.id].eS + mpp[task.id].duration;
    }
    

    int projectDuration = 0;    
    for (auto it = tasks.rbegin(); it != tasks.rend(); ++it) {
        int minlF = INT32_MAX;
        for (char dependentTask : it->dependencies) {
            minlF = min(minlF, mpp[dependentTask].lS);
        }
        mpp[it->id].lF = minlF;
        mpp[it->id].lS = minlF - mpp[it->id].duration;
        projectDuration = max(projectDuration, mpp[it->id].eF);
    }
    
    // Find critical path
    cout << "Critical Path: ";
    for (const auto& task : tasks) {
        if (task.eS == task.lS && task.eF == task.lF) {
            cout << task.id << " ";
        }
    }
}

int main() {

// A - 1 - send out invitation - 
// B - 2 - buy decoration      - A
// C - 1 - Bakecake 	    - B	
// D - 3 - Buy Gifts	    - A
// E - 2 - Venues		    - B, D
// F - 1 - Attendence	    - A
    vector<Task> tasks = {
        {'A', 1, {}, 0, 0, 0, 0},
        {'B', 2, {'A'}, 0, 0, 0, 0},
        {'C', 1, {'B'}, 0, 0, 0, 0},
        {'D', 3, {'A'}, 0, 0, 0, 0},
        {'E', 2, {'B', 'D'}, 0, 0, 0, 0},
        {'F', 1, {'A'}, 0, 0, 0, 0}
    };

    findCriticalPath(tasks);
    cout << endl;

    return 0;
}
