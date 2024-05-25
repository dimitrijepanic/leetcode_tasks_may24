#include <string>
#include <set>
#include <vector>

using namespace std;
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> dict;
        vector<vector<string>> dp(s.size() + 1, vector<string>(1,"-"));

        for(auto s: wordDict) dict.insert(s);

        return helper(dp, s, dict, 0);
    }

    vector<string> helper(
        vector<vector<string>>& dp,
        string& s, 
        set<string>& dict, 
        int start){
        
        if(start >= s.size()){
            return {""};
        }
        if(dp[start][0] != "-") return dp[start];
        // per level 
        string curr = "";
        vector<string> result;

        for(int i = start; i < s.size(); i++){
            curr += s[i];
            if(dict.find(curr) != dict.end()){
                vector<string> tmp = helper(dp, s, dict, i + 1);
                for(auto sent: tmp){
                    result.push_back(curr + (sent.size() == 0 ? "" :" ") + sent);
                }
            }
        }

        return dp[start] = result;
    }
};