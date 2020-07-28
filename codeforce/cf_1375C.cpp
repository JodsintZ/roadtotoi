#include <bits/stdc++.h>

using namespace std;

//can be greedy to check only the first one and the last one
//if the first one is lower then it's always possible 100%

void solve() {
    int a, b, n, tmp;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        if(!i) a = tmp;
        if(i == n-1) b = tmp;
    }
    if(a < b) printf("YES\n");
    else printf("NO\n");
    return;

}

int t;

int main() {
    scanf("%d ", &t);
    while(t--) {
        solve();
    }
    return 0;
}