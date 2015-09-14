#include <iostream>
#include <vector>
using std::cout;
using std::vector;
using std::endl;

template<typename T>
void printVector(vector<T>& vect) {
    int v_size = vect.size();

    if (v_size == 0) return;
    for (int i = 0; i < v_size; ++i) {
        cout << vect[i] << " ";
    }
    cout << endl;
}
