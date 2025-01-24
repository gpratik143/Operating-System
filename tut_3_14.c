#include<stdio.h>
int main ()

{
int i = 5 , j=6 , k=7 ;
if (i>j==k)
    printf("%d%d%d" ,i++ , ++j , --k);
else
    printf("%d%d%d" ,i , j , k );
return  0 ;

}
