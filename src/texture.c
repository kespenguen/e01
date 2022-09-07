#include "texture.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char* texture_parseTGA(unsigned char *__source, size_t __lenght){
    unsigned char* rVAL = NULL;

    TGA header;
        header.idlength         = __source[0];
        header.colourmaptype    = __source[1];
            if(header.colourmaptype == 1){//If Color Map included fecth data
                header.colourmaporigin  = (__source[4]<<8) + __source[3];
                header.colourmaplength  = (__source[6]<<8) + __source[5];
                header.colourmapdepth   = (__source[7]);
            }

        header.datatypecode     = __source[2];

        header.width            = (__source[13]<<8) | __source[12];
        header.height           = (__source[15]<<8) | __source[14];        
        header.bitsperpixel     = __source[16];

    unsigned char *tga_data;

    printf("Parsing TGA Image!\n");
    
    printf("Width: %d\n",  header.width);
    printf("Height: %d\n", header.height);
    printf("Depth: %dbit\n", header.bitsperpixel);

    if(header.colourmaptype == 1){printf("ColorMap present\n");}
        else{printf("ColorMap not present!\n");}

    switch(header.datatypecode){
        case 0: printf("Error parsing texture! No image data present\n"); break;
        case 1: printf("Warning! Using uncompressed color-mapped texture\n"); break;
        case 2: printf("Warning! Using uncompressed RGB texture\n"); break;
        case 3: printf("Warning! Using uncompressed black and white texture\n"); break;
        case 9: printf("Parsing RLE encoded color-mapped image\n"); break;
        case 10: printf("Parsing RLE encoded RGB image\n"); break;

        default: printf("Error! Unrecognized or unsupported image format! %d\n", header.datatypecode); break;
    }

    short int packagesize = header.bitsperpixel / 8;
    
    rVAL = malloc((header.width*header.height) * (4 * sizeof(unsigned char)));

    int p = 0;

    int raw_skip = 0;
    for(int i = 18;i + packagesize < __lenght - 27;i= i + (packagesize + 1)){//27 is the total bytes of tga footer
        int rle = (__source[i] & 0x7f);

            if(raw_skip > 0){
//printf("RAW: ");
//printf("%x %x %x %x\n", __source[i],__source[i+1],__source[i+2],__source[i+3]);
                if(packagesize == 4){
                    rVAL[p]   = __source[i+2];//r
                    rVAL[p+1] = __source[i+1];//g
                    rVAL[p+2] = __source[i];  //b
                    rVAL[p+3] = __source[i+3];//a
                    p = p + 4;
                }else{
//printf("RAW: ");
//printf("%x %x %x\n", __source[i],__source[i+1],__source[i+2]);
                    rVAL[p]   = __source[i+2];//r
                    rVAL[p+1] = __source[i+1];//g
                    rVAL[p+2] = __source[i];  //b
                    rVAL[p+3] = 0xFF;
                    p = p + 4;
                }

                i = i - 1;
                --raw_skip;
            }else if(__source[i] & 0x80){
                if(packagesize == 4){
//printf("rle: %d | ", rle);
//printf("%x %x %x %x %x\n", __source[i],__source[i+1],__source[i+2],__source[i+3],__source[i+4]);

                    for(int j = 0; j <= rle;++j){
                        rVAL[p+3] = __source[i+4];//a
                        rVAL[p]   = __source[i+3];//r
                        rVAL[p+1] = __source[i+2];//g
                        rVAL[p+2] = __source[i+1];//b

                        p = p + 4;                    
                    }
                }else{
//printf("rle: %d | ", rle);
//printf("%x %x %x %x\n", __source[i],__source[i+1],__source[i+2],__source[i+3]);
                    for(int j = 0; j <= rle;++j){
                        rVAL[p+3] = 255;
                        rVAL[p]   = __source[i+3];//r
                        rVAL[p+1] = __source[i+2];//g
                        rVAL[p+2] = __source[i+1];//b

                        p = p + 4;                    
                    }
                }

            }else {
 
                if(packagesize == 4){
//printf("RAWHeader skipping next: %d | ",rle);
//printf("%x %x %x %x %x\n", __source[i],__source[i+1],__source[i+2],__source[i+3],__source[i+4]);

                    rVAL[p+3] = __source[i+4];//a
                    rVAL[p]   = __source[i+3];//r
                    rVAL[p+1] = __source[i+2];//g
                    rVAL[p+2] = __source[i+1];//b

                    p = p + 4;
                }else{
//printf("RAWHeader skipping next: %d | ",rle);
//printf("%x %x %x %x\n", __source[i],__source[i+1],__source[i+2],__source[i+3]);


                    rVAL[p+3] = 255;//a
                    rVAL[p]   = __source[i+3];  //r
                    rVAL[p+1] = __source[i+2];//g
                    rVAL[p+2] = __source[i+1];//b

                    p = p + 4;
                }
                raw_skip = __source[i];
            }
    }
    return rVAL;
}