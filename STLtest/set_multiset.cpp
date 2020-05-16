#include <bits/stdc++.h>

using namespace std;

set<int> s;
//set<int, greater<int> > s;
multiset<int> ms;
int n;

int main() {
    scanf("%d", &n);
    for(int i = 0, t; i < n; i++) {
        scanf("%d", &t);
        s.emplace(t);
    }
    for(auto e : s) printf("%d ", e);
    auto a = s.find(5); // USE TO  ITERATE
    
    for(auto it = a; it != s.end(); it++) printf("%d ", *it);
    if ( a != s.end())  printf("k");
    //or
    if(s.count(5)) printf("k"); //same as s != end
    //count return 1 if find it else 0
    return 0;
}