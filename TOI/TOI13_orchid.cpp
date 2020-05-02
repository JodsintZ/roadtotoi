#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int n, t;

int main () {
    scanf("%d", &n);
    scanf("%d", &t);
    v.emplace_back(t);
    for(int i = 1; i < n; i++) {
        scanf("%d", &t);
        if(v.back() > t) {
            auto it = upper_bound(v.begin(),v.end(),t);
            *it = t;
        }
        else v.emplace_back(t);
    }
    //for(int i = 0; i < v.size(); i++) printf("%d ", v[i]);
    printf("%d\n", n-v.size());


    return 0;
}
