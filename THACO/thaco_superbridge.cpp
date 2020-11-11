#include <bits/stdc++.h>

#define long long long
#define pii pair<int,int>
#define x first
#define y second
#define tii tuple<int,int,int,int>
#define ti tuple<int,int,int>

using namespace std;
//unfinihsed cuz the value name is too shit;
//and i can't understand in the second time reading
const int N = 1e5+5;

int par[N];
int n, m, ta, tb, k;
long ans;
vector<tii> E, M;
vector<pii> pr, ansb;
vector<ti> fv;
vector<int> ansa;//price  first vector
//priority_queue<tii,vector<tii>,greater<tii> > pq[N];

int find(int x) { return par[x] = par[x] == x ? x : find(par[x]); }

void unite(int x, int y) {
    int px = find(x), py = find(y);
    if(px == py) return;
    par[px] = py;
}

int main() {
    for(int i = 1; i < N; i++) par[i] = i;

    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1, a, b, c; i <= m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        E.emplace_back(c, a, b, i);
    }
    for(int i = 1; i <= k; i++) {
        scanf("%d %d", &ta, &tb);
        pr.emplace_back(tb, ta);
    }
    sort(E.begin(), E.end());
    sort(pr.begin(), pr.end());

    for(tii e : E) {
        int a, b, c, d;
        a = get<1>(e), b = get<2>(e), c = get<0>(e), d = get<3>(e);
        if(find(a) != find(b)) {
            unite(a, b);
            //M.emplace_back(a, b, c);
            //ans += c;
            fv.emplace_back(c, d);
        }
    }
    sort(fv.begin(), fv.end(), greater<int>());

    for(int i = 0; i < fv.size(); i++) {
        if(i < pr.size()) {
            int a, b, c;
            a = get<1>(pr[i]), b = get<2>(pr[i]), c = get<0>(pr[i]);
            ans += min(fv[i].x, a);
            if(fv[i].x < a) ansa.emplace_back(fv[i].y);
            else ansb.emplace_back(pr[i].y);
        }
        else {
            ans += fv[i].x;
            ansa.emplace_back(fv[i].y);
        }
    }
    //for(auto e : M) cout << get<0>(e) << " " << get<1>(e) << " " << get<2>(e) << endl;
    printf("%lld\n", ans);
    printf("%d \n", ansa.size());
    for(int i = 0; i < ansa.size(); i++) {
        printf("%d ",ansa[i]);
    }
    printf("%d \n", ansb.size());
    for(int i = 0; i < ansb.size(); i++) {
        printf("%d %d ",ansb[i].x ,ansb[i].y);
    }

    return 0;
}

