class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        if (size == 0 || size == 1) return s;
        
        int start = 0;
        int length = 1;
        // expand string
        for (int i = 0; i < size; ) {
            if (size - i <= length / 2) break; // As the length of course less then length
            
            int j = i;
            int k = i;
            
            // skip the same char
            while (k < size - 1 && s[k+1] == s[k]) k++;
            // next i is the later of k, as [j, k] is the same, start in the range is no use
            i = k + 1;
            
            // expand from j and k
            while (k < size - 1 && j > 0 && s[k+1] == s[j-1]) {
                k ++;
                j --;
            }
            int newLength = k - j + 1;
            if (newLength > length) {
                length = newLength;
                start = j;
            }
        }
    
        return s.substr(start, length);
    }
};
