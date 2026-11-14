/* NTSC-U draft (2026-11-14, Claude worker): C of func_L01_0044F5E8, the NTSC-U twin of func_L01_00452860, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/shared/L01_00451A68.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as").
 */
#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L01_00452860 (src/levels/shared/L01_00451A68.c) */
/* localdecomp:start func_L01_0044F5E8 */
typedef union { u8 b[0x1B0]; u8 *ptr[0x6C]; } T_0044F5E8;
extern T_0044F5E8 D_L01_00221118;
extern s32 D_L01_001D66B0[2];
extern u8 *func_L01_00445EE8(void *);
extern s32 func_00388398(void *);
extern f32 func_0037E250(f32, f32);
extern void func_L01_00443610(void *, void *, s32, f32);
extern void func_L01_00443840(void *, void *);
extern s32 func_003BD668(void *, s32);
extern s32 func_0037E1D8(s32);
extern void func_0037E2F0(void *, f32, f32);
extern s32 func_0037E208(s32, s32);
extern u8 *func_L01_00460318(void *, void *, u32, u32, s32, s32, s32, s32);
extern s32 func_L01_00444800(void *, s32, void *, s32, f32);
extern void func_L01_004C41E8(void *, void *);
extern void func_003886C0(void *, void *, void *, f32);
extern void func_003886E8(void *, void *, f32);

s32 func_L01_0044F5E8(u8 *self, u8 *e, u8 *o) {
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;
    vu0_v4 arr[10];
    u8 *p;
    u8 *sc;
    u8 *r;
    s32 n;
    s32 i;
    s32 j;
    s32 k;
    f32 f;

    if (e == 0) {
        return 0;
    }
    if (self == 0) {
        return 0;
    }
    p = func_L01_00445EE8(self);
    if (p == 0 && o == 0) {
        return 0;
    }
    if (o != 0) {
        p = o;
    }
    if (e[0x2F] == 0) {
        return 1;
    }
    *(u16 *)(p + 0x1E) = *(u16 *)(p + 0x1E) + 1;
    if (func_00388398(e + 0x38) != 0) {
        *(u16 *)(p + 0x1E) = 0;
        e[0x35] = 1;
        e[0x2F] = 0;
    }
    if (*(u8 **)(p + 0x10) != 0 && *(s16 *)(*(u8 **)(p + 0x10) + 0xAA) != 0 && *(s16 *)(p + 0x16) == 0) {
        *(s16 *)(p + 0x16) = 1;
    }
    if (*(s16 *)(p + 0x16) > 0 || (*(u8 **)(p + 0x10) != 0 && *(s16 *)(*(u8 **)(p + 0x10) + 0xAA) == 0)) {
        *(u16 *)(p + 0x16) = *(u16 *)(p + 0x16) + 1;
    }
    if (0.0f < *(f32 *)e) {
        if (*(u8 **)(p + 0x10) != 0 && *(s16 *)(*(u8 **)(p + 0x10) + 0xAA) == 0) {
            f = (f32)*(s16 *)(p + 0x16);
            if (func_0037E250(90.0f, 150.0f) < f) {
                func_L01_00443610(&a, self, 0x10000, 1500.0f);
                func_L01_00443840(self, &a);
            }
        }
        if (*(f32 *)e <= 1.0f) {
            func_L01_00443610(&a, self, 0x10000, 1500.0f);
            func_L01_00443840(self, &a);
        }
        if (*(s16 *)(p + 0x1E) >= 0x12D) {
            *(f32 *)e = *(f32 *)e - (f32)*(s16 *)(e + 4) * 0.002f;
        }
    } else {
        func_L01_00443610(&a, self, 0x10000, 1500.0f);
        func_L01_00443840(self, &a);
    }
    n = func_003BD668(self, 0);
    if (n != 0) {
        sc = (u8 *)0x70000000;
        for (i = 0; i < n; i++, sc += 0x20) {
            if (func_0037E1D8(2) == 0) {
                continue;
            }
            if (*(f32 *)(sc + 0x1C) == 0.0f) {
                a = *(vu0_v4 *)sc;
                a.w = 1.0f;
                func_0037E2F0(&b, 0.0f, *(f32 *)(sc + 0xC));
                vec_add_ab(&a, &a, &b);
                r = func_L01_00460318(&a, D_L01_001D66B0, 0x3005A182, 0x5A182, func_0037E208(10, 0x12), 0x4B, 0x78, 1);
                if (r != 0) {
                    r[3] = 0x44;
                    k = func_0037E1D8(4);
                    if (k == 0) {
                        r[2] = *D_L01_00221118.ptr[0x5C / 4];
                    } else if (k == 1) {
                        r[2] = *D_L01_00221118.ptr[0x1A4 / 4];
                    } else {
                        r[2] = *D_L01_00221118.ptr[0x88 / 4];
                    }
                }
            } else {
                a = *(vu0_v4 *)sc;
                b = *(vu0_v4 *)(sc + 0x10);
                a.w = 1.0f;
                b.w = 1.0f;
                func_003886C0(&c, &a, &b, func_0037E250(0.0f, 1.0f));
                c.x = c.x + func_0037E250(-*(f32 *)(sc + 0xC) * 0.4f, *(f32 *)(sc + 0xC) * 0.4f);
                c.y = c.y + func_0037E250(-*(f32 *)(sc + 0xC) * 0.4f, *(f32 *)(sc + 0xC) * 0.4f);
                c.z = c.z + func_0037E250(-*(f32 *)(sc + 0xC) * 0.4f, *(f32 *)(sc + 0xC) * 0.4f);
                r = func_L01_00460318(&c, D_L01_001D66B0, 0x3005A182, 0x5A182, func_0037E208(10, 0x12), 0x4B, 0x78, 1);
                if (r != 0) {
                    r[3] = 0x44;
                    k = func_0037E1D8(4);
                    if (k == 0) {
                        r[2] = *D_L01_00221118.ptr[0x5C / 4];
                    } else if (k == 1) {
                        r[2] = *D_L01_00221118.ptr[0x1A4 / 4];
                    } else {
                        r[2] = *D_L01_00221118.ptr[0x88 / 4];
                    }
                }
            }
        }
        return 1;
    }
    n = func_L01_00444800(self, 10, arr, 0xFFFF, 7.0f);
    if (n != 0) {
        for (j = 0; j < n; j++) {
            func_L01_004C41E8(self + 0x10, &a);
            func_003886E8(&a, &a, func_0037E250(-0.05f, 0.05f));
            r = func_L01_00460318(&arr[j], &a, 0x3005A182, 0x5A182, func_0037E208(10, 0x19), 0x2D, 0x5A, 1);
            if (r != 0) {
                r[3] = 0x44;
                k = func_0037E1D8(4);
                if (k == 0) {
                    r[2] = *D_L01_00221118.ptr[0x5C / 4];
                } else if (k == 1) {
                    r[2] = *D_L01_00221118.ptr[0x1A4 / 4];
                } else {
                    r[2] = *D_L01_00221118.ptr[0x88 / 4];
                }
            }
        }
    }
    return 1;
}
/* localdecomp:end func_L01_0044F5E8 */
