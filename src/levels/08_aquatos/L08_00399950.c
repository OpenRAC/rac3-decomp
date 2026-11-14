#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L08_00399950);

/* localdecomp:start func_L08_00399978 */
/* Ps2EeAs only uses $gp for these if it knows they are small before the use. */
__asm__(".extern D_L08_001E13B0, 4");
__asm__(".extern D_L08_001E13B4, 4");
__asm__(".extern D_L08_001E13B8, 4");
__asm__(".extern D_L08_001E13BC, 4");
__asm__(".extern D_L08_001DDFB0, 4");
__asm__(".extern D_L08_001DDFC0, 8");
__asm__(".extern D_L08_001DDFD0, 8");
__asm__(".extern D_L08_001DDFE0, 1");

extern s32 D_L08_001D6694;
extern s32 D_L08_001E13B0;
extern s32 D_L08_001E13B4;
extern s32 D_L08_001E13B8;
extern s32 D_L08_001E13BC;
extern f32 D_L08_001DDFB0;
extern s32 D_L08_001DDFC0[2];
extern s32 D_L08_001DDFD0[2];
extern u8 D_L08_001DDFE0;
extern u8 *D_L08_001DF21C;
extern u8 D_L08_001D9A20[] __attribute__((section(".sdata")));
extern u8 D_L08_001E1D40[];
extern u8 D_1A4BE0[];
extern u8 D_1A4C60[];
extern s32 D_142660[];

extern void func_L08_0039AC38(u8 *);
extern s32 func_L01_004BA800(void);
extern s32 func_L01_004561B8(u8 *);
extern s32 func_L01_00456208(u8 *);
extern void func_L01_00335F38(u8 *, s32);
extern s32 func_L01_00335EC0(u8 *, s32);
extern void func_003C3A10(u8 *, s32, s32, s32);
extern void func_L01_004AA7E8(u8 *, s32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_L01_00445188(u8 *, s32);
extern void func_L01_0044FD88(u8 *, s32, s32, s32);
extern s32 func_L01_0045A9F0(u8 *);
extern void func_L01_0045BD78(f32, f32, f32, f32, u8 *);
extern s32 func_L01_0045C2A0(f32, f32, f32, u8 *);
extern s32 func_L01_0044E1B8(f32, u8 *);
extern f32 func_L01_00448890(void *, f32, f32, f32, f32, void *, s32);
extern void func_L01_00456C98(u8 *, s32, f32, f32, void *, s32, s32, s32, f32, s32, s32, s32, s32);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern s32 func_00382468(s32);
extern s32 func_0038CB00(void *);
extern f32 func_0038CF38(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_0038D890(void *, void *, void *, f32);
extern void func_003C4098(void *, void *, void *, f32);
extern f32 func_003C4088(f32, f32, f32);
extern void func_L03_003B1DD0(u8 *);
extern s32 func_L08_003C3BD8(u8 *);

#define U8(p, o) (((struct { u8 _p[o]; u8 v; } *)(p))->v)
#define U16(p, o) (((struct { u8 _p[o]; u16 v; } *)(p))->v)
#define S16(p, o) (((struct { u8 _p[o]; s16 v; } *)(p))->v)
#define S32(p, o) (((struct { u8 _p[o]; s32 v; } *)(p))->v)
#define F32(p, o) (((struct { u8 _p[o]; f32 v; } *)(p))->v)
#define PTR(p, o) (((struct { u8 _p[o]; u8 *v; } *)(p))->v)
#define Q128(p, o) (((struct { u8 _p[o]; vu0_q v; } *)(p))->v)

void func_L08_00399978(u8 *a) {
    vu0_v4 sp10;
    vu0_v4 sp20;
    u8 *v;
    f32 r;
    s32 s17;
    s32 one;

    func_L08_0039AC38(a);
    v = PTR(a, 0x68);
    if (D_L08_001D6694 == 2) {
        U8(a, 0x31) = 0;
        U16(a, 0x34) |= 1;
        return;
    }
    if (func_L01_004BA800() == 0) {
        U8(a, 0x31) = 1;
        U16(a, 0x34) &= 0xFFFE;
    }
    if (D_L08_001E13B4 == 0) {
        D_L08_001E13B4 = 1;
        D_L08_001E13B0 = S32(D_1A4BE0, 0x2850);
    }
    if (D_L08_001E13BC == 0) {
        D_L08_001E13BC = 1;
        D_L08_001E13B8 = D_142660[2];
    }

    switch (U8(a, 0x20)) {
    case 0:
        S32(a, 0x98) = 0;
        U16(a, 0x34) = (U16(a, 0x34) | 0x43) & 0xEFFF;
        func_L01_004AA7E8(a, 1);
        func_L01_004450F0(a, 1, -1);
        break;
    case 2:
        if (func_L01_004561B8(a) != 0) {
            func_L01_00335F38(PTR(a, 0xB8), 0);
            func_003C3A10(a, 0, 0, 0);
        }
        break;
    case 3:
        if (func_L01_004561B8(a) != 0) {
            func_L01_00335F38(PTR(a, 0xB8), 0);
            func_003C3A10(a, 0, 0, S32(v, 0x47C));
        }
        S32(v, 0x3AC) = 1;
        S32(v, 0x3CC) = 2;
        func_L01_0045A9F0(a);
        if (U8(v, 0x490) != 0 && (U8(a, 0x60) & 2) != 0) {
            func_L01_00335F38(PTR(a, 0xB8), 1);
        }
        break;
    case 4:
        if (func_L01_004561B8(a) != 0) {
            func_L01_00335F38(PTR(a, 0xB8), 0);
            func_003C3A10(a, 1, 0, S32(v, 0x47C));
        }
        S32(v, 0x3CC) = 0;
        S32(v, 0x3AC) = 1;
        func_L01_0045A9F0(a);
        if (U8(v, 0x490) != 0 && (U8(a, 0x60) & 2) != 0) {
            func_L01_00335F38(PTR(a, 0xB8), 1);
        }
        break;
    case 5:
        if (func_L01_004561B8(a) != 0) {
            func_L01_00335F38(PTR(a, 0xB8), 0);
            func_003C3A10(a, 2, 0, S32(v, 0x47C));
        }
        S32(v, 0x3CC) = 0;
        S32(v, 0x3AC) = 1;
        func_L01_0045A9F0(a);
        if (U8(v, 0x490) != 0 && (U8(a, 0x60) & 2) != 0) {
            func_L01_00335F38(PTR(a, 0xB8), 1);
        }
        break;
    case 6:
        if (func_L01_004561B8(a) != 0) {
            func_L01_00335F38(PTR(a, 0xB8), 0);
            func_003C3A10(a, 0xC, 0, S32(v, 0x47C));
        }
        S32(v, 0x3AC) = 1;
        Q128(v, 0x280) = Q128(v, 0x4A0);
        func_L01_0045A9F0(a);
        if ((U8(a, 0x60) & 2) != 0) {
            func_L01_00335F38(PTR(a, 0xB8), 1);
        }
        break;
    case 7:
        if (func_L01_004561B8(a) != 0) {
            func_L01_00335F38(PTR(a, 0xB8), 0);
            func_L01_0045BD78(0.0028000001f, 0.050000004f, 0.020106195f, 2.0106194f, a);
            func_003C3A10(a, 3, 0, S32(v, 0x47C));
        }
        {
            f32 q = F32(v, 0x240) / F32(v, 0x1B8);
            if (q < 0.7f) {
                q = 0.7f;
            }
            F32(a, 0x48) = q;
        }
        S32(v, 0x3AC) = 0;
        if (U8(v, 0x490) != 0 && (U8(a, 0x60) & 2) != 0) {
            func_L01_00335F38(PTR(a, 0xB8), 1);
        }
        break;
    case 8:
        if (func_L01_004561B8(a) != 0) {
            func_L01_00335F38(PTR(a, 0xB8), 0);
            func_L01_0045BD78(0.0064000003f, 0.13000001f, 0.020106195f, 2.0106194f, a);
            func_003C3A10(a, 4, 0, S32(v, 0x47C));
        }
        {
            f32 q = F32(v, 0x240) / F32(v, 0x1B8);
            if (q < 0.7f) {
                q = 0.7f;
            }
            F32(a, 0x48) = q;
        }
        S32(v, 0x3AC) = 0;
        if (U8(v, 0x490) != 0 && (U8(a, 0x60) & 2) != 0) {
            func_L01_00335F38(PTR(a, 0xB8), 1);
        }
        break;
    case 9:
    case 15: {
        u8 *rot;
        u8 *w;
        if (func_L01_004561B8(a) != 0) {
            func_L01_00335F38(PTR(a, 0xB8), 0);
            func_L01_0045BD78(0.0064000003f, 0.13000001f, 0.0050265486f, 0.50265485f, a);
            func_003C3A10(a, 3, 0, S32(v, 0x47C));
        }
        rot = a + 0xF8;
        w = PTR(PTR(a, 0xB8), 0x68);
        r = func_0038D160(F32(v, 0x4A0) - F32(a, 0x10), F32(v, 0x4A4) - F32(a, 0x14));
        func_L01_00448890(rot, r, F32(v, 0x1A4), F32(v, 0x1A8), F32(v, 0x1AC), w + 0x74, 0);
        F32(a, 0x48) = F32(w, 0x74) / F32(v, 0x1AC) * D_L08_001DDFB0;
        S32(v, 0x3AC) = 1;
        Q128(v, 0x280) = Q128(v, 0x4A0);
        if (U8(a, 0x20) == 9 && U8(v, 0x490) != 0 && (U8(a, 0x60) & 2) != 0) {
            func_L01_00335F38(PTR(a, 0xB8), 1);
            break;
        }
        if (U8(a, 0x20) == 0xF) {
            r = func_0038D160(F32(v, 0x4A0) - F32(a, 0x10), F32(v, 0x4A4) - F32(a, 0x14));
            if (func_0038DBA0(F32(a, 0xF8), r) <= 0.034906585f) {
                func_L01_004450F0(a, 0x10, -1);
            }
        }
        break;
    }
    case 10:
        if (func_L01_004561B8(a) != 0) {
            func_L01_00335F38(PTR(a, 0xB8), 0);
            func_L01_0045BD78(0.0064000003f, 0.13000001f, 0.020106195f, 2.0106194f, a);
            func_003C3A10(a, 0xE, 0, S32(v, 0x47C));
            func_0038CE20(v + 0x230, a + 0xC0, 0.16000001f);
            S32(v, 0x268) = -1;
            qzero(v + 0x1E0);
            F32(v, 0x238) = 0.96000004f;
            S32(v, 0x220) = 0;
            S32(v, 0x218) = 0;
            S32(v, 0x21C) = 0;
        }
        r = F32(v, 0x238) - 0.019200001f;
        F32(v, 0x230) = F32(v, 0x230) * 0.99000001f;
        F32(v, 0x234) = F32(v, 0x234) * 0.99000001f;
        S32(v, 0x3AC) = 1;
        S32(v, 0x3CC) = 1;
        F32(v, 0x238) = r;
        if (r < -0.80000007f) {
            F32(v, 0x238) = -0.80000007f;
        }
        if (func_L01_0045C2A0(11.0f, 18.0f, 28.0f, a) != 0) {
            F32(a, 0x48) = 1.0f;
            func_L01_0045A9F0(a);
            if (U8(v, 0x490) != 0) {
                func_L01_00335F38(PTR(a, 0xB8), 1);
            }
        }
        break;
    case 11:
        if (func_L01_004561B8(a) != 0) {
            func_L01_00335F38(PTR(a, 0xB8), 0);
            func_L01_0045BD78(0.0064000003f, 0.13000001f, 0.0050265486f, 0.50265485f, a);
            D_L08_001DDFE0 = 0;
            func_L01_00445188(a, 0);
        }
        func_L01_00456C98(a, -1, 10.0f, 10.0f, 0, 0, 1, 1, 1.0f, 3, 0, 0, 0);
        func_L01_0045A9F0(a);
        s17 = U8(a, 0xBC);
        if (s17 == 0) {
            if (func_L01_00456208(a) != 0 || (U8(a, 0x60) & 2) != 0) {
                if (func_00382468(5) != 0) {
                    func_003C3A10(a, 0, 0, S32(v, 0x47C));
                } else {
                    func_003C3A10(a, 1, 0, S32(v, 0x47C));
                }
            }
            S32(v, 0x3AC) = 1;
            S32(v, 0x3CC) = 2;
            if (S16(v, 0xC4) == 1) {
                func_L01_00445188(a, 2);
            } else {
                r = func_0038D160(F32(D_1A4BE0, 0x80) - F32(a, 0x10), F32(D_1A4BE0, 0x84) - F32(a, 0x14));
                if (1.3089969f < func_0038DBA0(F32(a, 0xF8), r)) {
                    func_L01_00445188(a, 1);
                }
            }
            if (func_0038CF38(a + 0x10, D_1A4C60) < 10.0f) {
                if (D_L08_001DDFE0 == 0) {
                    u8 *h = v + 0x5EC;
                    func_L01_00335EC0(a, *(s32 *)(h + func_00382468(5) * 4));
                    D_L08_001DDFE0 = 1;
                }
            }
            if (U8(v, 0x490) != 0) {
                func_L01_00335F38(PTR(a, 0xB8), 1);
            }
        } else if (one = 1, s17 == one) {
            u8 *u = PTR(PTR(a, 0xB8), 0x68);
            u8 *hero;
            u8 *rot;
            if (func_L01_00456208(a) != 0) {
                func_003C3A10(a, 3, 0, S32(v, 0x47C));
            }
            hero = D_1A4BE0;
            rot = a + 0xF8;
            r = func_0038D160(F32(hero, 0x80) - F32(a, 0x10), F32(hero, 0x84) - F32(a, 0x14));
            func_L01_00448890(rot, r, F32(v, 0x1A4), F32(v, 0x1A8), F32(v, 0x1AC), u + 0x74, 0);
            F32(a, 0x48) = F32(u, 0x74) / F32(v, 0x1AC) * D_L08_001DDFB0;
            S32(v, 0x3AC) = s17;
            Q128(v, 0x280) = Q128(hero, 0x80);
            if (S16(v, 0xC4) == s17) {
                func_L01_00445188(a, 2);
            } else {
                r = func_0038D160(F32(hero, 0x80) - F32(a, 0x10), F32(hero, 0x84) - F32(a, 0x14));
                if (func_0038DBA0(F32(a, 0xF8), r) <= 0.034906585f) {
                    func_L01_00445188(a, 0);
                }
            }
            if (U8(v, 0x490) != 0) {
                func_L01_00335F38(PTR(a, 0xB8), 1);
            }
        } else if (s17 == 2) {
            if (func_L01_00456208(a) != 0) {
                func_003C3A10(a, 5, 0, S32(v, 0x47C));
            }
            S32(v, 0x3AC) = 0;
            if ((U8(a, 0x60) & 2) != 0) {
                func_L01_00445188(a, 3);
            }
        } else if (s17 == 3) {
            if (func_L01_00456208(a) != 0) {
                S16(v, 0x5D4) = 0x32;
                func_003C3A10(a, 6, 0, 0);
            }
            S32(v, 0x3AC) = 0;
            if (U8(v, 0x490) != 0 || (S16(v, 0xC4) != one && func_0038CB00(v + 0x5D4) != 0)) {
                func_L01_00445188(a, 4);
            } else if (S16(v, 0xC4) == one) {
                S16(v, 0x5D4) = 0x32;
            }
        } else if (s17 == 4) {
            if (func_L01_00456208(a) != 0) {
                func_003C3A10(a, 7, 0, 0);
            }
            S32(v, 0x3AC) = 0;
            if (func_L01_0044E1B8(28.0f, a) != 0) {
                if (U8(v, 0x490) != 0) {
                    func_L01_00335F38(PTR(a, 0xB8), 1);
                } else {
                    func_L01_00445188(a, 0);
                }
            }
        }
        break;
    case 12:
        if (func_L01_004561B8(a) != 0) {
            func_L01_00335F38(PTR(a, 0xB8), 0);
            func_003C3A10(a, 5, 0, S32(v, 0x47C));
        }
        S32(v, 0x3AC) = 0;
        if ((U8(a, 0x60) & 2) != 0) {
            func_L01_004450F0(a, 0xD, -1);
        }
        break;
    case 13:
        if (func_L01_004561B8(a) != 0) {
            func_L01_00335F38(PTR(a, 0xB8), 0);
            func_003C3A10(a, 6, 0, 0);
        }
        S32(v, 0x3AC) = 0;
        if (U8(v, 0x490) != 0) {
            func_L01_004450F0(a, 0xE, -1);
        }
        break;
    case 14:
        if (func_L01_004561B8(a) != 0) {
            func_L01_00335F38(PTR(a, 0xB8), 0);
            func_003C3A10(a, 7, 0, 0);
        }
        S32(v, 0x3AC) = 0;
        if (U8(v, 0x490) != 0 && func_L01_0044E1B8(28.0f, a) != 0) {
            func_L01_00335F38(PTR(a, 0xB8), 1);
        }
        break;
    case 16: {
        u8 *w;
        f32 f20;
        s32 idx;
        if (func_L01_004561B8(a) != 0) {
            func_L01_00335F38(PTR(a, 0xB8), 0);
            func_L01_00335EC0(PTR(a, 0xB8), func_00382468(2) == 0 ? S32(v, 0x5E8) : S32(v, 0x5E4));
            S16(v, 0x5D4) = U16(v, 0x47C);
            F32(v, 0x5D8) = 1.0f / (f32)S16(v, 0x47C);
            func_003C3A10(a, 9, 0, S32(v, 0x47C));
        }
        idx = S32(PTR(PTR(PTR(a, 0xB8), 0xB8), 0x68), 0x60);
        S32(v, 0x3AC) = 0;
        Q128(v, 0x530) = *(vu0_q *)D_L08_001DDFC0;
        w = D_L08_001DF21C + (idx << 8);
        if (func_0038CB00(v + 0x5D4) == 0) {
            f20 = (f32)S16(v, 0x5D4) * F32(v, 0x5D8);
            func_0038D890(&sp10, D_L08_001DDFD0, D_L08_001D9A20, F32(w, 0xF8));
            vec_add_ba(&sp10, w + 0x10, &sp10);
            *(vu0_q *)&sp20 = Q128(a, 0x10);
            func_003C4098(a + 0x10, &sp10, &sp20, f20);
            F32(a, 0xF8) = func_003C4088(func_0038DAB8(F32(w, 0xF8), 3.1415927f), F32(a, 0xF8), f20);
        } else {
            func_0038D890(&sp10, D_L08_001DDFD0, D_L08_001D9A20, F32(w, 0xF8));
            vec_add_ab(&sp10, w + 0x10, &sp10);
            Q128(a, 0x10) = *(vu0_q *)&sp10;
            F32(a, 0xF8) = func_0038DAB8(F32(w, 0xF8), 3.1415927f);
        }
        if ((U8(a, 0x60) & 2) != 0) {
            s32 j = S32(PTR(PTR(PTR(a, 0xB8), 0xB8), 0x68), 0x60);
            if (j != -1) {
                func_L03_003B1DD0(D_L08_001DF21C + (j << 8));
            }
            func_L01_004450F0(a, 0x11, -1);
        }
        break;
    }
    case 17: {
        s32 idx;
        if (func_L01_004561B8(a) != 0) {
            func_L01_00335F38(PTR(a, 0xB8), 0);
            func_003C3A10(a, 0xA, 0, 0);
        }
        {
            u8 *m = PTR(PTR(PTR(a, 0xB8), 0xB8), 0x68);
            S32(v, 0x3AC) = 0;
            Q128(v, 0x530) = *(vu0_q *)D_L08_001DDFC0;
            idx = S32(m, 0x60);
        }
        if (idx != -1) {
            if (func_L08_003C3BD8(D_L08_001DF21C + (idx << 8)) != 0) {
                func_L01_004450F0(a, 0x12, -1);
            }
        }
        break;
    }
    case 18:
        if (func_L01_004561B8(a) != 0) {
            func_L01_00335F38(PTR(a, 0xB8), 0);
            func_003C3A10(a, 0xB, 0, 2);
        }
        S32(v, 0x3AC) = 0;
        if (func_L01_0044E1B8(26.0f, a) != 0) {
            func_L01_00335F38(PTR(a, 0xB8), 1);
        }
        break;
    }

    if (U8(a, 0x31) != 0) {
        if (func_L01_0040E548(D_L08_001E1D40, a + 0x10) < 576.0f) {
            func_L01_004472C0(a);
            U8(a, 0x6F) = 0x16;
        }
    }
    if (U8(a, 0x20) >= 2) {
        if (func_0038CB00(v + 0x5D6) != 0) {
            if (D_L08_001E13B8 == D_142660[2]) {
                if ((f32)D_L08_001E13B8 * 0.1f <= (f32)(D_L08_001E13B0 - S32(D_1A4BE0, 0x2850))) {
                    func_L01_00335EC0(PTR(a, 0xB8), func_00382468(2) == 0 ? S32(v, 0x5DC) : S32(v, 0x5E0));
                    S16(v, 0x5D6) = 0x5DC;
                }
            }
        }
    }
    D_L08_001E13B0 = S32(D_1A4BE0, 0x2850);
    D_L08_001E13B8 = D_142660[2];
    S32(a, 0xF0) = 0;
    S32(a, 0xF4) = 0;
    if (U8(a, 0x20) >= 2) {
        func_L01_0044FD88(a, S32(v, 0x5D0), 0, 2);
    }
}
/* localdecomp:end func_L08_00399978 */
