#include <vector>
using namespace std;
class Solution {
public:
    int specialArray(vector<int>& nums) {
        vector<int> tmp(nums.size() + 1, 0);

        for(auto e: nums) {
            tmp[ e >= nums.size() + 1 ? nums.size() : e]++;
        }

        int number = 0;
        for(int i = nums.size(); i >= 0; i--){
            number += tmp[i];
            if(i == number) return i;
        }

        return -1;
    }
};