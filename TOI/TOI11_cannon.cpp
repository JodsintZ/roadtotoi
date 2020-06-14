#include <bits/stdc++.h>

using namespace std;

int n, m, k, l, t;
vector<int> A;
// 1 sub boi
int main() {
    scanf("%d %d %d %d", &n, &m, &k, &l);
    for(int i = 0; i < n; i++) {
        scanf("%d", &t);
        A.emplace_back(t);
    }
    while(k--) {
        int ans = 0;
        vector<int> v;
        for(int i = 0 ;i < m; i++) {
            scanf("%d", &t);
            v.emplace_back(t - l);
            if(i) {
                if(v.back() <= v[v.size()-2]) {
                    v.pop_back();
                    v.pop_back();
                }
            }
            v.emplace_back(t + l);
        }
        for(int i = 0; i < v.size(); i++) {
            if(i % 2) ans += upper_bound(A.begin(), A.end(), v[i]) - A.begin(); 
            else ans -= lower_bound(A.begin(), A.end(), v[i]) - A.begin(); 
        }

        printf("%d\n", ans);
    }

    return 0;
}