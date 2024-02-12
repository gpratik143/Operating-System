#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
    fork();
    printf("Hello World\n");
    printf("Hii Pratik\n");
}

// Output:- 
// Hello World
// Hii Pratik
// Hello World
// Hii Pratik