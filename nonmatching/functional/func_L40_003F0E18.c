/* functional: high. ported from the NTSC-U draft (same structure, constants re-verified against the PAL asm line by line); all callee, table and global names re-translated to level 40 catalogue names; not byte exact (gp vs lui forms for D_L40_00241120) */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L40_003F0E18 */
typedef int Q_003F0E18 __attribute__((mode(TI)));

typedef union Buf_003F0E18 {
    u8 b[8];
    u32 w[2];
    Q_003F0E18 q;
} Buf_003F0E18;

typedef struct Ent_003F0E18 {
    s32 w0;
    s32 w4;
    s32 w8;
    u8 pad_c[0x1C - 0xC];
} Ent_003F0E18;

extern s32 *D_L40_00241120;
__asm__(".extern D_L40_00241120, 16");
extern s32 D_001A5CD8[];
extern u8 D_L40_003BFE20[];
extern Ent_003F0E18 D_L40_003AA6E0[];
extern void func_L01_00353880(void);

extern u8 *func_L39_0061BF38(s32);
extern s32 func_L40_003F0C68(s32);
extern s32 func_L40_003F0CB0(s32);
extern void func_L40_003F0D10(void *, s32);
extern f32 func_L01_0040E570(void *, void *);
extern s32 func_L39_00648840(void *, s32);
extern void func_L39_00648960(void *, s32);
extern void func_L01_00404AD8(void (*)(void), s32);
extern s32 func_L39_005F3488(s32, s32, void *, s32);
extern void func_L40_003EDB38(void *, void *, void *);

void func_L40_003F0E18(u8 *o, s32 a1) {
    u8 *p = *(u8 **)(o + 0x68);
    u8 *s0;
    s32 i;
    u32 x;
    u8 ok;

    if (*(s32 *)(p + 0x304) != 0) {
        return;
    }
    for (i = 0; i < *D_L40_00241120; i++) {
        s0 = func_L39_0061BF38(i);
        if (*(s32 *)(p + 0x264) != 0x539) {
            continue;
        }
        if (*(s32 *)(s0 + 0x2558) == 0) {
            continue;
        }
        if (*(s32 *)(s0 + 0x254C) != 0) {
            continue;
        }
        if (func_L40_003F0C68(*(s32 *)(*(u8 **)(*(u8 **)(s0 + 0x2558) + 4) + 0x38)) != 0) {
            continue;
        }
        if (*(s32 *)(p + 0x2C0) != -1) {
            if (s0 == 0) {
                continue;
            }
            if (*(s32 *)(s0 + 0x2558) == 0) {
                continue;
            }
            if (*(s32 *)(*(u8 **)(*(u8 **)(s0 + 0x2558) + 4) + 0x40) != *(s32 *)(p + 0x2C0)) {
                continue;
            }
        }
        if (!(func_L01_0040E570(o + 0x10, *(u8 **)(s0 + 0x2524) + 0x10) < 9.0f)) {
            continue;
        }
        if (!(fabs_asm(*(f32 *)(o + 0x18) - *(f32 *)(*(u8 **)(s0 + 0x2524) + 0x18)) < 5.0f)) {
            continue;
        }
        {
            u8 *q = s0 + 0x19E6;
            Buf_003F0E18 buf;
            s32 n, k, m, j;
            u8 *d;
            if (*q == 0) {
                x = 0;
            } else {
                n = *q;
                k = ((u32)q - n) & 7;
                m = n + 1;
                d = buf.b;
                for (j = 0; j < 40; j += 5) {
                    *d++ = D_L40_003BFE20[m + ((k + j) & 7) * 255];
                }
                buf.w[0] ^= (u32)q;
                buf.w[1] ^= buf.w[0];
                x = buf.w[1];
            }
        }
        if ((x ^ 20) == 0) {
            continue;
        }
        ok = 0;
        if (*(u8 **)(s0 + 0x2530) != 0) {
            if ((*(u8 **)(s0 + 0x2530))[0x27B] != 0) {
                u8 *q = s0 + 0x19E4;
                Buf_003F0E18 buf;
                s32 n, k, m, j;
                u8 *d;
                if (*q == 0) {
                    x = 0;
                } else {
                    n = *q;
                    k = ((u32)q - n) & 7;
                    m = n + 1;
                    d = buf.b;
                    for (j = 0; j < 40; j += 5) {
                        *d++ = D_L40_003BFE20[m + ((k + j) & 7) * 255];
                    }
                    buf.w[0] ^= (u32)q;
                    buf.w[1] ^= buf.w[0];
                    x = buf.w[1];
                }
                if ((x ^ 0x31) == 0) {
                    ok = 1;
                }
            }
        }
        if (ok != 0) {
            continue;
        }
        if (func_L39_00648840(s0, 0x15) == 0) {
            func_L39_00648960(s0, 0x15);
        }
        if ((u32)(D_L40_003AA6E0[*(s32 *)(s0 + 0x2544)].w0 - 4) < 2) {
            continue;
        }
        D_L40_003AA6E0[*(s32 *)(s0 + 0x2544)].w0 = 6;
        D_L40_003AA6E0[*(s32 *)(s0 + 0x2544)].w8 = 0xA;
        D_L40_003AA6E0[*(s32 *)(s0 + 0x2544)].w4 = 0;
        func_L01_00404AD8(func_L01_00353880, *(s32 *)(s0 + 0x2524));
        if ((*(s32 *)(*(u8 **)(s0 + 0x2534) + 0x1A4) & 0x10) == 0) {
            continue;
        }
        if (func_L40_003F0CB0(*(s32 *)(*(u8 **)(*(u8 **)(s0 + 0x2558) + 4) + 0x38)) == 0) {
            continue;
        }
        if (func_L39_00648840(s0, 0x10) == 0) {
            func_L39_00648960(s0, 0x10);
        }
        func_L39_005F3488(0xA, 0, o, 0x109D);
        p[0x33E] = 1;
        func_L40_003F0D10(o, *(s32 *)s0);
        break;
    }
    if (p[0x33E] != 0) {
        func_L40_003EDB38((void *)a1, (void *)D_001A5CD8[0], o);
        p[0x33E] = 0;
    }
}
/* localdecomp:end func_L40_003F0E18 */
