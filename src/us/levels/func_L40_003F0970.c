#include "common.h"

/* NTSC-U counterpart of func_L40_003F0E18 (src/levels/shared/L40_003F0E18.c) */
/* localdecomp:start func_L40_003F0970 */
#include "vu0.h"

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    u8 padC[0x10];
} E_003F0E18;

typedef union {
    u8 b[8];
    u32 w[2];
} Buf_003F0E18;

extern s32 *D_L40_002412A0;
extern u8 D_L40_003BFF60[];
extern E_003F0E18 D_L40_003AA820[];
extern s32 D_001A5E58[];
extern u8 *func_L39_006197C0(s32);
extern f32 func_L01_0040C040(void *, void *);
extern s32 func_L39_00645FE0(void *, s32);
extern void func_L39_006460E8(void *, s32);
extern void func_L01_00352D38(void);
extern void func_L01_00402768(void (*)(void), s32);
extern s32 func_L39_005F0D88(s32, s32, void *, s32);
extern void func_L40_003ED698(void *, void *, void *);
extern s32 func_L40_003F07C0(s32);
extern s32 func_L40_003F0808(s32);
extern void func_L40_003F0868(char *, int);

static __inline__ u32 decode_003F0E18(u8 *q) {
    Buf_003F0E18 buf;
    s32 n, k, m, j;
    u8 *d;
    if (*q == 0) {
        return 0;
    }
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    d = buf.b;
    for (j = 0; j < 40; j += 5) {
        *d++ = D_L40_003BFF60[m + ((k + j) & 7) * 255];
    }
    buf.w[0] ^= (u32)q;
    buf.w[1] ^= buf.w[0];
    return buf.w[1];
}

void func_L40_003F0970(u8 *self, void *a1) {
    u8 *v = *(u8 **)(self + 0x68);
    u8 *p;
    s32 i;
    u8 flag;
    u8 *r;

    if (*(s32 *)(v + 0x304) != 0) {
        return;
    }
    for (i = 0; i < *D_L40_002412A0; i++) {
        p = func_L39_006197C0(i);
        if (*(s32 *)(v + 0x264) != 0x539) {
            continue;
        }
        if (*(u8 **)(p + 0x2558) == 0) {
            continue;
        }
        if (*(s32 *)(p + 0x254C) != 0) {
            continue;
        }
        if (func_L40_003F07C0(*(s32 *)(*(u8 **)(*(u8 **)(p + 0x2558) + 4) + 0x38)) != 0) {
            continue;
        }
        if (*(s32 *)(v + 0x2C0) != -1) {
            if (p == 0) {
                continue;
            }
            if (*(u8 **)(p + 0x2558) == 0) {
                continue;
            }
            if (*(s32 *)(*(u8 **)(*(u8 **)(p + 0x2558) + 4) + 0x40) != *(s32 *)(v + 0x2C0)) {
                continue;
            }
        }
        if (!(func_L01_0040C040(self + 0x10, *(u8 **)(p + 0x2524) + 0x10) < 9.0f)) {
            continue;
        }
        if (!(fabs_asm(*(f32 *)(self + 0x18) - *(f32 *)(*(u8 **)(p + 0x2524) + 0x18)) < 5.0f)) {
            continue;
        }
        if ((decode_003F0E18(p + 0x19E6) ^ 20) == 0) {
            continue;
        }
        r = *(u8 **)(p + 0x2530);
        if ((flag = r != 0 ? (r[0x27B] != 0 && (decode_003F0E18(p + 0x19E4) ^ 0x31) == 0) : 0)) {
            continue;
        }
        if (func_L39_00645FE0(p, 0x15) == 0) {
            func_L39_006460E8(p, 0x15);
        }
        if ((u32)(D_L40_003AA820[*(s32 *)(p + 0x2544)].f0 - 4) < 2) {
            continue;
        }
        D_L40_003AA820[*(s32 *)(p + 0x2544)].f0 = 6;
        D_L40_003AA820[*(s32 *)(p + 0x2544)].f8 = 10;
        D_L40_003AA820[*(s32 *)(p + 0x2544)].f4 = 0;
        func_L01_00402768(func_L01_00352D38, *(s32 *)(p + 0x2524));
        if ((*(s32 *)(*(u8 **)(p + 0x2534) + 0x1A4) & 0x10) == 0) {
            continue;
        }
        if (func_L40_003F0808(*(s32 *)(*(u8 **)(*(u8 **)(p + 0x2558) + 4) + 0x38)) == 0) {
            continue;
        }
        if (func_L39_00645FE0(p, 0x10) == 0) {
            func_L39_006460E8(p, 0x10);
        }
        func_L39_005F0D88(10, 0, self, 0x109D);
        v[0x33E] = 1;
        func_L40_003F0868((char *)self, *(s32 *)p);
        break;
    }
    if (v[0x33E] != 0) {
        func_L40_003ED698(a1, (void *)D_001A5E58[0], self);
        v[0x33E] = 0;
    }
}
/* localdecomp:end func_L40_003F0970 */
