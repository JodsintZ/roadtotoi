#include <bits/stdc++.h>

#define long long long
#define tii tuple<int,int,int>
#define pii pair<int,int>
#define x first
#define y second

using namespace std;

const int N = 5e5+5;
const int M = 3e5+5;
const int B = 3e3+5;

int b, e, j, p, par[B];
long ans;
vector<tii> g, premst, mst; // distance node node
vector<pii> preprc, prc; // distance price
//pii prepec[M], prc[M];
int find(int x) { return par[x] = par[x] == x ? x : find(par[x]); }

int main() {
    for(int i = 0; i < B; i++) par[i] = i; //set initial parent's node

    scanf("%d %d", &b, &e);
    for(int i = 0, s, t, l, r; i < e; i++) {
        scanf("%d %d %d %d", &s, &t, &l, &r);
        if(r == 1) l = -1;
        g.emplace_back(l, s, t);
    }
    scanf("%d", &p);
    for(int i = 0, c, d; i < p; i++) {
        scanf("%d %d", &c, &d);
        preprc.emplace_back(c, d);
    }
    //end of input
    sort(preprc.begin(), preprc.end());
    //for(int i = 0; i < p; i++) printf("%d %d \n",preprc[i].x, preprc[i].y);
    prc.emplace_back(preprc[0]); //prc start with 1st in preprc
    for(int i = 1; i < p; i++) {
       // if(prc.empty())
        while(prc.back().y > preprc[i].y && !prc.empty()) {
            prc.pop_back();
        }
        prc.emplace_back(preprc[i]);
    }
   // printf("\n");
   // for(int i = 0; i < prc.size(); i++) printf("%d %d\n", prc[i].x,prc[i].y); //debug prcy
    //x = distance ,y = price
    for(auto v : g) {
        int c = get<0>(v), a = get<1>(v), b = get<2>(v);
        pii z = {c,-1};
       // printf("c = %d\n", c);
        if(c != -1) {
            auto it = lower_bound(prc.begin(),prc.end(), z);
            int t = it - prc.begin();
            mst.emplace_back(prc[t].y, a, b);
        }
        else mst.emplace_back(0,a,b);
    }

    sort(mst.begin(),mst.end());

    for(auto v : mst) {
        int c = get<0>(v), a = get<1>(v), b = get<2>(v);
        int pa = find(a), pb = find(b);
        if(pa != pb) { //merge
            par[pa] = pb;
            ans += c;
        }
    }

    printf("%lld\n", ans);
    return 0;
}
