#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        // compare from from . to .
        int i = 0;
        int j = 0;
        while(i < version1.size() || j < version2.size()){
            int n1 = nextDot(i, version1);
            int n2 = nextDot(j, version2);
            // cout << n1 << " " << n2 << endl;
            if(n1 == n2) continue;
            return n1 > n2 ? 1 : -1;
        }

        return 0;
    }

    int nextDot(int& i, string& version){
        if(i >= version.size()) return 0;
        int result = 0;
        while(i < version.size() && version[i] != '.'){
            // cout << version[i] << endl;
            result = result * 10 + (version[i++] - '0');
        }

        i++;
        return result;
    }

};

int main() {
    Solution solution;

    cout << solution.compareVersion("1.0", "1.1") << endl;
    cout << solution.compareVersion("1.0.0", "1.1") << endl;
    cout << solution.compareVersion("1.01", "1.0001") << endl;
    return 0;
}