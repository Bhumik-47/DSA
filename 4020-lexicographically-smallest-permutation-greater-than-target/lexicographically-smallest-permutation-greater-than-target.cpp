#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        if (target.size() != n) return "";

        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;

        // Step 1: Match target character-by-character as far as possible
        int matchLen = 0;
        while (matchLen < n && cnt[target[matchLen] - 'a'] > 0) {
            cnt[target[matchLen] - 'a']--;
            matchLen++;
        }

        // Step 2: Backtrack from matchLen down to 0 to find the first position 
        // that can take a strictly larger character
        for (int i = matchLen; i >= 0; i--) {
            int tChar = (i < n) ? (target[i] - 'a') : 26;

            // Try to place the smallest available character strictly greater than target[i]
            for (int c = tChar + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    cnt[c]--;
                    
                    // Build result: target[0...i-1] + c + sorted remaining
                    string res = target.substr(0, i);
                    res += (char)('a' + c);

                    for (int k = 0; k < 26; k++) {
                        if (cnt[k] > 0) {
                            res.append(cnt[k], 'a' + k);
                        }
                    }
                    return res;
                }
            }

            
            if (i > 0) {
                cnt[target[i - 1] - 'a']++;
            }
        }

        return "";
    }
};