/**#include<stdio.h>
int main(void) {
  int n;
  printf("Enter the number of rows\n");
  scanf("%d",&n);
  int spaces=n-1;
  int stars=1;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=spaces;j++)
    {
      printf(" ");
    }
    for(int k=1;k<=stars;k++)
    {
      printf("*");
    }
    if(spaces>i)
    {
      spaces=spaces-1;
      stars=stars+2;
    }
    if(spaces<i)
    {
      spaces=spaces+1;
      stars=stars-2;
    }
    printf("\n");
  }
  return 0;

}
*/
#include <stdio.h>

int main()
{
    int i, j, rows;
    int stars, spaces;

    printf("Enter rows to print : ");
    scanf("%d", &rows);


    stars = 1;
    spaces = rows - 1;

    /* Iterate through rows */
    for(i=1; i<rows*2; i++)
    {
        /* Print spaces */
        for(j=1; j<=spaces; j++)
            printf(" ");

        /* Print stars */
        for(j=1; j<stars*2; j++)
            printf("*");

        /* Move to next line */
        printf("\n");

        if(i<rows)
        {
            spaces--;
            stars++;
        }
        else
        {
            spaces++;
            stars--;
        }
    }

    return 0;
}
