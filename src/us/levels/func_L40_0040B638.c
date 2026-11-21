#include "common.h"

/* NTSC-U counterpart of func_L40_0040BCF0 (src/levels/shared/L40_0040A4D0.c) */
#include "vu0.h"
extern f32 func_00388800(void *a, void *b);
extern f32 func_00388A28(f32 x, f32 y);
typedef struct {
    u8 pad[0x88];
    s32 f88[1];
} Team_0040BCF0;
extern s32 D_L40_002473C4;
extern u8 *D_L40_003575EC[];
extern void func_003BD360(void *);
extern void func_003BDA38(u8*m, s32 a1, void*pos);
extern void func_L40_0040B638(u8 *m);
extern void func_003BDA38(u8 *m, s32 a1, void *pos);
extern s32 *D_L40_0028FF00[];
extern s32 func_L39_005B24C8(s32 lo, s32 hi);
extern void func_L40_0040C828(u8 *a0, s32 a1, s32 a2, s32 a3);
#include "vu0.h"
extern s32 *D_L40_0028FF00[];
extern u8 *D_L40_002485EC;
extern void func_L40_0040C6B0(u8 *m);
extern void func_L40_0040C828(u8 *a0, s32 a1, s32 a2, s32 a3);
extern void func_L40_0053CE30();
extern void func_L39_00669B68(s32 uid);
extern void func_L01_00441FB8(u8 *m, s32 state, s32 a2);
extern u8 *func_L01_0032FE90_0040B638(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern u8 *func_L39_00619838(u32);
extern s32 func_L40_0053C768(u8 *m);
extern void func_00388830(void *d, void *s, f32 k);

/* localdecomp:start func_L40_0040B638 */
__asm__(".extern D_L40_002473C4, 4");
__asm__(".extern D_L40_002473C8, 4");
__asm__(".extern D_L40_002473DC, 4");
__asm__(".extern D_L40_002473E0, 4");
__asm__(".extern D_L40_002473E4, 4");
__asm__(".extern D_L40_002473F4, 4");
__asm__(".extern D_L40_002473F8, 4");
__asm__(".extern D_L40_002473FC, 4");
__asm__(".extern D_L40_00247400, 4");
__asm__(".extern D_L40_00247404, 4");
__asm__(".extern D_L40_00247408, 4");
__asm__(".extern D_L40_0024740C, 4");
__asm__(".extern D_L40_00247410, 4");
__asm__(".extern D_L40_002485EC, 4");
extern s32 D_L40_002473C4;
extern s32 D_L40_002473C8;
extern f32 D_L40_002473DC;
extern f32 D_L40_002473E0;
extern s32 D_L40_002473E4;
extern s32 D_L40_002473F4;
extern s32 D_L40_002473F8;
extern s32 D_L40_002473FC;
extern s32 D_L40_00247400;
extern s32 D_L40_00247404;
extern s32 D_L40_00247408;
extern f32 D_L40_0024740C;
extern f32 D_L40_00247410;
extern u8 *D_L40_002485EC;

extern u8 D_L40_00242AE0[] __attribute__((section(".sdata")));

extern u32 D_001A5E58[];
extern void func_L40_0053CE30();
extern s32 func_L40_0053C768(u8 *m);
extern void func_003BD360(void *);
extern s32 func_L40_0040C020(u8 *m, s32 a1);
extern s32 func_L01_00452EC8(u8 *m);
extern void func_003BE4F0(u8 *, s32, s32, s32);
extern void func_L01_00441FB8(u8 *, s32, s32);
extern f32 func_L01_0040C040(void *, void *);
extern s32 func_L01_00457440(u8 *, void *);
extern f32 func_L01_004455F0(void *, f32, void *, f32, f32, f32, s32);
extern s32 func_L01_0044AF40(u8 *, f32);
extern u8 *func_0037E0B8(void *);
extern void func_00388830(void *, void *, f32);
extern void func_L39_00564BD8(u8 *, void *, void *, s32, s32, f32, f32, f32);
extern void func_L40_0040C898(void *);
extern void func_L40_0040C6B0(u8 *m);
extern u8 *func_L01_0032FE90_0040B638(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern u8 *func_L39_00619838(u32);
extern void func_L39_00669B68(s32);
extern void func_L40_0040A9A0(u8 *m);
extern s32 func_L40_0040B308(u8 *m);
extern void func_L40_0040B438(u8 *m, void *target, f32 yaw);
extern void func_L40_0040B548(u8 *m);

void func_L40_0040B638(u8 *m) {
    s32 *ctx;
    u8 *v;
    s32 uid;
    s32 st;
    s32 c;
    s32 sh;
    s16 s;
    u8 b;
    vu0_v4 B;
    vu0_v4 A;
    vu0_v4 D;
    vu0_v4 C;

    if (m == 0) {
        return;
    }
    ctx = *(s32 **)(m + 0x90);
    v = *(u8 **)(m + 0x68);
    uid = ctx[0];
    if ((u32)(*(u8 *)(m + 0x20) - 0x25) < 2) {
        func_L40_0053CE30();
        if (*(u8 **)(v + 0x270) != 0 && *(s16 *)(*(u8 **)(v + 0x270) + 0xAA) == 0x109E) {
            func_003BD360(*(u8 **)(v + 0x270));
        }
        *(s32 *)(v + 0x270) = 0;
        return;
    }
    if (func_L40_0040C020(m, uid) != 0) {
        return;
    }
    st = *(u8 *)(m + 0x20);
    if ((u8)st == 0xFD || (u8)st == 0xFE) {
        return;
    }
    if ((u8)st == 0x25) {
        return;
    }
    if ((u8)st == 0x26) {
        return;
    }
    if (*(s32 *)(v + 0x2B8) != -1) {
        s32 tv = ((Team_0040BCF0 *)D_L40_003575EC[0])->f88[*(s32 *)(v + 0x2B8)];
        *(s32 *)(v + 0x2F0) = tv;
        ctx[6] = tv;
    }
    c = *(s32 *)(v + 0x2F0);
    if ((u32)c >= 2) {
        c = D_L40_002473C4;
    }
    *(u8 *)(m + 0x7E) = (((*(u8 *)(m + 0x7E)) | 0x80) & 0x8F) | (c << 4);
    if (*(u8 **)(v + 0x270) != 0) {
        *(u8 *)(*(u8 **)(v + 0x270) + 0x7E) |= 0x80;
        *(u8 *)(*(u8 **)(v + 0x270) + 0x7E) &= 0x8F;
        *(u8 *)(*(u8 **)(v + 0x270) + 0x7E) |= c << 4;
    }
    if (*(s32 *)(m + 0x28) == 0 && m != D_L40_002485EC) {
        return;
    }
    if (func_L40_0053C768(m) != 0) {
        *(u8 *)(m + 0x30) = 0xFF;
        *(s16 *)(*(u8 **)(v + 0x270) + 0x32) = 0xFF;
        *(s16 *)(m + 0x32) = 0xFF;
    } else {
        *(u8 *)(m + 0x30) = 0x46;
        *(s16 *)(*(u8 **)(v + 0x270) + 0x32) = 0x3C;
        *(s16 *)(m + 0x32) = 0x3C;
    }
    if (*(u8 **)(v + 0x270) != 0) {
        *(s32 *)(*(u8 **)(v + 0x270) + 0x98) = 0;
    }
    switch (*(u8 *)(m + 0x20)) {
    case 2:
        if (func_L01_00452EC8(m) != 0) {
            func_003BE4F0(*(u8 **)(v + 0x270), 4, 0, 10);
        }
        if (*(s16 *)(v + 0x234) == 1) {
            if (*(s32 *)(v + 0x2C8) == -1) {
                u8 *p = v + 0x220;
                if (func_L01_0040C040(v + 0x240, p) < D_L40_002473E0 && func_L40_0040B308(m) == 0) {
                    func_L01_00457440(m, p);
                    func_L40_0040B548(m);
                    *(f32 *)(m + 0x48) = 1.0f;
                }
            }
            {
                u8 *t = *(u8 **)(v + 0x270) + 0xF8;
                func_L01_004455F0(t, func_00388A28(*(f32 *)(v + 0x220) - *(f32 *)(m + 0x10), *(f32 *)(v + 0x224) - *(f32 *)(m + 0x14)),
                                  v + 0x284, 0.0069813174f, 0.00058177643f, 0.41887906f, 0);
            }
            if (func_L01_0044AF40(*(u8 **)(v + 0x270), D_L40_002473DC) != 0) {
                func_003BDA38(*(u8 **)(v + 0x270), D_L40_002473C8, &A);
                B = *(vu0_v4 *)(v + 0x220);
                if (*(s32 *)(v + 0x230) != 0) {
                    u8 *r = func_0037E0B8(*(void **)(v + 0x230));
                    if (r != 0) {
                        func_00388830(&C, D_L40_00242AE0, *(f32 *)(r + 0x10));
                        vec_add_ab(&B, &B, &C);
                    }
                }
                vec_sub_ab(&D, &B, &A);
                func_00388830(&D, &D, 0.6666667f);
                {
                    s32 a7 = D_L40_002473F4;
                    s32 a8 = D_L40_00247400;
                    if (*(s32 *)(v + 0x2F0) == 0) {
                        a7 = D_L40_002473F8;
                        a8 = D_L40_00247404;
                    } else if (*(s32 *)(v + 0x2F0) == 1) {
                        a7 = D_L40_002473FC;
                        a8 = D_L40_00247408;
                    }
                    func_L39_00564BD8(m, &A, &D, a7, a8, *(f32 *)(v + 0x3D4), D_L40_0024740C, D_L40_00247410);
                }
            }
            if (*(s32 *)(v + 0x2C8) != -1) {
                u8 *path = (u8 *)D_L40_0028FF00[*(s32 *)(v + 0x2C8)];
                if (func_00388800(m + 0x10, path + (*(s32 *)(v + 0x290) * 16 + 0x10)) > 0.2f && func_L40_0040B308(m) == 0) {
                    if (*(u8 *)(m + 0x43) != 10) {
                        func_003BE4F0(m, 10, 0, 10);
                    }
                    func_L01_00457440(m, path + (*(s32 *)(v + 0x290) * 16 + 0x10));
                } else if (*(u8 *)(m + 0x43) != 4) {
                    func_003BE4F0(m, 4, 0, 10);
                }
            }
        } else {
            func_L40_0040C828(m, 0, 0, 10);
            qzero(v + 0x110);
        }
        if (*(u16 *)(m + 0x96) >= 0x3D || (*(u8 *)(m + 0x60) & 2) != 0) {
            func_L01_00441FB8(m, 3, -1);
        }
        break;
    case 3:
        {
            u8 *t = *(u8 **)(v + 0x270);
            if ((*(u8 *)(t + 0x60) & 2) != 0) {
                if (*(u8 *)(t + 0x43) == 4) {
                    if (*(s16 *)(v + 0x234) == 1) {
                        func_003BE4F0(t, 5, 0, 10);
                    } else {
                        func_003BE4F0(t, 0, 0, 10);
                    }
                } else if (*(u8 *)(t + 0x43) == 5) {
                    func_L01_00441FB8(m, 2, -1);
                }
            }
        }
        {
            u8 *t = *(u8 **)(v + 0x270) + 0xF8;
            func_L01_004455F0(t, func_00388A28(*(f32 *)(v + 0x220) - *(f32 *)(m + 0x10), *(f32 *)(v + 0x224) - *(f32 *)(m + 0x14)),
                              v + 0x284, 0.0069813174f, 0.00058177643f, 0.41887906f, 0);
        }
        if (D_L40_002473E4 < *(u16 *)(m + 0x96)) {
            func_L01_00441FB8(m, 2, -1);
        }
        if (*(s32 *)(v + 0x2C8) != -1) {
            u8 *path = (u8 *)D_L40_0028FF00[*(s32 *)(v + 0x2C8)];
            if (func_00388800(m + 0x10, path + (*(s32 *)(v + 0x290) * 16 + 0x10)) > 0.2f && func_L40_0040B308(m) == 0) {
                if (*(u8 *)(m + 0x43) != 10) {
                    func_003BE4F0(m, 10, 0, 10);
                }
                func_L01_00457440(m, path + (*(s32 *)(v + 0x290) * 16 + 0x10));
            } else {
                u8 *t = *(u8 **)(v + 0x270);
                if (*(u8 *)(m + 0x43) != *(u8 *)(t + 0x43)) {
                    func_003BE4F0(m, *(u8 *)(t + 0x43), 0, 10);
                }
            }
        } else {
            if (*(u8 *)(m + 0x43) != 9) {
                func_003BE4F0(m, 9, 0, 10);
            }
            if (*(s32 *)(v + 0x2EC) == 1) {
                s32 fl = *(s32 *)(v + 0xA8);
                *(s32 *)(v + 0xA8) = fl | 0x10;
                func_L40_0040B438(m, v + 0x310, *(f32 *)(v + 0x2E4));
                func_L40_0040B548(m);
                *(f32 *)(m + 0x48) = 1.0f;
                *(s32 *)(v + 0xA8) = fl;
            }
        }
        break;
    case 1:
        if (func_L01_00452EC8(m) != 0) {
            func_L40_0040C828(m, 0, 0, 0x14);
            func_003BDA38(m, 0, *(u8 **)(v + 0x270) + 0x10);
            *(f32 *)(*(u8 **)(v + 0x270) + 0xF0) = *(f32 *)(m + 0xF0);
            *(f32 *)(*(u8 **)(v + 0x270) + 0xF4) = *(f32 *)(m + 0xF4);
        }
        if (*(s32 *)(v + 0x2C8) != -1 && *(s32 *)(v + 0x340) != -1) {
            u8 *path = (u8 *)D_L40_0028FF00[*(s32 *)(v + 0x2C8)];
            if (func_00388800(m + 0x10, path + (*(s32 *)(v + 0x340) * 16 + 0x10)) > 0.8f && func_L40_0040B308(m) == 0) {
                if (*(u8 *)(m + 0x43) != 9) {
                    func_003BE4F0(m, 9, 0, 10);
                }
                func_L01_00457440(m, path + (*(s32 *)(v + 0x340) * 16 + 0x10));
                *(f32 *)(*(u8 **)(v + 0x270) + 0xF8) = *(f32 *)(m + 0xF8);
                break;
            }
            if ((*(u8 *)(m + 0x60) & 2) == 0) {
                if (*(u8 *)(m + 0x43) != 9) {
                    break;
                }
            }
        } else if ((*(u8 *)(m + 0x60) & 2) == 0) {
            break;
        }
        func_L40_0040C828(m, func_L39_005B24C8(0, 1), 0, 10);
        break;
    case 4:
        if (*(f32 *)(v + 0x30) <= 0.0f && func_L40_0053C768(m) != 0) {
            u8 *r;
            u8 *e;
            u32 w;
            func_L40_0040C6B0(m);
            func_L40_0053CE30(m);
            r = func_L01_0032FE90_0040B638(m + 0x10, 0, 5, 5, 5, 10, 10, 3, 1.0f, 0.0f, 0.0f, 2.0f,
                                  0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF,
                                  0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            if (r != 0) {
                *(u8 **)(r + 0xB8) = m;
            }
            w = *(u32 *)(v + 0x2AC);
            if ((w >> 28) == D_001A5E58[0]) {
                e = func_L39_00619838(w);
                if (e != 0) {
                    *(u8 *)(e + 0x1A11) = 0;
                }
            }
            return;
        }
        break;
    case 5:
        func_L40_0040A9A0(m);
        break;
    }
    func_L40_0040C898(m);
    if (*(f32 *)(m + 0x10) < 10.0f || *(f32 *)(m + 0x14) < 10.0f || *(f32 *)(m + 0x18) < 2.0f) {
        func_L39_00669B68(uid);
    }
    if (*(u8 **)(v + 0x270) != 0) {
        u8 *t = *(u8 **)(v + 0x270);
        *(s32 *)(t + 0x98) = *(s32 *)(*(u8 **)(t + 0x24) + 0x10);
    }
}
/* localdecomp:end func_L40_0040B638 */
