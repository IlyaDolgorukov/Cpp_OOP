#include <iostream>
#include <cstdint>

using namespace std;

class RGBA {
    public:
    std::uint8_t m_red;
    std::uint8_t m_green;
    std::uint8_t m_blue;
    std::uint8_t m_alpha;

    RGBA(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a): m_red(0), m_green(0), m_blue(0), m_alpha(255) {
        m_red = r;
        m_green = g;
        m_blue = b;
        m_alpha = a;
    }

    void print() {
        cout << unsigned(m_red) << ", " << unsigned(m_green) << ", " << unsigned(m_blue) << ", " << unsigned(m_alpha);
    }
};

int main()
{
    RGBA color(25, 14, 48, 200);
    color.print();

    return 0;
}
