#ifndef TWOSUM_H_
#define TOWSUM_H_

#include <vector>
#include <algorithm>

using std::vector;
using std::swap;

class Solution {
    public:
        static vector<int> twoSum(vector<int>& nums, int target);
    private:
        static void quickSort(vector<int>& nums);
        static void splitSort(vector<int>& nums, int lo, int hi);
};
#endif
