class Solution {

    void dfs(vector<string>& res, string& path, const vector<string>& digitsMap,const string& digits, int index) {

        if (index == digits.size()) {
            res.push_back(path);
            return;
        }

        int digit = digits[index] - '0';
        if (digit <= 1) return;
        string letters = digitsMap[digit-2];

        for (char ch: letters) {
            path.push_back(ch);
            dfs(res, path, digitsMap, digits, index+1);
            path.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;

        vector<string> digitsMap = {
            "abc","def","ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        string path;
        dfs(res, path, digitsMap, digits, 0);

        return res;
    }
};
