#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <cstdio>

using namespace std;

int itoa(int val, char* buf, int radix)  
{  
    char* p;  
    unsigned int a;        //every digit  
    int len;  
    char* b;            //start of the digit char  
    char temp;  
    unsigned int u;  
  
    p = buf;  
  
    if (val < 0)  
    {  
        *p++ = '-';  
        val = 0 - val;  
    }  
    u = (unsigned int)val;  
  
    b = p;  
  
    do  
    {  
        a = u % radix;  
        u /= radix;  
  
        *p++ = a + '0';  
  
    } while (u > 0);  
  
    len = (int)(p - buf);  
  
    *p-- = 0;  
  
    //swap  
    do  
    {  
        temp = *p;  
        *p = *b;  
        *b = temp;  
        --p;  
        ++b;  
  
    } while (b < p);  
  
    return len;  
}  

class Solution {
    static int cmp2(string longer_str, string shorter_str) {
        int size_of_longer = longer_str.size();
        int size_of_shorter = shorter_str.size();
        
        int start = 0;
        while (start < size_of_longer) {
            int tmp = longer_str.substr(start, size_of_shorter).compare(shorter_str);
            if (tmp > 0) {
                return 1;
            } else if (tmp < 0) {
                return -1;
            } else {
                start += size_of_shorter;
            }
        }
        return 0;
    }
    static bool cmp(int left, int right) {
      char c1[8], c2[8];
      itoa(left,c1,10);
      itoa(right,c2,10);
      string left_str = c1;
      string right_str = c2;
        int size_of_left = left_str.size();
        int size_of_right = right_str.size();
        
        if (size_of_left < size_of_right) {
            return -cmp2(right_str, left_str);
        } else if (size_of_left > size_of_right) {
            return cmp2(left_str, right_str);
        } else {
            return left_str.compare(right_str);
        }
    }
public:
    string largestNumber(vector<int>& nums) {
        int size = nums.size();
        
        if (size == 0) {
            return "";
        }
        if (size == 1) {
            return "" + nums[0];
        }
        
        sort(nums.begin(), nums.end(), cmp);
        
        string res="";
        for (int i=0; i<size; i++) {
            res += nums[i];
        }
        
        return res;
    }
};


int main()
{
  int nums[] = {41,23,87,55,50,53,18,9,39,63,35,33,54,25,26,49,74,61,32,81,97,99,38,96,22,95,35,57,80,80,16,22,17,13,89,11,75,98,57,81,69,8,10,85,13,49,66,94,80,25,13,85,55,12,87,50,28,96,80,43,10,24,88,52,16,92,61,28,26,78,28,28,16,1,56,31,47,85,27,30,85,2,30,51,84,50,3,14,97,9,91,90,63,90,92,89,76,76,67,55};
  vector<int> data(nums, nums + sizeof(nums)/sizeof(int));

  Solution s;
  s.largestNumber(data);
}
