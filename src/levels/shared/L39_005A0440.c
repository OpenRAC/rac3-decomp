#include "common.h"

/* localdecomp:start func_L39_005A0440 */
#include "vu0.h"

typedef int u128_005A0440 __attribute__((mode(TI)));

typedef struct {
    u8 pad0[4];
    u16 w;
    s16 h;
    s16 nmip;
    s16 cbp;
    s16 tbp2;
    s16 tbp3;
} Tex_005A0440;

typedef union {
    struct {
        unsigned long d0;
        unsigned long r8;
        unsigned long d10;
        unsigned long r18;
        unsigned long d20;
        unsigned long r28;
        unsigned long d30;
        unsigned long r38;
        unsigned long d40;
        unsigned long r48;
    } q;
    struct {
        s32 f0;
        s32 f4;
        s32 f8;
        s32 fC;
        s32 f10;
        s32 f14;
        s32 f18;
        s32 f1C;
        s32 f20;
        s32 f24;
        s32 f28;
        s32 f2C;
        s32 f30;
        s32 f34;
    } w;
} Rec_005A0440;

typedef struct {
    s32 f0;
    s32 pad4[3];
} Sub_005A0440;

typedef struct {
    s32 f[3];
    u8 b[4];
    f32 f10;
    f32 f14;
    f32 f18;
    s32 f1C;
    s32 f20;
    u8 pad24[0xC];
    s32 f30;
    s32 f34;
    u8 pad38[6];
    s16 f3E;
    u8 pad40[6];
    s16 f46;
    f32 f48;
} Obj_005A0440;

extern s32 D_L39_0024C9E0;
__asm__(".extern D_L39_0024C9E0, 16");
extern u8 D_L39_002BA740[];
extern s16 D_L39_002BA640[];
extern u8 *D_L39_002BA440[];
extern s32 D_L39_002C1740[];
extern u8 D_L39_002C1B40[];
extern unsigned long D_L39_00268A40[];
extern s32 D_001FC450[];

void func_L39_005A0440(Obj_005A0440 *p, Tex_005A0440 *tex, u128_005A0440 *src, s32 slot) {
    s32 i;
    s32 j;
    s32 k;
    u8 *pal;
    Rec_005A0440 *r;

    D_L39_002BA740[slot] = D_L39_0024C9E0;
    D_L39_002BA640[D_L39_0024C9E0] = slot;
    D_L39_002BA440[D_L39_0024C9E0] = (u8 *)p;
    p->f46 = D_L39_0024C9E0;
    D_L39_002C1740[D_L39_0024C9E0++] = p->f48 * 1024.0f;
    p->f20 = -1;
    p->f3E = 0;

    for (i = 0; i < 3; i++) {
        if (p->f[i] != 0) {
            p->f[i] += (s32)p;
            for (j = 0; j < p->b[i]; j++) {
                ((Sub_005A0440 *)p->f[i])[j].f0 += p->f[i];
            }
        }
    }
    if (p->b[1] == 0) {
        p->f14 = 8190.0f;
    }
    if (p->b[2] == 0) {
        p->f18 = 8192.0f;
    }
    p->f30 = 0;
    p->f34 += (s32)p;
    p->f1C += (s32)p;

    pal = D_L39_002C1B40 + (D_L39_002BA740[slot] << 4);
    *(u128_005A0440 *)pal = *src;

    r = (Rec_005A0440 *)p->f1C;
    for (k = 0; k < p->b[3]; k++) {
        s32 t = pal[k];
        s32 k10 = r->w.f10;
        s32 k14 = r->w.f14;
        s32 k30 = r->w.f30;
        s32 k34 = r->w.f34;

        if (tex != 0) {
            Tex_005A0440 *e = &tex[t];
            s32 base = D_001FC450[8] >> 8;
            s32 w = (s16)e->w;
            s32 tw = 30 - plzcw_asm(w);
            s32 th = 30 - plzcw_asm(e->h);
            s32 tbw1 = w >> 7;
            s32 tbw = w >> 6;
            s32 cbp = e->cbp + base;
            s32 mxl = e->nmip - 1;
            s32 tbp2 = e->tbp2 + base;
            s32 tbp3 = e->tbp3 + base;
            if (tbw < 1) tbw = 1;
            if (tbw1 < 1) tbw1 = 1;

            r->q.d0 = ((unsigned long)0 << 0) | ((unsigned long)tbw << 14) | ((unsigned long)0x13 << 20) |
                      ((unsigned long)tw << 26) | ((unsigned long)th << 30) | ((unsigned long)1 << 34) |
                      ((unsigned long)0 << 35) | ((unsigned long)cbp << 37) |
                      ((unsigned long)0 << 51) | ((unsigned long)0 << 55) | ((unsigned long)0 << 56) |
                      ((unsigned long)4 << 61);
            r->q.d10 = ((unsigned long)0 << 0) | ((unsigned long)mxl << 2) | ((unsigned long)1 << 5) |
                       ((unsigned long)k14 << 6) | ((unsigned long)0 << 9) | ((unsigned long)0 << 19) |
                       ((unsigned long)k10 << 32);
            r->q.d20 = ((unsigned long)0 << 0) | ((unsigned long)tbw1 << 14) | ((unsigned long)tbp2 << 20) |
                       ((unsigned long)1 << 34) | ((unsigned long)tbp3 << 40) | ((unsigned long)1 << 54);
            r->q.d30 = ((unsigned long)k30 << 0) | ((unsigned long)k34 << 2) | ((unsigned long)t << 24);
        } else {
            unsigned long v0 = D_L39_00268A40[t * 3];
            unsigned long v1 = D_L39_00268A40[t * 3 + 1];
            unsigned long v2 = D_L39_00268A40[t * 3 + 2];
            r->q.d0 = v0;
            r->q.d10 = (v1 & 0x1C) | ((unsigned long)1 << 5) | ((unsigned long)k14 << 6) | ((unsigned long)k10 << 32);
            r->q.d20 = v2;
            r->q.d30 = ((unsigned long)k30 << 0) | ((unsigned long)k34 << 2) | ((unsigned long)t << 24);
        }
        r++;
    }
}
/* localdecomp:end func_L39_005A0440 */

INCLUDE_ASM("asm/levels", func_L39_005A0818);

/* localdecomp:start func_L39_005A0DB0 */
#include "vu0.h"
typedef struct { s32 pixels; s16 width, height, storage, base, first, second; } Tex_005A0DB0;
typedef struct {
    u8 pad0[0x10];
    u8 *packets;
    u8 pad14[8];
    u16 offset;
    u8 pad1E[0xA];
    u8 count;
    u8 pad29[0x17];
} Rec_005A0DB0;

extern Rec_005A0DB0 *D_L39_0024C9A0;
extern s32 D_L39_0024C9A4;
extern f32 D_L39_0024C9AC;
extern f32 D_L39_0024C9B0[3];
extern s32 D_L39_00268BD8 __attribute__((section(".data")));
extern s32 D_L39_001FC450[];
extern void func_003CEDF8(void);

/* from rac2-decomp's func_00292B88 (its storage arm, inlined here) */
void func_L39_005A0DB0(u8 *h, Tex_005A0DB0 *texs) {
    Rec_005A0DB0 *r;
    s32 i, j, m;
    f32 s;

    D_L39_0024C9A4 = *(s32 *)(h + 4);
    s = *(f32 *)(h + 8);
    D_L39_0024C9AC = s;
    D_L39_00268BD8 = *(s32 *)(h + 0xC);
    D_L39_0024C9B0[0] = s * 6.0f;
    D_L39_0024C9B0[1] = s * 4.0f;
    D_L39_0024C9B0[2] = s + s;
    func_003CEDF8();
    r = (Rec_005A0DB0 *)(h + *(s32 *)h);
    D_L39_0024C9A0 = r;
    for (m = 0; m < D_L39_0024C9A4; m++) {
        r[m].packets = (u8 *)r + (s32)r[m].packets;
    }
    for (i = 0; i < D_L39_0024C9A4; i++) {
        for (j = 0; j < D_L39_0024C9A0[i].count; j++) {
            long *out = (long *)(D_L39_0024C9A0[i].packets + D_L39_0024C9A0[i].offset + j * 0x50);
            s32 tb = D_L39_001FC450[8] >> 8;
            s32 idx = ((s32 *)out)[0];
            s32 k = ((s32 *)out)[4];
            s32 filter = ((s32 *)out)[5];
            Tex_005A0DB0 *t = &texs[idx];
            s32 width = t->width >> 6;
            s32 half_width = t->width >> 7;
            s32 log_width, log_height, base, first, second, storage, address, clamp;
            long format, tex, tex_address, flags, control, other, other_address;
            if (width <= 0) width = 1;
            if (half_width <= 0) half_width = 1;
            log_width = 30 - plzcw_asm(t->width);
            log_height = 30 - plzcw_asm(t->height);
            base = t->base + tb;
            first = t->first + tb;
            second = t->second + tb;
            storage = t->storage;
            format = ((long)log_width << 26) | 0x01300000;
            tex = (((long)width << 14) | format) | ((long)log_height << 30);
            tex_address = 0x400000000L | ((long)base << 37);
            tex |= tex_address;
            tex |= 0x8000000000000000UL;
            *out = tex;
            address = ((s32 *)out)[8];
            clamp = ((s32 *)out)[9];
            flags = ((long)filter << 6) | 0x20;
            control = ((long)(storage - 1) << 2) | flags;
            control |= (long)k << 32;
            out += 2;
            *out = control;
            out += 2;
            *out = address | ((long)clamp << 2) | ((long)idx << 24);
            out += 2;
            other = ((long)half_width << 14) | ((long)first << 20);
            other_address = ((long)second << 40) | 0x400000000L;
            other |= other_address;
            other |= 0x40000000000000L;
            *out = other;
            out[2] = 0;
        }
    }
}
/* localdecomp:end func_L39_005A0DB0 */
