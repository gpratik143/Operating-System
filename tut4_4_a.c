#include<stdio.h>
int main()
{

    int a=10 , b = 5 , c = 2.5 ;
    c += (a > 0 && a <= 10) ? ++a : a/b ;
printf("%f", c );
}
