#include <bits/stdc++.h>

using namespace std;

template<typename T, int N>
struct point {
    T x, y;
    point() { x = 3, y = 4; }
    point(T a, T b) {
        if(a < b) x = a, y = b;
        else x = b, y = a;
    }
    friend bool operator<(const point &a, const point &b) {
        if(a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    }
    friend point operator+(const point &a, const point &b) {
        point ret;
        ret.x = a.x + b.x, ret.y = a.y + b.y;
        return ret;
    }
    void operator+=(const point &b) {
        x += b.x, y += b.y;
    }
    T mul() {
        return x * y;
    }
    void print_N() {
        printf("N = %d\n", N);
    }
};

point<int, 123> a;

int main() {
    printf("%d\n", a.mul());
    a.print_N();

    return 0;
}
