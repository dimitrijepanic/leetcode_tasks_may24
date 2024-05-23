// set solution
// would not work if there are duplicate values
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        set<int> curr;
        return helper(nums, curr, k, 0);
    }

    int helper(vector<int>& nums, set<int>& curr, int k, int start){
        if(start >= nums.size()) return 0;
        int total = 0;

        for(int i = start; i < nums.size(); i++){
            if((curr.find(nums[i] - k) == curr.end()) && (curr.find(k + nums[i]) == curr.end())){
                curr.insert(nums[i]);
                total += helper(nums, curr, k, i + 1) + 1;
                curr.erase(nums[i]);
            }
        }
        return total;
    }
};