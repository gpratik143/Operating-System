/*
A c program contains the following declarations and initial assignments:
int i=8,j=5;
float x=0.005,y=-0.01;
char c=‟c‟,d=‟d‟;
Determine the value of each of the following expressions. Use the values initially assigned to the variables
for each expression.
(a) (3*i-2*j))+(i%2*d-c)
(b) 2*((i/5)+(4*(j-3))%(i+j-2)
(c) (i-3*j)%(c+2*d)/(x-y)
*/

#include <stdio.h>
int main() {
    int i=8,j=5;
    float x=0.005,y=-0.01;
    char c ='c', d='d';
    int exp1, exp2, exp3;

    printf("ASCII value of c = %d\n", c);
    printf("char c = %c\n", c);

    exp1 = (3*i-2*j)%(2*d-c);
    exp2 =  2*((i/5)+(4*(j-3))%(i+j-2));
    exp3 = (i-3*j)%(c+2*d)/(x-y);
    /*
    printf("Expression1 = %d\n", exp1);
    printf("Expression2 = %d\n", exp2);
    printf("Expression3 = %d\n", exp3);

    printf("Expression1 = %d\n", (3*i-2*j)+(i%2*d-c));
    */
    printf("Printing using single printf\n");
    printf("Expression1 = %d,\n Expression2 = %d,\n Expression3 = %d\n", exp1, exp2, exp3);

    return 0;
}
