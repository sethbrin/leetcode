class Solution {
private:
    string helper(int num) {
        const string less_ten[] = { "", " One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine" };
        const string less_twenty[] = { " Ten", " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen" };
        const string less_hundred[] = { "", "", " Twenty", " Thirty", " Forty", " Fifty", " Sixty", " Seventy", " Eighty", " Ninety" };
        
        string res;
        if (num != 0) {
            int hundred = num / 100;
            num = num % 100;
            int ten = num / 10;
            num = num % 10;
            if (hundred != 0) {
                res = res + less_ten[hundred] + " Hundred";
            }
            if (ten == 1) {
                res = res + less_twenty[num];
            } else {
                res = res + less_hundred[ten] + less_ten[num];
            }
        }
        return res;
    }
public:
    string numberToWords(int num) {
        // break the number into 4 number, within the 4 number consider seperate
        string unit[] = {"", " Thousand", " Million", " Billion"};
        int parts[4] = {0};
        
        // As number <= 2^31 - 1, use billion enough
        for (int i=0; i<4; i++) {
            parts[i] = num % 1000;
            num = num / 1000;
        }
        
        string res;
        
        for (int i=0; i<4; i++) {
            if (parts[i] == 0) continue;
            res = helper(parts[i]) + unit[i] + res;
        }
        if (res.size() == 0) return "Zero";
        if (res[0] == ' ') return res.substr(1);
        return res;
    }
};
