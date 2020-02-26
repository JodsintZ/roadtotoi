#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

int m, k, ans[700005];
vector<pair<int,int>> b;
vector<int> a;

int main() {
    scanf("%d %d", &m, &k);
    for(int i = 0, temp; i < m; i++) {
        scanf("%d", &temp);
        a.emplace_back(temp);
    }
    for(int i = 0, temp; i < k; i++) {
        scanf("%d", temp);
        b.emplace_back(temp,i);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    for(int i = 0, ptra = 0; i < k; i++) {
        while(ptra < m && a[ptra] - ptra <= b[i].first) ++ptra;
        ans[b[i].y] =  b[i].x + ptra;
    }
    for(int i = 1; i <= k; i++) printf("%d ", ans[i]);


    return 0;
}
