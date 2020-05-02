#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;

int n;
vector<int> dp;

int main() {
    scanf("%d", &n);
    for(int i = 1, a; i <= n; i++) {
        scanf("%d", &a);
        if(dp.empty() || dp.back() < a) dp.emplace_back(a); // <= and upper bound
        else {
            auto it = lower_bound(dp.begin(), dp.end(), a);// < and lower bound
            if(it != dp.end()) *it = a;
        }
    }
    printf("%d\n", dp.size());

    return 0;
}
