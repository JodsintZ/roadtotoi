#include <bits/stdc++.h>

#define long long long
#define pii pair<int,int>
#define tii tuple<long,int,int>
#define x first
#define y second

using namespace std;

int n, m;
priority_queue<tii> pq;

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0, b, c, long c; i < m; i++) {
        scanf("%d %d %lld", &a, &b, &c);
        pq.emplace_back(c, a, b);
    }
    while(!pq.empty()) {
        tii now = pq.top();
        pq.pop();
        long c = get<2>(now);

    }

    return 0;
}
