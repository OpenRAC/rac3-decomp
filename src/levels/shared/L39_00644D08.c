#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00644D08);

/* localdecomp:start func_L39_006461B0 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_006461B0;

extern s32 D_001A5CDC __attribute__((section(".data")));
extern const f32 D_001DAA30_sda;
extern f32 D_L39_00246144;
extern s32 D_L39_0024112C;
extern u8 D_L39_0049C8D0[];
extern u8 D_L39_0025F760[];

extern void func_L39_006468F0(u8 *a, u8 *b);
extern s32 func_L39_00639D90(void *);
extern void func_003C7C38(void *);
extern void func_0038D570(void *, void *);
extern void func_0038D590(void *, void *);
extern f32 func_003C4138(f32 *, f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern void func_0038D028(void *, void *, void *);
extern void func_0038D328(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern void func_003C48A8(void *, void *);
extern void func_003C3FC0(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern f32 func_0038CF00(void *, void *);
extern void func_003C41A0(f32 *, f32 *, f32, f32, f32, f32);
extern void func_0038CE90(void *, void *, void *);

void func_L39_006461B0(u8 *a) {
    u8 *m = *(u8 **)(a + 0x450);
    s32 st;
    s32 skip;
    u8 *ent;
    f32 k;
    f32 t;
    V4_006461B0 mtx[4];
    V4_006461B0 rot[4];
    V4_006461B0 pos;
    V4_006461B0 v90;
    V4_006461B0 vA0;

    if (m == 0) {
        return;
    }
    if (*(s16 *)(m + 0xAA) == 0x18AB) {
        func_L39_006468F0(a, m);
        return;
    }
    st = -1;
    if (*(s32 *)(a + 0x474) == 2) {
        st = *(s32 *)(a + 0x478);
    }
    if (st == 6 || st == 12) {
        skip = 1;
    } else {
        skip = 0;
    }
    if (skip) {
        *(u16 *)(m + 0x34) |= 1;
        m[0x31] = 0;
        if (*(void (**)(void *))(m + 0x64)) {
            (*(void (**)(void *))(m + 0x64))(m);
        }
        func_003C7C38(m);
        return;
    }
    if (*(s32 *)(a + 0x1310) != 2) {
        if (*(void (**)(void *))(m + 0x64)) {
            (*(void (**)(void *))(m + 0x64))(m);
        }
        func_003C7C38(m);
        return;
    }
    ent = D_L39_0049C8D0 + *(s32 *)(a + 0x478) * 128;
    k = 0.15f;
    if (D_001A5CDC == 2) {
        k = 0.1f;
    }
    func_0038D570(mtx, a + 0x11A0);
    mtx[3] = *(V4_006461B0 *)(a + 0x11D0);
    mtx[3].w = 1.0f;
    pos = *(V4_006461B0 *)ent;
    pos.x += *(f32 *)(a + 0x1318);
    pos.z -= k;
    pos.y += 0.05f;
    t = (0.02f < *(f32 *)(a + 0x1A4) ? D_L39_00246144 : D_001DAA30_sda) * 0.017453292f * 0.020000001f;
    func_003C4138((f32 *)(a + 0x1324), t, 0.010053097f);
    *(f32 *)(a + 0x1320) = func_0038DAB8(*(f32 *)(a + 0x1320), *(f32 *)(a + 0x1324));
    pos.z += func_0038D0B0(*(f32 *)(a + 0x1320)) * 0.02f;
    func_0038D028(m + 0x10, &pos, mtx);
    if (func_L39_00639D90(a) == 0) {
        vec_add_ab(m + 0x10, m + 0x10, a + 0x180);
    }
    func_0038D328(rot, ent + 0x10);
    func_0038D5F0(m + 0xC0, mtx, rot);
    func_003C48A8(m + 0xC0, m + 0xF0);
    func_003C3FC0(a + 0x1160, m + 0xF0);
    *(f32 *)(m + 0xCC) = *(f32 *)(m + 0xDC) = *(f32 *)(m + 0xEC) = 0.0f;
    if (a[0x1A0B]) {
        m[0x31] = 0;
        *(u16 *)(m + 0x34) |= 1;
    } else {
        m[0x31] = 1;
        *(u16 *)(m + 0x34) &= 0xFFFE;
    }
    func_003C7C38(m);
    if (((u8)D_L39_0024112C ^ 1) & 1) {
        f32 s = 0.0009765625f;
        f32 h = *(f32 *)(m + 0xC) * s;

        func_0038CE20(&v90, m, s);
        func_0038CF68(&vA0, m + 0xD0, h * -1.2f);
        vec_add_ab(&vA0, &vA0, &v90);
        if (func_003D3CB0(*(void **)(a + 0x2530), &vA0, 0, *(void **)(a + 0x2524), 0)) {
            *(f32 *)(a + 0x131C) = *(f32 *)(a + 0x1318) - h + func_0038CF00(D_L39_0025F760, &v90);
            if (*(f32 *)(a + 0x131C) > 0.0f) {
                *(f32 *)(a + 0x131C) = 0.0f;
            } else if (*(f32 *)(a + 0x131C) < -1.5f) {
                *(f32 *)(a + 0x131C) = -1.5f;
            }
        } else {
            *(f32 *)(a + 0x131C) = 0.0f;
        }
    }
    func_003C41A0((f32 *)(a + 0x1318), (f32 *)(a + 0x1314), *(f32 *)(a + 0x131C), 0.006f, 0.006f, 0.10000001f);
    if (*(s32 *)(a + 0x1310) == 2) {
        func_0038D590(a + 0x380, mtx);
        *(V4_006461B0 *)(a + 0x3B0) = mtx[0];
        *(V4_006461B0 *)(a + 0x3C0) = *(V4_006461B0 *)(*(u8 **)(a + 0x2530) + 0x10);
    } else {
        vu0_q qu;

        vec_sub_ba(a + 0x380, a + 0x12B0, a + 0x1180);
        __asm__("vmr32.xyzw %0, $vf0" : "=j"(qu));
        __asm__("sqc2 %1, %0" : "=m"(v90) : "j"(qu));
        func_0038CF68(a + 0x380, a + 0x380, 1.0f);
        func_0038CE90(a + 0x390, a + 0x380, &v90);
        func_0038CF68(a + 0x390, a + 0x390, 1.0f);
        func_0038CE90(a + 0x3A0, a + 0x390, a + 0x380);
        func_003C48A8(a + 0x380, a + 0x3C0);
        *(V4_006461B0 *)(a + 0x3B0) = *(V4_006461B0 *)(a + 0x380);
    }
    if (*(void (**)(void *))(m + 0x64)) {
        (*(void (**)(void *))(m + 0x64))(m);
    }
    func_0038D570(a + 0x1340, m + 0xC0);
    *(V4_006461B0 *)(a + 0x1370) = *(V4_006461B0 *)(m + 0x10);
}
/* localdecomp:end func_L39_006461B0 */

/* localdecomp:start func_L39_00646660 */
#include "vu0.h"

extern s32 *D_001D5A10_sda;
extern void func_L39_006468F0(u8 *a, u8 *b);
extern void func_0038D590(void *, void *);
extern void func_0038D278(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D5F0(void *, void *, void *);
extern void func_0038D000(void *, void *, void *);
extern void func_003C7DD8(void *);

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00646660;

void func_L39_00646660(u8 *a, s32 alt) {
    u8 *m = *(u8 **)(a + 0x450);
    u8 *src;
    s32 st;
    s32 skip;

    if (m == 0) {
        return;
    }
    st = -1;
    if (*(s32 *)(a + 0x474) == 2) {
        st = *(s32 *)(a + 0x478);
    }
    if (st == 6 || st == 12) {
        skip = 1;
    } else {
        skip = 0;
    }
    if (skip) {
        return;
    }
    if (*(s16 *)(m + 0xAA) == 0x18AB) {
        if (alt) {
            func_L39_006468F0(a, m);
            if (m[0x42] == m[0x43] && m[0x42] == 6) {
                return;
            }
            if (*D_001D5A10_sda < 2) {
                *(f32 *)(m + 0x18) += 0.6f;
            } else {
                *(f32 *)(m + 0x18) += 0.2f;
            }
        } else {
            m[0x31] = 1;
            *(u16 *)(m + 0x34) &= 0xFFFE;
        }
        return;
    }
    src = alt ? a + 0x1340 : a + 0x1380;
    func_0038D590(m + 0xC0, src);
    *(V4_00646660 *)(m + 0x10) = *(V4_00646660 *)(src + 0x30);
    if (*(s16 *)(a + 0x2488) != 0 && alt == 0) {
        V4_00646660 rot[3];
        V4_00646660 scale;
        V4_00646660 mtx[3];
        V4_00646660 rel;

        func_0038D278(rot);
        scale = *(V4_00646660 *)(a + 0xF0);
        if (scale.x < 0.0f) {
            scale.x = 0.0f;
        }
        if (scale.y < 0.0f) {
            scale.y = 0.0f;
        }
        if (scale.z < 0.0f) {
            scale.z = 0.0f;
        }
        func_0038CF68(&rot[0], &rot[0], scale.x);
        func_0038CF68(&rot[1], &rot[1], scale.y);
        func_0038CF68(&rot[2], &rot[2], scale.z);
        func_0038D5F0(mtx, rot, a + 0x60);
        func_0038D5F0(mtx, a + 0x20, mtx);
        func_0038D5F0(m + 0xC0, mtx, m + 0xC0);
        vec_sub_ba(&rel, m + 0x10, a + 0xA0);
        func_0038D000(&rel, &rel, mtx);
        vec_add_ab(m + 0x10, &rel, a + 0xA0);
        if (*(f32 *)(a + 0xF0) < 0.1f) {
            *(u16 *)(m + 0x34) |= 0x41;
        }
    }
    func_003C7DD8(m);
    if ((u32)((*(u8 **)(a + 0x2524))[0x42] - 0x40) < 2) {
        *(f32 *)(m + 0xC) += 1800.0f;
    }
}
/* localdecomp:end func_L39_00646660 */
