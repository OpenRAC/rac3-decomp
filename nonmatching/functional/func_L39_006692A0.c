/* functional: high. Compiles at level 39 (no draft: written from the PAL asm, blocks cross-read once). Keyed byte-table decodes of protected actor words kept via helpers (dec/decf); bytes differ in scheduling/regalloc only. Unset-owner and owner passes mirror retail's two blocks. */
#include "common.h"
#include "vu0.h"

typedef union Dec_006692A0 {
    u8 b[8];
    u32 w[2];
    f32 f[2];
} Dec_006692A0;

typedef struct W_006692A0 {
    u8 pad0[0x16C];
    s32 event;
    u8 pad170[0x6AC - 0x170];
    u8 b6AC;
} W_006692A0;

typedef struct Tbl_006692A0 {
    s32 w0;
    s32 w4;
    s32 w8;
    u8 padC[0x10];
} Tbl_006692A0;

typedef struct Kind_006692A0 {
    u8 pad0[0xC];
    void (*hookC)(u8 *);
    u8 pad10[0xC];
} Kind_006692A0;

typedef struct Ctl_006692A0 {
    u8 pad0[0x1A4];
    u32 w1A4;
} Ctl_006692A0;

typedef struct Ref_006692A0 {
    u8 pad0[0x27B];
    u8 b27B;
} Ref_006692A0;

typedef struct S_006692A0 {
    u8 pad0[0x2D0];
    u8 * model;
    u8 pad2D4[0x4];
    u8 * owner;
    u8 * other;
    u8 pad2E0[0x18];
    s32 flags;
    s16 type;
    u8 pad2FE[0xA];
    f32 health;
    u8 pad30C[0x1C];
    s32 w328;
    u8 pad32C[0x14];
} S_006692A0;

typedef struct A_006692A0 {
    s32 id;
    u8 pad4[0x1C];
    vu0_v4 q20;
    vu0_v4 q30;
    vu0_v4 q40;
    u8 pad50[0x50];
    vu0_v4 qA0;
    vu0_v4 qB0;
    u8 padC0[0x20C];
    u8 * p2CC;
    u8 pad2D0[0x20];
    s32 w2F0;
    u8 pad2F4[0x16F0];
    u8 b19E4;
    u8 pad19E5[0x1];
    u8 b19E6;
    u8 pad19E7[0xA69];
    s32 w2450;
    u8 pad2454[0x22];
    u8 b2476;
    u8 pad2477[0x52];
    u8 b24C9;
    u8 pad24CA[0x52];
    s32 w251C;
    u8 pad2520[0xC];
    void * w252C;
    Ref_006692A0 * p2530;
    Ctl_006692A0 * p2534;
    u8 pad2538[0xC];
    s32 w2544;
    s32 w2548;
    s32 w254C;
    s32 w2550;
} A_006692A0;

extern W_006692A0 D_001A5CD0;
extern Tbl_006692A0 D_L39_004840A0[];
extern Kind_006692A0 D_L39_0033AB08[];
extern u8 D_L39_004997E0[];
__asm__(".extern D_L39_00241120, 16");
extern s32 *D_L39_00241120;
extern s32 func_L39_0061BF68(void *);
extern A_006692A0 *func_L39_0061BF38(s32);
extern f32 func_L01_0040E570(void *, void *);
extern void func_L01_00451F60(s32, s32, s32);
extern void func_L01_004606A8(void *);
extern void func_L39_00668660(S_006692A0 *, void *, s32);
extern void func_L39_00667700(S_006692A0 *, A_006692A0 *, s32);
extern void func_L39_0061CFC8(void *, void *, void *, s32, s32);
extern void func_L39_00621370(void *);
extern void func_L39_00667208(void *, u32, s32, s32);

/* keyed byte-table decode of the protected word at q (0 when unset), as the matched L39 code writes it */
static u32 dec_006692A0(u8 *q) {
    Dec_006692A0 buf;
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
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    return b;
}

/* the same decode read as a float (the second word) */
static f32 decf_006692A0(u8 *q) {
    Dec_006692A0 buf;
    u32 a;
    u32 b;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*q == 0) {
        return 0.0f;
    }
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = b;
    return buf.f[1];
}

/* the slot's team bits select this actor (flags 0x400: only the matching one of 0x100/0x200) */
static s32 team_ok_006692A0(S_006692A0 *s, A_006692A0 *a) {
    s32 f = s->flags;

    if (!(f & 0x400)) {
        return 1;
    }
    if ((f & 0x100) && a->w2548 == 0) {
        return 1;
    }
    if ((f & 0x200) && a->w2548 == 1) {
        return 1;
    }
    return 0;
}

/* the actor is within reach of the slot's model: z window -2.5..+3.0 and distance under limit */
static s32 near_006692A0(S_006692A0 *s, A_006692A0 *a, f32 limit) {
    u8 *m = s->model;
    f32 z = *(f32 *)(m + 0x18);

    if (z - 2.5f <= a->qA0.z && a->qA0.z <= z + 3.0f) {
        return func_L01_0040E570(m + 0x10, &a->qA0) < limit;
    }
    return 0;
}

static void copy_model_006692A0(S_006692A0 *s, A_006692A0 *a) {
    u8 *m = s->model;

    a->qA0 = *(vu0_v4 *)(m + 0x10);
    a->qB0 = *(vu0_v4 *)(m + 0xF0);
    a->q20 = *(vu0_v4 *)(m + 0xC0);
    a->q30 = *(vu0_v4 *)(m + 0xD0);
    a->q40 = *(vu0_v4 *)(m + 0xE0);
    func_L39_00621370(a);
}

void func_L39_006692A0(S_006692A0 *self, u8 *changed) {
    s32 idx;
    s32 i;
    A_006692A0 *a;
    Tbl_006692A0 *t;
    u8 tmp[16];
    s32 h;
    s32 st;

    idx = func_L39_0061BF68(self->owner);
    if (idx >= 0) {
        s32 update = 0;

        a = func_L39_0061BF38(idx);
        if (a->w2F0 >= 0x1A && self->model[0xBC] != 0xB && (a->p2534->w1A4 & 0x10)) {
            update = 1;
        } else if (decf_006692A0(&a->b2476) <= 0.0f) {
            update = 1;
        } else if (a->p2530 != 0 && a->p2530->b27B != 0 && (dec_006692A0(&a->b19E4) ^ 0x31) == 0) {
            update = 1;
        }
        if (update) {
            func_L39_00668660(self, tmp, 1);
            *changed = 1;
            self->flags |= 2;
            func_L39_00667700(self, a, 1);
            func_L01_004606A8(a->p2534);
            self->w328 = idx + 1;
            if (!(self->flags & 0x10000000)) {
                func_L39_0061CFC8(a, tmp, (u8 *)a + 0xB0, 1, 0);
            }
        } else if (a->w254C == 5 || a->w254C == 3) {
            if (D_L39_0033AB08[self->type].hookC != 0) {
                D_L39_0033AB08[self->type].hookC(self->model);
            }
            if (!(self->flags & 0x2000000)) {
                a->w2450 = 0x1D;
            }
            if (!(self->flags & 0x10000000)) {
                copy_model_006692A0(self, a);
            }
        }
    }

    for (i = 0; i < *D_L39_00241120; i++) {
        a = func_L39_0061BF38(i);
        if (*changed == 0 && self->owner == 0) {
            if (a->w251C == 0 && D_001A5CD0.b6AC == 0 && !(a->p2CC != 0 && *(s16 *)(a->p2CC + 0xAA) == 0x10C3) &&
                a->w254C == 0 && (dec_006692A0(&a->b19E4) ^ 0x31) != 0 && (dec_006692A0(&a->b19E4) ^ 0x37) != 0) {
                t = &D_L39_004840A0[a->w2544];
                if ((t->w0 == 0 || t->w0 == 7) &&
                    (self->other == 0 || *(s32 *)(self->other + 0x2548) == a->w2548) &&
                    decf_006692A0(&a->b2476) > 0.0f && self->health > 0.0f && team_ok_006692A0(self, a) &&
                    (dec_006692A0(&a->b19E6) ^ 0x14) != 0 &&
                    near_006692A0(self, a, (self->flags & 0x1000000) ? 8.0f : 20.0f)) {
                    t = &D_L39_004840A0[a->w2544];
                    t->w0 = 7;
                    t->w8 = 10;
                    t->w4 = 0;
                    func_L01_00451F60((self->flags & 0x1000000) ? 0x8C5 : 0x8C2, 4, a->b24C9);
                    if (a->p2534->w1A4 & 0x10) {
                        a->w2550 = 0;
                        a->w254C = 1;
                        a->w252C = self;
                        func_L39_00667208(self, a->id, 0, D_001A5CD0.event);
                    }
                }
            }
        }
        if (self->owner != 0 && D_001A5CD0.b6AC == 0 && !(self->flags & 0x100000) &&
            *(s32 *)(self->owner + 0x2548) == a->w2548 &&
            !(a->p2CC != 0 && *(s16 *)(a->p2CC + 0xAA) == 0x10C3) && self->other == 0 &&
            (dec_006692A0(&a->b19E4) ^ 0x31) != 0 && (dec_006692A0(&a->b19E4) ^ 0x37) != 0 && a->w254C == 0 &&
            decf_006692A0(&a->b2476) > 0.0f && self->health > 0.0f && team_ok_006692A0(self, a) &&
            (dec_006692A0(&a->b19E6) ^ 0x14) != 0) {
            t = &D_L39_004840A0[a->w2544];
            if ((t->w0 == 0 || t->w0 == 7) && near_006692A0(self, a, 20.0f)) {
                t = &D_L39_004840A0[a->w2544];
                t->w0 = 7;
                t->w8 = 10;
                t->w4 = 0;
                func_L01_00451F60(0x8C3, 4, a->b24C9);
                if (a->p2534->w1A4 & 0x10) {
                    a->w2550 = 0;
                    a->w254C = 2;
                    a->w252C = self;
                    func_L39_00667208(self, a->id, 1, D_001A5CD0.event);
                    *changed = 1;
                }
            }
        }
        if (self->owner == (u8 *)a) {
            if (a->p2534->w1A4 & 2) {
                h = *(s16 *)(self->model + 0xAA);
                if (h == 0x107C || h == 0x107E) {
                    st = self->model[0xBC];
                    if (st != 0xB && st != 10 && a->w254C != 3 && self->other == 0) {
                        a->w254C = 3;
                        a->w2550 = 0;
                        a->w252C = self;
                        func_L39_00667208(self, a->id, 1, D_001A5CD0.event);
                        *changed = 1;
                    }
                }
            }
        }
        if (self->other == (u8 *)a && a->w251C == 0) {
            if (a->p2534->w1A4 & 2) {
                st = self->model[0xBC];
                if (st != 0xB && st != 10 && a->w254C != 4) {
                    h = *(s16 *)(self->model + 0xAA);
                    if ((h == 0x107C || h == 0x107E) && self->owner == 0) {
                        a->w254C = 4;
                        a->w2550 = 0;
                        a->w252C = self;
                        func_L39_00667208(self, a->id, 0, D_001A5CD0.event);
                        *changed = 1;
                    }
                }
            }
        }
    }
}
