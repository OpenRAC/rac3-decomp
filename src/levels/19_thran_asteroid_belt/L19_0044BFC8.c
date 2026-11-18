#include "common.h"

typedef struct { u8 p0[0x64]; s32 f64; } S_44BFC8_R;
typedef struct { u8 p0[0x7C]; s16 h7C; u8 p7E[0x1A]; s32 f98; } S_44BFC8_O;

extern void func_L01_00451E78(void *, s32, f32);
extern void func_L01_00439880(void *, u16 *, s32 *);
extern void func_003A52A0(s32, s32, void *);
extern f32 func_003824E0(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern void func_0038D000(float *, float *, void *);
extern S_44BFC8_R *func_L01_003F79D8(void *, s32, s32, s32, void *, void *, void *, s32, f32, f32, s32, s32, s32);

/* localdecomp:start func_L19_0044BFC8 */
extern s32 D_001D7BF4_sda;
__asm__(".extern D_001D7BF4_sda, 4");
extern s32 D_001DF918_sda;
__asm__(".extern D_001DF918_sda, 4");
extern s32 D_L19_001DF240;
__asm__(".extern D_L19_001DF240, 16");
extern s32 D_L19_001DF918;
__asm__(".extern D_L19_001DF918, 16");

void func_L19_0044BFC8(S_44BFC8_O *obj, f32 *a1, f32 *a2, f32 *a3, s32 mask1, s32 t1, s32 skip, s32 flags, s32 mask2, u8 b, s32 extra) {
    f32 vec[4];
    u16 n0;
    s32 count;
    s32 i;
    f32 sa;
    f32 sb;
    S_44BFC8_R *r;

    if (D_001D7BF4_sda != D_L19_001DF240) {
        D_001D7BF4_sda = D_L19_001DF240;
        D_L19_001DF918 = 0;
    }
    D_001DF918_sda = D_L19_001DF918 + 1;
    if (obj == 0) {
        return;
    }
    obj->h7C = 0;
    obj->f98 = 0;
    if ((flags ^ 1) & 1) {
        func_L01_00451E78(obj, 1, 0.0f);
    }
    if (flags & 0x10) {
        func_L01_00451E78(obj, 9, 0.0f);
    } else if (flags & 0x20) {
        func_L01_00451E78(obj, 2, 0.0f);
    }
    func_L01_00439880(obj, &n0, &count);
    if (t1 != -1) {
        func_003A52A0(t1, 0, obj);
    }
    for (i = 0; i < count; i++) {
        if (skip == i) {
            continue;
        }
        if (((mask2 >> i) ^ 1) & 1) {
            continue;
        }
        sa = func_003824E0(a3[0], a3[1]);
        sb = func_003824E0(a2[0], a2[1]);
        if (flags & 2) {
            vec[0] = func_L01_00443A18(a1[0], a1[4]) * 0.020000001f;
        } else {
            vec[0] = func_003824E0(a1[0], a1[4]) * 0.020000001f;
        }
        if (flags & 4) {
            vec[1] = func_L01_00443A18(a1[1], a1[5]) * 0.020000001f;
        } else {
            vec[1] = func_003824E0(a1[1], a1[5]) * 0.020000001f;
        }
        vec[2] = func_003824E0(a1[2], a1[6]) * 0.020000001f;
        if (!(flags & 8)) {
            func_0038D000(vec, vec, (u8 *)obj + 0xC0);
        }
        if ((mask1 >> i) & 1) {
            r = func_L01_003F79D8(obj, 2, *(s16 *)((u8 *)obj + 0xAA), i, (u8 *)obj + 0x10, (u8 *)obj + 0xF0, vec, b, sb, sa, 0xB4, 0, 0x80);
        } else {
            r = func_L01_003F79D8(obj, 1, *(s16 *)((u8 *)obj + 0xAA), i, (u8 *)obj + 0x10, (u8 *)obj + 0xF0, vec, b, sb, sa, 0xB4, 0, 0x80);
        }
        if (r != 0) {
            if (extra != 0) {
                r->f64 = extra;
            }
        }
    }
}
/* localdecomp:end func_L19_0044BFC8 */
