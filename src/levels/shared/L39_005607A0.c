#include "common.h"

/* localdecomp:start func_L39_005607A0 */
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    f32 f[4];
} __attribute__((aligned(16))) V_005607A0;
extern void func_0038CE20(void *out, void *in, f32 s);
extern f32 func_0038CE68(void *a, void *b);
extern void func_0038CE90(void *out, void *a, void *b);
void func_L39_005607A0(void *m, void *n) {
    V_005607A0 x;
    V_005607A0 y;
    V_005607A0 d;
    f32 t;

    *(u128_t *)&x = 0;
    *(u128_t *)&y = 0;
    x.f[0] = 1.0f;
    y.f[1] = 1.0f;
    func_0038CE20(&d, n, -1.0f);
    t = func_0038CE68(&x, &d);
    if (fabs_asm(t) > 0.98f) {
        func_0038CE90(m, &d, &y);
    } else {
        func_0038CE90(m, &d, &x);
    }
    func_0038CE90((u8 *)m + 16, m, &d);
    *(u128_t *)((u8 *)m + 32) = *(u128_t *)&d;
}
/* localdecomp:end func_L39_005607A0 */

/* localdecomp:start func_L39_00560868 */
typedef union Buf_00560868 {
    u8 b[8];
    u32 w[2];
    u16 h[4];
} Buf_00560868;

typedef struct Rec_00560868 {
    u8 pad0[0x1A14];
    u8 b1A14;
    u8 pad1A15[0x1A40 - 0x1A15];
    u8 b1A40;
    u8 b1A41;
    u8 pad1A42[0x10];
    u8 a1A52[0x10];
    u8 pad1A62[0x24C9 - 0x1A62];
    u8 b24C9;
} Rec_00560868;

typedef struct Ent_00560868 {
    u8 pad0[0x1E];
    s16 h1E;
    u8 pad20;
    s8 b21;
    u8 pad22[0x80 - 0x22];
} Ent_00560868;

typedef struct Sub_00560868 {
    u8 pad0[4];
    s32 w4;
    u16 h8;
    u16 hA;
} Sub_00560868;

typedef struct V3_00560868 {
    f32 x;
    f32 y;
    f32 z;
} V3_00560868;

typedef struct V4_00560868 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} V4_00560868;

typedef struct Self_00560868 {
    u8 pad0[0x10];
    V4_00560868 v10;
    u8 pad20[0x68 - 0x20];
    Sub_00560868 *x68;
    u8 pad6C[0xC0 - 0x6C];
    u8 xC0[0x30];
    u8 xF0[0x10];
} Self_00560868;

typedef struct Strm_00560868 {
    u32 w0;
    u32 w4;
    u32 w8;
} Strm_00560868;

extern u8 D_L39_00483A00[];
extern u8 D_L39_00483A01[];
extern u32 D_L39_0024B9C8;
__asm__(".extern D_L39_0024B9C8, 16");
extern u32 D_L39_0024D5D8[] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024D5D8, 64");
extern u32 *D_L39_00246330;
__asm__(".extern D_L39_00246330, 16");
extern Ent_00560868 D_L39_0049C890[];
extern s32 D_L39_0024B440;
__asm__(".extern D_L39_0024B440, 4");
extern void func_L39_00662B18(void *, void *, s32);
extern void func_L39_005607A0(void *, void *);
extern void func_003C48A8(void *, void *);
extern Rec_00560868 *func_L39_0061BFB0(u32);
extern s32 func_L39_005F3488(s32, s32, void *, s32);
extern void func_L39_00673540(void *, s32, s32);
extern void func_L39_00673B68(void *, s32);
extern s32 func_L39_00648AE0(void *, s32);
extern s32 func_L39_00648840(void *, s32);
extern void func_L39_00648960(void *, s32);
extern void func_L01_00451F60(s32, s32, s32);
extern void func_L39_005DB1A8(void *, s32);
extern void func_L01_004450F0(void *, s32, s32);

static inline u16 Dec16_00560868(u8 *q) {
    Buf_00560868 buf;
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
        s32 x = ((k + i) & 7) * 209 + m;
        *d++ = D_L39_00483A00[x];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
    return buf.h[2];
}

static inline void Prep_00560868(u8 *q) {
    s32 t;
    if (*q == 0) {
        *q = ++D_L39_00483A00[0];
    } else {
        t = *q;
        *q = D_L39_00483A01[0];
        D_L39_00483A01[0] = t;
    }
}

static inline void Set16_00560868(u8 *q, s16 v) {
    u8 *hk = q;
    Buf_00560868 buf;
    u32 key;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    Prep_00560868(q);
    key = ((u32 *)D_L39_00483A00)[((u32)hk * D_L39_0024B9C8) % 418];
    k = ((u32)q - *q) & 7;
    buf.h[2] = v;
    buf.w[0] = (u32)q ^ key;
    buf.w[1] = ((buf.w[1] & 0xFFFF) | (buf.w[1] << 16)) ^ key;
    m = *q + 1;
    d = buf.b;
    for (i = 0; i < 24; i += 3) {
        s32 x = ((k + i) & 7) * 209 + m;
        D_L39_00483A00[x] = *d++;
    }
}

static __inline__ void set_00560868(V4_00560868 *d, V3_00560868 *v) {
    d->x = v->x;
    d->y = v->y;
    d->z = v->z;
    d->w = 0;
}

void func_L39_00560868(Self_00560868 *self, Strm_00560868 *s) {
    Sub_00560868 *d = self->x68;
    u8 ok;
    if ((ok = s != 0 && s->w8 == *D_L39_00246330)) {
        if ((s->w0 & 0xF) == 0) {
            V3_00560868 v;
            V3_00560868 w;
            V4_00560868 t;
            u8 *e = self->xC0;
            func_L39_00662B18(s, &v, 12);
            func_L39_00662B18(s, &w, 12);
            set_00560868(&self->v10, &v);
            set_00560868(&t, &w);
            func_L39_005607A0(e, &t);
            func_003C48A8(e, self->xF0);
            func_L39_00662B18(s, &d->h8, 2);
            func_L39_00662B18(s, &d->hA, 2);
        }
    } else {
        switch (s->w0 & 0xF) {
        case 0: {
            s32 id;
            s32 i;
            Rec_00560868 *p;
            u32 *flags;
            func_L39_00662B18(s, &id, 4);
            p = func_L39_0061BFB0(id);
            if (p != 0 && p->b1A14 != 0) {
                func_L39_005F3488(0, 0, self, 0x1AFC);
            }
            d->w4 = id;
            D_L39_0024B440 = 0;
            flags = D_L39_0024D5D8;
            for (i = 0; i < 16; i++) {
                flags[i] = 0;
                if ((d->hA >> i) & 1) {
                    if (!((s16)Dec16_00560868(&p->b1A40) >> i & 1)) {
                        func_L39_00673540(&p->b1A40, i, 0);
                        d->h8 &= ~(1 << i);
                    }
                    d->hA &= ~(1 << i);
                    if (!((s16)Dec16_00560868(&p->b1A41) >> i & 1)) {
                        flags[i] = 2;
                        D_L39_0024B440++;
                        func_L39_00673B68(&p->b1A40, i);
                    }
                } else if ((d->h8 >> i) & 1) {
                    if (!((s16)Dec16_00560868(&p->b1A40) >> i & 1)) {
                        flags[i] = 1;
                        D_L39_0024B440++;
                        func_L39_00673540(&p->b1A40, i, 0);
                        d->h8 &= ~(1 << i);
                    } else if (((d->h8 >> i) & 1) && ((s16)Dec16_00560868(&p->b1A40) >> i & 1)) {
                        s16 h;
                        Ent_00560868 *q;
                        if (func_L39_00648AE0(p, i)) {
                            q = D_L39_0049C890 + D_L39_0049C890[i].b21;
                        } else {
                            q = &D_L39_0049C890[i];
                        }
                        h = q->h1E;
                        if (h != 0) {
                            Set16_00560868(&p->a1A52[i], h);
                        }
                    }
                }
            }
            if (p->b1A14 != 0) {
                func_L01_00451F60(0xD2C, -1, p->b24C9);
                if (func_L39_00648840(p, 0x23) == 0) {
                    func_L39_00648960(p, 0x23);
                }
                func_L39_005DB1A8(flags, p->b24C9);
            }
            func_L01_004450F0(self, 3, -1);
            break;
        }
        case 1:
            func_L39_00662B18(s, &d->h8, 2);
            func_L39_00662B18(s, &d->hA, 2);
            func_L01_004450F0(self, 5, -1);
            break;
        case 2:
            func_L01_004450F0(self, 5, -1);
            break;
        }
    }
}
/* localdecomp:end func_L39_00560868 */

/* localdecomp:start func_L39_00560FC0 */
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_004561B8(void *);
extern f32 func_L01_0040E548(void *, void *);
extern s32 func_L39_00560618(u8 *, u8 *, s32);
extern s32 func_L39_00560330(u8 *, u8 *);
extern s32 func_L39_00560220_00560FC0(s32);
extern void func_L39_00560308_00560FC0(s32);
extern s32 func_L39_005601F8_00560FC0(s32);
extern void func_L39_00560248_00560FC0(s32, s32);
extern void func_L39_00560290(u8 *);
extern s32 D_001A5DF8[];
extern u8 *D_L39_0024CE20[] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024B43C, 4");
__asm__(".extern D_L39_0024B40C, 4");
extern s32 D_L39_0024B43C;
extern f32 D_L39_0024B40C;

s32 func_L39_00560FC0(u8 *a0, s32 a1) {
    u8 *q = *(u8 **)(a0 + 0x68);
    s32 i;
    u8 *p;
    if (a1 != 0) {
        *(s32 *)q = -1;
        *(u32 *)(q + 4) = 0xFFFFFFFF;
        *(s32 *)(q + 0xC) = D_001A5DF8[0];
        return 0;
    }
    switch (a0[0x20]) {
    case 0:
        return 0;
    case 1:
    case 2:
        if (*(s32 *)(q + 0xC) + D_L39_0024B43C < D_001A5DF8[0]) {
            func_L01_004450F0(a0, 4, -1);
            if (func_L39_00560220_00560FC0((s32)a0) == 0) {
                func_L39_00560308_00560FC0((s32)a0);
            }
            return 0;
        }
        for (i = 0; i < 8; i++) {
            p = D_L39_0024CE20[i];
            if (p != 0 && func_L01_0040E548(p + 0xA0, a0 + 0x10) < D_L39_0024B40C
                && (func_L39_00560618(p, a0, 1) != 0 || func_L39_00560330(p, a0) != 0)) {
                func_L39_00560248_00560FC0((s32)a0, *(s32 *)p);
                break;
            }
        }
        return 0;
    case 3:
        if (func_L01_004561B8(a0) != 0) {
            if (func_L39_005601F8_00560FC0((s32)a0) == 0) {
                func_L39_00560290(a0);
            }
        }
        return 0;
    }
    return 0;
}
/* localdecomp:end func_L39_00560FC0 */
