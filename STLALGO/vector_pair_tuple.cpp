#include <bits/stdc++.h>

using namespace std;


int main(){
    vector<int> g1;

    for (int i = 1; i <= 5; i++)
        g1.push_back(i);
    cout << g1[0];

    cout << "Output of begin and end: ";
    for (auto i : g1)
        cout << i << " ";
    cout << endl;
    int m = 2;
    while (m--){ // 1 0 (2 loops)
        printf ("%d ",m);
    }
    priority_queue <int, vector<int>,greater<int> > pq;
    pq.emplace(5);
    pq.emplace(4);
    pq.emplace(26);
    pq.emplace(27);
    pq.emplace(28);
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() <<endl;

    while(!pq.empty()) {
        cout <<pq.top() << " ";
        pq.pop();
    }
    printf("\n");
    vector<tuple <int,int>> vtp;
    vtp.emplace_back(make_tuple(1,2));
    vtp.push_back({2,3});
    cout << get<0>(vtp[0]) << endl;

    tuple <int,int> tp;
    tp = (make_tuple(6,9));
    cout << get<0>(tp) << " " << get<1>(tp) << endl;

    string s = "stringg";
    cout << s << endl;
    s.pop_back();
    cout << s << endl;
    printf("%d\n",s.length()); // length = size

    cout << "pair" << endl;
    pair <int,int> pii;
    pii = make_pair (4,5);
    cout << pii.first << " " << pii.second << endl;

    vector <pair<int,int> > vpii;
    vpii.emplace_back(make_pair(5,6));
    cout << vpii[0].first << endl;

    return 0;
}
