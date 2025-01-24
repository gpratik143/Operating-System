#include<stdio.h>
int main()
{

    int n , a , b ;
    printf("enter the character:");
    scanf("%d" , &n);
    printf("enter the number :");
    scanf("%d%d" , &a,&b);
    switch(n)
    {
        case1:
            printf("sum is: %d", a+b);
            break;
            case2:
                printf("subtraction is:%d" , a-b);
                break;
            default:
                printf("the product is: %d" , a*b);
    }
                return 0 ;


    }

