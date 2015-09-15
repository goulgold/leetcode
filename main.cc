#include "twoSum.h"
#include "util.h"

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
