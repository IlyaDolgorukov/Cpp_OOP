#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<int> v = {10, 8, 8, 5, 10, 4, 21, 16, 8, 1, 6, 4, 2, 1};
    sort(v.begin(), v.end());
    vector<int>::iterator it;
    it = unique(v.begin(), v.end());  
    v.resize(distance(v.begin(), it));
    cout << v.size();

    return 0;
}
