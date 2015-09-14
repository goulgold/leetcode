#include "twoSum.h"

vector<int> Solution::twoSum(vector<int>& nums, int target) {

    quickSort(nums);

    vector<int>::iterator head, tail;
    vector<int> result;
    head = nums.begin();
    tail = nums.end() - 1;

    while(head != tail) {
        if ((*head) + (*tail) < target) {
            head++;
        } else if ((*head) + (*tail) > target) {
            tail--;
        } else {
            result.push_back(std::distance(nums.begin(), head) + 1);
            result.push_back(std::distance(tail, nums.end()) + 1);
            break;
        }
    }
    return result;
}

void Solution::quickSort(vector<int>& nums) {
    int n_size = nums.size();
    int lo = 0;
    int hi = n_size - 1;
    Solution::splitSort(nums, lo, hi);
}
void Solution::splitSort(vector<int>& nums, int lo, int hi) {
    if (hi - lo < 1) return;

    int small_ptr = lo;
    int norm = nums[lo];
    swap(nums[lo], nums[hi]);

    for (int i = lo; i < hi; ++i) {
        if (nums[i] < norm) {
            swap(nums[i], nums[small_ptr]);
            small_ptr++;
        }
    }
    swap(nums[small_ptr], nums[hi]);
    splitSort(nums, lo, small_ptr-1);
    splitSort(nums, small_ptr+1, hi);
}
