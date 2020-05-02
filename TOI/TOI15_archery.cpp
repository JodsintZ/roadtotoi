#include <bits/stdc++.h>

#define pii pair<int,int>
#define x first
#define y second
#define long long long

using namespace std;

const int N = 5e5+5;

int n, mm;
long sum, temp;
vector<pii> v(N); // x pos y max

int main() {
    mm = 2e9;
    scanf("%d", &n);
    for(int i = 0, t; i < n; i++) {
        scanf("%d", &t);
        v[i].y = t;
        mm = min(mm, t);
    }
    for(int i = 0, t; i < n; i++) {
        scanf("%d", &t);
        v[i].x = t;
    }
    sort(v.begin(),v.end());
    //end of input

    for(int i = 0; i < n; i++) {
        sum += (v[i].x - v[0].x);
    }
    for(int i = 1; i < n; i++) {
        if(v[i].x > mm) break;
        sum += (v[i-1].y - v[i].x + v[i-1].x + 1) - (v[i].x - v[i-1].x * (n-i) ) + (v[i].x - v[i-1].x * i);
    }

}
