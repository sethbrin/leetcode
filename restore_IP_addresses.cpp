class Solution {

private:

    void dfs(vector<string>& res, string path, int index, const string& s, int sInd) {
        if (s.size() <= sInd) return;

        if (index == 3) {
            string tmp = s.substr(sInd);
            if (tmp == "" || (tmp.size() > 1 && tmp[0] == '0') || tmp.size() > 3 || stoi(tmp) > 255 ) return;

            path = path + tmp;
            res.push_back(path);
            return;
        }

        for (int i=1; i<=3; i++) {
            string tmp = s.substr(sInd, i);
            if (tmp == "" || (tmp.size() > 1 && tmp[0] == '0') || stoi(tmp) > 255) continue;

            dfs(res, path + s.substr(sInd, i) + ".", index+1, s, sInd+i);
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.size() < 4) return res;
        dfs(res, "", 0, s, 0);
        return res;
    }
};
