#include <bits/stdc++.h>

using namespace std;

vector<int> vec, v;
int n, t, a;

int main() {
    scanf("%d", &n);
    for(int i = 0, t; i < n; i++) {
        scanf("%d", &t);
        vec.emplace_back(t);
    }

    v.emplace_back(vec[0]);
    for(int i = 1, a; i < n; i++) {
        a = vec[i];
        if(a > v.back()) v.emplace_back(a);
        else {
            int t = lower_bound(v.begin(), v.end(), a) - v.begin();
            v[t] = a;
        }
    }
    printf("%d \n", n - v.size());
    return 0;
}
