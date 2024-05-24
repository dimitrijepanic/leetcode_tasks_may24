#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int maxScoreWords(vector<string>& w, vector<char>& l, vector<int>& score) {
        // precompute score for every word
        unordered_map<string, int> scores;
        // only keep the words we can actually make out of the letters
        vector<string> words;
        // what letters we have and how much
        vector<int> letters(26, 0);

        for(auto letter: l) letters[letter - 'a']++;

        for(auto word: w){
            int s = compute_word(letters, word, score);
            if(s == 0) continue;
            scores[word] = s;
            words.push_back(word);
            // cout << word << scores[word] << endl;
        }

        // precomputation done
        return helper(scores, letters, w, 0);
    }

    int helper( 
        unordered_map<string, int>& scores,
        vector<int>& letters,
        vector<string>& words,
        int i){
            if(i >= words.size()) return 0;

        // keep
        // check if you can keep it
        int keep = 0;
        if(compute(letters, words[i])){
            // cout << "ok" << endl;
            for(char c: words[i]) letters[c - 'a']--;
            keep = scores[words[i]] + helper(scores, letters, words, i + 1);
            for(char c: words[i]) letters[c - 'a']++;
        }
        // skip  
        int skip = helper(scores, letters, words, i + 1); 

        return max(keep, skip);
    }

    int compute_word(vector<int>& letters, string& word, vector<int>& scores){
        vector<int> l(26, 0);
        int score = 0;
        for(auto c: word) l[c - 'a']++;

        for(int i = 0; i < 26; i++) 
            if(letters[i] < l[i]) return 0;
            else score += l[i] * scores[i];
        
        return score;
    }

    bool compute(vector<int>& letters, string& word){
        vector<int> l(26, 0);
        for(auto c: word) l[c - 'a']++;

        for(int i = 0; i < 26; i++) 
            if(letters[i] < l[i]) return 0;
        
        return 1;
    }
};