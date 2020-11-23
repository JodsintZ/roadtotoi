#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;
//geeks for geeks i think. not sure
int main() {
    // Input vector
    std::vector<int> v{ 4, 10, 20, 30, 40, 50 };

    // Print vector
    std::cout << "Vector contains :";
    for (unsigned int i = 0; i < v.size(); i++)
        std::cout << " " << v[i];
    std::cout << "\n";

    std::vector<int>::iterator low1, low2;

    // std :: lower_bound
    low1 = std::lower_bound(v.begin(), v.end(), 5);
    low2 = std::lower_bound(v.begin(), v.end(), 55);

    cout << (low1 - v.begin());
    cout << (low2 - v.begin());
    cout << "\n";
    
    printf("%d %d", *low1, v[low1-v.begin()]);
    
    return 0;
}
