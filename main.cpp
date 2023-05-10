#include "./vector.h"
#include <iostream>

class Point {
    public:
        Point() {}
        Point(const Point&) = default;
        Point(int a, int b, int c) : m_a(a), m_b(b), m_c(c) {}
        Point(Point&&) {
            std::cout << "MOVE CTOR" << std::endl;
        }
        Point& operator=(Point&&) = default;

        const int a() const { return m_a; }
        const int b() const { return m_b; }
        const int c() const { return m_c; }

    private:
        int m_a;
        int m_b;
        int m_c;
};

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for(auto i=0; i < v.size(); i++) {
        std::cout << v[i] << std::endl;
    }

    vector<Point> vp;
    vp.emplace_back(1,2,3);
    vp.emplace_back(4,5,6);
    for(auto i=0; i < vp.size(); i++) {
        std::cout << "A: " << vp[i].a() << std::endl;
        std::cout << "B: " << vp[i].b() << std::endl;
        std::cout << "C: " << vp[i].c() << std::endl;
    }
    return 0;
}