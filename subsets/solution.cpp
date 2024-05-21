#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int> nums) {
        vector<vector<int>> result;
        vector<int> curr;
        result.push_back({});

        helper(nums, result, curr, 0);

        return result;
    }

    void helper(vector<int>& nums, vector<vector<int>>& result,vector<int>& curr, int start){
        if(start >= nums.size()) return;

        for(int i = start; i < nums.size(); i++){
            curr.push_back(nums[i]);
            result.push_back(curr);
            helper(nums, result, curr, i + 1);
            curr.pop_back();
        }
    }
};


int main() {
    Solution solution;

    vector<vector<int>> result = solution.subsets({1,2,3,4});
    for(auto e: result){
        for(auto d: e){
            cout << d <<" ";
        }
        cout << endl;
    }
    return 0;
}