#include <iostream>

using namespace std;

template<typename T1, typename T2>
inline basic_ostream<T1, T2>& endll(basic_ostream<T1, T2>& stream) {
    stream.put(stream.widen('\n'));
    return flush(stream.put(stream.widen('\n'))); 
}

int main() {
    cout << "start" << endll << "end";

    return 0;
}
