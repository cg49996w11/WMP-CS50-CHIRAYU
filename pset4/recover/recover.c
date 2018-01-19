#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "bmp.h"

int main(int argc,char *argv[])
{

    if(argc!=2)
    {
        fprintf(stderr,"enter correct arguement");
        return 1;
    }

    FILE *file = fopen(argv[1],"r");
    BYTE *buffer;

    if(file==0)
    {
        fprintf(stderr,"file not opening");
        return 2;
    }
   buffer = malloc(512);
   int y = 512;
   int counter = 0;
   FILE *img = NULL;
   int s;
   while(y==512)
   {


    y = fread(buffer,1,512,file);
    char filename[8];

    if(buffer[0]==0xff&&buffer[1]==0xd8&&buffer[2]==0xff&&(buffer[3]&0xf0)==0xe0)
    {
        if(counter!=0)
        fclose(img);
        sprintf(filename,"%3d.jpg",counter);
        counter = counter + 1;
        s=6;

    }

    if(counter==0)
    continue;
    if(s==6)
   img = fopen(filename,"w");
fwrite(buffer,1,y,img);



s=7;


}
fclose(file);
fclose(img);
free(buffer);

}