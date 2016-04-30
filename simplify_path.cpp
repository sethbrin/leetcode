class Solution {

    void checkName(vector<string>& vec, string s) {
        if (s == "..") {
            if (!vec.empty()) vec.pop_back();
        } else if (s != "." && s != "") {
            vec.push_back(s);
        }
    }

public:

    string simplifyPath(string path) {
        vector<string> vec;
        int start = 0;
        int pos = path.find_first_of("/", start);

        while (pos != string::npos) {
            string tmp = path.substr(start, pos-start);
            checkName(vec, tmp);

            start = pos + 1;
            pos = path.find_first_of("/", start);

        }

        checkName(vec, path.substr(start, pos));

        string res = "";
        for (string s: vec) {
            res = res + "/" + s;
        }
        if (res == "") {
            res = "/";
        }
        return res;
    }
};
