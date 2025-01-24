
//  C program to print number pattern

#include <stdio.h>

int main()
{
    int r, c, i, j, k;

    /* Input rows and columns from user */
    printf("Enter number of rows: ");
    scanf("%d", &r);
    printf("Enter number of columns: ");
    scanf("%d", &c);

    k = 1;
    for(i=1; i<=r; i++)
    {
        for(j=1; j<=c; j++, k++)
            printf("%d", k);
        }
{
        printf("\n");
}

    return 0;
    }

