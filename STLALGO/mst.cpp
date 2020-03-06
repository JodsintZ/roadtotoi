#include <bits/stdc++.h>

#define iii tuple<int, int, int>

using namespace std;

const int N = 1e5+5;

int par[N];

// int find(int x) { return par[x] = par[x] == x ? x : find(par[x]); }

int find(int x) {
    if(par[x] == x) return x;
    else {
        int y = find(par[x]); //Find the highest rank parent
        par[x] = y; //Set current node's parent to the highest one
        return y; //Return the answer
    }
}

void unite(int x, int y) {
    int px = find(x), py = find(y); //Find the highest rank parent
    if(px == py) return; //Check if x and y is in the same component
    par[px] = py; //Merge components
}

int n, m, ans;
vector<iii> E, M;

int main() {
    for(int i = 1; i < N; i++) par[i] = i;

    scanf("%d %d", &n, &m);
    for(int i = 1, a, b, c; i <= m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        E.emplace_back(c, a, b);
    }
    sort(E.begin(), E.end());
    // sort(E.begin(), E.end(), greater<iii>());
    for(iii e : E) {
        int a, b, c;
        // tie(c, a, b) = e;
        a = get<1>(e), b = get<2>(e), c = get<0>(e);
        if(find(a) != find(b)) {
            unite(a, b);
            //Do something with edge in MST
            M.emplace_back(a, b, c);
            ans += c;
        }
    }
    for(auto e : M) cout << get<0>(e) << " " << get<1>(e) << " " << get<2>(e) << endl;
    printf("%d\n", ans);

    return 0;
}
