class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int size = words.size();
        if (size == 0) return res;
        if (maxWidth == 0) {
            res.push_back("");
            return res;
        }
        
        int start = 0;
        while (start < size) {
            int end = start;
            int stringSize = words[end++].size();
            while (end < size && stringSize + words[end].size() + 1 <= maxWidth) {
                stringSize += (words[end++].size() + 1);
            }
            
            int extraCnt = 0;
            int spaceCnt = 1;
            if (end < size && end - start != 1) {
                // remove the last space
                spaceCnt = (maxWidth - stringSize) / (end - start - 1) + 1;
                extraCnt = (maxWidth - stringSize) % (end - start - 1);
            }
            
            res.push_back(words[start++]);
            string& curString = res.back();
            while (extraCnt --) {
                curString.append(spaceCnt + 1, ' ');
                curString.append(words[start++]);
            }
            
            while (start < end) {
                curString.append(spaceCnt, ' ');
                curString.append(words[start++]);
            }
            
            // if the line has only one word
            curString.append(maxWidth - curString.size(), ' ');
            
            start = end;
        }
        
        return res;
    }
};
