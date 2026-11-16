#include "common.h"

/* NTSC-U counterpart of func_L20_0035CA68 (src/levels/20_final_boss/L20_0035CA68.c) */
/* localdecomp:start func_L20_0035BE20 */
extern u8 D_001A30B0[];
extern u8 D_001A4C60[];
extern s32 D_L20_001DEC34;
extern s32 D_L20_001DEC30;
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern f32 func_0037E2A8(void);
extern void func_0037E4B8(void *, f32, f32, f32);
extern f32 func_L01_00440918(f32, f32);
extern void func_L01_00467DA8(void *, s32, f32, f32, s32, s32, s32, void *, f32, s32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_0039FB08(s32);
extern s32 func_L01_003F9498(void *, s32, u8 *, f32);

typedef struct {
    f32 x, y, z, w;
} V_0035CA68 __attribute__((aligned(16)));

typedef struct {
    u8 pad0[0x18];
    u8 *moby;
    u8 pad1[4];
    V_0035CA68 pos;
} S_0035CA68;

extern S_0035CA68 D_L20_001E9BC0_0035BE20;

typedef struct {
    u8 pad0[0xC];
    s32 sound;
    f32 u;
    f32 du;
    f32 v;
    f32 dv;
    s32 flag;
} St_0035CA68;

void func_L20_0035BE20(u8 *self)
{
    St_0035CA68 *st;
    u8 *e;
    u8 *q;
    s32 cur;
    s32 i;
    s32 n;
    s32 idx;
    f32 size;
    f32 a;
    f32 b;
    V_0035CA68 tmp;
    V_0035CA68 dir;
    V_0035CA68 old;
    V_0035CA68 pos;

    st = *(St_0035CA68 **)(self + 0x68);
    if (self[0x20] == 0) {
        self[0x20] = 2;
        *(u16 *)(self + 0x34) |= 0x41;
    }
    if (self[0x20] != 2)
        return;

    st->u += st->du;
    st->v += st->dv;
    if (st->u >= 8.0f)
        st->u -= 8.0f;
    if (st->v >= 8.0f)
        st->v -= 8.0f;
    st->du = func_0037E250(0.003f, 0.005f);
    st->dv = func_0037E250(0.001f, 0.0025f);

    if (D_L20_001DEC34 != 0 && st->flag == 0) {
        *(s32 *)(self + 0x98) = 0;
        self[0x20] = 3;
    }
    if (D_L20_001DEC30 != 0) {
        *(s32 *)(self + 0x98) = 0;
        self[0x20] = 3;
    }

    tmp = *(V_0035CA68 *)D_001A4C60;
    tmp.z += 0.75f;
    if (func_L01_003F9498(&tmp, 0, *(u8 **)(D_001A4C60 + 0x2540), 0.5f) != 0
        && (q = D_L20_001E9BC0_0035BE20.moby) != 0 && *(s16 *)(q + 0xAA) == 0x10FB) {
        pos = D_L20_001E9BC0_0035BE20.pos;
        for (i = 0; i < 3; i++) {
            idx = st->sound;
            if (idx == -1 || (e = &D_001A30B0[idx * 128], *(u8 **)(e + 0xDC) != self) || e[0xD0] == 0)
                st->sound = func_0039FE80(1, 4, self);
            size = func_0037E250(1.0f, 2.0f);
            n = func_0037E1D8(2);
            if (n == 0)
                n--;
            a = func_0037E2A8();
            b = func_0037E250(0.34906584f, 1.5358897f);
            func_0037E4B8(&dir, func_0037E250(0.05f, 0.1f), a, b);
            old = pos;
            pos.x += func_L01_00440918(0.0f, 0.15f);
            pos.y += func_L01_00440918(0.0f, 0.15f);
            pos.z += func_L01_00440918(0.0f, 0.15f);
            func_L01_00467DA8(&pos, 15, size * 0.1f, size, 0xFF803040, 0, n, &dir, 0.006f, 0);
        }
    } else {
        cur = st->sound;
        if (cur != -1) {
            u8 *h;

            h = D_001A30B0 + cur * 128;
            if (*(u8 **)(h + 0xDC) == self && h[0xD0] != 0)
                func_0039FB08(cur);
        }
        st->sound = -1;
    }
}
/* localdecomp:end func_L20_0035BE20 */
