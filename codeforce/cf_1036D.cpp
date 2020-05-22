#include <bits/stdc++.h>
#define long long long

using namespace std;

int n, m, ans;
long t1, t2, sum;
vector<int> a, b;

int main() {
    scanf("%d", &n);
    for(int i = 0, t; i < n; i++) {
        scanf("%d", &t);
        a.emplace_back(t);
        sum += t;
    }
    scanf("%d", &m);
    for(int i = 0, t; i < m; i++) {
        scanf("%d", &t);
        b.emplace_back(t);
        sum -= t;
    }
    if(sum) return !printf("-1\n");
    for(int i = 0, j = 0; i < n; i++) {
        t1 += a[i];
        while(j < m && t2 < t1) {
            t2 += b[j];
            j++;
        } 
        if(t2 == t1) {
            ans++;
            t1 = 0;
            t2 = 0;
        }

    }
    if(!t1 && !t2) printf("%d", ans);
    else printf("-1\n");
    return 0;
}