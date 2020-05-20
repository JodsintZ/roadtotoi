#include <bits/stdc++.h>
#define PI 3.141592653589793

using namespace std;

int q;
//param like 30 45 60
int main() {
    cin >> q;
    while(q--) {
        double param, ans, ag, a = 0;
        cin >> ag;
        ag = 180.0 / ag;
        ag /= 2;
        ag = 90.0 - ag;
       // printf("%lf\n", ag);
        //a = sqrt( 1 / (1 - cos(ag * PI / 180.0)));
        a = tan(ag * PI / 180.0);
      //  printf("\n%lf\n", a);   
      printf("%.9lf \n", a);
      //  cout <<a << endl;   


    }
    return 0;
}