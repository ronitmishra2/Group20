#include <iostream>
using namespace std;

template <typename T>
T findLargest(T a, T b, T c) {
    T largest = a; // Assume a is the largest to start with

    if (b > largest)
        largest = b;
    if (c > largest)
        largest = c;

    return largest;
}

int main() {
    cout << "Largest of 3, 7, 2: " << findLargest(3, 7, 2) << endl;
    cout << "Largest of 4.5, 2.3, 8.1: " << findLargest(4.5, 2.3, 8.1) << endl;
    cout << "Largest of 'a', 'b', 'c': " << findLargest('a', 'b', 'c') << endl;

    return 0;
}
```
