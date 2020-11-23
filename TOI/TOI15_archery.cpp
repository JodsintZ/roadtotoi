#include <bits/stdc++.h>

#define long long long
#define pii pair<int, int>
#define pll pair<long,long>
#define x first
#define y second

const int N = 5e5+5;
const int M = 2e9;

using namespace std;

int n, mx ,t;
pll ans;
vector<pii> v(N);

int main() {
    scanf("%d", &n);
    mx = M; ans.y = 6e17;
    for(int i = 1; i <= n; i++) scanf("%d", &t), v[i].y = t;
    for(int i = 1; i <= n; i++) scanf("%d", &t), v[i].x = t;
    sort(v.begin(), v.end());
    for(int i = 1; i <= n; i++) printf("%d ", v[i].x);
    
    return 0;
}