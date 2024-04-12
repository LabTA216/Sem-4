#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> limitedChange(vector<pair<int, int>>& coins, int amount) {
    sort(coins.rbegin(), coins.rend()); // Sort coins in descending order based on value
    vector<int> change;
    for (auto& coin : coins) {
        while (amount >= coin.first && coin.second > 0) {
            change.push_back(coin.first);
            amount -= coin.first;
            coin.second--;
        }
    }
    if (amount == 0) {
        return change;
    } else {
        return {};
    }
}

vector<int> unlimitedChange(vector<int>& coins, int amount) {
    sort(coins.rbegin(), coins.rend()); // Sort coins in descending order
    vector<int> change;
    for (int coin : coins) {
        while (amount >= coin) {
            change.push_back(coin);
            amount -= coin;
        }
    }
    if (amount == 0) {
        return change;
    } else {
        return {};
    }
}

int main() {
    // Example usage:
    vector<pair<int, int>> limitedCoins = {{1, 3}, {5, 2}, {10, 1}, {20, 4}, {50, 2}}; 
    vector<int> unlimitedCoins = {1, 5, 10, 20, 50}; 
    int amount = 172; 

    cout << "Limited coins required:" << endl;
    cout << "Amount: " << amount << endl;
    vector<int> lc = limitedChange(limitedCoins, amount);
    if (!lc.empty()) {
        cout << "Change:";
        for (int coin : lc) {
            cout << " " << coin;
        }
        cout << endl;
    } else {
        cout << "Cannot make exact change" << endl;
    }

    cout << "\nUnlimited coins required:" << endl;
    cout << "Amount: " << amount << endl;
    vector<int> uc = unlimitedChange(unlimitedCoins, amount);
    if (!uc.empty()) {
        cout << "Change:";
        for (int coin : uc) {
            cout << " " << coin;
        }
        cout << endl;
    } else {
        cout << "Cannot make exact change" << endl;
    }

    return 0;
}
