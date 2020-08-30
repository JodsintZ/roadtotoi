#include <bits/stdc++.h>

#define pii pair<int,int>
#define x first
#define y second
#define long long long

using namespace std;

const int N = 5e5+5;
const int M = 8e18;

pair<long, long> ans;
vector<pii> v[N];
long a[N], b[N];
int n, m, mm;

int main() {
    ans = {M, M};
    scanf("%d", &n);
    for(int i = 1, t; i <= n; i++) {
        scanf("%d", &t);
        v[i].y = t; //max hieght
        mm = min(mm, t);
    }
    for(int i = 1, t; i <= n; i++) {
        scanf("%d", &t);
        v[i].x = t; //position
    }
    sort(v.begin(), v.end());
    for(int i = 1; i <= n; i++) {
        a[i] = a[i-1] + v[i].y;
    }
    for(int i = 1; i <= n; i++) {
        b[i] = b[i-1] + v[i].x;
    }

    //bruh like this should be it
    //Q is how do I next ptr cuz it's not always up by 1
    // or i can just do that and check < instead of <= 
    int ptr = 1;
    while(ptr != mm) {
        auto lb = lower_bound(v.begin(), v.end(),pii(ptr,-1));
        auto ub = lower_bound(v.begin(), v.end(),pii(ptr+1,-1));
        long tt = a[ptr-1] - (lb-1) + b[n] - b[ub-1] - (n-ub) * ptr;
        if(ans.x < ())
    }

}
