#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct Item {
    int weight;
    int profit;

    Item(int w, int p) : weight(w), profit(p) {}
};

int zeroOneKnapsack(int W, vector<Item>& items) {
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (items[i - 1].weight <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - items[i - 1].weight] + items[i - 1].profit);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    vector<Item> items;
    for (int i = 0; i < n; i++) {
        int weight, profit;
        cout << "Enter weight and profit for item " << i + 1 << ": ";
        cin >> weight >> profit;
        items.push_back(Item(weight, profit));
    }

    int maxProfit = zeroOneKnapsack(W, items);
    cout << "Maximum profit in the knapsack = " << maxProfit << endl;

    return 0;
}
