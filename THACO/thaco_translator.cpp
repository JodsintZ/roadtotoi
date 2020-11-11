#include <bits/stdc++.h>

#define long long long

using namespace std;

const int N = 1e5 + 5;

int n, m, a[N], chk[N], tmp, ans;
vector<pii> b;
priority_queue<int> pr;

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i <n; i++) {
        scanf("%d", a + i);
    }
    for(int i = 0; i < m; i++ ) {
        scanf("%d", &tmp);
        b.emplace_back(tmp, i);
    }
    for(int i = 0; i < n; i++) {
        int cnt = 0;
        if(chk[i]) continue;
        chk[i] = true;
        tmp = a[i];
        while(69) {
            t2 = a[a[i]];
            cnt++;
            if(t2 == tmp) break;

        }
        pr.emplace_back(cnt);
    }
    

    return 0;
}