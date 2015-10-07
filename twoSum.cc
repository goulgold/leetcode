#include "util/util.h"
#include <vector>
#include <algorithm>
#include <unordered_map>

using std::vector;
using std::swap;
using std::unordered_map;

class Solution {
    public:
        static vector<int> twoSum_Hash(vector<int>& nums, int target);
        static vector<int> twoSum(vector<int>& nums, int target);
    private:
        static vector<int> quickSort(vector<int>& nums);
        static void splitSort(vector<int>& nums, vector<int>& index, int lo, int hi);
};

vector<int> Solution::twoSum_Hash(vector<int>& nums, int target) {
    unordered_map<int, int> store;
    vector<int> result;
    for (int i = 0; i < nums.size(); ++i) {
        store[nums[i]] = i+1;
    }
    for (int i = 0; i < nums.size(); ++i) {
        int num = target - nums[i];
        if (store.find(num) != store.end() && store.find(num)->second != (i+1)) {
            result.push_back(i+1);
            result.push_back(store[num]);
            break;
        }
    }
    return result;
}

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
int main(int argc, char* argv[]) {
    ifstream myfile;
    myfile.open(argv[1]);
    vector<int> nums;
    int temp;
    if (myfile.is_open()) {
        while(!myfile.eof()) {
            myfile >> temp;
            nums.push_back(temp);
        }
    }
    myfile.close();

    printVector(nums);

    int target = atoi(argv[2]);
    cout << "target: " << target << endl;
    clock_t start, end;
    //timer start
    start = clock();
    vector<int> result = Solution::twoSum_Hash(nums, target);
    end = clock();
    double time = (end - start) / CLK_TCK;
    cout << "index: ";
    printVector(result);
    cout << "Time Elapsed:" << time << "ms" << endl;

    return 0;
}
