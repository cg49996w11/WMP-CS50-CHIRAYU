/**
 * Copies a BMP piece by piece, just because.
 */

#include <stdio.h>
#include <stdlib.h>
#include<math.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./copy infile outfile\n");
        return 1;
    }

    float f =atof(argv[1]);

    int k = (int)floor((1/f));

  int  n =(int)floor(f);



    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;

    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);





    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }



    int oldbiWidth=bi.biWidth;
    int oldbiHeight=abs(bi.biHeight);
            int oldpadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;



    bi.biWidth=floor(bi.biWidth*f);
    bi.biHeight=floor(bi.biHeight*f);


     // determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;


    bi.biSizeImage=((sizeof(RGBTRIPLE)*bi.biWidth)+padding)*abs(bi.biHeight);
    bf.bfSize=bi.biSizeImage+sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER);


    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

if(f>=1)
{

    // iterate over infile's scanlines
    for (int i = 0; i < oldbiHeight; i++)
    {
        for(int z = n;z>0;z--)
       {



        // iterate over pixels in scanline
        for (int j = 0; j < oldbiWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
            for(int s = n;s>0;s--)

            // write RGB triple to outfile
            fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
        }
        if(z==1)


        fseek(inptr, oldpadding, SEEK_CUR);

        else
        {
            fseek(inptr,-sizeof(RGBTRIPLE)*oldbiWidth,SEEK_CUR);


        }





        // then add it back (to demonstrate how)
        for (int m = 0; m < padding; m++)
        {
            fputc(0x00, outptr);
        }

       }


    }

}



if(f<1)
{

    int r = 0;int j ,s;

        for (int i = 0; i < abs(bi.biHeight); i++)
    {





        // iterate over pixels in scanline
        for ( j = 0, s = 0; j < bi.biWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);


            // write RGB triple to outfile
            fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
            s=s+k;
            if(s<oldbiWidth)
            fseek(inptr,(k-1)*3,SEEK_CUR);
            else
            fseek(inptr,-3,SEEK_CUR);

        }

       r=r+k;
       if(r<=abs(oldbiHeight))
{
        long int t=(((oldbiWidth-1)%k)+1)*3+oldpadding;
        fseek(inptr, t, SEEK_CUR);

        for(int d =k-1;d>0;d--)
                fseek(inptr, (oldbiWidth)*3+oldpadding, SEEK_CUR);

}






        // then add it back (to demonstrate how)
        for (int m = 0; m < padding; m++)
        {
            fputc(0x00, outptr);

        }

       }

}









    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
