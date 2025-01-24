
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int number , guess  , ngusses=1 ;
    srand(time(0));
    number = rand()%100 + 1 ; 

    do{

        printf("guess the number between 1 to 100\n ");
        scanf("%d",&guess);
        if(guess>number){
            printf("lower number plz\n");

        }
        else if (guess<number){
            printf("higher number plz\n");

    }
else
{
    printf("you guessed it in %d attempts\n", ngusses);
}
ngusses++;
    }while(guess!=number);
    return 0 ;


}
