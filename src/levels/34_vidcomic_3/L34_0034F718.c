#include "common.h"

/* localdecomp:start func_L34_0034F718 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_0034F718;

extern u8 D_001A4BE0[];
extern f32 D_001A4C60[];
__asm__(".extern D_001A4C60, 16");
extern u8 D_001D66B0;
extern u8 *D_L34_0021F218[];
extern u8 *D_L34_0021F228[];
extern u8 *D_L34_0021F2EC[];
extern u8 *D_L34_0021F384[];
extern f32 D_L34_001DD724;
extern s32 D_L34_001DD728;
extern f32 D_L34_001DD72C;
extern s32 D_L34_001DD730;
extern f32 D_L34_001DD734;
extern f32 D_L34_001DD738;
extern f32 D_L34_001DD73C;
extern f32 D_L34_001DD740;
extern f32 D_L34_001DD744;
extern f32 D_L34_001DD748;
extern f32 D_L34_001DD74C;
__asm__(".extern D_L34_001DD724, 4");
__asm__(".extern D_L34_001DD728, 4");
__asm__(".extern D_L34_001DD72C, 4");
__asm__(".extern D_L34_001DD730, 4");
__asm__(".extern D_L34_001DD734, 4");
__asm__(".extern D_L34_001DD738, 4");
__asm__(".extern D_L34_001DD73C, 4");
__asm__(".extern D_L34_001DD740, 4");
__asm__(".extern D_L34_001DD744, 4");
__asm__(".extern D_L34_001DD748, 4");
__asm__(".extern D_L34_001DD74C, 4");

extern f32 func_0038CF38(void *, void *);
extern void func_L34_00350360(u8 *);
extern void func_0038D308(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L34_003508A8(u8 *);
extern s32 func_0038CAD0(void *);
extern void func_L01_004450F0(u8 *, s32, s32);
extern s32 func_L01_004561B8(void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_L34_00350710(u8 *);
extern s32 func_L34_003502C8(u8 *);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L03_004495A8(void *, s32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern void func_L01_0045A748(void *, void *);
extern s32 func_L30_0034D8D8(void *, f32);
extern void func_003A52A0(s32, s32, void *);
extern void func_003C2F58(void *, s32, void *);
extern s32 func_0038DBD8(s32, s32, f32);
extern u8 *func_L01_00475C60(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_L01_0044E1B8(void *, f32);
extern void func_L34_00350768(u8 *);
extern s32 func_L01_00454370(void *, void *);
extern void func_003C2880(void *);
extern f32 fabsf(f32);

void func_L34_0034F718(u8 *a0) {
    u8 *p;
    u8 *g;
    f32 d;
    f32 t;
    u8 a;
    s32 c;
    s32 c2;
    s32 i;
    u8 *e;
    V4_0034F718 tmp;
    V4_0034F718 v;
    V4_0034F718 w;
    s32 s;

    p = *(u8 **)(a0 + 0x68);
    d = func_0038CF38(a0 + 0x10, D_001A4C60);
    func_L34_00350360(a0);
    func_0038D308(a0 + 0xC0, a0 + 0xF0);
    func_0038CF68(a0 + 0xD0, a0 + 0xD0, D_L34_001DD72C);
    switch (*(u8 *)(a0 + 0x20)) {
    case 0:
        func_L34_003508A8(a0);
        break;
    case 1:
        if (*(s32 *)(p + 0x270) != 0 && func_0038CAD0(p + 0x274)) {
            *(u16 *)(a0 + 0x34) &= ~0x41;
            *(s32 *)(a0 + 0x98) = *(s32 *)(*(u8 **)(a0 + 0x24) + 0x10);
            func_L01_004450F0(a0, 2, -1);
        }
        break;
    case 2:
        if (*(s32 *)(p + 0x260) != -1) {
            func_L01_004450F0(a0, 3, -1);
            return;
        }
        if (func_L01_004561B8(a0)) {
            *(s32 *)(p + 0x250) = D_L34_001DD728;
            if (*(s32 *)(p + 0x254) != 0) {
                if (*(u8 *)(a0 + 0x43) != 2) {
                    func_003C3A10(a0, 2, 0, 9);
                }
            } else {
                if (*(u8 *)(a0 + 0x43) != 0) {
                    func_003C3A10(a0, 0, 0, 9);
                }
            }
        }
        func_L34_00350710(a0);
        if (func_L34_003502C8(a0)) {
            func_L01_004450F0(a0, 5, -1);
        }
        break;
    case 3:
        func_L01_0045BD78(a0, D_L34_001DD748 * 0.00040000002f, D_L34_001DD740 * 0.020000001f,
                          D_L34_001DD738 * 0.017453292f * 0.00040000002f,
                          D_L34_001DD73C * 0.017453292f * 0.020000001f);
        func_L03_004495A8(a0, *(s32 *)(p + 0x260));
        if (*(u8 *)(a0 + 0x43) != 0xC) {
            func_003C3A10(a0, 0xC, 0, 7);
        }
        *(f32 *)(a0 + 0x48) = 0.92f;
        if (func_L34_003502C8(a0)) {
            func_L01_004450F0(a0, 5, -1);
        }
        break;
    case 10:
        if (*(u8 *)(a0 + 0x43) != 0xE) {
            func_003C3A10(a0, 0xE, 2, 6);
        }
        if (*(u8 *)(a0 + 0x60) & 2) {
            func_L01_004450F0(a0, 2, -1);
        }
        break;
    case 5:
        if (*(f32 *)(p + 0x268) + 1.5f < d) {
            func_L01_004450F0(a0, 4, -1);
            break;
        }
        if (*(s32 *)(p + 0x27C) != 0) {
            u8 *g = D_001A4BE0;
            if (func_0038DBA0(*(f32 *)(a0 + 0xF8),
                              func_0038D160(*(f32 *)(g + 0x80) - *(f32 *)(a0 + 0x10),
                                            *(f32 *)(g + 0x84) - *(f32 *)(a0 + 0x14))) < 0.17453292f) {
                if (*(u8 *)(a0 + 0x43) != 0xF) {
                    func_003C3A10(a0, 0xF, 8, 9);
                }
                func_L01_004450F0(a0, 9, -1);
                *(s32 *)(p + 0x27C) = 0;
                break;
            }
        }
        *(s32 *)(p + 0x254) = 1;
        if (*(u8 *)(a0 + 0x43) != 9) {
            func_003C3A10(a0, 9, 0, 7);
        }
        {
            s32 prev = *(s32 *)(p + 0x278);
            *(s32 *)(p + 0x278) = D_L34_001DD730;
            *(s32 *)(p + 0x250) = prev;
        }
        func_L01_004450F0(a0, 6, -1);
        break;
    case 4:
        t = D_L34_001DD744;
        if (*(f32 *)(p + 0x280) != 0.0f) {
            t = *(f32 *)(p + 0x280);
        }
        func_L01_0045BD78(a0, D_L34_001DD748 * 0.00040000002f, t * 0.020000001f,
                          D_L34_001DD738 * 0.017453292f * 0.00040000002f,
                          D_L34_001DD73C * 0.017453292f * 0.020000001f);
        func_L01_0045A748(a0, D_001A4C60);
        if (d < *(f32 *)(p + 0x268)) {
            func_L01_004450F0(a0, 5, -1);
        }
        if (*(u8 *)(a0 + 0x43) != 0xD) {
            func_003C3A10(a0, 0xD, 0, 6);
        }
        break;
    case 6:
        func_L34_00350710(a0);
        if (func_L01_004561B8(a0) && func_L30_0034D8D8(a0 + 0x10, D_L34_001DD74C)) {
            func_003A52A0(6, 0, a0);
        }
        func_003C2F58(a0, 0, &tmp);
        v = tmp;
        v.x += -*(f32 *)(a0 + 0xC0) * 0.6f;
        v.y -= 0.24f;
        v.z += 0.15f;
        a = 0x7F - *(s32 *)(p + 0x250) * 4;
        c = func_0038DBD8(0x95227E, 0xFF45DA, (f32)a / 127.0f) | (a << 24);
        e = func_L01_00475C60(&v, &D_001D66B0, 2, 1, c, c, 315000.0f, 315000.0f, 0.0f, 0);
        if (e != 0) {
            e[2] = *D_L34_0021F2EC[0];
            e[3] = func_00382468(2) ? 0x44 : 0x48;
        }
        v = tmp;
        v.x += *(f32 *)(a0 + 0xC0) * 0.2f;
        func_0038CE20(&w, a0 + 0xC0, 0.060000002f);
        e = func_L01_00475C60(&v, &w, 0xE, 1, 0x7F00B4FF, 0xB4FF, 147000.0f, 42000.0f, -5.0f, 0);
        if (e != 0) {
            e[2] = *D_L34_0021F228[0];
            e[3] = func_00382468(2) ? 0x44 : 0x48;
        }
        e = func_L01_00475C60(&v, &w, 7, 1, 0x50007EFF, 0x7EFF, 63000.004f, 21000.0f, 0.0f, 0);
        if (e != 0) {
            e[2] = *D_L34_0021F384[0];
            e[3] = 0x48;
        }
        for (i = 0; i < 2; i++) {
            c = func_00382468(4) ? 0x504A5053 : 0x40111111;
            c2 = c & 0xFFFFFF;
            func_0038CE20(&w, a0 + 0xC0, func_003824E0(0.6f, 3.0f) * 0.020000001f);
            s = func_00382498(0x19, 0x23);
            e = func_L01_00475C60(&v, &w, s, 1, c, c2, 105000.0f, 262500.0f, func_003824E0(-5.0f, -10.0f), 0);
            if (e != 0) {
                e[2] = *D_L34_0021F218[4];
                e[3] = func_00382468(2) ? 0x44 : 0x48;
            }
        }
        if (func_0038CAD0(p + 0x250)) {
            u8 *g = D_001A4BE0;
            if (func_0038DBA0(*(f32 *)(a0 + 0xF8),
                              func_0038D160(*(f32 *)(g + 0x80) - *(f32 *)(a0 + 0x10),
                                            *(f32 *)(g + 0x84) - *(f32 *)(a0 + 0x14))) < 0.17453292f) {
                if (*(s32 *)(p + 0x254) != 0) {
                    if (*(u8 *)(a0 + 0x43) != 0xA) {
                        func_003C3A10(a0, 0xA, 1, 3);
                    }
                } else {
                    if (*(u8 *)(a0 + 0x43) != 6) {
                        func_003C3A10(a0, 6, 1, 3);
                    }
                }
                func_L01_004450F0(a0, 7, -1);
            }
        }
        break;
    case 7:
        func_L34_00350710(a0);
        *(f32 *)(a0 + 0x48) = 0.57f;
        if (func_L01_0044E1B8(a0, *(s32 *)(p + 0x254) != 0 ? D_L34_001DD724 : D_L34_001DD734)) {
            if (func_L30_0034D8D8(a0 + 0x10, D_L34_001DD74C)) {
                func_L34_00350768(a0);
            }
            g = D_001A4BE0;
            if (func_0038DBA0(*(f32 *)(a0 + 0xF8),
                              func_0038D160(*(f32 *)(g + 0x80) - *(f32 *)(a0 + 0x10),
                                            *(f32 *)(g + 0x84) - *(f32 *)(a0 + 0x14))) > 1.5707964f
                || fabsf(*(f32 *)(g + 0x88) - *(f32 *)(a0 + 0x18)) > 2.0f) {
                *(s32 *)(p + 0x250) = 0x2A;
                if (*(s32 *)(p + 0x254) != 0) {
                    if (*(u8 *)(a0 + 0x43) != 9) {
                        func_003C3A10(a0, 9, 0, 7);
                    }
                } else {
                    if (*(u8 *)(a0 + 0x43) != 5) {
                        func_003C3A10(a0, 5, 0, 7);
                    }
                }
                func_L01_004450F0(a0, 6, -1);
                break;
            }
        }
        if (*(u8 *)(a0 + 0x60) & 2) {
            if (*(u8 *)(a0 + 0x43) != 2) {
                func_003C3A10(a0, 2, 0, 9);
            }
            func_L01_004450F0(a0, 2, -1);
        }
        break;
    case 9:
        *(f32 *)(a0 + 0x48) = 0.8f;
        if (func_L01_0044E1B8(a0, 28.0f) || (*(u8 *)(a0 + 0x60) & 2)) {
            if (*(u8 *)(a0 + 0x43) != 5) {
                func_003C3A10(a0, 5, 0, 7);
            }
            func_L01_004450F0(a0, 6, -1);
        }
        break;
    case 8:
        func_L01_00454370(a0, p + 0x190);
        if (func_L01_0044E1B8(a0, 13.0f)) {
            if (*(s32 *)(p + 0x254) != 0) {
                if (*(u8 *)(a0 + 0x43) != 9) {
                    func_003C3A10(a0, 9, 0, 7);
                }
            } else {
                if (*(u8 *)(a0 + 0x43) != 5) {
                    func_003C3A10(a0, 5, 0, 7);
                }
            }
            *(s32 *)(p + 0x250) = 0xC;
            func_L01_004450F0(a0, 6, -1);
        }
        break;
    case 0x42:
        if (func_L01_004561B8(a0)) {
            func_003C2880(a0);
            return;
        }
        break;
    }
    {
        u8 *h = D_001A4BE0;
        if (*(s32 *)(h + 0x25C4) == 0x9E && *(s32 *)(h + 0x1B8) < 0x1F
            && func_0038CF38(a0 + 0x10, h + 0x80) < 10.0f) {
            u8 st = *(u8 *)(a0 + 0x20);
            if (st != 0x42 && st != 1 && st != 10 && !func_00382468(9)) {
                func_L01_004450F0(a0, 10, -1);
            }
        }
    }
}
/* localdecomp:end func_L34_0034F718 */

/* localdecomp:start func_L34_003502C8 */
extern u8 D_001A4BE0[];
extern void func_L01_003A6BB0(void *);
extern s32 func_0038CAD0(void *);
extern f32 fabsf(f32);

s32 func_L34_003502C8(u8 *a0) {
    u8 *p;
    u8 *g;

    p = *(u8 **)(a0 + 0x68);
    if (*(s32 *)(p + 0x270) != 0
        || ((g = D_001A4BE0),
            fabsf(*(f32 *)(g + 0x338) - *(f32 *)(a0 + 0x18)) < 1.0f
            && fabsf(*(f32 *)(g + 0x80) - *(f32 *)(a0 + 0x10)) < *(f32 *)(p + 0x264))) {
        func_L01_003A6BB0(a0);
        return func_0038CAD0(p + 0x274) != 0;
    }
    return 0;
}
/* localdecomp:end func_L34_003502C8 */
