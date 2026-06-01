#include <iostream>
using namespace std;

template <typename T>
T findMin(T a, T b) {
    return (a < b) ? a : b;
}

int main() {
    cout << findMin(2, 1) << endl;
    cout << findMin(2.5, 4.8) << endl;
    cout << findMin('m', 'a') << endl;
    return 0;
}
