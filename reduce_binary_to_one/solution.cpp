#include <string>

using namespace std;
class Solution {
public:
    int numSteps(string s) {
        // if(s.size() == 1) return 0;

        int steps = 0;
        int i = s.size() - 1;
        int j = s.size();
        int carry = 0;

        while(i > 0){
            // cout << i << ":" << steps << endl;
            if(s[i] == '1'){
                steps = carry ? steps : (steps + 1);
                j = carry ? j : (i + 1);
                carry = 1;
                i--;
            } else {
                if(carry){
                    s[i] = '1';
                    steps += j - i - 1;
                    carry = 0;
                } else{
                    steps++;
                    i--;
                } 
            }
        }

        if(carry) {
            steps += j - i;
        } 

        return steps;
    }
};