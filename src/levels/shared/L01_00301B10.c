#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_00301B10 */
extern vu0_v4 D_L01_001E29C0;
extern vu0_v4 D_001A4EC0;
extern f32 D_L01_001DC4F8;
__asm__(".extern D_L01_001DC4F8, 4");
extern f32 D_L01_001DC4FC;
__asm__(".extern D_L01_001DC4FC, 4");
extern s32 D_L01_001DC500;
__asm__(".extern D_L01_001DC500, 4");
extern s32 D_L01_001DC504;
__asm__(".extern D_L01_001DC504, 4");
extern s32 D_L01_001DC508;
__asm__(".extern D_L01_001DC508, 4");
extern s32 D_L01_001DC50C;
__asm__(".extern D_L01_001DC50C, 4");
extern f32 D_L01_001DC510;
__asm__(".extern D_L01_001DC510, 4");
extern f32 D_L01_001DC514;
__asm__(".extern D_L01_001DC514, 4");
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern s32 func_00382468(s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D890(void *, void *, void *, f32);
extern void func_L01_0046C470(void *, void *, s32, f32, s32, s32, s32, s32, s32);

void func_L01_00301B10(u8 *o) {
    vu0_v4 d;
    vu0_v4 v10;
    vu0_v4 v20;
    u8 *st;
    s32 color;

    vec_sub_ab(&d, &D_L01_001E29C0, o + 0x10);
    st = *(u8 **)(o + 0x68);
    func_0038CE20(&v10, &D_001A4EC0, func_003824E0(D_L01_001DC4F8 * 0.020000001f, D_L01_001DC4FC * 0.020000001f));
    func_0038D890(&v20, &v10, &d, func_00382538());
    if (st[0x57] != 0) {
        color = D_L01_001DC50C;
    } else {
        color = D_L01_001DC504;
    }
    func_L01_0046C470(o + 0x10, &v20, color, D_L01_001DC510, D_L01_001DC500, func_00382468(0xFF) & 0xFF, 1, 0x40, 0);
    func_L01_0046C470(o + 0x10, &v20, D_L01_001DC508, D_L01_001DC514, D_L01_001DC500, func_00382468(0xFF) & 0xFF, 1, 0x40, 0);
}
/* localdecomp:end func_L01_00301B10 */

/* localdecomp:start func_L01_00301C38 */
#include "vu0.h"
extern u8 *D_L01_00221098[];
extern f32 D_L01_001DC530[2];
__asm__(".extern D_L01_001DC530, 4");
extern f32 D_L01_001DC540[2];
__asm__(".extern D_L01_001DC540, 4");
extern f32 D_L01_001DC550[2];
__asm__(".extern D_L01_001DC550, 4");
extern s32 D_L01_001DC518;
__asm__(".extern D_L01_001DC518, 4");
extern s32 D_L01_001DC51C;
__asm__(".extern D_L01_001DC51C, 4");
extern s32 D_L01_001DC520;
__asm__(".extern D_L01_001DC520, 4");
extern s32 D_L01_001DC524;
__asm__(".extern D_L01_001DC524, 4");
extern s32 D_L01_001DC528;
__asm__(".extern D_L01_001DC528, 4");
extern s32 D_L01_001DC52C;
__asm__(".extern D_L01_001DC52C, 4");
extern s32 D_L01_001DC4CC;
__asm__(".extern D_L01_001DC4CC, 4");

extern void func_0038CF68(void *, void *, f32);
extern s32 func_0038CB00(void *);
extern s32 func_0038DBD8(s32, s32, f32);
extern u8 *func_L01_0046C2E8(void *, s32, s32, s32, s32, s32, s32, s32, f32);

typedef struct {
    u8 pad[0x57];
    u8 flag;
    s16 h[4];
    f32 fa[4];
} St;

s32 func_L01_00301C38(u8 *obj) {
    vu0_v4 va;
    vu0_v4 vb;
    s32 found;
    St *st;
    s32 i;
    s32 x;
    s32 col;
    s32 al;
    s32 ah;
    f32 f1;
    f32 z;
    f32 d;
    f32 t;
    f32 keep;
    u8 *r;

    st = *(St **)(obj + 0x68);
    vec_sub_ab(&va, &D_L01_001E29C0, obj + 0x10);
    func_0038CF68(&va, &va, -0.3f);
    found = 0;
    func_0038CF68(&vb, &va, 0.1f);
    vec_add_ba(&va, &va, obj + 0x10);
    z = va.z;
    for (i = 0; i < 4; i++) {
        if (func_0038CB00(&st->h[i]) != 0) {
            continue;
        }
        f1 = st->fa[i] + D_L01_001DC530[i];
        if (st->h[i] >= 0x29) {
            found = 1;
        }
        st->fa[i] = f1;
        if (255.0f <= f1) {
            st->fa[i] = f1 - 255.0f;
        } else if (f1 <= 0.0f) {
            st->fa[i] = f1 + 255.0f;
        }
        keep = fabs_asm(0.5f - (f32)(0xD4 - st->h[i]) / 212.0f);
        if (st->flag != 0) {
            col = func_0038DBD8(D_L01_001DC520, D_L01_001DC524, keep);
        } else {
            col = func_0038DBD8(D_L01_001DC518, D_L01_001DC51C, keep);
        }
        x = D_L01_001DC52C;
        d = 1.0f - (f32)st->h[i] / (f32)((D_L01_001DC4CC * 5 + 2) / 6);
        al = col >> 24;
        va.z = z + D_L01_001DC550[i];
        t = 1.0f - d;
        al = (s32)((f32)al * t);
        ah = al << 24;
        r = func_L01_0046C2E8(&va, ah | (col & 0xFFFFFF),
                              (u8)(s32)st->fa[i], x, 0, 2, 1, 0,
                              D_L01_001DC540[i] * d);
        if (r != 0) {
            r[2] = *D_L01_00221098[0xF8 / 4];
        }
        r = func_L01_0046C2E8(&va, ah | 0xFFFFFF,
                              (u8)(s32)st->fa[i], D_L01_001DC52C, D_L01_001DC528, 2, 1, 0,
                              D_L01_001DC540[i] * (d * 0.7f));
        if (r != 0) {
            r[2] = *D_L01_00221098[0xF8 / 4];
        }
        vec_add_ab(&va, &va, &vb);
    }
    return found;
}
/* localdecomp:end func_L01_00301C38 */
