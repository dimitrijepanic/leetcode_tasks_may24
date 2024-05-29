#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> diff(s.size(), 0);
        int n = s.size();

        for(int i = 0; i < s.size(); i++){
            diff[i] = abs(s[i] - t[i]);
        }

        int left = 0;
        int right = 0;
        int curr = 0;
        int result = 0;
        while(right < n){
            curr += diff[right];
            while(left <= right && curr > maxCost) {
                curr -= diff[left];
                left++;
            }
            if(curr <= maxCost){
                result = max(result, right - left + 1);
            } else {
                curr = 0;
                left++;
            }
            right++;
        }

        return result;
    }
};