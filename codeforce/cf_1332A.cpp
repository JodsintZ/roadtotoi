#include <bits/stdc++.h>

using namespace std;

int q, a, b, c, d, x ,y;
int x1, x2, y1, y2;

int main() {
    scanf("%d", &q);
    while(q--) { // if left > 1 that's it boi
        scanf("%d %d %d %d", &a, &b, &c, &d);
        bool john = true;
        int xx = a - b; // + is left
        int yy = c - d; // + is down
        scanf("%d %d %d %d %d %d", &x, &y, &x1, &y1, &x2, &y2);
        int left = x - x1, right = x2 - x, down = y - y1, up = y2 - y;
        if(xx > 0) {
            if( left < xx)
                john = false;
        }
        else if( xx < 0) {
            xx *= -1;
            if( right < xx)
                john = false;
        }
        else if(xx == 0) {
            if(right > 0 || left > 0)
                john = true;
            else if(a == 0 && b == 0) john = true;
            else john = false;
        }

        if(yy > 0) {
            if(down < yy)
                john = false;
        }
        else if( yy < 0) {
            yy *= -1;
            if(up < yy)
                john = false;
        }
        else if(yy == 0) {
            if(down > 0 || up > 0) john = true;
            else if(c == 0 && d == 0) john = true;
            else john = false;
        }

        if(john) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
