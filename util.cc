#include "util.h"

void printNumArray(int begin, int end, int increment) {
    for (int i = begin; i <= end; i += increment) {
        cout << i << " ";
    }
    cout << endl;
}
