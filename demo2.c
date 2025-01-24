 #include<stdio.h>
#include<string.h>
int main()
{
 char s1[]="Pratik";
 char s2[]="Gupta";
  char s3[50];
  char s4[50];

  strcpy(s2,s1);
  strcpy(s3,"copied successful");
  printf("S1:%s\n S2:%s\n S3:%s", s1 , s2, s3);
  return 0 ;


}


