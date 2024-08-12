#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Vector {
    vector<T> arr;
public:
    void addElement(T element) {
        arr.push_back(element);
    }

    T findSmallest() {
        return *min_element(arr.begin(), arr.end());
    }

    bool searchElement(T element) {
        return find(arr.begin(), arr.end(), element) != arr.end();
    }

    double findAverage() {
        T sum = accumulate(arr.begin(), arr.end(), T(0));
        return static_cast<double>(sum) / arr.size();
    }
};

int main() {
    Vector<int> vec;
    vec.addElement(10);
    vec.addElement(20);
    vec.addElement(5);
    vec.addElement(40);

    cout << "Smallest Element: " << vec.findSmallest() << endl;
    cout << "Search 20: " << (vec.searchElement(20) ? "Found" : "Not Found") << endl;
    cout << "Average: " << vec.findAverage() << endl;

    return 0;
}
