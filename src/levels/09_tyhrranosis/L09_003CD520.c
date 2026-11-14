#include "common.h"

typedef struct {
    u8 pad[4];
    s32 (*f4)(void *);
    s32 (*f8)(void *);
} V_003CDA30;

typedef struct {
    s32 (*f0)(void *);
    u8 pad[4];
    s32 (*f8)(void *);
} V_003CD520;

/* localdecomp:start func_L09_003CD520 */
extern u16 *D_L09_0021CDA0[];
extern u8 *D_L09_001E009C;
__asm__(".extern D_L09_001E009C, 16");
extern u8 *D_L09_001E009C_sda;
extern s32 D_L09_001E00D8_sda;
extern u8 D_001BBC40[][16];
extern s32 func_L01_004561B8(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern V_003CD520 *func_L01_0043B568(s32, s32, s32);
extern s32 func_0038CAD0(void *);
extern s32 func_00382380(void *, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern f32 func_003C3BE8(f32, f32, f32);

void func_L09_003CD520(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    u8 ok1;
    u8 ok2;
    u16 *p;
    u8 *e;
    V_003CD520 *v;
    s32 t;

    switch (a0[0x20]) {
    case 0: {
        s32 t0;
        s32 lv;
        u8 *q;
        *(s16 *)(a0 + 0x32) = 200;
        a0[0x30] = 200;
        t0 = *(s32 *)(s + 4);
        if (t0 != -1) {
            q = D_L09_001E009C_sda + (t0 << 8);
            *(s16 *)(q + 0x32) = 200;
            q[0x30] = 200;
        }
        lv = *(s32 *)0x1D545C;
        *(f32 *)(s + 0xC) = 0.01f;
        if ((D_001BBC40[lv][a0[0xB0]] & 0x80) && *(s32 *)(s + 0x1C) != 0) {
            func_L01_004450F0(a0, 3, -1);
        } else {
            func_L01_004450F0(a0, 1, -1);
        }
        break;
    }
    case 1:
        if (func_L01_004561B8(a0) != 0) {
            *(f32 *)(a0 + 0xF0) = -1.5707964f;
        }
        break;
    case 2:
        if (func_L01_004561B8(a0) != 0) {
            *(s32 *)(s + 8) = 100;
            func_003A52A0(0, 0, a0);
        }
        if (func_0038CAD0(s + 8) != 0) {
            func_L01_004450F0(a0, 3, -1);
        } else {
            *(f32 *)(a0 + 0xF0) = func_003C3BE8(0.0f, -1.5707964f, (f32)*(s32 *)(s + 8) * *(f32 *)(s + 0xC));
        }
        break;
    case 3:
        ok1 = 1;
        ok2 = 1;
        if (func_L01_004561B8(a0) != 0) {
            *(s32 *)(a0 + 0xF0) = 0;
            if (a0[0xBC] == 1) {
                V_003CD520 *v1;
                u8 *e1;
                for (p = D_L09_0021CDA0[*(s32 *)(s + 0x10)];
                     (*(s32 *)(s + 0x10) & 0xFF) != 0xFF && *(s32 *)(s + 0x10) <= D_L09_001E00D8_sda && p != 0 &&
                     ((s16)p[-1] >= 0 || p == D_L09_0021CDA0[*(s32 *)(s + 0x10)]);
                     p++) {
                    e1 = D_L09_001E009C + ((*p & 0x7FFF) << 8);
                    if (e1 == 0) {
                        break;
                    }
                    v1 = func_L01_0043B568(*(s16 *)(e1 + 0xAA), 5, 0xC);
                    if (v1 != 0) {
                        if (v1->f8(e1) != 0) {
                            v1->f0(e1);
                        }
                    }
                }
            }
        }
        if (a0[0xBC] == 1) {
            for (p = D_L09_0021CDA0[*(s32 *)(s + 0x10)];
                 (*(s32 *)(s + 0x10) & 0xFF) != 0xFF && *(s32 *)(s + 0x10) <= D_L09_001E00D8_sda && p != 0 &&
                 ((s16)p[-1] >= 0 || p == D_L09_0021CDA0[*(s32 *)(s + 0x10)]);
                 p++) {
                e = D_L09_001E009C + ((*p & 0x7FFF) << 8);
                if (e == 0) {
                    break;
                }
                v = func_L01_0043B568(*(s16 *)(e + 0xAA), 5, 0xC);
                if (v != 0) {
                    if (v->f8(e) == 0) {
                        if (func_00382380(e + 0x10, *(s32 *)(s + 0x14), 0) != 0) {
                            ok1 = 0;
                        }
                    }
                    if (ok1 == 0 ||
                        (*(s16 *)(e + 0xAA) != 0x18AD && v->f8(e) == 0 &&
                         func_00382380(e + 0x10, *(s32 *)(s + 0x18), 0) != 0)) {
                        ok2 = 0;
                    }
                }
            }
        } else {
            ok1 = 0;
            ok2 = 0;
        }
        {
            s32 t2;
            u8 *e2;
            t2 = *(s32 *)(s + 4);
            if (t2 != -1) {
                e2 = D_L09_001E009C_sda + (t2 << 8);
                if (*(s16 *)(e2 + 0xAA) == 0x1A77) {
                    *(s32 *)(*(u8 **)(e2 + 0x68) + 0xC) = (u8)(ok1 ^ 1);
                }
            }
        }
        if (ok2 != 0) {
            func_L01_004450F0(a0, 4, -1);
        }
        break;
    case 4:
        if (func_L01_004561B8(a0) != 0) {
            s32 t3;
            u8 *e3;
            *(s32 *)(s + 8) = 100;
            t3 = *(s32 *)(s + 4);
            if (t3 != -1) {
                e3 = D_L09_001E009C + (t3 << 8);
                if (*(s16 *)(e3 + 0xAA) == 0x1A77) {
                    *(s32 *)(*(u8 **)(e3 + 0x68) + 0xC) = 0;
                }
            }
        }
        if (func_0038CAD0(s + 8) != 0) {
            func_L01_004450F0(a0, 1, -1);
        } else {
            *(f32 *)(a0 + 0xF0) = func_003C3BE8(-1.5707964f, 0.0f, (f32)*(s32 *)(s + 8) * *(f32 *)(s + 0xC));
        }
        break;
    }
}
/* localdecomp:end func_L09_003CD520 */
