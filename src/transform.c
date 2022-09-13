#include "transform.h"

void transform_Translate(mat4 **__transform,vec3 __pos){
    glm_translate(**__transform,__pos);
}
void transform_Rotate(mat4 **__transform, vec3 __rot){
    glm_rotate(**__transform,glm_rad(90.0f),__rot);
}
void transform_Scale(mat4 **__transform, vec3 __scl){
    glm_scale(**__transform, __scl);
}