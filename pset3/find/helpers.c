/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */


/**
 * Sorts array of n values.
 */
 #include<stdio.h>

 int j=0;


void sort(int values[], int n)
{
    int tmp[65536];

    for(int i =0;i<=65536;++i)
    tmp[i]=0;





    for(int i =0;i<n;++i)
    {
        tmp[values[i]]=tmp[values[i]]+1;


    }

int k;
for(int i,j = 0;j<=65536;++j)
{
    if(tmp[j]!=0)
   {
       k = tmp[j];
       while(k>0)
       {
         values[i]=j;
         i=i+1;
         k=k-1;
       }






   }


}




}



bool search(int value, int values[], int n)
{

   int i =0; n = n-1;
    while(n>=i)
    {
       int k=(n+i)/2;
         if(value>values[k])
         i=k+1;

         else if(value<values[k])
         n= k-1;

         else
        {

             return true;

        }

    }




        return false;

 }












