#ifndef __io_h__
#define __io_h__

#include <stdlib.h>

char* io_read(const char *input);

void io_write(const char *output, char *input);

unsigned char* io_readBinary(const char *__path, size_t **__lenght);



#endif