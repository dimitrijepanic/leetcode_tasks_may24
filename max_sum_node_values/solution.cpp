#include <string>
#include <iostream>
#include <vector>
#include <algorithm>    // std::sort
#include <queue>
#include <numeric>

using namespace std;

class Solution {
public:
    long long maximumValueSum(vector<int>& v, int k, vector<vector<int>>& edges) {
        // the solutions lies in the tree strucutre being practically useless
        // the point is that every two node is reachable
        // meaning that a->b->c->d ONLY A and B are here being xor-ed only once, all 
        // of the others 2 times - we get the same value

        // the only problematic solution is when we have odd number of values
        // that increase when we xor them
        long long total = accumulate(v.begin(), v.end(), 0LL);
        
        long long total_diff = 0;
        long long diff;
        int positive_count = 0;
        long long min_abs_diff = INT_MAX;
        for(auto p : v){
            diff = (p^k) - p;
            
            if(diff > 0){
                total_diff += diff;
                positive_count++;
            }
            min_abs_diff = min(min_abs_diff, abs(diff));
        }
        if(positive_count % 2 == 1){
            total_diff = total_diff - min_abs_diff;
        }
        return total + total_diff;
    }
};