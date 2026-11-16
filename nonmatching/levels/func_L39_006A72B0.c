/* NTSC-U draft (Claude wave K): C of func_L39_006A4AA0, the NTSC-U twin of func_L39_006A72B0, with NTSC-U names and addresses (the two versions' code differs).
 * near miss on NTSC-U: does not compile in its file's context yet (declaration conflicts; the worker's note at the top has the details) (NTSC-U twin "func_L39_006A4AA0", whose code is not the PAL one).
 * Worker's note: best TOTAL 68 aligned words (retail 129, ours 133), 2 compiles + a 120-permutation scan of the decode helper locals (no effect: 68 for all orders). Flags match the PAL line (@ps2as). Decoded: calls func_L39_0067C5E0(0x330000), 00687F10(o), 00687E10(0), ...
 */
#include "common.h"

/* localdecomp:start func_L39_006A4AA0 */
typedef union Buf_006A4AA0 {
    u8 b[8];
    u32 w[2];
    u16 h[4];
} Buf_006A4AA0;

typedef struct N_006A4AA0 {
    u8 pad00[0x170];
    s32 w170;
} N_006A4AA0;

extern N_006A4AA0 D_001A5E50;
extern u8 D_L39_00240598;
extern u8 D_L39_002405A0;
extern u8 D_L39_00241240[];
extern u8 D_L39_00241241[];
__asm__(".extern D_L39_0024BAC8, 16");
extern u32 D_L39_0024BAC8;

extern void func_L39_0067C5E0(s32);
extern void func_L39_00687F10(void *);
extern void func_L39_00687E10(s32);
extern void func_L39_006A5108(void *);
extern void func_0019CB68(s32);
extern void func_L39_006A5AA0(void *);
extern void func_L39_006DDFD8(void);
extern void func_001962F8(void);

static inline void Prep_006A4AA0(u8 *q) {
    s32 t;
    if (*q == 0) {
        *q = ++D_L39_00241240[0];
    } else {
        t = *q;
        *q = D_L39_00241241[0];
        D_L39_00241241[0] = t;
    }
}

static inline u8 Dec24_006A4AA0(u8 *q) {
    Buf_006A4AA0 buf;
    u32 a;
    u32 h;
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
        *d++ = D_L39_00241240[m + ((k + i) & 7) * 4];
    }
    a = buf.w[0] ^ (u32)q;
    buf.w[0] = a;
    a = buf.w[1] ^ a;
    h = a >> 16;
    buf.w[1] = h / (((a ^ h) << 16) + 1);
    return buf.b[4];
}

static inline void Set40_006A4AA0(u8 *q, u32 w) {
    u8 *hk = q;
    Buf_006A4AA0 buf;
    u32 key;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    Prep_006A4AA0(q);
    key = ((u32 *)D_L39_00241240)[((u32)hk * D_L39_0024BAC8) % 8];
    k = ((u32)q - *q) & 7;
    buf.w[0] = (u32)q ^ key;
    buf.w[1] = w ^ key;
    m = *q + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        D_L39_00241240[m + ((k + i) & 7) * 4] = *d++;
    }
}

void func_L39_006A4AA0(u8 *o) {
    func_L39_0067C5E0(0x330000);
    func_L39_00687F10(o);
    func_L39_00687E10(0);
    func_L39_006A5108(o);
    if (D_001A5E50.w170 == 0) {
        func_0019CB68(1);
    }
    func_L39_006A5AA0(o);
    if (D_001A5E50.w170 == 0) {
        func_L39_006DDFD8();
    }
    if (Dec24_006A4AA0(&D_L39_002405A0) != 0) {
        Set40_006A4AA0(&D_L39_00240598, 0xFFFFFFFF);
        func_001962F8();
    }
    *(s32 *)(o + 0x48C) = 0;
    *(s32 *)(o + 0x470) = -1;
    *(s32 *)(o + 0x478) = -1;
    *(s32 *)(o + 0x47C) = -1;
}
/* localdecomp:end func_L39_006A4AA0 */
