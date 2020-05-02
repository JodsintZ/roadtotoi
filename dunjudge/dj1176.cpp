#include <bits/stdc++.h>

using namespace std;

stack <int> s;

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int t1;
        scanf("%d", &t1);
        if(s.size() > 0) {
            while (  !s.empty()&& s.top() <= t1) {
         //   if(s.top() <= t1) {
                s.pop();
            }
            s.emplace(t1);
            if(s.top() > t1 ) {
                s.emplace(t1);
            }
        }
        else s.emplace(t1);
    }
    while(!s.empty()){
        printf("%d\n", s.top());
        s.pop();
    }
}
