#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<stdlib.h>

string encrypt(string  ,int  ,int  );



int main(int argc,string argv[])
{
    if(argc!=2)

    {
        printf("incorrect number of arguments");
        return 1;
    }

    int key = atoi(argv[1]);




    printf("plaintext: ");

    string input = get_string();

    int n = strlen(input);


   string encrypted = encrypt(input,n+1,key);



printf("ciphertext: ");

printf("%s\n",encrypted);

return 0;

}



string encrypt(string input,int n,int key)
{
char a1[27] = "abcdefghijklmnopqrstuvwxyz";
char a2[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int r;
for(int count = 0;count<n-1;++count)
{
    if(input[count]>=65&&input[count]<=90)
    {
        r = input[count]-65;
        input[count] = a2[(r+key)%26];



    }

 if(input[count]>=97&&input[count]<=122)
{
    r = input[count]-97;
    input[count] = a1[(r+key)%26];
}



}


return input;



}

