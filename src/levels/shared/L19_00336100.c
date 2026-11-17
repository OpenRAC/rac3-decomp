#include "common.h"

/* localdecomp:start func_L19_00336100 */
#include "vu0.h"

typedef struct {
    s32 n;
    s32 pad[3];
    vu0_v4 pt[1];
} P_00336100;

typedef struct {
    u8 p0[0x28];
    s32 path[4];
    s32 count;
    u8 p3C[0xA4];
    vu0_v4 offset;
} V_00336100;

extern P_00336100 *D_L19_0021D500[];
extern void func_L19_00336008(void *, void *, s32);

void func_L19_00336100(u8 *m) {
    V_00336100 *v = *(V_00336100 **)(m + 0x68);
    vu0_v4 o;
    s32 i;
    s32 j;

    for (i = 0; i < 4; i++) {
        P_00336100 *p = D_L19_0021D500[v->path[i]];
        if (p != 0) {
            func_L19_00336008(&o, p, v->count);
            for (j = 0; j < v->count; j++) {
                vec_sub_ab(&p->pt[j], &p->pt[j], &o);
                vec_add_ab(&p->pt[j], &p->pt[j], &v->offset);
            }
        }
    }
}
/* localdecomp:end func_L19_00336100 */
