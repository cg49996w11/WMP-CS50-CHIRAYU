#include<stdio.h>
#include<cs50.h>
#include<math.h>

int main(void)
{
    float change;
    printf("o hai!");
    do
    {
        printf("how much change is owed?\n");

        change = get_float();

    }
    while(change<0);

    change = change*100;

    change = (int)round(change);

    int y,count;
    count = change/25;
    y = (int)change%25;

    count = count + y/10;
    y = y%10;

    count = count + y/5;
    y = y%5;

    count = count + y;
    printf("%d\n",count);




}