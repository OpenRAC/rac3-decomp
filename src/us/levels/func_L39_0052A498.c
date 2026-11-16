#include "common.h"

/* NTSC-U counterpart of func_L39_0052AA00 (src/levels/shared/L39_0052A2B8.c) */
/* localdecomp:start func_L39_0052A498 */
#include "vu0.h"

typedef struct VT_0052AA00 {
    u8 pad0[0x34];
    void (*fn34)(void *, s32, s32, s32, s32);
} VT_0052AA00;

typedef struct Q_0052AA00 {
    u8 pad0[4];
    f32 f4;
} Q_0052AA00;

typedef struct M3_0052AA00 {
    vu0_v4 v[3];
} M3_0052AA00;

typedef struct Dst_0052AA00 {
    u8 pad0[0x10];
    vu0_v4 v10;
    u8 pad20[0x34 - 0x20];
    u16 h34;
    u8 pad36[0x68 - 0x36];
    Q_0052AA00 *p68;
    u8 pad6C[0xC0 - 0x6C];
    M3_0052AA00 m;
} Dst_0052AA00;

typedef struct G_0052AA00 {
    u8 pad0[0x14];
    VT_0052AA00 *vt;
    u8 pad18[0x180 - 0x18];
    u8 b180[0x2F0 - 0x180];
    s32 s2F0;
    u8 pad2F4[0x470 - 0x2F4];
    s32 s470;
    u8 pad474[0x610 - 0x474];
    f32 f610;
    u8 pad614[0x15E0 - 0x614];
    u8 *p15E0;
    u8 *p15E4;
    u8 pad15E8[0x15EC - 0x15E8];
    s16 h15EC;
    u8 pad15EE[0x19E4 - 0x15EE];
    u8 b19E4;
    u8 pad19E5[0x1A14 - 0x19E5];
    u8 b1A14;
    u8 pad1A15[0x1A40 - 0x1A15];
    u8 b1A40;
    u8 pad1A41[0x2488 - 0x1A41];
    s16 h2488;
    u8 pad248A[0x24C9 - 0x248A];
    u8 b24C9;
} G_0052AA00;

typedef struct Obj_0052AA00 {
    u8 pad0[0x14];
    Dst_0052AA00 *p14;
    f32 f18;
    f32 f1C;
    f32 f20;
    G_0052AA00 *p24;
} Obj_0052AA00;

typedef struct Self_0052AA00 {
    u8 pad0[0x20];
    u8 b20;
    u8 pad21[0x34 - 0x21];
    u8 b34;
    u8 pad35[0x60 - 0x35];
    u8 b60;
    u8 pad61[0x68 - 0x61];
    Obj_0052AA00 *p68;
    u8 pad6C[0xC0 - 0x6C];
    M3_0052AA00 m;
} Self_0052AA00;

typedef union Buf_0052AA00 {
    u8 b[8];
    u32 w[2];
} Buf_0052AA00;

typedef union Tmp_0052AA00 {
    vu0_v4 v;
    Buf_0052AA00 buf;
} Tmp_0052AA00;

extern u8 D_L39_004998A0[];
extern vu0_v4 D_L39_0024D5F0 __attribute__((section(".sdata")));
extern f32 D_L39_0024D600[] __attribute__((section(".sdata")));
extern s32 D_L39_0024AB94;
__asm__(".extern D_L39_0024AB94, 4");

extern void func_L39_00619D58(Self_0052AA00 *, void *);
extern Dst_0052AA00 *func_L39_0052AE98(Self_0052AA00 *, f32);
extern void func_L01_003F4D78(s32, Self_0052AA00 *, u32, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern void func_003BDA38(Self_0052AA00 *, s32, void *);
extern f32 func_003887C8(void *, void *);
extern f32 func_00388770(void *);
extern void func_00388830(void *, void *, f32);
extern void func_L01_00402498(void (*)(Self_0052AA00 *), Self_0052AA00 *);
extern void func_L01_004026A0(void (*)(Self_0052AA00 *), Self_0052AA00 *);
extern void func_L01_002FD500(Self_0052AA00 *);
extern void func_L01_002FD0A0(Self_0052AA00 *);
extern s32 func_L39_005F0CE0(s32, s32, Self_0052AA00 *);
extern s32 func_L39_00670988(void *, s32, s32, s32);
extern s32 func_00388398(void *);
extern void func_L39_00529D78(Self_0052AA00 *);

static __inline__ u32 Dec_0052AA00(u8 *q) {
    Buf_0052AA00 buf;
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
        *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = b;
    return b;
}

static __inline__ u32 DecQ_0052AA00(u8 *q, Buf_0052AA00 *buf) {
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
    d = buf->b;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
    }
    a = buf->w[0] ^ (u32)q;
    b = buf->w[1] ^ a;
    buf->w[0] = a;
    buf->w[1] = b;
    return b;
}

void func_L39_0052A498(Self_0052AA00 *self) {
    Obj_0052AA00 *obj;
    G_0052AA00 *g;
    Q_0052AA00 *q;
    f32 d;
    s32 n;

    obj = self->p68;
    if (self->b20 == 0) {
        func_L39_00619D58(self, (u8 *)obj + 0x24);
    }
    g = obj->p24;
    if ((Dec_0052AA00(&g->b19E4) ^ 1) == 0) {
        g->vt->fn34(g, 0x1D, 1, 0, 1);
    }
    if (obj != 0) {
        q = 0;
        if (obj->p14 == 0) {
            obj->p14 = func_L39_0052AE98(self, 0.8000000715255737f);
        }
        if (obj->p14 != 0) {
            q = obj->p14->p68;
        }
        if ((Dec_0052AA00(&g->b19E4) ^ 1) == 0 || (Dec_0052AA00(&g->b19E4) ^ 0x1D) == 0) {
            if (g->s2F0 >= 2) {
                if (g->b1A14 != 0) {
                    func_L01_003F4D78(g->b24C9, self, 0xFF0000FF, 0, 0x24, -1, 4, 1.0f, 0.0f, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
                }
                if (g->p15E0 != 0) {
                    u8 *pos = g->p15E0 + 0x10;
                    if (g->b1A14 != 0) {
                        func_L01_003F4D78(g->b24C9, self, 0xFFFF0000, pos, 0x24, -1, 4, 1.4f, 0.0f, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
                    }
                }
            }
        }
        func_003BDA38(self, 0, &D_L39_0024D5F0);
        func_003BDA38(self, 1, &D_L39_0024D600);
        {
        vu0_v4 sv = D_L39_0024D5F0;
        Tmp_0052AA00 b;
        vu0_v4 a;
        D_L39_0024D600[2] -= 0.02f;
        if ((u32)(self->b20 - 2) >= 0x13) {
            if (obj->p14 != 0) {
                func_003BDA38(self, 0, (u8 *)obj->p14 + 0x10);
                obj->p14->m = self->m;
                obj->p14->h34 |= 0x41;
            }
        }
        switch (self->b20) {
        case 0:
        case 1:
            if (self->b60 & 2) {
                self->b20 = 1;
            }
            func_L39_00670988(&g->b1A40, 0, 1, 0);
            if ((DecQ_0052AA00(&g->b19E4, &b.buf) ^ 0x2B) == 0 && q != 0 && g->p15E4 != 0) {
                d = func_003887C8(g->p15E4 + 0x10, (u8 *)obj->p14 + 0x10);
                n = g->s470 <= 0x1D ? 5 : 7;
                q->f4 = d / (f32)n;
                obj->f20 = 0.28f;
                obj->f1C = 1.0f;
                obj->f18 = 0;
                func_L39_005F0CE0(0, 0, self);
                self->b20 = 9;
            }
            break;
        case 6:
            func_L01_00402498(func_L39_00529D78, self);
            q->f4 = 1.3333333730697632f;
            self->b20 = 7;
            break;
        case 7: {
            func_003BDA38(self, 0, &a);
            vec_sub_ab(&b.v, &a, (u8 *)obj->p14 + 0x10);
            d = q->f4;
            d += func_00388770(g->b180);
            if (d < func_003887C8((u8 *)obj->p14 + 0x10, &a)) {
                func_00388830(&b.v, &b.v, d);
                vec_add_ba((u8 *)obj->p14 + 0x10, (u8 *)obj->p14 + 0x10, &b.v);
                func_L01_00402498(func_L39_00529D78, self);
            } else {
                obj->p14->v10 = a;
                self->b20 = 1;
            }
            break;
        }
        case 9: {
            func_L01_00402498(func_L39_00529D78, self);
            vec_sub_ab(&b.v, g->p15E4 + 0x10, (u8 *)obj->p14 + 0x10);
            if (q->f4 < func_00388770(&b.v)) {
                func_00388830(&b.v, &b.v, q->f4);
                vec_add_ba((u8 *)obj->p14 + 0x10, (u8 *)obj->p14 + 0x10, &b.v);
            } else {
                obj->p14->v10 = *(vu0_v4 *)(g->p15E4 + 0x10);
                self->b20 = 0xB;
                func_L39_005F0CE0(1, 0, self);
            }
            break;
        }
        case 10:
            func_L01_00402498(func_L39_00529D78, self);
            self->b20 = 0xB;
            break;
        case 11:
            func_L01_00402498(func_L39_00529D78, self);
            obj->f20 *= 0.4000000059604645f;
            obj->f18 += 0.69813168f;
            if (obj->f20 < 0.16800001f) {
                g->h15EC = 1;
                self->b20 = 0xC;
            }
            break;
        case 12:
            if (g->p15E4 != 0) {
                obj->p14->v10 = *(vu0_v4 *)(g->p15E4 + 0x10);
            }
            obj->f20 *= 0.4000000059604645f;
            obj->f18 += 0.69813168f;
            func_L01_00402498(func_L39_00529D78, self);
            if ((DecQ_0052AA00(&g->b19E4, &b.buf) ^ 0x2B) != 0) {
                self->b20 = 0xD;
            }
            break;
        case 13:
            func_L01_00402498(func_L39_00529D78, self);
            q->f4 = 1.3333333730697632f;
            self->b20 = 0xE;
            break;
        case 14: {
            func_003BDA38(self, 0, &a);
            vec_sub_ab(&b.v, &a, (u8 *)obj->p14 + 0x10);
            if (q->f4 < func_003887C8((u8 *)obj->p14 + 0x10, &a)) {
                func_00388830(&b.v, &b.v, q->f4);
                vec_add_ba((u8 *)obj->p14 + 0x10, (u8 *)obj->p14 + 0x10, &b.v);
                func_L01_00402498(func_L39_00529D78, self);
            } else {
                obj->p14->v10 = a;
                self->b20 = 1;
            }
            if ((Dec_0052AA00(&g->b19E4) ^ 0x2B) == 0 && q != 0 && g->p15E4 != 0) {
                q->f4 = func_003887C8(g->p15E4 + 0x10, (u8 *)obj->p14 + 0x10) / 10.0f;
                obj->f18 = 0;
                obj->f20 = 0;
                obj->f1C = 1.0f;
                self->b20 = 9;
            }
            break;
        }
        case 25:
            break;
        case 22:
            if (func_00388398(&D_L39_0024AB94) != 0) {
                g->f610 = 1.0f;
                D_L39_0024AB94 = 7;
                self->b20 = 0x17;
            }
            break;
        }
        }
        func_L01_002FD500(self);
        if ((self->b34 ^ 1) & 1) {
            if (g != 0) {
                if (g->h2488 == 0) {
                    func_L01_004026A0(func_L01_002FD0A0, self);
                }
            }
        }
    }
}
/* localdecomp:end func_L39_0052A498 */
