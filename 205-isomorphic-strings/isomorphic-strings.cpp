class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // Arrays initialized to 0 to store the "last seen index + 1"
        int mapS[256] = {0};
        int mapT[256] = {0};
        
        int n = s.size(); // Since lengths are equal (or checked), we use one variable
        
        for (int i = 0; i < n; i++) {
            // If the "last seen" positions don't match, they aren't isomorphic
            if (mapS[s[i]] != mapT[t[i]]) {
                return false;
            }
            
            // Mark the current position (using i + 1 to distinguish from the initial 0)
            mapS[s[i]] = i + 1;
            mapT[t[i]] = i + 1;
        }
        
        return true;
    }
};