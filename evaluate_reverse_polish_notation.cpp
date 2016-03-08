class Solution {
public:
    inline bool isOp(string s) {
        return "+" == s || "-" == s || "*" == s || "/" == s;
    }

    inline int compute(int a, int b, string op) {
        if ("+" == op) {
            return a + b;
        } else if ("-" == op) {
            return a - b;
        } else if ("*" == op) {
            return a * b;
        } else {
            return a/b;
        }
    }

    int evalRPN(vector<string>& tokens) {
        if (tokens.empty()) {
            return 0;
        }
        stack<int> s;

        for(vector<string>::const_iterator iter=tokens.begin(); iter != tokens.end(); ++iter) {
            string curStr = *iter;
            if (isOp(curStr)) {
                // pop two operand
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(compute(b, a, curStr));
            } else {
                s.push(stoi(curStr));
            }
        }
        return s.top();

    }

};
