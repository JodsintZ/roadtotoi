#include <bits/stdc++.h>

using namespace std;

vector <int> v;

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int t;
        scanf("%d", &t);
        v.emplace_back(t);
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    printf("%d", v.size());
    return 0;
}


