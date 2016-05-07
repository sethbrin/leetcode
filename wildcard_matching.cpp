class Solution {
public:
    bool isMatch(string s, string p) {
        int sSize = s.size();
        int pSize = p.size();
        
        // if met many continuous *, just the same as one *
        int indexOfS = 0;
        int indexOfP = 0;
        int lastS = sSize;
        int lastP = pSize;
        while (indexOfS < sSize) {
            if (p[indexOfP] == '*') {
                indexOfP ++; // skip *, and mark
                if (indexOfP == pSize) return true;
                
                lastS = indexOfS;
                lastP = indexOfP;
            } else if (p[indexOfP] == '?' || p[indexOfP] == s[indexOfS]) {
                indexOfP ++;
                indexOfS ++;
            } else if (lastS < sSize) {
                // if lastS not reach the end, we return back to the lastP, and cove a string in S
                indexOfP = lastP;
                indexOfS = ++lastS;
            } else {
                return false;
            }
        }
        
        while (indexOfP < pSize && p[indexOfP] == '*') {
            indexOfP++;
        }
        if (indexOfP == pSize) {
            return true;
        } else {
            return false;
        }
    }
};
