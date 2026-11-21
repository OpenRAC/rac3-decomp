#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L32_003A1E58 */
extern u8 *D_L32_001DFF00;
__asm__(".extern D_L32_001DFF00, 16");
extern f32 D_L32_001DE6AC;
__asm__(".extern D_L32_001DE6AC, 4");
extern u8 D_1A4C60[];
extern s32 func_00382380(void *, s32, s32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern f32 func_L30_0034CE78(u8 *);
extern void func_L02_003BA9F8(void *, void *, void *, void *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CF00(void *, void *);

typedef struct {
    u8 pad0[0x30];
    vu0_v4 pos;
    u8 pad40[0x40];
} E_003A1E58;

void func_L32_003A1E58(void *a) {
    u8 *arg0 = a;
    vu0_v4 best;
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 t;
    vu0_v4 v40;
    vu0_v4 v50;
    u8 *p = *(u8 **)(arg0 + 0x68);
    s32 *ids;
    s32 i;
    s32 off;
    f32 dist;
    f32 far;

    ids = (s32 *)(p + 0xA0);
    far = 0.0f;
    dist = far;
    best = ((E_003A1E58 *)D_L32_001DFF00)[*ids].pos;
    for (i = 0, off = 0; i < 8; ids++, i++, off += 4) {
        if (*ids == -1 || *(s32 *)(p + off + 0xC0) == -1) {
            continue;
        }
        if (func_00382380(D_1A4C60, *(s32 *)(p + off + 0xC0), 0) == 0) {
            continue;
        }
        if (func_003D3CB0(arg0 + 0x10, &((E_003A1E58 *)D_L32_001DFF00)[*ids].pos, 2, arg0, 0) != 0) {
            continue;
        }
        t = *(vu0_v4 *)D_1A4C60;
        t.z += func_L30_0034CE78(*(u8 **)(D_1A4C60 + 0x2540));
        vec_sub_ab(&v10, &((E_003A1E58 *)D_L32_001DFF00)[*ids].pos, arg0 + 0x10);
        vec_sub_ab(&v20, &t, arg0 + 0x10);
        func_L02_003BA9F8(&v20, &v10, &v40, &v50);
        if ((D_L32_001DE6AC <= dist && D_L32_001DE6AC <= func_0038CEA8(&v50) &&
             far < func_0038CF00(D_1A4C60, &((E_003A1E58 *)D_L32_001DFF00)[*ids].pos)) ||
            (dist < D_L32_001DE6AC && dist < func_0038CEA8(&v50))) {
            best = ((E_003A1E58 *)D_L32_001DFF00)[*ids].pos;
            dist = func_0038CEA8(&v50);
            far = func_0038CF00(D_1A4C60, &((E_003A1E58 *)D_L32_001DFF00)[*ids].pos);
        }
    }
    *(vu0_v4 *)(p + 0x1C0) = best;
}
/* localdecomp:end func_L32_003A1E58 */
