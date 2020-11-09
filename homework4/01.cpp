#include <iostream>
#include <cassert>

using namespace std;

class ArrayInt {
private:
    int m_length;
    int *m_data;
public:
    ArrayInt(): m_length(0), m_data(nullptr) {}
    ArrayInt(int length): m_length(length) {
        assert(length >= 0);
        if (length > 0) {
            m_data = new int[length];
            for (int i = 0; i < length; i++) {
                m_data[i] = 0;
            }
        } else {
            m_data = nullptr;
        }
    }
    ~ArrayInt() {
        delete [] m_data;
    }
    void erase() {
        delete [] m_data;
        m_data = nullptr;
        m_length = 0;
    }
    int getLength() const {
        return m_length;
    }
    int &operator[](int index) {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }
    void resize(int newLength) {
        if (newLength == m_length) return;
        if (newLength <= 0) {
            erase();
            return;
        }
        int *data = new int[newLength];
        for (int i = 0; i <= newLength; i++) {
            data[i] = i <= m_length ? m_data[i] : 0;
        }
        delete [] m_data;
        m_data = data;
        m_length = newLength;
    }
    void insertBefore(int value, int index) {
        assert(index >= 0 && index <= m_length);
        int *data = new int[m_length + 1];
        for (int before = 0; before < index; ++before) {
            data[before] = m_data[before];
        }
        data[index] = value;
        for (int after = index; after < m_length; ++after) {
            data[after + 1] = m_data[after];
        }
        delete [] m_data;
        m_data = data;
        ++m_length;
    }
    void pushBack(int value) {
        insertBefore(value, m_length);
    }
    void popBack() {
        resize(m_length - 1);
    }
    void popFront() {
        --m_length;
        int *data = new int[m_length];
        for (int i = 1; i <= m_length; ++i) {
            data[i - 1] = m_data[i];
        }
        delete [] m_data;
        m_data = data;
    }
    void sortAsc() {
        qsort(m_data, m_length, sizeof(int), [](const void* a, const void* b) {
            return *(int *)a - *(int *)b;
        });
    }
    void print() const {
        cout << "[";
        if (m_length > 0) {
            for (int i = 0; i < m_length; i++) {
                cout << m_data[i] << (i < (m_length - 1) ? ", " : "");
            }
        }
        cout << "]" << endl;
    }
};

int main() {
    ArrayInt arr(2);
    arr.print();
    cout << arr.getLength() << endl;
    arr.pushBack(3);
    arr.pushBack(8);
    cout << arr.getLength() << endl;
    arr.print();
    arr.insertBefore(4, 1);
    arr.pushBack(5);
    arr.print();
    arr.popBack();
    arr.print();
    arr.popFront();
    arr.print();
    arr.sortAsc();
    arr.print();

    return 0;
}
