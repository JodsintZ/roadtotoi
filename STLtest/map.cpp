#include <bits/stdc++.h>

#define pii pair<int,int>

using namespace std;

map <int,int> m;
map <int, vector<int> > mv;

int main() {
    m.emplace(pii(1,2));
    cout << m[2] << endl;
    mv.emplace(3,4);
    cout << mv[1];
    return 0;
}
