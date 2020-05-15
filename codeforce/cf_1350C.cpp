#include <bits/stdc++.h>
#define long long long

using namespace std;

const int N = 450;
const int M = 2e5+5;

bool prime[N];
int n, t, cnt, ptr;
vector<int> v, pr;

void sieve() {
   //fill_n(prime, N, 1);
    for(int i = 2; i*i < M; i++) {
        if(!prime[i]) {
            for(int p = i*i; p < N; p += i) prime[p] = true;
            pr.emplace_back(i);
        }
    }
    pr.emplace_back(449);
  //  for(int i = 0; i < pr.size(); i++) printf("%d ", pr[i]);
   // printf("\n%d\n", pr.size());
}

int main() {
    long ans = 1;
    scanf("%d", &n);
    sieve(); // 3181
    for(int i = 0, t; i < n; i++) {
        scanf("%d", &t);
        v.emplace_back(t);
    }
    int ptr = 0;
    while(ptr != pr.size()) {
        int cnt = 0;
        for(int i = 0; i < n; i++) {
           if(v[i] % pr[ptr] != 0) cnt++;
           //if(cnt == 2) break;
        }
        if(cnt < 2) {
            for(int i = 0; i < n; i++) {
            if(v[i] % pr[ptr] == 0)
            v[i] /= pr[ptr];
           // printf("%d ", v[i]);
            }
           // printf("\n");
            ans = ans * (1ll * pr[ptr]);
        }    
        else ptr++;
    }
    printf("%lld\n", ans);

    return 0;
}