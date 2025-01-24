#include<stdio.h>
#include<math.h>

int miain ()
{


    int i = 0 , limit=4 ;
    double sum = 0 , x=0 ;
    scanf("1f",&x);
    for(i=0;i<=limit;i++)
    {

        sum+=pow(-x,i);

    }
    printf("sumis %o.0f\n",sum);
    return 0 ;

}
