#ifndef __texture_h__
#define __texture_h__

#include <stddef.h>

/*                             TRUEVISION TGA HEADER FORMAT
/___________________________________________________________________________________________\
| Field no. 	Length 	    Field name 	                Description                         |
|___________________________________________________________________________________________|
|       1 	    1 byte 	    ID length 	                Length of the image ID field        |
|       2 	    1 byte 	    Color map type 	            Whether a color map is included     |
|       3 	    1 byte 	    Image type 	                Compression and color types         |
|       4 	    5 bytes     Color map specification 	Describes the color map             |
|       5 	    10 bytes 	Image specification 	    Image dimensions and format         |
\__________________________________________________________________________________________*/

#define TEXTURE_TYPE_SINGULAR 0
#define TEXTURE_TYPE_BLEND    255

typedef struct {
   char  idlength;
   char  colourmaptype;
   char  datatypecode;
   short int colourmaporigin;
   short int colourmaplength;
   char  colourmapdepth;
   short int x_origin;
   short int y_origin;
   short width;
   short height;
   char  bitsperpixel;
   char  imagedescriptor;
} TGA;


unsigned char* texture_parseTGA(unsigned char *__source, size_t __lenght);


#endif