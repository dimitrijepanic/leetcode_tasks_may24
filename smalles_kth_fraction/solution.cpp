#include <string>
#include <iostream>
#include <vector>
#include <algorithm>    // std::sort
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int> arr, int k) {
        // Create a priority queue to store pairs of fractions
        priority_queue<pair<double, pair<int, int>>> pq;

        // Push the fractions formed by dividing each element by
        // the largest element into the priority queue
        for (int i = 0; i < arr.size(); i++)
            pq.push({-1.0 * arr[i] / arr.back(), {i, arr.size() - 1}});
        
        // Iteratively remove the top element (smallest fraction) 
        // and replace it with the next smallest fraction
        while (--k > 0) {
            pair<int, int> cur = pq.top().second;
            pq.pop();
            cur.second--;
            pq.push({-1.0 * arr[cur.first] / arr[cur.second], 
                    {cur.first, cur.second}});
        }
        
        // Retrieve the kth smallest fraction from 
        // the top of the priority queue
        pair<int, int> result = pq.top().second;
        return {arr[result.first], arr[result.second]};
    }
};

int main() {
    Solution solution;

    cout << solution.kthSmallestPrimeFraction({1,2,3,5}, 3)[0] << endl;
    cout << solution.kthSmallestPrimeFraction({1,7}, 1)[0] << endl;
    return 0;
}