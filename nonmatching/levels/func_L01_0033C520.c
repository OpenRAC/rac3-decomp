/* func_L01_0033C520 (Claude wave 14 r74, 2026-11-28). First draft kept here. */
/* r74 wave 14 (2026-11-28), first draft (fresh entry), from the functional C. NEEDS ANOTHER LINE: retail loads float
 * constants as lui/ori/mtc1 through $at (Ps2EeAs li.s: @ps2as) and has lqc2/vsub.xyz/vadd.xyz/sqc2 (vu0.h helpers:
 * -mvu0-use-vf0-vf2); the file's line '-O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses' has neither.
 * This file is the plain-float form for the file's line (393 diff there). The real draft is
 * out/func_L01_0033C520.vu0.c, under the existing line of L01_002FFBC8.c '-O2 -G8 -fopt-stack -mno-check-zero-division
 * -mno-split-addresses @ps2as -mvu0-use-vf0-vf2': 286 raw / 113 aligned at level 01 (422 retail instructions, 415
 * there). Cut 0x0033C520-0x0033CBC0 (the function is the last of L01_0033B7C0.c; the next file starts at 0x0033CBC0).
 * Forms from retail: abs_asm for the three frame-distance tests (blezl/neg), qzero for the spark position, switches on
 * the moby type (0x1FA/0x1FF/default; 0x1F5,0x200 / 0x1F4,0x1FF) and on k (2, 1, default 0x25), the named prototype of
 * func_L01_003303B8 (L08_003A4E60.c). Retail reaches the counters 0x001DFB40/0x001E1898/0x001E1894 absolutely
 * (lui/lw) except in delay slots, where they are $gp-relative: SN's assembler does that for a plain extern scalar
 * without an .extern hint, so they are plain externs here. Left: one saved register more
 * here, the a0/a1 temporaries of the link walk, the 004653B8 argument order. */
#include "common.h"

/* localdecomp:start func_L01_0033C520 */
#include "vu0.h"
typedef int u128_0033C520 __attribute__((mode(TI)));
extern u8 D_001A4BE0[];
extern vu0_v4 D_L01_001E29C0;
extern u8 D_L01_001E2A40[];
extern u8 D_00142660[];
extern u8 *D_001A71A0[];
extern u16 D_001A8A6C[];
extern s32 D_L01_001DAFEC;
extern s32 D_L01_001DFB40;
extern s32 D_L01_001DFF40;
extern s32 D_L01_001E1894;
extern s32 D_L01_001E1898;
extern s32 D_001DCFAC_sda;
__asm__(".extern D_001DCFAC_sda, 4");
extern s32 D_001DCFB0_sda;
__asm__(".extern D_001DCFB0_sda, 4");
void func_L01_0033C520(u8 *m, s32 a1, u8 *a2) {
    extern void func_L01_004AAC98(s32, s32, u8 *, s32);
    extern s32 func_003A52A0(s32, s32, void *);
    extern s32 func_003C4B50(void *, void *);
    extern void func_L01_004653B8(void *, s32, u32, f32, f32, f32, f32, f32);
    extern void func_L01_00448248(void *, s32, s32);
    extern void func_L01_0044C870(u8 *, u8 *, void *, void *);
    extern void func_L01_00451FE0(u8 *, s32, void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void *func_L01_003303B8(void *pos, s32 notify, s32 w20, s32 w24, s32 w28, s32 w2C, s16 h32, s16 h30,
                            f32 scale, f32 last, f32 f6C, f32 f68,
                            s16 h18, s16 h1C, s16 h1A, s16 h1E, s16 h16, s16 h3C, s32 w64, s32 owner,
                            s32 u0, s32 u1, s32 u2, s32 u3, s32 u4, s32 u5,
                            s32 w58, s32 w5C, s32 w60, s16 h36);
    extern void func_L01_00349998(u8 *, void *, void *, s32, f32);
    extern void func_L01_00425A08(s32);
    extern void func_L01_00451F60(s32, s32, s32);
    extern void func_L01_0041A5B0(s32, s32);
    vu0_v4 pos;
    vu0_v4 dir;
    vu0_v4 spot;
    vu0_v4 aim;
    u8 *p;
    u8 *q;
    u8 *hero;
    s32 stamp;
    s32 d;
    s32 k;
    s32 n;
    s32 i;

    func_L01_0033C4B8((S_33BDC8 *)m);
    p = *(u8 **)(m + 0x68);
    if (abs_asm(D_L01_001DFB40 - D_L01_001E1894) >= 2) {
        switch (*(s16 *)(m + 0xAA)) {
        case 0x1FA:
            func_L01_004AAC98(0, 0, m, 0x1F4);
            stamp = D_L01_001DFB40;
            break;
        case 0x1FF:
            func_L01_004AAC98(1, 0, m, 0x1FF);
            stamp = D_L01_001DFB40;
            break;
        default:
            func_003A52A0(0, 0, m);
            stamp = D_L01_001DFB40;
            break;
        }
        D_L01_001E1894 = stamp;
    }
    stamp = D_L01_001DFB40;
    if (abs_asm(stamp - D_L01_001E1898) >= 2) {
        D_L01_001E1898 = stamp;
    }
    if (*(u8 **)(p + 0xD0) != 0) {
        q = *(u8 **)(*(u8 **)(p + 0xD0) + 0x68);
        *(s32 *)(q + 0xD4) = *(s32 *)(p + 0xD4);
        q = *(u8 **)(*(u8 **)(p + 0xD0) + 0x68);
        *(s32 *)(q + 0xDC) |= 0x24;
    }
    if (*(u8 **)(p + 0xD4) != 0) {
        func_003C4B50(*(void **)(*(u8 **)(*(u8 **)(p + 0xD4) + 0x68) + 0xD0), m);
        q = *(u8 **)(*(u8 **)(p + 0xD4) + 0x68);
        *(s32 *)(q + 0xD0) = *(s32 *)(p + 0xD0);
        q = *(u8 **)(*(u8 **)(p + 0xD4) + 0x68);
        *(s32 *)(q + 0xDC) |= 0x24;
    }
    q = m;
    do {
        u8 *v = *(u8 **)(q + 0x68);
        *(s32 *)(v + 0xDC) |= 0x20;
        q = *(u8 **)(v + 0xD0);
    } while (q != 0);
    *(u128_0033C520 *)&pos = *(u128_0033C520 *)(m + 0x10);
    pos.z += 0.3f;
    func_L01_004653B8(&pos, 1, 0x40808080, 0.3f, 1.01f, 1.075f, 0.05f, 50000.0f);
    for (i = 4; i >= 0; i--) {
        func_L01_004653B8(&pos, 1, 0x40808080, 0.3f, 1.01f, 1.07f, 0.05f, 50000.0f);
    }
    if (a2 != 0) {
        *(u128_0033C520 *)&dir = *(u128_0033C520 *)(a2 + 0x10);
    } else {
        dir = *(vu0_v4 *)(m + 0x10);
        dir.x -= ((vu0_v4 *)(D_001A71A0[0] + 0x10))->x;
        dir.y -= ((vu0_v4 *)(D_001A71A0[0] + 0x10))->y;
        dir.z -= ((vu0_v4 *)(D_001A71A0[0] + 0x10))->z;
    }
    stamp = D_L01_001DFB40;
    d = abs_asm(stamp - D_001DCFAC_sda);
    if (d >= 0xC9) {
        D_001DCFAC_sda = stamp;
        D_001DCFB0_sda = 0;
    } else if (stamp != D_001DCFAC_sda) {
        func_L01_00448248(&D_001DCFB0_sda, 0, d >> 2);
        D_001DCFAC_sda = D_L01_001DFB40;
    }
    {
        s32 v = D_L01_001DFF40;
        if (v >= 0xFB && D_001DCFB0_sda < 5) {
            k = 4;
        } else if (v >= 0xC9 && D_001DCFB0_sda < 10) {
            k = 3;
        } else if (v >= 0x97 && D_001DCFB0_sda < 15) {
            k = 2;
        } else if (v >= 0x65) {
            k = D_001DCFB0_sda < 20;
        } else {
            k = 0;
        }
    }
    if (k != 0) {
        D_001DCFB0_sda += k;
        n = 0;
        switch (*(s16 *)(m + 0xAA)) {
        case 0x1F5:
        case 0x200:
            n = (1 << (k - 1)) - 1;
            if (n >= 0x10) {
                n = 15;
            }
            break;
        case 0x1F4:
        case 0x1FF:
            switch (k) {
            case 2:
                n = 5;
                break;
            case 1:
                n = 1;
                break;
            default:
                n = 0x25;
                break;
            }
            break;
        }
        if (n != 0) {
            qzero(&spot);
            if (*(u8 **)(p + 0x120) != 0 && D_L01_001DAFEC == 0) {
                func_L01_0044C870(m, *(u8 **)(p + 0x120), m + 0x10, &spot);
            }
            func_L01_00451FE0(m, n, &spot, 0xFF, 0xB4, 0, 0, 0x23, 0, 3, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
        }
    }
    m[0x20] = 3;
    m[0xBC] = 0xC;
    *(u16 *)(m + 0x34) |= 1;
    *(s32 *)(m + 0x98) = 0;
    if (a1 != 0) {
        p[0xFA] = 1;
        func_0038CF68(&spot, m + 0xE0, 0.5f);
        spot.x += ((vu0_v4 *)(m + 0x10))->x;
        spot.y += ((vu0_v4 *)(m + 0x10))->y;
        spot.z += ((vu0_v4 *)(m + 0x10))->z;
        func_L01_003303B8(&spot, 0, 10, 10, 10, 10, 15, 0, 1.0f, 0.0f, 0.0f, 2.0f, 0, 0, 0, 0, 0, 0, 0x1010000, 0,
                          0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
    }
    if (*(s16 *)(m + 0xAA) != 0x1F8) {
        return;
    }
    aim = D_L01_001E29C0;
    aim.x -= spot.x;
    aim.y -= spot.y;
    aim.z -= spot.z;
    func_0038CF68(&aim, &aim, 1.0f);
    hero = D_001A4BE0;
    if (*(s32 *)(hero + 0x234) == 0) {
        q = D_00142660;
        *(s32 *)(q + 0x78) = *(s16 *)(q + 0x40);
        *(s16 *)(q + 0x40) = 4;
    }
    func_L01_00349998(m, m + 0x10, &aim, 1, 5.0f);
    q = D_L01_001E2A40;
    *(f32 *)(q + 0x40) = 0.2f;
    *(s32 *)(hero + 0x234) = 0x3E8;
    *(s32 *)(q + 0x48) = 0x4B;
    *(s32 *)(q + 0x28) = 0x32;
    *(f32 *)(q + 0x20) = 0.3f;
    *(s32 *)(q + 0x2C) = 0;
    func_L01_00425A08(1);
    func_L01_00451F60(0x121A, -1, 0);
    if (D_001A8A6C[0] == 0) {
        func_L01_0041A5B0(0x1405, 0x107);
    }
}
/* localdecomp:end func_L01_0033C520 */

/* The other form the notes name (Claude wave 14 r74, func_L01_0033C520.vu0.c): the draft for the line or declaration it needs, not compiled here. */
#if 0
/* r74: the VU0/@ps2as form of func_L01_0033C520 (see out/func_L01_0033C520.near.c): 286 raw / 113 aligned rows under '-O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses @ps2as -mvu0-use-vf0-vf2'. */
#include "common.h"

/* localdecomp:start func_L01_0033C520 */
#include "vu0.h"
typedef int u128_0033C520 __attribute__((mode(TI)));
extern u8 D_001A4BE0[];
extern vu0_v4 D_L01_001E29C0;
extern u8 D_L01_001E2A40[];
extern u8 D_00142660[];
extern u8 *D_001A71A0[];
extern u16 D_001A8A6C[];
extern s32 D_L01_001DAFEC;
extern s32 D_L01_001DFB40;
extern s32 D_L01_001DFF40;
extern s32 D_L01_001E1894;
extern s32 D_L01_001E1898;
extern s32 D_001DCFAC_sda;
__asm__(".extern D_001DCFAC_sda, 4");
extern s32 D_001DCFB0_sda;
__asm__(".extern D_001DCFB0_sda, 4");
void func_L01_0033C520(u8 *m, s32 a1, u8 *a2) {
    extern void func_L01_004AAC98(s32, s32, u8 *, s32);
    extern s32 func_003A52A0(s32, s32, void *);
    extern s32 func_003C4B50(void *, void *);
    extern void func_L01_004653B8(void *, s32, u32, f32, f32, f32, f32, f32);
    extern void func_L01_00448248(void *, s32, s32);
    extern void func_L01_0044C870(u8 *, u8 *, void *, void *);
    extern void func_L01_00451FE0(u8 *, s32, void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void *func_L01_003303B8(void *pos, s32 notify, s32 w20, s32 w24, s32 w28, s32 w2C, s16 h32, s16 h30,
                            f32 scale, f32 last, f32 f6C, f32 f68,
                            s16 h18, s16 h1C, s16 h1A, s16 h1E, s16 h16, s16 h3C, s32 w64, s32 owner,
                            s32 u0, s32 u1, s32 u2, s32 u3, s32 u4, s32 u5,
                            s32 w58, s32 w5C, s32 w60, s16 h36);
    extern void func_L01_00349998(u8 *, void *, void *, s32, f32);
    extern void func_L01_00425A08(s32);
    extern void func_L01_00451F60(s32, s32, s32);
    extern void func_L01_0041A5B0(s32, s32);
    vu0_v4 pos;
    vu0_v4 dir;
    vu0_v4 spot;
    vu0_v4 aim;
    u8 *p;
    u8 *q;
    u8 *hero;
    s32 stamp;
    s32 d;
    s32 k;
    s32 n;
    s32 i;

    func_L01_0033C4B8((S_33BDC8 *)m);
    p = *(u8 **)(m + 0x68);
    if (abs_asm(D_L01_001DFB40 - D_L01_001E1894) >= 2) {
        switch (*(s16 *)(m + 0xAA)) {
        case 0x1FA:
            func_L01_004AAC98(0, 0, m, 0x1F4);
            stamp = D_L01_001DFB40;
            break;
        case 0x1FF:
            func_L01_004AAC98(1, 0, m, 0x1FF);
            stamp = D_L01_001DFB40;
            break;
        default:
            func_003A52A0(0, 0, m);
            stamp = D_L01_001DFB40;
            break;
        }
        D_L01_001E1894 = stamp;
    }
    stamp = D_L01_001DFB40;
    if (abs_asm(stamp - D_L01_001E1898) >= 2) {
        D_L01_001E1898 = stamp;
    }
    if (*(u8 **)(p + 0xD0) != 0) {
        q = *(u8 **)(*(u8 **)(p + 0xD0) + 0x68);
        *(s32 *)(q + 0xD4) = *(s32 *)(p + 0xD4);
        q = *(u8 **)(*(u8 **)(p + 0xD0) + 0x68);
        *(s32 *)(q + 0xDC) |= 0x24;
    }
    if (*(u8 **)(p + 0xD4) != 0) {
        func_003C4B50(*(void **)(*(u8 **)(*(u8 **)(p + 0xD4) + 0x68) + 0xD0), m);
        q = *(u8 **)(*(u8 **)(p + 0xD4) + 0x68);
        *(s32 *)(q + 0xD0) = *(s32 *)(p + 0xD0);
        q = *(u8 **)(*(u8 **)(p + 0xD4) + 0x68);
        *(s32 *)(q + 0xDC) |= 0x24;
    }
    q = m;
    do {
        u8 *v = *(u8 **)(q + 0x68);
        *(s32 *)(v + 0xDC) |= 0x20;
        q = *(u8 **)(v + 0xD0);
    } while (q != 0);
    *(u128_0033C520 *)&pos = *(u128_0033C520 *)(m + 0x10);
    pos.z += 0.3f;
    func_L01_004653B8(&pos, 1, 0x40808080, 0.3f, 1.01f, 1.075f, 0.05f, 50000.0f);
    for (i = 4; i >= 0; i--) {
        func_L01_004653B8(&pos, 1, 0x40808080, 0.3f, 1.01f, 1.07f, 0.05f, 50000.0f);
    }
    if (a2 != 0) {
        *(u128_0033C520 *)&dir = *(u128_0033C520 *)(a2 + 0x10);
    } else {
        vec_sub_ab(&dir, m + 0x10, D_001A71A0[0] + 0x10);
    }
    stamp = D_L01_001DFB40;
    d = abs_asm(stamp - D_001DCFAC_sda);
    if (d >= 0xC9) {
        D_001DCFAC_sda = stamp;
        D_001DCFB0_sda = 0;
    } else if (stamp != D_001DCFAC_sda) {
        func_L01_00448248(&D_001DCFB0_sda, 0, d >> 2);
        D_001DCFAC_sda = D_L01_001DFB40;
    }
    {
        s32 v = D_L01_001DFF40;
        if (v >= 0xFB && D_001DCFB0_sda < 5) {
            k = 4;
        } else if (v >= 0xC9 && D_001DCFB0_sda < 10) {
            k = 3;
        } else if (v >= 0x97 && D_001DCFB0_sda < 15) {
            k = 2;
        } else if (v >= 0x65) {
            k = D_001DCFB0_sda < 20;
        } else {
            k = 0;
        }
    }
    if (k != 0) {
        D_001DCFB0_sda += k;
        n = 0;
        switch (*(s16 *)(m + 0xAA)) {
        case 0x1F5:
        case 0x200:
            n = (1 << (k - 1)) - 1;
            if (n >= 0x10) {
                n = 15;
            }
            break;
        case 0x1F4:
        case 0x1FF:
            switch (k) {
            case 2:
                n = 5;
                break;
            case 1:
                n = 1;
                break;
            default:
                n = 0x25;
                break;
            }
            break;
        }
        if (n != 0) {
            qzero(&spot);
            if (*(u8 **)(p + 0x120) != 0 && D_L01_001DAFEC == 0) {
                func_L01_0044C870(m, *(u8 **)(p + 0x120), m + 0x10, &spot);
            }
            func_L01_00451FE0(m, n, &spot, 0xFF, 0xB4, 0, 0, 0x23, 0, 3, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
        }
    }
    m[0x20] = 3;
    m[0xBC] = 0xC;
    *(u16 *)(m + 0x34) |= 1;
    *(s32 *)(m + 0x98) = 0;
    if (a1 != 0) {
        p[0xFA] = 1;
        func_0038CF68(&spot, m + 0xE0, 0.5f);
        vec_add_ab(&spot, &spot, m + 0x10);
        func_L01_003303B8(&spot, 0, 10, 10, 10, 10, 15, 0, 1.0f, 0.0f, 0.0f, 2.0f, 0, 0, 0, 0, 0, 0, 0x1010000, 0,
                          0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
    }
    if (*(s16 *)(m + 0xAA) != 0x1F8) {
        return;
    }
    vec_sub_ba(&aim, &D_L01_001E29C0, &spot);
    func_0038CF68(&aim, &aim, 1.0f);
    hero = D_001A4BE0;
    if (*(s32 *)(hero + 0x234) == 0) {
        q = D_00142660;
        *(s32 *)(q + 0x78) = *(s16 *)(q + 0x40);
        *(s16 *)(q + 0x40) = 4;
    }
    func_L01_00349998(m, m + 0x10, &aim, 1, 5.0f);
    q = D_L01_001E2A40;
    *(f32 *)(q + 0x40) = 0.2f;
    *(s32 *)(hero + 0x234) = 0x3E8;
    *(s32 *)(q + 0x48) = 0x4B;
    *(s32 *)(q + 0x28) = 0x32;
    *(f32 *)(q + 0x20) = 0.3f;
    *(s32 *)(q + 0x2C) = 0;
    func_L01_00425A08(1);
    func_L01_00451F60(0x121A, -1, 0);
    if (D_001A8A6C[0] == 0) {
        func_L01_0041A5B0(0x1405, 0x107);
    }
}
/* localdecomp:end func_L01_0033C520 */
#endif
