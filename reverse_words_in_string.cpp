class Solution {
public:
    // reverse the string[start, end]
    void reverseWords(string &s, int start, int end) {
        char tmp;
        while (start <= end) {
            tmp = s[start];
            s[start] = s[end];
            s[end] = tmp;
            
            start ++;
            end --;
        }
    }
    void reverseWords(string &s) {
        int len = s.size();
        if (len == 0) {
            return;
        }
        int start = 0;
        int end = 0;
        
        // trim leading or trailing whitespace and the inner white space set to one
        for (int i=0; i<len; i++) {
            while (i < len && s[i] == ' ') {
                i++;
            }
            while (i < len && s[i] != ' ') {
                s[start++] = s[i++];
            }
            if (i < len) {
              s[start++] = ' ';
            }
        }

        if (s[start-1] == ' ') {
            start --;
        }
        len = start;
        if (len <= 0) {
            s = "";
            return;
        }
        s = s.substr(0, len);
        
        
        
        for (int i=0; i<len; i++) {
            start = i;
            // find the next word
            while (i < len && s[i] != ' ') {
                i ++;
            }
            end = i - 1;
            reverseWords(s, start, end);
        }
        
        reverseWords(s, 0, len-1);
    }
};
