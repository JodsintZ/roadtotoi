#include <bits/stdc++.h>

#define long long long

using namespace std;

int n;
vector<int> vec;
long sum;

int main () {
    scanf("%d ", &n);
    for(int i = 0, t; i < 2*n; i++) {
        scanf("%d", &t);
        vec.emplace_back(t);
    }
    int s = vec.size();
    sort(vec.begin(),vec.end());
    for(int i = 0; i < n; i++) {
        sum = sum + (1ll*vec[i] * 1ll*vec[s - i - 1]);
    }
    printf("%lld", sum);
    return 0;
}
