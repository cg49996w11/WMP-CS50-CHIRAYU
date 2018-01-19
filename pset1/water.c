#include<stdio.h>
#include<cs50.h>
int main(void)
{



    int minutes;
    printf("Minutes: ");
    do
    {
        minutes = get_int();
    }
    while(minutes<=0);




    minutes = minutes*12;

    printf("Bottles: %i\n",minutes);



}