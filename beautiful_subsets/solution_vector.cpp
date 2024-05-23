// solution with vectors
#include <vector>

using namespace std;
class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int> curr;
        return helper(nums, curr, k, 0);
    }

    int helper(vector<int>& nums, vector<int>& curr, int k, int start){
        if(start >= nums.size()) return 0;
        int total = 0;
         for(int i = start; i < nums.size(); i++){
            if(validate(curr, nums[i], k)){
                curr.push_back(nums[i]);
                total += helper(nums, curr, k, i + 1) + 1;
                curr.pop_back();
            }
        }
        return total;
    }

    bool validate(vector<int> curr, int val, int k){
        for(auto e: curr){
            if(abs(e - val) == k) return false;
        }
        return true;
    }

};