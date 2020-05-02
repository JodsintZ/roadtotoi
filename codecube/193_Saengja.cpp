#include <bits/stdc++.h>
#define long long long
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 1e5+5;

int n, k;
long dp[N][2];
vector<pii> v;

void read_input() {
    scanf("%d %d", &n, &k);
   // v.emplace_back(0, 0);
    for(int i = 0, a, b; i < n; i++) {
        scanf("%d %d", &a, &b);
        v.emplace_back(a, b); // position, value
    }
}

int main () {
    read_input();

    sort(v.begin(), v.end()) ;
    for(int i = 1; i < n; i++) {// 1 is chosen, 0 is not chosen (the last one)
        if(v[i].x - v[i-1].x <= k) {
            dp[i][1] = v[i].y + v[i-1].y + v[i-1].x - v[i].x + dp[i-1][0];
            if(i > 1 && v[i].x - v[i-2].x <= k) {
                dp[i][1] = max (dp[i][1], v[i].y + v[i-2].y + v[i-2].x - v[i].x + dp[i-2][0]);
            }
            dp[i][0] = max(dp[i-1][1], dp[i-1][0]);
        }
        else {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = dp[i][0];
        }
    }
    printf("%lld", max(dp[n-1][0], dp[n-1][1]));
    return 0;
}
