#include <bits/stdc++.h>

using namespace std;

const int N = 1e9;

int q, temp, t1;
vector<int> p;

int main() {
    scanf("%d", &q);
    temp = 2; t1 = 2;
    while(temp <= N) {
        p.emplace_back(temp);
        t1 += 3;
        temp += t1;
        //printf("%d ", temp);
    }
   // for(int i  =0 ;i  < 10; i++) printf("%d ", p[i]);
  //  printf("%d", p[1]);
    for(int i = 0, t, a; i < q; i++) {
        int cnt = 0;
        scanf(" %d", &t);
        while(t > 1) {
            a = upper_bound(p.begin(), p.end(), t) - p.begin() - 1;
           // printf(" %d ", p[a]);
            t -= p[a];
            ++cnt;
        }
        printf("%d \n", cnt);
    }
    return 0;
}