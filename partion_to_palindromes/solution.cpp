#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> curr;
        helper(result, curr, 0, s);

        return result;
    }

    void helper(vector<vector<string>>& result, vector<string>& curr, int start, string& s){
        if(start >= s.length()) {
            // add string to result
            result.push_back(curr);
            return;
        }
        // cout << start << endl;
        string str = "";
        for(int i = start; i < s.length(); i++){
            str += s[i];
            // ako je palindrome
            if(is_palindrome(str)){
                curr.push_back(str);
                helper(result, curr, i + 1, s);
                curr.pop_back();
            }
        }
    }

    bool is_palindrome(string& s){
        int left = 0;
        int right = s.length() - 1;
        while(left < right){
            if(s[left++] != s[right--]) return false;
        }

        return true;
    }
};

int main(){
    Solution solution;

    vector<vector<string>> result = solution.partition("aab");
    for(auto e: result){
        for(auto d: e){
            cout << d <<" ";
        }
        cout << endl;
    }
    return 0;
}