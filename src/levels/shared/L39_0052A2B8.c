#include "common.h"

/* localdecomp:start func_L39_0052A2B8 */
#include "vu0.h"
struct Self_0052AA00;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0052A2B8;
typedef struct {
    V4_0052A2B8 v[4];
    u32 col[4];
    f32 uv[4][2];
    unsigned long tag[4];
} Q_0052A2B8;
typedef struct {
    u8 pad0[0x14];
    u8 *f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    u8 *f24;
    f32 f28;
    s32 f2C;
    u32 f30;
} P_0052A2B8;
extern u8 *D_L39_002968EC __attribute__((section(".data")));
extern unsigned long func_L39_00589890(int);
extern void func_003C2F58(struct Self_0052AA00 *, s32, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_L39_005B4468(f32, f32);
extern f32 func_L39_005B4410(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_L39_005B43C8(s32, s32);
extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, f32, f32, f32, s32);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038DB48(f32);
extern void func_003D2DA0(void *, s32, s32);

/* from rac2-decomp's func_L01_0038EF40 (the wavy link strip), here drawn twice with sparks */
void func_L39_0052A2B8(struct Self_0052AA00 *self) {
    u8 *a0 = (u8 *)self;
    Q_0052A2B8 q;
    V4_0052A2B8 start;
    V4_0052A2B8 cur;
    V4_0052A2B8 end;
    V4_0052A2B8 dir;
    V4_0052A2B8 side;
    V4_0052A2B8 up;
    V4_0052A2B8 tmp;
    V4_0052A2B8 to;
    V4_0052A2B8 off;
    V4_0052A2B8 pos;
    V4_0052A2B8 vel;
    P_0052A2B8 *pv;
    u8 *tgt;
    s32 i;
    s32 n;
    f32 ang;
    f32 dang;
    f32 width;
    f32 len;
    f32 t;
    f32 step;
    f32 wave;
    f32 s;
    f32 sn;
    f32 a;
    f32 amp;
    f32 sc;
    u8 *r;
    s32 k;
    unsigned long tex;
    unsigned long t2 = 0xFF9000000260;
    unsigned long t3 = 0xFF00000044;

    if (a0 == 0) {
        return;
    }
    pv = *(P_0052A2B8 **)(a0 + 0x68);
    if (pv == 0) {
        return;
    }
    pv->f28 += 0.2f;
    tgt = pv->f24;
    if (pv->f28 >= 3.0f) {
        pv->f28 = 0.0f;
    }
    for (i = 0; i < 2; i++) {
        if (i == 1) {
            pv->f2C = 14;
            pv->f30 = 0x3020FF20;
            width = 0.11f;
        } else {
            pv->f2C = 0x45;
            pv->f30 = 0x80208040;
            width = 0.05f;
        }
        tex = func_L39_00589890(pv->f2C);
        q.col[3] = pv->f30;
        q.col[2] = pv->f30;
        q.col[1] = pv->f30;
        q.col[0] = pv->f30;
        q.tag[1] = tex;
        q.tag[2] = t2;
        q.tag[0] = 0;
        q.tag[3] = t3;
        q.uv[0][0] = pv->f28 + 0.0f;
        q.uv[0][1] = 0.0f;
        q.uv[1][0] = pv->f28 + 1.0f;
        q.uv[1][1] = 0.0f;
        q.uv[2][0] = pv->f28 + 0.0f;
        q.uv[2][1] = 1.0f;
        q.uv[3][0] = pv->f28 + 1.0f;
        q.uv[3][1] = 1.0f;
        func_003C2F58(self, 1, &end);
        start = *(V4_0052A2B8 *)(pv->f14 + 0x10);
        cur = start;
        dang = func_0038D160(*(f32 *)(tgt + 0x23A0) - *(f32 *)(a0 + 0x10),
                            *(f32 *)(tgt + 0x23A4) - *(f32 *)(a0 + 0x14));
        n = func_L39_005B4468(2.0f, 5.0f);
        pos.x = *(f32 *)(a0 + 0x10) + func_L39_005B4410(-0.01f, 0.01f);
        pos.y = *(f32 *)(a0 + 0x14) + func_L39_005B4410(-0.01f, 0.01f);
        pos.z = *(f32 *)(a0 + 0x18) + func_L39_005B4410(-0.01f, 0.01f);
        s = func_L39_005B4410(0.4f, 0.6f);
        sc = func_L39_005B4410(4.5f, 6.0f);
        ang = func_0038DAB8(dang, func_L39_005B4468(0.0f, 1.3962634f));
        sc *= 0.020000001f;
        vel.x = func_0038D098(ang);
        vel.x *= sc;
        vel.y = func_0038D0B0(ang);
        vel.y *= sc;
        vel.z = 0.0f;
        vel.z = func_L39_005B4410(0.0f, 0.5f);
        vel.z *= 0.020000001f;
        func_L01_004713C8(&start, &vel, (func_L39_005B43C8(15, 25) * 5 + 2) / 6, 0x40FF7F, n, 0x7F, 0x7F,
                          s * 210000.0f, 2100.0f, 0.0064000003f, 6);
        n = -(n * 2);
        k = func_L39_005B43C8(15, 25);
        s *= 3.0f;
        r = func_L01_004713C8(&start, &vel, (k * 5 + 2) / 6, 0xFF20, n, 0x30, 0x30,
                              s * 210000.0f, 4200.0f, 0.0064000003f, 0);
        if (r != 0) {
            r[2] = *D_L39_002968EC;
        }
        func_003D9508(&start, 0x31, 0x2F208040, 1, 0.25f, 0.125f, 0.0f);
        func_003D9508(&start, 0x31, 0x2F208040, 1, 0.4f, 0.124f, 0.0f);
        func_003D9508(&start, 0xB, 0x2F007F00, 1, 0.55f, 0.123f, 0.0f);
        vec_sub_ab(&dir, &end, &start);
        len = func_0038CEA8(&dir);
        tmp = dir;
        tmp.z -= 0.1f;
        func_0038CE90(&side, &dir, &tmp);
        func_0038CE90(&up, &dir, &side);
        q.v[0] = start;
        q.v[2] = start;
        q.v[2].z += width;
        q.v[0].z -= width;
        amp = func_0038D098(func_0038DB48(pv->f18));
        t = 0.0f;
        while (t < len) {
            step = 0.4f;
            if (len - t < step) {
                step = len - t;
            }
            t += step;
            a = t * 3.1415927f;
            sn = func_0038D0B0(a / len);
            wave = func_0038D0B0(func_0038DB48(a / pv->f1C)) * sn;
            wave *= amp;
            wave *= pv->f20;
            func_0038CF68(&dir, &dir, step);
            vec_add_ab(&cur, &cur, &dir);
            q.v[1] = cur;
            q.v[3] = cur;
            vec_sub_ba(&to, tgt + 0x23A0, &cur);
            func_0038CE90(&off, &to, &dir);
            func_0038CF68(&off, &off, width);
            vec_add_ab(&q.v[1], &q.v[1], &off);
            vec_sub_ab(&q.v[3], &q.v[3], &off);
            func_0038CF68(&tmp, &side, wave);
            vec_add_ab(&q.v[1], &q.v[1], &tmp);
            vec_add_ab(&q.v[3], &q.v[3], &tmp);
            func_003D2DA0(&q, 0, 1);
            start = cur;
            q.v[0] = q.v[1];
            q.v[2] = q.v[3];
        }
    }
}
/* localdecomp:end func_L39_0052A2B8 */

/* localdecomp:start func_L39_0052AA00 */
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

extern u8 D_L39_004997E0[];
extern vu0_v4 D_L39_0024D4F0 __attribute__((section(".sdata")));
extern f32 D_L39_0024D500[] __attribute__((section(".sdata")));
extern s32 D_L39_0024AA84;
__asm__(".extern D_L39_0024AA84, 4");

extern void func_L39_0061C4D0(Self_0052AA00 *, void *);
extern Dst_0052AA00 *func_L39_0052B400(Self_0052AA00 *, f32);
extern void func_L01_003F6F20(s32, Self_0052AA00 *, u32, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern void func_003C2F58(Self_0052AA00 *, s32, void *);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00404808(void (*)(Self_0052AA00 *), Self_0052AA00 *);
extern void func_L01_00404A10(void (*)(Self_0052AA00 *), Self_0052AA00 *);
extern void func_L01_002FD530(Self_0052AA00 *);
extern void func_L01_002FD0C8(Self_0052AA00 *);
extern s32 func_L39_005F33E0(s32, s32, Self_0052AA00 *);
extern s32 func_L39_006732D0(void *, s32, s32, s32);
extern s32 func_0038CAD0(void *);
extern void func_L39_0052A2B8(Self_0052AA00 *);

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
        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
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
        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    a = buf->w[0] ^ (u32)q;
    b = buf->w[1] ^ a;
    buf->w[0] = a;
    buf->w[1] = b;
    return b;
}

void func_L39_0052AA00(Self_0052AA00 *self) {
    Obj_0052AA00 *obj;
    G_0052AA00 *g;
    Q_0052AA00 *q;
    f32 d;
    s32 n;

    obj = self->p68;
    if (self->b20 == 0) {
        func_L39_0061C4D0(self, (u8 *)obj + 0x24);
    }
    g = obj->p24;
    if ((Dec_0052AA00(&g->b19E4) ^ 1) == 0) {
        g->vt->fn34(g, 0x1D, 1, 0, 1);
    }
    if (obj != 0) {
        q = 0;
        if (obj->p14 == 0) {
            obj->p14 = func_L39_0052B400(self, 0.96000004f);
        }
        if (obj->p14 != 0) {
            q = obj->p14->p68;
        }
        if ((Dec_0052AA00(&g->b19E4) ^ 1) == 0 || (Dec_0052AA00(&g->b19E4) ^ 0x1D) == 0) {
            if (g->s2F0 >= 2) {
                if (g->b1A14 != 0) {
                    func_L01_003F6F20(g->b24C9, self, 0xFF0000FF, 0, 0x24, -1, 4, 1.0f, 0.0f, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
                }
                if (g->p15E0 != 0) {
                    u8 *pos = g->p15E0 + 0x10;
                    if (g->b1A14 != 0) {
                        func_L01_003F6F20(g->b24C9, self, 0xFFFF0000, pos, 0x24, -1, 4, 1.4f, 0.0f, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
                    }
                }
            }
        }
        func_003C2F58(self, 0, &D_L39_0024D4F0);
        func_003C2F58(self, 1, &D_L39_0024D500);
        {
        vu0_v4 sv = D_L39_0024D4F0;
        Tmp_0052AA00 b;
        vu0_v4 a;
        D_L39_0024D500[2] -= 0.02f;
        if ((u32)(self->b20 - 2) >= 0x13) {
            if (obj->p14 != 0) {
                func_003C2F58(self, 0, (u8 *)obj->p14 + 0x10);
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
            func_L39_006732D0(&g->b1A40, 0, 1, 0);
            if ((DecQ_0052AA00(&g->b19E4, &b.buf) ^ 0x2B) == 0 && q != 0 && g->p15E4 != 0) {
                d = func_0038CF00(g->p15E4 + 0x10, (u8 *)obj->p14 + 0x10);
                n = g->s470 <= 0x18 ? 4 : 6;
                q->f4 = d / (f32)n;
                obj->f20 = 0.28f;
                obj->f1C = 1.0f;
                obj->f18 = 0;
                func_L39_005F33E0(0, 0, self);
                self->b20 = 9;
            }
            break;
        case 6:
            func_L01_00404808(func_L39_0052A2B8, self);
            q->f4 = 1.6000001f;
            self->b20 = 7;
            break;
        case 7: {
            func_003C2F58(self, 0, &a);
            vec_sub_ab(&b.v, &a, (u8 *)obj->p14 + 0x10);
            d = q->f4;
            d += func_0038CEA8(g->b180);
            if (d < func_0038CF00((u8 *)obj->p14 + 0x10, &a)) {
                func_0038CF68(&b.v, &b.v, d);
                vec_add_ba((u8 *)obj->p14 + 0x10, (u8 *)obj->p14 + 0x10, &b.v);
                func_L01_00404808(func_L39_0052A2B8, self);
            } else {
                obj->p14->v10 = a;
                self->b20 = 1;
            }
            break;
        }
        case 9: {
            func_L01_00404808(func_L39_0052A2B8, self);
            vec_sub_ab(&b.v, g->p15E4 + 0x10, (u8 *)obj->p14 + 0x10);
            if (q->f4 < func_0038CEA8(&b.v)) {
                func_0038CF68(&b.v, &b.v, q->f4);
                vec_add_ba((u8 *)obj->p14 + 0x10, (u8 *)obj->p14 + 0x10, &b.v);
            } else {
                obj->p14->v10 = *(vu0_v4 *)(g->p15E4 + 0x10);
                self->b20 = 0xB;
                func_L39_005F33E0(1, 0, self);
            }
            break;
        }
        case 10:
            func_L01_00404808(func_L39_0052A2B8, self);
            self->b20 = 0xB;
            break;
        case 11:
            func_L01_00404808(func_L39_0052A2B8, self);
            obj->f20 *= 0.27999997f;
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
            obj->f20 *= 0.27999997f;
            obj->f18 += 0.69813168f;
            func_L01_00404808(func_L39_0052A2B8, self);
            if ((DecQ_0052AA00(&g->b19E4, &b.buf) ^ 0x2B) != 0) {
                self->b20 = 0xD;
            }
            break;
        case 13:
            func_L01_00404808(func_L39_0052A2B8, self);
            q->f4 = 1.6000001f;
            self->b20 = 0xE;
            break;
        case 14: {
            func_003C2F58(self, 0, &a);
            vec_sub_ab(&b.v, &a, (u8 *)obj->p14 + 0x10);
            if (q->f4 < func_0038CF00((u8 *)obj->p14 + 0x10, &a)) {
                func_0038CF68(&b.v, &b.v, q->f4);
                vec_add_ba((u8 *)obj->p14 + 0x10, (u8 *)obj->p14 + 0x10, &b.v);
                func_L01_00404808(func_L39_0052A2B8, self);
            } else {
                obj->p14->v10 = a;
                self->b20 = 1;
            }
            if ((Dec_0052AA00(&g->b19E4) ^ 0x2B) == 0 && q != 0 && g->p15E4 != 0) {
                q->f4 = func_0038CF00(g->p15E4 + 0x10, (u8 *)obj->p14 + 0x10) / 10.0f;
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
            if (func_0038CAD0(&D_L39_0024AA84) != 0) {
                g->f610 = 1.0f;
                D_L39_0024AA84 = 6;
                self->b20 = 0x17;
            }
            break;
        }
        }
        func_L01_002FD530(self);
        if ((self->b34 ^ 1) & 1) {
            if (g != 0) {
                if (g->h2488 == 0) {
                    func_L01_00404A10(func_L01_002FD0C8, self);
                }
            }
        }
    }
}
/* localdecomp:end func_L39_0052AA00 */
