#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;

int n ,q, t;
map<int, vector<int>> m;

int query(int ) {


}

int main() {
    scanf("%d %d", &n, &q);
    for(int i = 0; i <n; i++) {
        scanf("%d", &t);
        m.emplace(make_pair(t,m.second.emplace_back(i)));
    }
    return 0;
}
