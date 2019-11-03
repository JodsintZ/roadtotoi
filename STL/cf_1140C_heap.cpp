#include <bits/stdc++.h>

#define long long long
#define pii pair<long, long>
#define x first
#define y second

using namespace std;

const int N = 3e5+5;

int n, k;
pii song[N];
priority_queue<long, vector<long>, greater<long> > Q;
//multiset<long, greater<long> > S; for multiset that sort from greater to less value

int main() {
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) scanf("%lld %lld", &song[i].x, &song[i].y);

    sort(song + 1, song + 1 + n, [&](pii a, pii b) {
        return a.y < b.y;
    });

    long sum = 0, ans = 0;
    for(int i = n; i; i--) {
        Q.emplace(song[i].x);
        sum += song[i].x;
        while(Q.size() > k) {
            sum -= Q.top();
            Q.pop();
        }
        ans = max(ans, sum * song[i].y);
    }
    printf("%lld\n", ans);

    return 0;
}