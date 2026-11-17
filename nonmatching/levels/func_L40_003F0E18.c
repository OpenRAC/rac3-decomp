/* NTSC-U draft (Claude wave K): C of func_L40_003F0970, the NTSC-U twin of func_L40_003F0E18, with NTSC-U names and addresses (the two versions' code differs).
 * near miss on NTSC-U, no count recorded (NTSC-U twin "func_L40_003F0970", whose code is not the PAL one).
 * Worker's note: first draft, structure matches (244 vs 236 words, 45 aligned words; mostly gp-vs-lui forms). Body: player loop over D_L40_002412A0 (count), 5 filters, two inlined protected-value reads (template of func_L40_004235C0: buf union, D_L40_003BFF60[m + ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L40_003F0970 */
typedef int Q_003F0970 __attribute__((mode(TI)));

typedef union Buf_003F0970 {
    u8 b[8];
    u32 w[2];
    Q_003F0970 q;
} Buf_003F0970;

typedef struct Ent_003F0970 {
    s32 w0;
    s32 w4;
    s32 w8;
    u8 pad_c[0x1C - 0xC];
} Ent_003F0970;

extern s32 *D_L40_002412A0;
__asm__(".extern D_L40_002412A0, 16");
extern void *D_001A5E58;
extern u8 D_L40_003BFF60[];
extern Ent_003F0970 D_L40_003AA820[];
extern void func_L40_003ED4C0(void);

extern u8 *func_L39_006197C0(s32);
extern s32 func_L40_003F07C0(s32);
extern s32 func_L40_003F0808(s32);
extern void func_L40_003F0868(void *, s32);
extern f32 func_L01_0040C040(void *, void *);
extern s32 func_L39_00645FE0(void *, s32);
extern void func_L39_006460E8(void *, s32);
extern void func_L01_00402768(void (*)(void), s32);
extern s32 func_L39_005F0D88(s32, s32, void *, s32);
extern void func_L40_003ED698(void *, void *, void *);

void func_L40_003F0970(u8 *o, s32 a1) {
    u8 *p = *(u8 **)(o + 0x68);
    u8 *s0;
    s32 i;
    u32 x;
    u8 ok;

    if (*(s32 *)(p + 0x304) != 0) {
        return;
    }
    for (i = 0; i < *D_L40_002412A0; i++) {
        s0 = func_L39_006197C0(i);
        if (*(s32 *)(p + 0x264) != 0x539) {
            continue;
        }
        if (*(s32 *)(s0 + 0x2558) == 0) {
            continue;
        }
        if (*(s32 *)(s0 + 0x254C) != 0) {
            continue;
        }
        if (func_L40_003F07C0(*(s32 *)(*(u8 **)(*(u8 **)(s0 + 0x2558) + 4) + 0x38)) != 0) {
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
        if (!(func_L01_0040C040(o + 0x10, *(u8 **)(s0 + 0x2524) + 0x10) < 9.0f)) {
            continue;
        }
        if (!(fabs_asm(*(f32 *)(o + 0x18) - *(f32 *)(*(u8 **)(s0 + 0x2524) + 0x18)) < 5.0f)) {
            continue;
        }
        {
            u8 *q = s0 + 0x19E6;
            Buf_003F0970 buf;
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
                    *d++ = D_L40_003BFF60[m + ((k + j) & 7) * 255];
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
                Buf_003F0970 buf;
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
                        *d++ = D_L40_003BFF60[m + ((k + j) & 7) * 255];
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
        if (func_L39_00645FE0(s0, 0x15) == 0) {
            func_L39_006460E8(s0, 0x15);
        }
        if ((u32)(D_L40_003AA820[*(s32 *)(s0 + 0x2544)].w0 - 4) < 2) {
            continue;
        }
        D_L40_003AA820[*(s32 *)(s0 + 0x2544)].w0 = 6;
        D_L40_003AA820[*(s32 *)(s0 + 0x2544)].w8 = 0xA;
        D_L40_003AA820[*(s32 *)(s0 + 0x2544)].w4 = 0;
        func_L01_00402768(func_L40_003ED4C0, *(s32 *)(s0 + 0x2524));
        if ((*(s32 *)(*(u8 **)(s0 + 0x2534) + 0x1A4) & 0x10) == 0) {
            continue;
        }
        if (func_L40_003F0808(*(s32 *)(*(u8 **)(*(u8 **)(s0 + 0x2558) + 4) + 0x38)) == 0) {
            continue;
        }
        if (func_L39_00645FE0(s0, 0x10) == 0) {
            func_L39_006460E8(s0, 0x10);
        }
        func_L39_005F0D88(0xA, 0, o, 0x109D);
        p[0x33E] = 1;
        func_L40_003F0868(o, *(s32 *)s0);
        break;
    }
    if (p[0x33E] != 0) {
        func_L40_003ED698((void *)a1, D_001A5E58, o);
        p[0x33E] = 0;
    }
}
/* localdecomp:end func_L40_003F0970 */
