class NumArray {
private:
    vector<int> m_sum;
    vector<int> m_nums;
    
    // as lowbit(0)=0, when update the first number, we need to update all the sums
    // so tree array should start from 1;
    int lowbit(int k) {
        return k & (-k);
    }
    
    void add(int index, int val) {
        index ++;
        while (index < m_sum.size()) {
            m_sum[index] += val;
            index += lowbit(index);
        }
    }
    
    int query(int index) {
        int res = 0;
        index ++;
        while (index > 0){
            res += m_sum[index];
            index -= lowbit(index);
        }
        return res;
    }
public:
    NumArray(vector<int> &nums) : m_nums(nums) {
        int size = nums.size();
        m_sum.resize(size + 1);
        
        for (int i=0; i<size; i++) {
            add(i, nums[i]);
        }
    }

    void update(int i, int val) {
        if (val != m_nums[i]) {
          add(i, val - m_nums[i]);
          m_nums[i] = val;
        }
    }

    int sumRange(int i, int j) {
        return query(j) - query(i-1);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
