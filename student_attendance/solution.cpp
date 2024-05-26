#include <vector>
#define MOD 1000000007
using namespace std;

class Solution {
public:
    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(3, vector<int>(2, -1)));
        // cout << dp[0][0][0];
        return helper(dp, 0, n, 0, 0);
    }


    int helper(vector<vector<vector<int>>>& dp, int i, int n, int a, int l){
        if(i >= n) return 1;
        if(dp[i][l][a] != -1) return dp[i][l][a];
        // cout << i << endl;
        // present
        int total = helper(dp, i + 1, n, a, 0);
        // absent
        if(a < 1) total = (total + helper(dp, i + 1, n, a + 1, 0)) % MOD;
        //late
        if(l < 2) total = (total + helper(dp, i + 1, n, a , l + 1)) % MOD;
        return  dp[i][l][a] =  total % MOD;;
    }

};