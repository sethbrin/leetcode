class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        
        int total = size1 + size2;
        if (total & 1) {
            return findKthElement(nums1.begin(), size1, nums2.begin(), size2, total/2 + 1);
        } else {
            return (findKthElement(nums1.begin(), size1, nums2.begin(), size2, total/2) + findKthElement(nums1.begin(), size1, nums2.begin(), size2, total/2 + 1)) / 2.0;
        }
    }
    
private:
    int findKthElement(vector<int>::iterator iter1, int m, vector<int>::iterator iter2, int n, int k) {
        if (m > n) return findKthElement(iter2, n, iter1, m, k);
        if (m == 0) return *(iter2 + k - 1);
        if (k == 1) return min(*iter1, *iter2);
        
        int ia = min(k/2, m);
        int ib = k - ia;
        
        // if iter1[ia-1] > iter2[ib-1] then the kth element is not in the reigon iter1[0, ia-1)
        if (*(iter1 + ia - 1) > *(iter2 + ib - 1)) {
            return findKthElement(iter1, m, iter2 + ib, n - ib, k - ib);
        } else if (*(iter1 + ia - 1) < *(iter2 + ib - 1)) {
            return findKthElement(iter1 + ia, m - ia, iter2, n, k - ia);
        } else {
            return *(iter1 + ia - 1);
        }
    }
};
