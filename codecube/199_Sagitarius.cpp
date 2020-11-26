#include <bits/stdc++.h>

#define long long long
#define pii pair<int, int>
#define x first
#define y second
#define tii tuple<int, int, int, int>

using namespace std;
/*
   - Sol is mst but sort from high to low
   - check the number of edges by cnt if the cnt is n-1 then add the cntn
     also keep the first highest number unavailable to add to the mst at the end;
     keep by chk = true after found the number above and the number is in chkn
   - do the normal mst(case t = 1) then edit the code to be availabled for t = 2

*/
const int N = 1e5+5;

int n, m, t, chkn, par[N], cnt;
bool jhn;
long ans;
int ansn;
int chk; //the node(i) of the one use
vector<tii> E;
vector<int> vans;

int find(int x) { return par[x] = x == par[x] ? x : find(par[x]); }

int main() {
    for(int i = 1; i < N ;i++) par[i] = i;
    scanf("%d %d", &n, &m);
    for(int i = 1, a, b, c; i <= m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        E.emplace_back(c, a, b, i);
    }
    scanf("%d", &t);
    sort(E.begin(), E.end(), greater<tii>() );
    for(auto ato : E) {
        int a, b, c, d; tie(c, a, b, d) = ato;
        int pa = find(a), pb = find(b);
        if(pa != pb) {
            par[pa] = pb;
            ans += c;
            vans.emplace_back(d);
            cnt++;
        }
        else if(!jhn){ //keep number
            jhn = true;
            ans += c;
            cnt++;
            vans.emplace_back(d);
        }
    }
    if(cnt != n) return !printf("-1\n");
   // for(int i = 0; i < n; i++) printf("%d ",par[i]);

    if(cnt == n) {
        //ans += chkn; 
       // vans.emplace_back(chk);
        printf("%lld\n", ans);
    }
    if(t == 2) {
        sort(vans.begin(), vans.end());
        for(auto ato : vans) printf("%d ", ato);
    }
    printf("\n");

    return 0;
}