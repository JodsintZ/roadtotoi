#include <bits/stdc++.h>

using namespace std;

const int N = 7e5+5;

int m, k, t, ptr; //t temp
vector <int> v;
vector<pair<int,int>> vpii;
int ans[N];

int main() {
    scanf("%d %d", &m, &k);
    for(int i = 0; i < m; i++) {
        scanf("%d", &t);
        v.emplace_back(t);
    }
    for(int i = 0; i < k; i++) {
        scanf("%d", &t);
        vpii.emplace_back(make_pair(t,i));
    }

    sort(v.begin(),v.end()); // A ptr
    sort(vpii.begin(),vpii.end()); // B i

    // 1 5 7
    // 1 2 4 8

    for(int i = 0, ptr = 0; i < k; i++) {
        while (ptr < m && vpii[i].first +ptr >= v[ptr]) ptr++;
        ans[vpii[i].second] = vpii[i].first + ptr;
        //cout << ptr << endl;
    }

    for(int i = 0; i < k; i++) printf("%d ", ans[i]);
    return 0;
}
