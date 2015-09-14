#include "twoSum.h"

vector<int> Solution::twoSum(vector<int>& nums, int target) {

    vector<int> order_index = quickSort(nums);
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
            int first = std::distance(nums.begin(), head);
            int second = std::distance(nums.begin(), tail);
            if (order_index[first] < order_index[second]) {
                result.push_back(order_index[first]);
                result.push_back(order_index[second]);
            } else {
                result.push_back(order_index[second]);
                result.push_back(order_index[first]);
            }
            break;
        }
    }
    return result;
}

vector<int> Solution::quickSort(vector<int>& nums) {
    vector<int> index(nums.size());
    for (int i = 0; i < nums.size(); ++i) {
        index[i] = i+1;
    }
    int n_size = nums.size();
    int lo = 0;
    int hi = n_size - 1;
    Solution::splitSort(nums, index, lo, hi);
    return index;
}
void Solution::splitSort(vector<int>& nums, vector<int>& index, int lo, int hi) {
    if (hi - lo < 1) return;

    int small_ptr = lo;
    int norm = nums[lo];
    swap(nums[lo], nums[hi]);
    swap(index[lo], index[hi]);

    for (int i = lo; i < hi; ++i) {
        if (nums[i] < norm) {
            swap(nums[i], nums[small_ptr]);
            swap(index[i], index[small_ptr]);
            small_ptr++;
        }
    }
    swap(nums[small_ptr], nums[hi]);
    swap(index[small_ptr], index[hi]);
    splitSort(nums, index, lo, small_ptr-1);
    splitSort(nums, index, small_ptr+1, hi);
}
