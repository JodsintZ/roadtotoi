#include <bits/stdc++.h>
#define tii tuple<int,int,int> 
#define long long long
#define pii pair<int, int>
#define x first
#define y second

using namespace std;
const int N = 15005;
int n, k, par[N], cnt;
pii v[N];
vector<pii> vt;
vector<tii> E;
long ans;

int main() {
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &v[i].x, &v[i].y);
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i != j) {
                vt.emplace_back(abs(v[i].x - v[j].x) + abs(v[i].y - v[j].y) );
            }
        }
        

        vt.clear();
    }
}