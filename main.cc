#include "twoSum.h"
#include "util.h"
#include <vector>
#include <iostream>



using std::vector;
int main() {
    vector<int> test;
    test.push_back(3);
    test.push_back(2);
    test.push_back(1);
    printVector(test);
    vector<int> result = Solution::twoSum(test, 3);
    printVector(result);
    return 0;
}
