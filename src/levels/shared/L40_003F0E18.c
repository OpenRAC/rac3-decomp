#include "common.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec4;
typedef struct Moby Moby;
typedef struct {
    u8 pad0[0x29C];
    s32 field_29C;
    u8 pad2A0[0x5C];
    s32 count;
    s32 field_300;
    s32 field_304;
    u8 pad308[8];
    Moby *items[1];
} Vars;
typedef struct {
    u8 pad0[0x354];
    s32 field_354;
    u8 pad358[8];
    Vec4 pos;
} VarsB;
struct Moby {
    u8 pad0[0x10];
    Vec4 pos;
    u8 field_20;
    u8 pad21[0x47];
    void *pVar;
};
typedef int u128_3F1460 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Vec4_003F1538;

/* localdecomp:start func_L40_003F0E18 */
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

extern s32 *D_L40_00241120;
extern u8 D_L40_003BFE20[];
extern E_003F0E18 D_L40_003AA6E0[];
extern s32 D_001A5CD8[];
extern u8 *func_L39_0061BF38(s32);
extern f32 func_L01_0040E570(void *, void *);
extern s32 func_L39_00648840(void *, s32);
extern void func_L39_00648960(void *, s32);
extern void func_L01_00353880(void);
extern void func_L01_00404AD8(void (*)(void), s32);
extern s32 func_L39_005F3488(s32, s32, void *, s32);
extern void func_L40_003EDB38(void *, void *, void *);
extern s32 func_L40_003F0C68(s32);
extern s32 func_L40_003F0CB0(s32);
extern void func_L40_003F0D10(char *, int);

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
        *d++ = D_L40_003BFE20[m + ((k + j) & 7) * 255];
    }
    buf.w[0] ^= (u32)q;
    buf.w[1] ^= buf.w[0];
    return buf.w[1];
}

void func_L40_003F0E18(u8 *self, void *a1) {
    u8 *v = *(u8 **)(self + 0x68);
    u8 *p;
    s32 i;
    u8 flag;
    u8 *r;

    if (*(s32 *)(v + 0x304) != 0) {
        return;
    }
    for (i = 0; i < *D_L40_00241120; i++) {
        p = func_L39_0061BF38(i);
        if (*(s32 *)(v + 0x264) != 0x539) {
            continue;
        }
        if (*(u8 **)(p + 0x2558) == 0) {
            continue;
        }
        if (*(s32 *)(p + 0x254C) != 0) {
            continue;
        }
        if (func_L40_003F0C68(*(s32 *)(*(u8 **)(*(u8 **)(p + 0x2558) + 4) + 0x38)) != 0) {
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
        if (!(func_L01_0040E570(self + 0x10, *(u8 **)(p + 0x2524) + 0x10) < 9.0f)) {
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
        if (func_L39_00648840(p, 0x15) == 0) {
            func_L39_00648960(p, 0x15);
        }
        if ((u32)(D_L40_003AA6E0[*(s32 *)(p + 0x2544)].f0 - 4) < 2) {
            continue;
        }
        D_L40_003AA6E0[*(s32 *)(p + 0x2544)].f0 = 6;
        D_L40_003AA6E0[*(s32 *)(p + 0x2544)].f8 = 10;
        D_L40_003AA6E0[*(s32 *)(p + 0x2544)].f4 = 0;
        func_L01_00404AD8(func_L01_00353880, *(s32 *)(p + 0x2524));
        if ((*(s32 *)(*(u8 **)(p + 0x2534) + 0x1A4) & 0x10) == 0) {
            continue;
        }
        if (func_L40_003F0CB0(*(s32 *)(*(u8 **)(*(u8 **)(p + 0x2558) + 4) + 0x38)) == 0) {
            continue;
        }
        if (func_L39_00648840(p, 0x10) == 0) {
            func_L39_00648960(p, 0x10);
        }
        func_L39_005F3488(10, 0, self, 0x109D);
        v[0x33E] = 1;
        func_L40_003F0D10((char *)self, *(s32 *)p);
        break;
    }
    if (v[0x33E] != 0) {
        func_L40_003EDB38(a1, (void *)D_001A5CD8[0], self);
        v[0x33E] = 0;
    }
}
/* localdecomp:end func_L40_003F0E18 */
