#include "common.h"

typedef struct Obj_00559980 {
    u8 pad0[0x10];
    u8 *ptr[5];
    u8 pad1[0xE0 - 0x24];
    u8 item[5][0x10];
} Obj_00559980;

/* localdecomp:start func_L39_00557FD0 */
#include "vu0.h"
typedef struct { u8 p0[0x10]; vu0_v4 pos; } O_00557FD0;
extern f32 func_0038CE68();
void func_L39_00557FD0(void *dir, void *org, void *list, s32 n) {
    O_00557FD0 **objs = list;
    vu0_v4 flat;
    f32 d[5];
    vu0_v4 delta;
    vu0_v4 tmp;
    s32 i;
    s32 j;
    f32 t;
    O_00557FD0 *o;

    if (n < 6) {
        for (i = 0; i < n; i++) {
            vec_sub_ab(&tmp, &objs[i]->pos, org);
            delta = tmp;
            flat = delta;
            flat.z = 0.0f;
            d[i] = func_0038CE68(&flat, dir);
        }
        for (i = 0; i < n; i++) {
            for (j = i + 1; j < n; j++) {
                if (d[i] < d[j]) {
                    t = d[i];
                    d[i] = d[j];
                    d[j] = t;
                    o = objs[i];
                    objs[i] = objs[j];
                    objs[j] = o;
                }
            }
        }
    }
}
/* localdecomp:end func_L39_00557FD0 */
