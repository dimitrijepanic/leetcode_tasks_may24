#include <string>
#include <iostream>
#include <vector>
#include <algorithm>    // std::sort

using namespace std;

class Solution {
public:
    int getMaximumGold(vector<vector<int>> grid) {
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        int result = 0;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                result = max(bfs(grid, visited, i, j), result);
            }
        }
    
        return result;
    }

    int bfs(vector<vector<int>>& grid, 
            vector<vector<int>>& v, 
            int i, 
            int j){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0 || v[i][j] == 1) return 0;
        v[i][j] = 1;
        int up = bfs(grid, v, i + 1, j);
        int low = bfs(grid, v , i - 1, j);
        int left = bfs(grid, v , i, j + 1);
        int right = bfs(grid, v , i, j - 1);

        v[i][j] = 0;
        int currMax = grid[i][j] + max(max(up, low), max(left, right));
        return currMax;
    }
};

int main() {
    Solution solution;

    cout << solution.getMaximumGold({{0,6,0}, {5,8,7}, {0,9,0}}) << endl;
    return 0;
}