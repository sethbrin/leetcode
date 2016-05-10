class Solution {
public:
    bool isPalindrome(string s) {
        int size = s.size();
        
        int start = 0;
        int end = size - 1;
        
        int strip = abs('A' - 'a');
        while (start < end) {
            if (!isalnum(s[start])) {
                start ++;
                continue;
            }
            if (!isalnum(s[end])) {
                end --;
                continue;
            }
            
            // Caution, only when char is alpha it has case, For example "0P" the escape is the same as 'A'-'a'
            if (!(s[start] == s[end] 
            || (isalpha(s[start]) && isalpha(s[end]) && abs(s[start]-s[end]) == strip))) {
                return false;
            }
            start ++;
            end --;
        }
        return true;
    }
};
