#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00672828);

INCLUDE_ASM("asm/levels", func_L39_00672898);

INCLUDE_ASM("asm/levels", func_L39_00672930);

INCLUDE_ASM("asm/levels", func_L39_006729B0);

/* localdecomp:start func_L39_00672C00 */
void func_L39_00672C00(u8 *a0, s32 a1) {
    s32 i;
    s32 c = 255;
    *(s32 *)(a0 + 872) = a1;
    for (i = 9; i >= 0; i--) a0[66 + i * 80] = c;
    *(s16 *)(a0 + 876) = 0;
}
/* localdecomp:end func_L39_00672C00 */

INCLUDE_ASM("asm/levels", func_L39_00672C30);

INCLUDE_ASM("asm/levels", func_L39_00672DD8);

INCLUDE_ASM("asm/levels", func_L39_00673160);

INCLUDE_ASM("asm/levels", func_L39_006732D0);

INCLUDE_ASM("asm/levels", func_L39_00673498);

INCLUDE_ASM("asm/levels", func_L39_00673540);

INCLUDE_ASM("asm/levels", func_L39_00673A80);

/* localdecomp:start func_L39_00673B68 */
typedef union Buf_00673B68 {
    u8 b[8];
    u32 w[2];
    u16 h[4];
} Buf_00673B68;

typedef struct Ent_00673B68 {
    u8 pad0[8];
    u8 b8;
    u8 pad9[0x1E - 9];
    s16 h1E;
    u8 pad20;
    s8 b21;
    u8 pad22[0x80 - 0x22];
} Ent_00673B68;

extern u8 D_L39_00483A00[];
extern u8 D_L39_00483A01[];
extern u8 D_L39_0049C340[];
extern u8 D_L39_0049C341[];
extern u32 D_L39_0024B9C8;
extern Ent_00673B68 D_L39_0049C890[];

static inline void PrepC_00673B68(u8 *q) {
    s32 t;
    if (*q == 0) {
        *q = ++D_L39_00483A00[0];
    } else {
        t = *q;
        *q = D_L39_00483A01[0];
        D_L39_00483A01[0] = t;
    }
}

static inline u16 Dec16C_00673B68(u8 *q) {
    Buf_00673B68 buf;
    u32 a;
    u32 b;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*q == 0) {
        return 0;
    }
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 24; i += 3) {
        *d++ = D_L39_00483A00[((k + i) & 7) * 209 + m];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
    return buf.h[2];
}

static inline void Set16C_00673B68(u8 *q, s16 v) {
    u8 *hk = q;
    Buf_00673B68 buf;
    u32 key;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    PrepC_00673B68(q);
    key = ((u32 *)D_L39_00483A00)[((u32)hk * D_L39_0024B9C8) % 418];
    k = ((u32)q - *q) & 7;
    buf.h[2] = v;
    buf.w[0] = (u32)q ^ key;
    buf.w[1] = ((buf.w[1] & 0xFFFF) | (buf.w[1] << 16)) ^ key;
    m = *q + 1;
    d = buf.b;
    for (i = 0; i < 24; i += 3) {
        D_L39_00483A00[((k + i) & 7) * 209 + m] = *d++;
    }
}

static inline void PrepD_00673B68(u8 *q) {
    s32 t;
    if (*q == 0) {
        *q = ++D_L39_0049C340[0];
    } else {
        t = *q;
        *q = D_L39_0049C341[0];
        D_L39_0049C341[0] = t;
    }
}

static inline void Set16D_00673B68(u8 *q, s16 v) {
    u8 *hk = q;
    Buf_00673B68 buf;
    u32 key;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    PrepD_00673B68(q);
    key = ((u32 *)D_L39_0049C340)[((u32)hk * D_L39_0024B9C8) % 258];
    k = ((u32)q - *q) & 7;
    buf.h[2] = v;
    buf.w[0] = (u32)q ^ key;
    buf.w[1] = ((buf.w[1] & 0xFFFF) | (buf.w[1] << 16)) ^ key;
    m = *q + 1;
    d = buf.b;
    for (i = 0; i < 24; i += 3) {
        D_L39_0049C340[m + ((k + i) & 7) * 129] = *d++;
    }
}

typedef struct Rec_00673B68 {
    u8 b0;
    u8 b1;
    u8 pad2[0x10];
    u8 a12[0x10];
    u8 a22[0x10];
} Rec_00673B68;

void func_L39_00673B68(Rec_00673B68 *p, s32 b) {
    s16 v;
    s16 bit = 1 << b;
    u8 *q = &p->b1;

    Set16C_00673B68(q, bit | Dec16C_00673B68(q));
    Set16D_00673B68(&p->a22[b], 0);
    v = (D_L39_0049C890 + D_L39_0049C890[b].b21)->h1E;
    if (v != 0) {
        Set16C_00673B68(&p->a12[b], v);
    }
}
/* localdecomp:end func_L39_00673B68 */

INCLUDE_ASM("asm/levels", func_L39_00673EF0);

INCLUDE_ASM("asm/levels", func_L39_00674190);

/* localdecomp:start func_L39_00674320 */
extern u32 D_L39_002404C0;
extern u8 *func_L39_0061BFB0(u32);
void func_L39_00674320(u8 *a0) {
    if (a0[6676] == 0) {
        u32 v = *(u32 *)(*(u8 **)(*(u8 **)(a0 + 9560) + 4) + 80) ^ D_L39_002404C0;
        if (v != 0xFFFFFFFF) {
            u8 *r = func_L39_0061BFB0(v);
            if (r != 0) {
                *(s32 *)(a0 + 4216) = *(s32 *)(r + 9508);
            }
        }
    }
}
/* localdecomp:end func_L39_00674320 */
