#include <iostream>
#include <vector>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using std::cout;
using std::vector;
using std::endl;
using std::vector;
using std::ifstream;

const double CLK_TCK= 1000;

template<typename T>
void printVector(vector<T>& vect) {
    int v_size = vect.size();

    if (v_size == 0) return;
    for (int i = 0; i < v_size; ++i) {
        cout << vect[i] << " ";
    }
    cout << endl;
}

void printNumArray(int begin, int end, int increment);
