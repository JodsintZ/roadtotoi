#include <bits/stdc++.h>

using namespace std;

int q, n;


int main() {
    scanf("%d", &q);
    while(q--) {
        vector<int> v, g;
        //v.clear();
        int ans = 0;
        scanf("%d", &n);
        for(int i = 0, t; i < n; i++) {
            scanf("%d",&t);
            v.emplace_back(t);
        }
        sort(v.begin(), v.end());
       // for(int i = 0; i < v.size(); i++) printf("%d ", v[i]); 
        for(auto i : v) {
            g.emplace_back(i);
            if(g.size() == g.back()) {
                g.clear();
                ans++;
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}