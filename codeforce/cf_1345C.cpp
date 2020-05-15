#include <bits/stdc++.h>

using namespace std;

int q, n;
vector<int> v;

int main() {
    scanf("%d", &q);
    while(q--) {
        bool john = false;
        scanf("%d", &n);
        for(int i = 0, t; i < n; i++) {
            scanf("%d", &t);
            v.emplace_back(t + i);
            v.emplace_back(t - i);
        }
        sort(v.begin(), v.end());
        for(int i = 1; i < n; i++) {
            if(v[i] == v[i-1]) {
                john = true;
                break;
            }
        }
        if(john) printf("NO\n");
        else printf("YES\n");
        v.clear();
    }
    return 0;
}