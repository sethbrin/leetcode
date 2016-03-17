#include <vector>
#include <iostream>

using namespace std;

class NumArray {
public:
    NumArray(vector<int> &nums) {
        m_size = nums.size();
        
        m_sum = vector<int>(m_size, 0);
        int tmp = 0;
        for (int i=0; i<m_size; i++) {
            tmp += nums[i];
            m_sum[i] = tmp;
        }
    }

    void update(int i, int val) {
        if (i < 0) {
            return;
        }
        int diff = 0;
        if (i == 0) {
            diff = val - m_sum[i];
        }
        diff = val - m_sum[i] + m_sum[i-1];
        for (int k=i; k<m_size; k++) {
            m_sum[k] = m_sum[k] + diff;
        }
    }

    int sumRange(int i, int j) {
        
      if (i==0) {
            return m_sum[j];
        }
        if (j >= m_size) {
            j = m_size - 1;
        }
        return m_sum[j] - m_sum[i-1];
    }
private:
    vector<int> m_sum;
    int m_size;
};

int main()
{

  vector<int> nums;
  nums.push_back(1);
  nums.push_back(3);
  nums.push_back(5);
  
  NumArray na(nums);
  cout << na.sumRange(0,2) << endl;
  na.update(1, 2);
  cout << na.sumRange(0,2) << endl;
}
