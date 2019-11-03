#include<stdio.h>

int dim[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int firstday()
{
    int day;
    printf("Input "); scanf("%d", &day);
    return day;
}

int fdom(int day)
{
    int fday;
    int d1, d2, d3;
    d1 = (day - 1)/ 4;
    d2 = (day - 1)/ 100;
    d3 = (day - 1)/ 400;
    fday = (day + d1 - d2 + d3) %7;
    return fday;
}

int leap(int leap){
    int x;
    printf("Leap or no(1/0): "); scanf("%d", &x);
    if(x == 1){
        dim[2] = 29;
        return 1;
    }
    if(x == 0){
        dim[2] = 28;
        return 0;
    }
}

int calendar(int fday)
{
    int day, month;
    printf("Month: "); scanf("%d", &month);
    printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n");
    for(day = 1; day <= 1 + fday * 5; day++){
        printf(" ");
    }
    for(day = 1; day <= dim[month]; day++){
        printf("%2d ", day);
        if((day + fday)%7 > 0){
            printf("  ");
        }else printf("\n ");
    }
    fday = (fday + dim[month])%7;
}

int main(){
    int first, l, fday;
    first = firstday();
    fday = fdom(first);
    leap(l);
    calendar(fday);
}
