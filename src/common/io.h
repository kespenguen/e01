#ifndef __io_h__
#define __io_h__

#include <stdlib.h>

char* io_read(const char *__path);

void io_write(const char *__path, char *__source);

unsigned char* io_readBinary(const char *__path, size_t **__lenght);

void io_ParseXML(const char *__path);
void io_ParseCollada(const char *__path);

#endif