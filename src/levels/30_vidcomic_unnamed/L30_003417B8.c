#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L30_003417B8 */
extern s32 func_L01_0045BD10(u8 *, f32);
extern void func_L30_00341E38(u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_L01_0045A9F0(u8 *);
extern void func_L01_0045A748(void *, void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_L01_004561B8(u8 *);
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_004AA7E8(void *, s32);
extern void func_003C2880(void *);
extern void func_L30_00341D88(u8 *);
extern void func_L30_00342030(u8 *);
extern void func_L30_00341BA0(u8 *);
extern u8 D_L30_001E9018[];
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003417B8;
extern s32 D_001A71A0[];

void func_L30_003417B8(u8 *o) {
    u8 *v = *(u8 **)(o + 0x68);

    func_L01_0045BD10(o, 3.1415927f);
    switch (o[0x20]) {
    case 0:
        func_L30_00341E38(o);
        func_L01_004450F0(o, 1, -1);
        break;
    case 1:
        if (*(s16 *)(v + 0x130) != 0 && *(s16 *)(v + 0x234) == 1) {
            func_L01_004450F0(o, 2, -1);
            break;
        }
        func_L01_0045A9F0(o);
        break;
    case 2: {
        f32 k = *(f32 *)(o + 0x2C) / *(f32 *)(*(u8 **)(o + 0x24) + 0x24);
        f32 s;
        f32 dx;
        s32 hit = 0;
        V4_003417B8 d, a, b, c;

        s = -1.0f;
        if (*(s32 *)(v + 0x298) != 0) {
            s = 1.0f;
        }
        dx = k * s;
        a = *(V4_003417B8 *)(o + 0x10);
        c = b = d = a;
        d.z += k * 0.7f;
        a.z += k * 0.7f;
        a.x += dx;
        b.z += k * 0.7f;
        b.x += k * 0.8f * s;
        c.z += k * -0.15f;
        c.x += k * 0.8f * s;
        if (func_003D3CB0(&d, &a, 0x10, o, 0) != 0) {
            hit = *(s32 *)D_L30_001E9018 != D_001A71A0[0];
        }
        if (func_003D3CB0(&b, &c, 0x12, o, 0) == 0) {
            hit = 1;
        }
        if (hit) {
            s32 t = *(s32 *)(v + 0x298) == 0;
            *(s32 *)(v + 0x298) = t;
            if (t) {
                if (o[0x43] != 2) {
                    func_003C3A10(o, 2, 0, 8);
                }
            } else {
                if (o[0x43] != 0) {
                    func_003C3A10(o, 0, 0, 8);
                }
            }
        } else {
            V4_003417B8 e = *(V4_003417B8 *)(o + 0x10);
            e.x += dx;
            func_L01_0045A748(o, &e);
        }
        break;
    }
    case 3:
        if (o[0x43] != 1) {
            func_003C3A10(o, 1, 0, 0);
        }
        func_L01_004450F0(o, 0x42, -1);
        break;
    case 0x42:
        if (func_L01_004561B8(o)) {
            func_L01_003303B8(o + 0x10, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 1, 0.9f, 0.0f, 0.0f, 2.0f,
                              1, 1, 0, 0, 1, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF,
                              0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            ((s32 (*)(s32, s32, void *))func_003A52A0)(1, 0, o);
            *(s32 *)(o + 0x98) = 0;
            *(u16 *)(o + 0x34) = (*(u16 *)(o + 0x34) | 0x41) & 0xEFFF;
            func_L01_004AA7E8(o, 1);
            if (*(void **)(v + 0x2A0) != 0) {
                func_003C2880(*(void **)(v + 0x2A0));
            }
            *(void **)(v + 0x2A0) = 0;
            return;
        }
        break;
    }
    func_L30_00341D88(o);
    func_L30_00342030(o);
    func_L30_00341BA0(o);
}
/* localdecomp:end func_L30_003417B8 */

/* localdecomp:start func_L30_00341BA0 */
#include "vu0.h"
extern void func_003C2F58(u8 *, s32, u8 *);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_003D4D00(void *, s32, void *, s32, f32);
extern void func_L30_00342090(u8 *, s32, u8 *);
extern void func_003C2880(void *);
extern s32 func_L30_00340E18(u8 *, u8 *, u8 *, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32);
__asm__(".extern D_L30_001DCE20, 4");
extern s32 D_L30_001DCE20;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00341BA0;
typedef struct { u8 pad[0x20]; s32 flags; u8 pad2[0xC]; } S_00341BA0;

void func_L30_00341BA0(u8 *o) {
    u8 *v = *(u8 **)(o + 0x68);
    f32 k = *(f32 *)(o + 0x2C) / *(f32 *)(*(u8 **)(o + 0x24) + 0x24);
    V4_00341BA0 pos;
    V4_00341BA0 dir;
    S_00341BA0 hit;

    if (*(s32 *)(v + 0x2A0) != 0) {
        func_003C2F58(o, 2, v + 0x2B0);
        func_003C2F58(o, 3, v + 0x2C0);
        func_003C2F58(o, 4, (u8 *)&pos);
        vec_sub_ab(&dir, v + 0x2C0, v + 0x2B0);
        func_L01_00446760(&hit, o, 1, &dir, 1.0f);
        hit.flags |= 1;
        if (func_003D3CB0(v + 0x2B0, v + 0x2C0, 9, o, 0) != 0) {
            func_L30_00342090(o, (s32)&hit, (u8 *)&pos);
        }
        if (func_003D4D00(&pos, 0x10, o, 0, k * 0.3f) != 0) {
            func_L30_00342090(o, (s32)&hit, (u8 *)&pos);
        }
    }
    if (D_L30_001DCE20 != 0) {
        if (*(void **)(v + 0x2A0) != 0) {
            func_003C2880(*(void **)(v + 0x2A0));
        }
        *(s32 *)(v + 0x2A0) = func_L30_00340E18(v + 0x2B0, o, v + 0x2C0, 0x32, 0x32, 0x14, 5, 0xFF0808,
                                                0.2f, 0.22f, 0.1f, 1.3f, 0xFF0808, 1, -1, 1);
        D_L30_001DCE20 = 0;
    }
}
/* localdecomp:end func_L30_00341BA0 */
