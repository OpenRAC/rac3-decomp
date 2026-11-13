#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_0066E378);

INCLUDE_ASM("asm/levels", func_L39_0066EAA8);

/* localdecomp:start func_L39_0066EC58 */
void func_L39_0066EC58(u8 *buf, s32 val, s32 *bitpos, s32 n) {
    u8 nbits = n;
    s32 byte;
    s32 bit;
    s32 avail;
    u8 take;
    u8 shift;
    u8 mask;
    s32 rem;

    byte = *bitpos / 8;
    bit = *bitpos % 8;
    buf += byte;
    avail = 8 - bit;
    if (avail < nbits) {
        take = avail;
        shift = 0;
    } else {
        take = nbits;
        shift = 8 - (nbits + bit);
    }
    *bitpos += take;
    mask = 0xFF >> (8 - take);
    rem = nbits - take;
    nbits = rem;
    *buf = (*buf & ~(mask << shift)) | ((mask & (val >> rem)) << shift);
    while (nbits != 0) {
        u8 m;

        buf++;
        if (nbits > 8) {
            shift = 0;
            take = 8;
        } else {
            take = nbits;
            shift = 8 - nbits;
        }
        *bitpos += take;
        m = 0xFF >> (8 - take);
        rem = nbits - take;
        nbits = rem;
        *buf = (*buf & ~(m << shift)) | ((m & (val >> rem)) << shift);
    }
}
/* localdecomp:end func_L39_0066EC58 */

/* localdecomp:start func_L39_0066ED88 */
s32 func_L39_0066ED88(u8 *buf, s32 *bitpos, u8 nbits) {
    s32 byte;
    s32 bit;
    s32 avail;
    u8 take;
    u8 shift;
    u8 mask;
    s32 result;
    s32 rem;

    byte = *bitpos / 8;
    bit = *bitpos % 8;
    buf += byte;
    avail = 8 - bit;
    if (avail < nbits) {
        take = avail;
        shift = 0;
    } else {
        take = nbits;
        shift = 8 - (nbits + bit);
    }
    *bitpos += take;
    mask = (0xFF >> (8 - take)) << shift;
    rem = nbits - take;
    result = ((*buf & mask) >> shift) << rem;
    nbits = rem;
    while (nbits != 0) {
        u8 m;

        buf++;
        if (nbits > 8) {
            shift = 0;
            take = 8;
        } else {
            take = nbits;
            shift = 8 - nbits;
        }
        *bitpos += take;
        m = (0xFF >> (8 - take)) << shift;
        rem = nbits - take;
        result |= ((*buf & m) >> shift) << rem;
        nbits = rem;
    }
    return result;
}
/* localdecomp:end func_L39_0066ED88 */

/* localdecomp:start func_L39_0066EE90 */
typedef struct {
    char pad0[0x8];
    char head[0x19 - 0x8];
    char bits[0x1DC - 0x19];
    s32 count;
} Obj;

extern void func_0038CC88(char *, char *, s32);
extern f32 func_001369D0(f32);

s32 func_L39_0066EE90(Obj *o, char *dst) {
    s32 ret;

    if (o->count == -1) {
        ret = 0;
    } else {
        func_0038CC88(dst, o->head, 8);
        dst += 8;
        func_0038CC88(dst, o->bits, (s32)func_001369D0(o->count * 0.125f));
        ret = (s32)func_001369D0(o->count * 0.125f) + 8;
    }
    return ret;
}
/* localdecomp:end func_L39_0066EE90 */

LINKER_REMNANT("asm/levels", func_L39_0066EF40);

/* localdecomp:start func_L39_0066EF48 */
typedef struct {
    char pad0[0x1CC];
    s32 f1CC;
} Ctx_0066EF48;

typedef struct {
    u16 w[12];
    u8 nib : 4;
    char pad1C[0x3C - 0x1C];
    s32 pos;
    char pad40[0x1D8 - 0x40];
    s32 count;
    s32 saved;
} S_0066EF48;

extern void func_L39_0066EC58(u8 *, s32, s32 *, s32);
extern u8 D_L39_002463A8[0x14] __attribute__((section(".sdata")));
__asm__(".extern D_L39_002463A8, 8");
__asm__(".extern D_L39_002463A0, 4");
__asm__(".extern D_L39_002463A4, 4");
extern s32 D_L39_002463A0;
extern s32 D_L39_002463A4;
extern u8 D_L39_002463AE[] __attribute__((section(".sdata")));
extern u8 D_L39_002463AC[] __attribute__((section(".sdata")));

void func_L39_0066EF48(Ctx_0066EF48 *ctx, u8 *src, s32 mode, S_0066EF48 *obj) {
    u8 *s;
    s32 idx;
    s32 prev;
    s32 diff;
    s32 b;
    s32 n;
    s32 saved;

    s = ctx->f1CC ? D_L39_002463A8 : src;
    idx = obj->count % 4;
    func_0038CC88((char *)&obj->w[idx], (char *)s + 2, 2);
    if (mode >= 8) {
        func_0038CC88((char *)&obj->w[idx + 4], (char *)s + 6, 2);
        func_0038CC88((char *)&obj->w[idx + 8], (char *)s + 4, 2);
    } else {
        func_0038CC88((char *)&obj->w[idx + 4], (char *)D_L39_002463AE, 2);
        func_0038CC88((char *)&obj->w[idx + 8], (char *)D_L39_002463AC, 2);
    }
    saved = obj->pos;
    prev = 0xFFFF;
    if (idx > 0) {
        prev = obj->w[idx - 1];
    }
    diff = obj->w[idx] ^ prev;
    n = 0;
    for (b = 0; b < 16 && n < 4; b++) {
        if ((diff >> b) & 1) {
            if (n != 0) {
                func_L39_0066EC58((u8 *)obj + 0x19, 0, &obj->pos, 1);
            }
            func_L39_0066EC58((u8 *)obj + 0x19, b, &obj->pos, 4);
            n++;
        }
    }
    if (n == 0) {
        obj->nib &= ~(1 << idx);
    } else {
        if (n >= 4) {
            obj->pos = saved;
            func_L39_0066EC58((u8 *)obj + 0x19, obj->w[idx] >> 12, &obj->pos, 4);
            func_L39_0066EC58((u8 *)obj + 0x19, 0, &obj->pos, 1);
            func_L39_0066EC58((u8 *)obj + 0x19, (obj->w[idx] & 0xF00) >> 8, &obj->pos, 4);
            func_L39_0066EC58((u8 *)obj + 0x19, 0, &obj->pos, 1);
            func_L39_0066EC58((u8 *)obj + 0x19, (obj->w[idx] & 0xF0) >> 4, &obj->pos, 4);
            func_L39_0066EC58((u8 *)obj + 0x19, 0, &obj->pos, 1);
            func_L39_0066EC58((u8 *)obj + 0x19, obj->w[idx] & 0xF, &obj->pos, 4);
        } else {
            func_L39_0066EC58((u8 *)obj + 0x19, 1, &obj->pos, 1);
        }
        obj->nib |= 1 << idx;
    }
    obj->count++;
    if ((obj->count & 3) == 0) {
        obj->saved = obj->pos;
        D_L39_002463A0 += obj->pos + 4;
        D_L39_002463A4 += 4;
        obj->pos = 0;
    } else {
        obj->saved = -1;
    }
}
/* localdecomp:end func_L39_0066EF48 */

/* localdecomp:start func_L39_0066F260 */
typedef struct {
    u16 hdr[4];
    u8 bits[0x28];
} Loc_0066F260;

typedef struct {
    u8 pad0[2];
    u8 lo;
    u8 hi;
    u8 pad4[0x10];
} Slot_0066F260;

extern s32 func_L39_0066ED88(u8 *, s32 *, u8);
extern u8 D_L39_002463A8[0x14] __attribute__((section(".sdata")));
__asm__(".extern D_L39_002463A8, 8");

s32 func_L39_0066F260(u8 mask, Slot_0066F260 *obj) {
    Loc_0066F260 loc;
    u16 cur;
    s32 bitpos;
    s32 last;
    u16 *curp;
    s32 i;
    s32 j;
    s32 r;
    s32 saved;
    s32 n;
    u8 *buf;
    s32 k;
    s32 m;

    func_0038CC88((char *)&loc, (char *)obj, 0x30);
    func_0038CC88((char *)&obj[0], (char *)D_L39_002463A8, 0x14);
    func_0038CC88((char *)&obj[1], (char *)D_L39_002463A8, 0x14);
    func_0038CC88((char *)&obj[2], (char *)D_L39_002463A8, 0x14);
    func_0038CC88((char *)&obj[3], (char *)D_L39_002463A8, 0x14);
    func_0038CC88((char *)obj + 6, (char *)&loc.hdr[0], 2);
    func_0038CC88((char *)obj + 0x1A, (char *)&loc.hdr[1], 2);
    func_0038CC88((char *)obj + 0x2E, (char *)&loc.hdr[2], 2);
    func_0038CC88((char *)obj + 0x42, (char *)&loc.hdr[3], 2);
    buf = loc.bits;
    last = 0xFFFF;
    curp = &cur;
    bitpos = 0;
    cur = last;
    for (i = 0; i < 4; i++) {
        k = i;
        if (i > 0) {
            m = i - 1;
            last = obj[m].lo | (obj[m].hi << 8);
        } else {
            bitpos = 0;
        }
        cur = last;
        if ((mask >> i) & 1) {
            saved = bitpos;
            j = 0;
            do {
                j++;
                cur ^= 1 << func_L39_0066ED88(buf, &bitpos, 4);
                r = func_L39_0066ED88(buf, &bitpos, 1) != 0;
            } while (r == 0 && j < 3);
            if (j == 3 && r == 0) {
                bitpos = saved;
                cur = 0;
                cur |= func_L39_0066ED88(buf, &bitpos, 4) << 12;
                func_L39_0066ED88(buf, &bitpos, 1);
                cur |= func_L39_0066ED88(buf, &bitpos, 4) << 8;
                func_L39_0066ED88(buf, &bitpos, 1);
                cur |= func_L39_0066ED88(buf, &bitpos, 4) << 4;
                func_L39_0066ED88(buf, &bitpos, 1);
                cur |= func_L39_0066ED88(buf, &bitpos, 4);
            }
        }
        func_0038CC88((char *)obj + k * 0x14 + 2, (char *)curp, 2);
    }
    n = (s32)func_001369D0(bitpos * 0.125f) + 8;
    func_0038CC88((char *)obj + 0x50, (char *)&loc + n, 0x11);
    return n;
}
/* localdecomp:end func_L39_0066F260 */

/* localdecomp:start func_L39_0066F558 */
/* Retail case-block order: 0x109F, 0x109A, 0x109D, 0x1A1B (fixes block layout). */
s32 func_L39_0066F558(s32 kind) {
    switch (kind) {
    case 0x109F: return -10;
    case 0x109A: return -9;
    case 0x109D: return -8;
    case 0x1A1B: return -7;
    default: return -1;
    }
}
/* localdecomp:end func_L39_0066F558 */

/* localdecomp:start func_L39_0066F5C0 */
s32 func_L39_0066F5C0(s32 x)
{
    switch (x) {
    case -10: return 0;
    case -9: return 1;
    case -8: return 2;
    case -7: return 3;
    }
    return -1;
}
/* localdecomp:end func_L39_0066F5C0 */

/* localdecomp:start func_L39_0066F628 */
typedef struct {
    char pad0[0x40];
    s32 f40[8];
    s32 f60[8];
    s32 f80;
    s32 f84;
    s32 f88[8];
    s32 fA8[8];
    s32 fC8[8];
    s32 fE8[8];
    s32 f108;
    char pad10C[0x168 - 0x10C];
    s32 f168;
} S_0066F628_A;

typedef struct {
    s32 f0[64];
    s32 f100;
    s32 f104;
    s32 f108;
} S_0066F628_B;

typedef struct {
    s32 f0, f4, f8, fC, f10, f14;
    u16 f18[8][2];
    u8 f38[8];
    u8 f40[8];
    u8 f48[8];
    u8 f50[8];
    s32 f58[8];
    char f78[0x120];
    u16 f198[8];
    s32 f1A8;
    struct { s32 a, b, c, d, e; } e[3];
    s32 f1E8, f1EC, f1F0, f1F4;
    s32 f1F8[2];
    s32 f200, f204, f208;
    S_0066F628_A *f20C;
    s32 f210;
    S_0066F628_B *f214;
} S_0066F628_G;

typedef struct { char pad[0xB8]; u8 fB8; } S_0066F628_C;

extern S_0066F628_G D_L39_00352940;
extern s32 D_L39_0024CFA0;
extern S_0066F628_C D_001A5CD0;
extern s32 D_L39_002412DC;
extern void func_0011D534(void *, s32, s32);

void func_L39_0066F628(s32 a0, S_0066F628_A *a1, s32 a2, S_0066F628_B *a3) {
    s32 i, j, k, l, m, n, lim, v;
    D_L39_00352940.f0 = a0;
    D_L39_00352940.f4 = -1;
    D_L39_00352940.f10 = -1;
    D_L39_00352940.f1A8 = 0;
    D_L39_00352940.f1E8 = 0;
    D_L39_00352940.f1EC = 0;
    D_L39_00352940.fC = 0;
    D_L39_00352940.f14 = 0;
    D_L39_00352940.f1F0 = 0;
    D_L39_00352940.f1F4 = 0;
    D_L39_0024CFA0 = 0;
    for (j = 2; j >= 0; j--) D_L39_00352940.e[j].d = 0;
    for (k = 0; k < 8; k++) {
        if (a1->f60[k] != -1) D_L39_00352940.f1F4++;
    }
    for (l = 1; l >= 0; l--) D_L39_00352940.f1F8[l] = 0;
    for (i = 0; i < 8; i++) {
        D_L39_00352940.f18[i][0] = 0;
        D_L39_00352940.f18[i][1] = 0;
        D_L39_00352940.f58[i] = 0;
        D_L39_00352940.f38[i] = 0;
        D_L39_00352940.f40[i] = 0;
        D_L39_00352940.f48[i] = 0;
        D_L39_00352940.f50[i] = 0;
        D_L39_00352940.f198[i] = 0;
    }
    D_001A5CD0.fB8 = 0;
    D_L39_00352940.f200 = 0;
    D_L39_00352940.f204 = 0;
    D_L39_00352940.f208 = 0;
    func_0011D534(D_L39_00352940.f78, 0, 0x120);
    D_L39_00352940.f20C = a1;
    D_L39_00352940.f210 = a2;
    D_L39_00352940.f214 = a3;
    for (i = 0; i < 8; i++) {
        D_L39_00352940.f20C->f88[i] = 6;
        D_L39_00352940.f20C->fA8[i] = -1;
        D_L39_00352940.f20C->fE8[i] = 100;
        if (D_L39_00352940.f20C->f40[i] != -1) D_L39_00352940.f20C->f168++;
    }
    D_L39_00352940.f20C->f88[D_L39_00352940.f20C->f80] = 0;
    D_L39_00352940.f20C->fC8[D_L39_00352940.f20C->f80] = 0;
    D_L39_00352940.f20C->fE8[D_L39_00352940.f20C->f80] = 100;
    D_L39_00352940.f20C->f88[D_L39_00352940.f20C->f84] = 1;
    D_L39_00352940.f20C->fC8[D_L39_00352940.f20C->f84] = 1;
    D_L39_00352940.f20C->fE8[D_L39_00352940.f20C->f84] = 100;
    D_L39_00352940.f214->f104 = 0;
    lim = 8;
    if (D_L39_00352940.f214->f108 <= lim) {
        n = 0;
        for (m = 0; m < 64; m++) {
            if (D_L39_00352940.f214->f0[m] != -1) n++;
        }
        if ((u32)(D_L39_002412DC - 0x2E) <= 3) lim = 4;
        v = (s32)((f32)n * 0.33f);
        D_L39_00352940.f214->f108 = (lim < v) ? v : lim;
    }
}
/* localdecomp:end func_L39_0066F628 */
