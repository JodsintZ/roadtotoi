#include <bits/stdc++.h>

using namespace std;

bitset<20> b;
bitset<20> c;

int main() {
    b = 30;
    c = 30;
    //array room 0 is the right most and 1 is the one to the left
    cout << b[2] << " " << c[1] << "\n";
    if(b == c) printf("kk\n");
    cout << "To use bit set the value in < N > must be const and known before compiling  \n";
    cout << "You can compare or operation like ==,  b ^= c, b &= c ";

    return 0;
}