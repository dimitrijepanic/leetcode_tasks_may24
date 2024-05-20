#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int subsetXORSum(vector<int> nums) {
        // no matter how many times a bit
        // is set it will always end to half of the elements actually containing it set

        // when we set it only once it is pretty self explanatory
        // 2^(n -1) - one bit is statically set
        // e.g. 3 numbers set the ith bit -  subsets that only contain one f those elements
        // 2^(n - 3) (we use combos 100,010,001 - combinatorics)
        // and the lastly a subset that contains all 3  - 2^(n -3)
        // total is 4 * 2 ^(n - 3) = 2 ^ (n - 1)

        int or_result = 0;
        for(auto e: nums) or_result |= e;

        int total = 0;
        int bit = 0;
        int half_subsets = (1 << nums.size()) / 2;
        // cout << half_subsets << endl;
        while(or_result) {
            // cout << (1 << bit ) << endl;
            total += (or_result & 1) * half_subsets * (1 << bit);
            or_result >>=1;
            bit++;
            // cout << total << endl;
        }

        return total;
    }
};

int main() {
    Solution solution;

    cout << solution.subsetXORSum({1,2,3,5}) << endl;
    cout << solution.subsetXORSum({1,7}) << endl;
    return 0;
}