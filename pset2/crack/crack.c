#define _XOPEN_SOURCE
#include <unistd.h>
#include<stdio.h>

#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include<crypt.h>


int main (int argc,string argv[])
{
    char key[5];
    char salt[3];

    key[4]='\0';salt[2]='\0';


    if(argc!=2)
    {
        printf("incorrect arguement");
        return 1;

    }

    strncpy(salt,argv[1],2);




        for(char i='A';i<='z' ;++i)
        {
            key[0]=i;


            for(char j='A';j<='z' ;++j)
            {
                key[1]=j;
                for(char k='A'; k<='z';++k)
                {
                    key[2]=k;
                    for(char l='A';l<='z' ;++l)
                    {
                        key[3]=l;





                    if(l=='Z')
                    l=l+6;

                    if(strcmp(crypt(key,salt),argv[1])==0)
                    {

                        printf("%s",key);
                        return 0;


                    }
                    }
                        if(k=='Z')
                    k=k+6;


                }
                                    if(j=='Z')
                    j=j+6;

            }

                                if(i=='Z')
                    i=i+6;
        }



        key[3]='\0';







            for(char j='A';j<='z' ;++j)
            {
                key[0]=j;
                for(char k='A'; k<='z';++k)
                {
                    key[1]=k;
                    for(char l='A';l<='z' ;++l)
                    {
                        key[2]=l;





                    if(l=='Z')
                    l=l+6;

                    if(strcmp(crypt(key,salt),argv[1])==0)
                    {

                        printf("%s",key);
                        return 0;


                    }
                    }
                        if(k=='Z')
                    k=k+6;


                }
                                    if(j=='Z')
                    j=j+6;

            }


            key[2]='\0';



                            for(char k='A'; k<='z';++k)
                {
                    key[0]=k;
                    for(char l='A';l<='z' ;++l)
                    {
                        key[1]=l;





                    if(l=='Z')
                    l=l+6;

                    if(strcmp(crypt(key,salt),argv[1])==0)
                    {

                        printf("%s",key);
                        return 0;


                    }
                    }
                        if(k=='Z')
                    k=k+6;


                }



        key[1]='\0';



                            for(char l='A';l<='z' ;++l)
                    {
                        key[0]=l;





                    if(l=='Z')
                    l=l+6;

                    if(strcmp(crypt(key,salt),argv[1])==0)
                    {

                        printf("%s",key);
                        return 0;


                    }
                    }





















return 2;




}