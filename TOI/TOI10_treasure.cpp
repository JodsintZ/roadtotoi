#include <bits/stdc++.h>

#define long long long
#define iii tuple<int, int, int>

using namespace std;

const int N = 4e5+5;

int m, n, prime[8];
vector<iii> vec;
vector<int> coord, in[N], out[N];

int get(int x) {
    return lower_bound(coord.begin(), coord.end(), x) - coord.begin() + 1;
}

int main() {
    scanf("%d %d", &m, &n);
    for(int i = 1, a, b, c; i <= m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        vec.emplace_back(a, b, c + 1);
        coord.emplace_back(b), coord.emplace_back(c + 1);
    }

    //For answer = 1 case
    vec.emplace_back(1, 0, n-1);
    coord.emplace_back(0), coord.emplace_back(n-1);

    sort(coord.begin(), coord.end());
    coord.resize(unique(coord.begin(), coord.end()) - coord.begin());

    for(iii t : vec) {
        int a, b, c; tie(a, b, c) = t;
        in[get(b)].emplace_back(a);
        out[get(c)].emplace_back(a);
    }


    int pre = 0, cnt = 0;
    long ans = 0, divisor = 1;
    for(int i = 1; i <= coord.size(); i++) {
        if(divisor == ans) cnt += coord[i-1] - pre;
        else if(divisor > ans) ans = divisor, cnt = coord[i-1] - pre;

        for(int x : in[i]) {
            int tmp = x;
            for(int j = 2; j * j <= x; j++)
                while(tmp % j == 0) tmp /= j, ++prime[j];
            if(tmp != 1) ++prime[tmp];
        }
        for(int x : out[i]) {
            int tmp = x;
            for(int j = 2; j * j <= x; j++)
                while(tmp % j == 0) tmp /= j, --prime[j];
            if(tmp != 1) --prime[tmp];
        }
        divisor = 1;
        for(int j = 2; j <= 7; j++) divisor *= 1ll * (prime[j] + 1);

        pre = coord[i-1];
    }
    printf("%lld %d\n", ans, cnt);

    return 0;
}
