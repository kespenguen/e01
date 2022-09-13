#ifndef __transform_h__
#define __transform_h__
#include "definitions.h"

void transform_Translate(mat4 **__transform,vec3 __pos);
void transform_Rotate(mat4 **__transform, vec3 __rot);
void transform_Scale(mat4 **__transform, vec3 __scl);


#endif