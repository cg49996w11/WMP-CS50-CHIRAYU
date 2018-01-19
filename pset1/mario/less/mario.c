#include<stdio.h>
#include<cs50.h>
int main(void)
{
    int height;

    do
    {
        printf("height: ");
        height = get_int();
        if(height==0)
        return 0;
    }
    while (height < 0  || height>23);

    for(int i=1;i<=height;i++)
    {
        for(int j=height-i;j>0;j--)
        {
        printf(" ");
        }

        for(int j =0;j<=i;++j )
        {printf("#");
        }
        printf("\n");
    }

return 0;
}
