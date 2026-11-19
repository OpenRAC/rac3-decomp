#include "common.h"

/* localdecomp:start func_L05_00312BD8 */
#include "vu0.h"

typedef int u128_00312BD8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00312BD8;

extern u8 D_001A4C60[];
extern u8 *D_L05_001DFC80;
__asm__(".extern D_L05_001DFC80, 4");
extern u8 *D_L05_001DFC80_00312BD8;
extern u8 *D_L05_0021ED80[];
extern u8 D_L05_001E2680[];
extern s32 func_00382380(void *, s32, s32);
extern s32 func_L01_00445AD0(s32, s32, s32);
extern void func_L01_003F2AF8(s32, void *);
extern u8 *func_L01_003F2A50(s32, s32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CF38(void *, void *);
extern void func_L01_003EB438(s32, void *, void *, s32, s32, s32);
extern void func_L01_003EB350(s32, void *);
extern void func_L01_003EB3C0(s32, void *);
extern s32 func_L05_003E6220(s32);
extern void func_L05_003E63C0(s32, s32, s32);
extern void func_L01_003EB5E0(s32, s32);
extern s32 func_0038DC20(void *, f32);

void func_L05_00312BD8(u8 *o) {
    V4_00312BD8 loc0;
    V4_00312BD8 loc10;
    u8 *st;
    u8 *p0;
    u8 *q;
    u8 *pt;
    s32 near;
    s32 ok;
    f32 f;

    st = *(u8 **)(o + 0x68);
    ok = 1;
    near = func_00382380(D_001A4C60, *(s32 *)(st + 0x10), 0);
    if (*(s32 *)st == -1 && *(s32 *)(st + 4) == -1 && *(s32 *)(st + 8) == -1) {
        if (*(s32 *)(st + 0xC) == -1) {
            ok = 0;
        }
    }
    if (*(s32 *)st != -1 && func_L01_00445AD0(*(s32 *)st, -1, 0) != 0) {
        ok = 0;
    }
    if (*(s32 *)(st + 4) != -1 && func_L01_00445AD0(*(s32 *)(st + 4), -1, 0) != 0) {
        ok = 0;
    }
    if (*(s32 *)(st + 8) != -1 && func_L01_00445AD0(*(s32 *)(st + 8), -1, 0) != 0) {
        ok = 0;
    }
    if (*(s32 *)(st + 0xC) != -1 && func_L01_00445AD0(*(s32 *)(st + 0xC), -1, 0) != 0) {
        ok = 0;
    }
    if (o[0x20] != 0) {
        p0 = *(u8 **)(st + 0x14);
        if (p0 != 0) {
            if (near == 0 || ok != 0) {
                func_L01_003F2AF8(0, p0);
                *(s32 *)(st + 0x14) = 0;
                goto tail;
            }
        } else if (near == 0) {
            goto l404;
        } else if (ok == 0 && *(s32 *)(st + 0x38) == -1) {
            q = func_L01_003F2A50(0, st[0x33]);
            *(u8 **)(st + 0x14) = q;
            if (q == 0) {
                return;
            }
            *(f32 *)q = *(f32 *)(st + 0x18);
            f = *(f32 *)(st + 0x1C);
            if (f != -1.0f) {
                f = f * 0.017453292f;
            }
            *(f32 *)(q + 0xC) = f;
            *(f32 *)(q + 4) = *(f32 *)(st + 0x20);
            *(f32 *)(q + 8) = *(f32 *)(st + 0x24);
            if (st[0x45] == 0) {
                *(f32 *)(q + 0x14) = *(f32 *)(st + 0x28);
            } else {
                *(f32 *)(q + 0x14) = -1.0f;
            }
            f = *(f32 *)(st + 0x2C);
            if (f != -1.0f) {
                f = f * 0.017453292f;
            }
            *(f32 *)(q + 0x10) = f;
            *(u16 *)(q + 0x1A) = st[0x30];
            q[0x1E] = st[0x31];
            q[0x1F] = st[0x32];
            q[0x18] = st[0x46];
            if (*(s32 *)(st + 0x40) != -1) {
                *(s32 *)(q + 0x34) = *(s32 *)(st + 0x40);
            }
            if (*(s32 *)(st + 0x34) == -1) {
                goto tail;
            }
            if (st[0x49] != 0) {
                *(u128_00312BD8 *)(q + 0x20) = *(u128_00312BD8 *)((u8 *)((*(s32 *)(st + 0x34) << 7) + (s32)D_L05_001DFC80));
                goto tail;
            }
            vec_sub_ba(&loc10, (u8 *)((*(s32 *)(st + 0x34) << 7) + (s32)D_L05_001DFC80) + 0x30, D_001A4C60);
            *(u128_00312BD8 *)&loc0 = *(u128_00312BD8 *)&loc10;
            *(u128_00312BD8 *)(q + 0x20) = *(u128_00312BD8 *)&loc0;
            goto tail;
        }
        if (near != 0 && *(s32 *)(st + 0x3C) == 0 && *(s32 *)(st + 0x38) != -1) {
            u8 *node = D_L05_0021ED80[*(s32 *)(st + 0x38)];
            u8 *np;
            *(u128_00312BD8 *)&loc0 = *(u128_00312BD8 *)D_001A4C60;
            loc0.z = loc0.z + 1.25f;
            np = node + 0x10;
            loc10.z = func_0038D160(loc0.x - *(f32 *)(node + 0x10), loc0.y - *(f32 *)(node + 0x14));
            loc10.y = -func_0038D160(func_0038CF38(np, &loc0), loc0.z - *(f32 *)(node + 0x18));
            loc10.x = 0.0f;
            func_L01_003EB438(0, D_L05_001E2680, D_L05_001E2680 + 0x10, 3, 100, 0);
            func_L01_003EB350(0, np);
            func_L01_003EB3C0(0, &loc10);
            *(s32 *)(st + 0x3C) = 1;
            goto tail;
        }
        if (near != 0) {
            if (*(s32 *)(st + 0x3C) == 0) {
                goto l41c;
            }
            if (*(s32 *)(st + 0x3C) == 1) {
                if (func_L05_003E6220(0) & 1) {
                    *(s32 *)(st + 0x3C) = 2;
                    func_L05_003E63C0(0, 1, 0);
                }
            }
            {
                u8 *node = D_L05_0021ED80[*(s32 *)(st + 0x38)];
                u8 *np;
                *(u128_00312BD8 *)&loc0 = *(u128_00312BD8 *)D_001A4C60;
                loc0.z = loc0.z + 1.25f;
                np = node + 0x10;
                loc10.z = func_0038D160(loc0.x - *(f32 *)(node + 0x10), loc0.y - *(f32 *)(node + 0x14));
                loc10.y = -func_0038D160(func_0038CF38(np, &loc0), loc0.z - *(f32 *)(node + 0x18));
                loc10.x = 0.0f;
                func_L01_003EB350(0, np);
                func_L01_003EB3C0(0, &loc10);
            }
            goto tail;
        }
    l404:
        if (*(s32 *)(st + 0x3C) != 0) {
            func_L01_003EB5E0(0, 1);
            *(s32 *)(st + 0x3C) = 0;
            goto tail;
        }
    l41c:
        if (p0 == 0) {
            return;
        }
        if (*(s32 *)(st + 0x34) != -1) {
            if (st[0x49] != 0) {
                *(u128_00312BD8 *)(p0 + 0x20) = *(u128_00312BD8 *)((u8 *)((*(s32 *)(st + 0x34) << 7) + (s32)D_L05_001DFC80));
            } else {
                vec_sub_ba(&loc10, (u8 *)((*(s32 *)(st + 0x34) << 7) + (s32)D_L05_001DFC80_00312BD8) + 0x30, D_001A4C60);
                *(u128_00312BD8 *)&loc0 = *(u128_00312BD8 *)&loc10;
                *(u128_00312BD8 *)(p0 + 0x20) = *(u128_00312BD8 *)&loc0;
            }
        }
    tail:
        pt = *(u8 **)(st + 0x14);
        if (pt != 0) {
            if (st[0x47] == 0) {
                if (*(s32 *)(st + 0x34) != -1) {
                    *(u128_00312BD8 *)&loc0 = *(u128_00312BD8 *)((u8 *)((*(s32 *)(st + 0x34) << 7) + (s32)D_L05_001DFC80) + 0x30);
                    loc0.w = 1.0f;
                    if (func_0038DC20(&loc0, 255.0f) != -1) {
                        st[0x47] = 1;
                        if (st[0x45] != 0) {
                            *(f32 *)(*(u8 **)(st + 0x14) + 0x14) = *(f32 *)(st + 0x28);
                        }
                        if (st[0x44] != 0) {
                            (*(u8 **)(st + 0x14))[0x1F] = 0;
                            (*(u8 **)(st + 0x14))[0x1E] = 0;
                        }
                        if (st[0x48] != 0) {
                            (*(u8 **)(st + 0x14))[0x18] = 1;
                        }
                    }
                }
            }
            *(f32 *)(pt + 0x10) = *(f32 *)(st + 0x2C) * 0.017453292f;
        }
    } else {
        *(s32 *)(st + 0x14) = 0;
        *(s32 *)(st + 0x3C) = 0;
        st[0x47] = 0;
        o[0x20] = 1;
        o[0x30] = 0xFF;
    }
}
/* localdecomp:end func_L05_00312BD8 */
