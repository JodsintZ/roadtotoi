#include <bits/stdc++.h>

#define long long long
#define pii pair<long, long>
#define x first
#define y second

using namespace std;

const int N = 3e5+5;

int n, k;
pii song[N];
multiset<long> S;

int main() {
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) scanf("%lld %lld", &song[i].x, &song[i].y);

    sort(song + 1, song + 1 + n, [&](pii a, pii b) {
        return a.y < b.y;
    });

    long sum = 0, ans = 0;
    for(int i = n; i; i--) {
        S.emplace(song[i].x);
        sum += song[i].x;
        while(S.size() > k) {
            sum -= *S.begin();
            S.erase(S.begin());
        }
        ans = max(ans, sum * song[i].y);
    }
    printf("%lld\n", ans);

    return 0;
}