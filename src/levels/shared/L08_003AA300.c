#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef struct V_003A8330 {
    f32 x, z, y, w;
} __attribute__((aligned(16))) V_003A8330;

/* declared by functions of L08_003AA1F8.c, which this file was cut from */
extern s32 func_0038CAD0(void *);

/* localdecomp:start func_L08_003AA300 */
#include "vu0.h"


typedef struct {
    u8 pad0[0x18];
    u8 *moby;
    u8 pad1[4];
    V_003A8330 v20;
    V_003A8330 v30;
    V_003A8330 v40;
} S_003AA300;

extern S_003AA300 D_L08_001E8A80;
extern void func_0038CE20(void *, void *, f32);
extern s32 func_L01_003FB640(void *, s32, void *, f32);
extern void func_L01_0040E790(void *, void *, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_004CB320(void);
extern void func_L01_004CB358(void);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern void func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003C2880(void *);

static __inline__ void vcopy_003AA300(V_003A8330 *d, V_003A8330 *s) {
    *d = *s;
}

void func_L08_003AA300(u8 *o) {
    u8 *p;
    V_003A8330 old;
    V_003A8330 g;
    V_003A8330 d;
    s32 hit;
    u8 *m;

    p = *(u8 **)(o + 0x68);
    if (p == 0) {
        return;
    }
    vcopy_003AA300(&old, (V_003A8330 *)(o + 0x10));
    vec_add_ba(o + 0x10, p, o + 0x10);
    {
        vu0_q q;
        __asm__("vmr32.xyzw %0, $vf0" : "=j"(q));
        __asm__("sqc2 %1, %0" : "=m"(g) : "j"(q));
    }
    func_0038CE20(&g, &g, *(f32 *)(p + 0x28) * 0.00040000002f);
    vec_sub_ab(p, p, &g);
    if (func_L01_003FB640(o + 0x10, 0, o, 0.1f) != 0) {
        if (D_L08_001E8A80.moby != 0) {
            if (D_L08_001E8A80.moby != *(u8 **)(o + 0xB8)) {
                *(V_003A8330 *)(o + 0x10) = D_L08_001E8A80.v30;
                func_L01_0040E790(p, p, &D_L08_001E8A80.v40);
                *(f32 *)(p + 8) = *(f32 *)(p + 8) * 2.0f;
                func_0038CE20(p, p, 0.25000003f);
                *(V_003A8330 *)(o + 0x10) = D_L08_001E8A80.v20;
                func_L01_004450F0(o, 1, -1);
            }
        } else {
            *(V_003A8330 *)(o + 0x10) = D_L08_001E8A80.v30;
            func_L01_0040E790(p, p, &D_L08_001E8A80.v40);
            *(f32 *)(p + 8) = *(f32 *)(p + 8) * 2.0f;
            func_0038CE20(p, p, 0.25000003f);
            *(V_003A8330 *)(o + 0x10) = D_L08_001E8A80.v20;
            *(f32 *)(o + 0x18) = *(f32 *)(o + 0x18) + 0.5f;
            func_L01_004450F0(o, 1, -1);
        }
    } else {
        func_L01_004CB320();
        hit = func_003D3CB0(&old, o + 0x10, 0x10, o, 0);
        if (hit != 0) {
            m = D_L08_001E8A80.moby;
            if (m != 0 && *(s16 *)(m + 0xAA) == 0x186D && m[0x20] != 2 && m[0x20] != 5) {
                m[0x20] = 4;
            }
        }
        func_L01_004CB358();
        if (hit != 0) {
            if (D_L08_001E8A80.moby != 0) {
                if (D_L08_001E8A80.moby != *(u8 **)(o + 0xB8)) {
                    *(V_003A8330 *)(o + 0x10) = D_L08_001E8A80.v30;
                    func_L01_0040E790(p, p, &D_L08_001E8A80.v40);
                    *(f32 *)(p + 8) = *(f32 *)(p + 8) * 2.0f;
                    func_0038CE20(p, p, 0.25000003f);
                    *(V_003A8330 *)(o + 0x10) = D_L08_001E8A80.v20;
                    func_L01_004450F0(o, 1, -1);
                }
            } else {
                *(V_003A8330 *)(o + 0x10) = D_L08_001E8A80.v20;
                func_0038CF68(&d, &D_L08_001E8A80.v40, 0.1f);
                vec_add_ba(o + 0x10, o + 0x10, &d);
                func_L01_0040E790(p, p, &D_L08_001E8A80.v40);
                *(f32 *)(p + 8) = *(f32 *)(p + 8) * 2.0f;
                func_0038CE20(p, p, 0.25000003f);
                *(V_003A8330 *)(o + 0x10) = D_L08_001E8A80.v20;
                *(f32 *)(o + 0x18) = *(f32 *)(o + 0x18) + 0.5f;
                func_L01_004450F0(o, 1, -1);
            }
        }
    }
    if (func_0038CAD0(p + 0x18) != 0 || func_0038CEA8(p) < 0.010000001f) {
        func_L01_003303B8(o + 0x10, 1, 10, 10, 10, 10, 0x1E, 0, 1.5f, 0.0f, *(f32 *)(p + 0x20), 2.0f,
                          0, 1, 0, 0, 0, 0, 0x10001, 0, 0x804020, 0x806040, 0x407FFF, 0x20FF, 0x8FFF,
                          0x3064FF, 0x7F804020, 0x28802020, 0xFF6020, 0);
        func_003C2880(o);
    }
}
/* localdecomp:end func_L08_003AA300 */
