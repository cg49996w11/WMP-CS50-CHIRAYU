#include<stdio.h>
#include<cs50.h>
#include<ctype.h>
#include<string.h>
 int main(void)
{



int i ;
 string s = get_string();


    int k = strlen(s);


    for(  i =0 ;i<k;++i)
    {
        while(i<k&&s[i]== ' ')
        i = i+1;
        if(s[i]!='\0')
        printf("%c",toupper(s[i]));


        while(i<k&&s[i]!=' ')
        i=i+1;



    }
    printf("\n");

    return 0;




}