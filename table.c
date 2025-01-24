 #include<stdio.h>
int main()
{

    int    h , t ;
    printf("Height(m)   time(s)");
    for(t=1;t<=321;t=t+4)
    {
        h=5*t*t;
        printf("%d   %d",h,t);
    }

    return 0 ;

}
