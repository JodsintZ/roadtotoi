#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;

int t[N];

void update(int x, int k) {
    for(int i = x; i < N; i += i & -i)
        t[i] += k;
}

int query(int x) {
    int ret = 0;
    for(int i = x; i; i -= i & -i) 
        ret += t[i];
    return ret;
}

int main() {
    //update range then query as single OR update single pint then query as range 
    //can't be both in the same program
    update(1, 1), update(6, -1); 
    query(3);

    return 0;
}