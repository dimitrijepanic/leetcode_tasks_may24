#include <string>
#include <iostream>
#include <vector>
#include <algorithm>    // std::sort

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int> people, int limit) {
        sort(people.begin(), people.end());
        int i = 0;
        int j = people.size() - 1;
        int boats = 0;

        while(i <= j){
            int rest = limit - people[j--];
            if(i < people.size() && rest - people[i] >= 0) rest -= people[i++];
            boats++;
        }

        return boats;
    }
};

int main() {
    Solution solution;

    cout << solution.numRescueBoats({2,49,10,7,11,41,47,2,22,6,13,12,33,18,10,26,2,6,50,10}, 50) << endl;
    cout << solution.numRescueBoats({3,5,3,4}, 5) << endl;
    cout << solution.numRescueBoats({2,2}, 6) << endl;
    return 0;
}