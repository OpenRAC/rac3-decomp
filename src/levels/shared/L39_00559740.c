#include "common.h"

typedef struct Obj_00559980 {
    u8 pad0[0x10];
    u8 *ptr[5];
    u8 pad1[0xE0 - 0x24];
    u8 item[5][0x10];
} Obj_00559980;

/* declared by functions of L39_00557E48.c, which this file was cut from */
extern f32 func_0038DAB8(f32, f32);

/* localdecomp:start func_L39_00559740 */
#include "vu0.h"
typedef struct { f32 v[4]; } __attribute__((aligned(16))) V4_00559740;
typedef struct {
    s32 w0;
    s32 p4;
    u8 *g;
    s32 pC;
    u8 *mobys[28];
    V4_00559740 pos80;
    u8 p90[0xB0];
    s32 w140;
} S_00559740;
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern int func_L39_005BEAF8(void *a, void *b, V4_00559740 *out);

s32 func_L39_00559740(u8 *m) {
    S_00559740 *v = *(S_00559740 **)(m + 0x68);
    V4_00559740 base;
    V4_00559740 out;
    s32 i;
    f32 a;

    base = v->pos80;
    a = *(f32 *)(*(u8 **)(v->g + 0x2524) + 0xF8);
    for (i = 0; i < 4; i++) {
        a = func_0038DAB8(a, 1.5707964f);
        out.v[0] = func_0038D098(a) * 2.0f;
        out.v[1] = func_0038D0B0(a) * 2.0f;
        out.v[2] = 0.0f;
        vec_add_ab(&out, &out, &base);
        if (func_L39_005BEAF8(&base, &out, 0) == 0) {
            v->w140 = 1;
            return 1;
        }
    }
    if (v->w140 != 1) {
        v->w140 = 0;
        return 0;
    }
    if (v->w0 == 0) {
        v->w140 = 0;
        return 0;
    }
    base = *(V4_00559740 *)(v->mobys[v->w0 - 1] + 0x10);
    a = *(f32 *)(*(u8 **)(v->g + 0x2524) + 0xF8);
    for (i = 0; i < 4; i++) {
        a = func_0038DAB8(a, 1.5707964f);
        out.v[0] = func_0038D098(a) * 2.0f;
        out.v[1] = func_0038D0B0(a) * 2.0f;
        out.v[2] = 0.0f;
        vec_add_ab(&out, &out, &base);
        if (func_L39_005BEAF8(&base, &out, 0) == 0) {
            v->w140 = 1;
            return 1;
        }
    }
    v->w140 = 0;
    return 0;
}
/* localdecomp:end func_L39_00559740 */
